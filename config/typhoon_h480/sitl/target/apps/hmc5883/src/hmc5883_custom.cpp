/****************************************************************************
*
*   Copyright (c) 2017 Windhover Labs, L.L.C. All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions
* are met:
*
* 1. Redistributions of source code must retain the above copyright
*    notice, this list of conditions and the following disclaimer.
* 2. Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in
*    the documentation and/or other materials provided with the
*    distribution.
* 3. Neither the name Windhover Labs nor the names of its 
*    contributors may be used to endorse or promote products derived 
*    from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
* "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
* LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
* FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
* COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
* OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
* AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
* LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
* ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
*
*****************************************************************************/
/************************************************************************
** Pragmas
*************************************************************************/

/************************************************************************
** Includes
*************************************************************************/
#include "cfe.h"
#include "hmc5883_app.h"
#include "hmc5883_i2c.h"
#include "hmc5883_events.h"
#include "hmc5883_perfids.h"
#include "px4lib.h"
#include "simlib.h"
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <time.h>

extern HMC5883 oHMC5883;

/************************************************************************
** Local Defines
*************************************************************************/

/************************************************************************
** Local Structure Declarations
*************************************************************************/
typedef enum {

/** \brief <tt> 'HMC5883 - ' </tt>
**  \event <tt> 'HMC5883 - ' </tt>
**  
**  \par Type: ERROR
**
**  \par Cause:
**
**  This event message is issued when a device resource encounters an 
**  error.
**
*/
    HMC5883_DEVICE_ERR_EID = HMC5883_EVT_CNT,

/** \brief Number of custom events 
**
**  \par Limits:
**       int32
*/
    HMC5883_CUSTOM_EVT_CNT
} HMC5883_CustomEventIds_t;


/************************************************************************
** External Global Variables
*************************************************************************/

/************************************************************************
** Global Variables
*************************************************************************/
HMC5883_AppCustomData_t HMC5883_AppCustomData;

/************************************************************************
** Local Variables
*************************************************************************/

/************************************************************************
** Local Function Definitions
*************************************************************************/
void HMC5883_Custom_InitData(void)
{
    /* Set all struct zero values */
    bzero(&HMC5883_AppCustomData, sizeof(HMC5883_AppCustomData));
    HMC5883_AppCustomData.SelfTestMode = FALSE;
    return;
}


boolean HMC5883_Custom_Init()
{
    boolean returnBool = TRUE;
    HMC5883_AppCustomData.Status = HMC5883_CUSTOM_INITIALIZED;

end_of_function:
    return (returnBool);
}


boolean HMC5883_Custom_Set_Range(uint8 Range)
{
    boolean returnBool = TRUE;
    
    if(HMC5883_BITS_CONFIG_B_RANGE_2GA5 == Range)
    {
        HMC5883_AppCustomData.SelfTestMode = TRUE;
    }
    else
    {
        HMC5883_AppCustomData.SelfTestMode = FALSE;
    }

    return (returnBool);
}


boolean HMC5883_Custom_Get_Range(uint8 *Range)
{
    return (TRUE);
}


boolean HMC5883_Custom_Check_Range(uint8 Range)
{
    return (TRUE);
}


boolean HMC5883_Custom_Set_Config(uint8 Config)
{
    return (TRUE);
}


boolean HMC5883_Custom_Get_Config(uint8 *Config)
{
    return (TRUE);
}


boolean HMC5883_Custom_Check_Config(uint8 Config)
{
    return (TRUE);
}


boolean HMC5883_Custom_Measure(int16 *X, int16 *Y, int16 *Z)
{
    boolean returnBool = TRUE;

    float calX_f = 0.0f;
    float calY_f = 0.0f;
    float calZ_f = 0.0f;
    /* Temp for inverse roation */
    float temp   = 0.0f;

    /* Null pointer check */
    if(0 == X || 0 == Y || 0 == Z)
    {
        (void) CFE_EVS_SendEvent(HMC5883_DEVICE_ERR_EID, CFE_EVS_ERROR,
            "HMC5883 Read_Gyro Null Pointer");
    }

    SIMLIB_GetMag(&calX_f, &calY_f, &calZ_f);


    if(FALSE == HMC5883_AppCustomData.SelfTestMode)
    {
        /* Apply inverse rotation */
        temp   = calY_f;
        calY_f = calX_f * -1;
        calX_f = temp;
        
        *X = ((calX_f / oHMC5883.Diag.Calibration.x_scale) + oHMC5883.Diag.Calibration.x_offset) / (oHMC5883.Diag.Conversion.Unit / oHMC5883.Diag.Conversion.Divider);
        *Y = ((calY_f / oHMC5883.Diag.Calibration.y_scale) + oHMC5883.Diag.Calibration.y_offset) / (oHMC5883.Diag.Conversion.Unit / oHMC5883.Diag.Conversion.Divider);
        *Z = ((calZ_f / oHMC5883.Diag.Calibration.z_scale) + oHMC5883.Diag.Calibration.z_offset) / (oHMC5883.Diag.Conversion.Unit / oHMC5883.Diag.Conversion.Divider);
    }
    else if (TRUE == HMC5883_AppCustomData.SelfTestMode)
    {
        /* Expected value from self-calibrate with inverse scaling */
        *X = 1.16f / (1.0f / 660.0f);
        *Y = 1.08f / (1.0f / 660.0f);
        *Z = 1.08f / (1.0f / 660.0f);
    }

    return (returnBool);
}


boolean HMC5883_Custom_Measure_Temp(int16 *Temp)
{
    boolean returnBool = TRUE;

    /* Null pointer check */
    if(0 == Temp)
    {
        (void) CFE_EVS_SendEvent(HMC5883_DEVICE_ERR_EID, CFE_EVS_ERROR,
            "HMC5883 Measure_Temp Null Pointer");
    }

    float calTemp = 0.0f;

    SIMLIB_GetTemp(&calTemp);

    *Temp = (int16) 128 * (calTemp -25);

    return (returnBool);
}


boolean HMC5883_Custom_ValidateID(void)
{
    return (TRUE);
}


boolean HMC5883_Custom_Send(uint8 Reg, uint8 Data)
{
    return (TRUE);
}


boolean HMC5883_Custom_Uninit(void)
{
    boolean returnBool = TRUE;
    HMC5883_AppCustomData.Status = HMC5883_CUSTOM_UNINITIALIZED;

    return (returnBool);
}


int32 HMC5883_Custom_Init_EventFilters(int32 ind, CFE_EVS_BinFilter_t *EventTbl)
{
    return (0);
}


boolean HMC5883_Apply_Platform_Rotation(float *X, float *Y, float *Z)
{
    boolean returnBool = TRUE;
    float temp         = 0;

    /* Null pointer check */
    if(0 == X || 0 == Y || 0 == Z)
    {
        (void) CFE_EVS_SendEvent(HMC5883_DEVICE_ERR_EID, CFE_EVS_ERROR,
            "HMC5883 Apply_Platform_Rotation Null Pointer");
        returnBool = FALSE;
        goto end_of_function;
    }
    
    /* The standard external mag by 3DR has x pointing to the
     * right, y pointing backwards, and z down, therefore switch x
     * and y and invert y. */
    temp = *X;
    *X = -*Y;
    *Y = temp;

end_of_function:

    return (returnBool);
}


void HMC5883_Get_Rotation(uint8 *Rotation)
{
    
    /* Null pointer check */
    if(0 == Rotation)
    {
        goto end_of_function;
    }

    *Rotation = ROTATION_YAW_90;

end_of_function:
    return;
}
