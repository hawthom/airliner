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

#include "to_app_test.h"
#include "to_app.h"
#include "to_test_utils.h"
#include "to_custom_stubs.h"
#include "to_custom_hooks.h"

#include "uttest.h"
#include "ut_osapi_stubs.h"
#include "ut_cfe_sb_stubs.h"
#include "ut_cfe_sb_hooks.h"
#include "ut_cfe_es_stubs.h"
#include "ut_cfe_es_hooks.h"
#include "ut_cfe_evs_stubs.h"
#include "ut_cfe_evs_hooks.h"
#include "ut_cfe_time_stubs.h"
#include "ut_cfe_psp_memutils_stubs.h"
#include "ut_cfe_tbl_stubs.h"
#include "ut_cfe_fs_stubs.h"
#include "ut_cfe_time_stubs.h"
#include "ut_osapi_hooks.h"
#include "ut_cfe_es_hooks.h"
#include "ut_cfe_es_hooks_ex.h"


int32 hookCalledCount = 0;

/**************************************************************************
 * Tests for TO_InitEvent()
 **************************************************************************/

/**
 * Test TO_InitEvent() with failed CFE_EVS_Register
 */
void Test_TO_InitEvent_Fail_Register(void)
{
    /* Set a fail result for EVS */
    int32 result = (CFE_SEVERITY_BITMASK & CFE_SEVERITY_ERROR)
                   | CFE_EVENTS_SERVICE | CFE_EVS_NOT_IMPLEMENTED;
    int32 expected = CFE_EVS_APP_NOT_REGISTERED;

    Ut_CFE_EVS_SetReturnCode(UT_CFE_EVS_REGISTER_INDEX, expected, 1);

    /* Execute the function being tested */
    result = TO_InitEvent();

    /* Verify results */
    UtAssert_True (result == expected, "InitEvent, failed EVS Register");
}


/**************************************************************************
 * Tests for TO_InitPipe()
 **************************************************************************/
/**
 * Test TO_InitPipe(), fail SCH CFE_SB_CreatePipe
 */
void Test_TO_InitPipe_Fail_CreateSCHPipe(void)
{
    /* Set a fail result for SB */
    int32 result = (CFE_SEVERITY_BITMASK & CFE_SEVERITY_ERROR)
                   | CFE_SOFTWARE_BUS_SERVICE | CFE_SB_NOT_IMPLEMENTED;
    int32 expected = CFE_SB_BAD_ARGUMENT;

    Ut_CFE_SB_SetReturnCode(UT_CFE_SB_CREATEPIPE_INDEX, expected, 1);

    /* Execute the function being tested */
    result = TO_InitPipe();

    /* Verify results */
    UtAssert_True (result == expected, "InitPipe, fail SB create SCH pipe");
}


/**
 * Test TO_InitPipe(), fail CFE_SB_SubscribeEx for wakeup
 */
void Test_TO_InitPipe_Fail_SubscribeWakeup(void)
{
    /* Set a fail result for SB */
    int32 result = (CFE_SEVERITY_BITMASK & CFE_SEVERITY_ERROR)
                   | CFE_SOFTWARE_BUS_SERVICE | CFE_SB_NOT_IMPLEMENTED;
    int32 expected = CFE_SB_BAD_ARGUMENT;

    Ut_CFE_SB_SetReturnCode(UT_CFE_SB_SUBSCRIBEEX_INDEX, expected, 1);

    /* Execute the function being tested */
    result = TO_InitPipe();

    /* Verify results */
    UtAssert_True (result == expected, "InitPipe, fail CFE_SB_SubscribeEx for wakeup");
}


/**
 * Test TO_InitPipe(), fail CFE_SB_SubscribeEx for sendhk
 */
void Test_TO_InitPipe_Fail_SubscribeSendHK(void)
{
    /* Set a fail result for SB */
    int32 result = (CFE_SEVERITY_BITMASK & CFE_SEVERITY_ERROR)
                   | CFE_SOFTWARE_BUS_SERVICE | CFE_SB_NOT_IMPLEMENTED;
    int32 expected = CFE_SB_BAD_ARGUMENT;

    Ut_CFE_SB_SetReturnCode(UT_CFE_SB_SUBSCRIBEEX_INDEX, expected, 2);

    /* Execute the function being tested */
    result = TO_InitPipe();

    /* Verify results */
    UtAssert_True (result == expected, "InitPipe, fail CFE_SB_SubscribeEx for sendhk");
}


/**
 * Test TO_InitPipe(), fail CMD CFE_SB_CreatePipe
 */
void Test_TO_InitPipe_Fail_CreateCMDPipe(void)
{
    /* Set a fail result for SB */
    int32 result = (CFE_SEVERITY_BITMASK & CFE_SEVERITY_ERROR)
                   | CFE_SOFTWARE_BUS_SERVICE | CFE_SB_NOT_IMPLEMENTED;
    int32 expected = CFE_SB_BAD_ARGUMENT;

    Ut_CFE_SB_SetReturnCode(UT_CFE_SB_CREATEPIPE_INDEX, expected, 2);

    /* Execute the function being tested */
    result = TO_InitPipe();

    /* Verify results */
    UtAssert_True (result == expected, "InitPipe, fail SB create CMD pipe");
}


/**
 * Test TO_InitPipe(), fail CFE_SB_Subscribe for CMD msg
 */
void Test_TO_InitPipe_Fail_SubscribeCMD(void)
{
    /* Set a fail result for SB */
    int32 result = (CFE_SEVERITY_BITMASK & CFE_SEVERITY_ERROR)
                   | CFE_SOFTWARE_BUS_SERVICE | CFE_SB_NOT_IMPLEMENTED;
    int32 expected = CFE_SB_BAD_ARGUMENT;

    Ut_CFE_SB_SetReturnCode(UT_CFE_SB_SUBSCRIBE_INDEX, expected, 1);

    /* Execute the function being tested */
    result = TO_InitPipe();

    /* Verify results */
    UtAssert_True (result == expected, "InitPipe, fail CFE_SB_Subscribe for CMD");
}


/**************************************************************************
 * Tests for TO_InitData()
 **************************************************************************/
/**
 * Test TO_InitData()
 */
void Test_TO_InitData(void)
{
    /* Set a fail result */
    int32 result = -1;
    int32 expected = CFE_SUCCESS;

    /* Execute the function being tested */
    TO_InitData();

    /* Verify results */
    UtAssert_True (CFE_SB_GetMsgId((CFE_SB_MsgPtr_t)&TO_AppData.HkTlm) == TO_HK_TLM_MID, "InitData");
}


/**************************************************************************
 * Tests for TO_InitApp()
 **************************************************************************/
/**
 * Test TO_InitApp(), fail init event
 */
void Test_TO_InitApp_Fail_InitEvent(void)
{
    int32 result = CFE_SUCCESS;
    int32 expected = CFE_EVS_APP_NOT_REGISTERED;

    Ut_CFE_EVS_SetReturnCode(UT_CFE_EVS_REGISTER_INDEX, expected, 1);

    /* Execute the function being tested */
    result = TO_InitApp();

    /* Verify results */
    UtAssert_True (result == expected, "InitApp, fail init event");
}


/**
 * Test TO_InitApp(), fail init pipe
 */
void Test_TO_InitApp_Fail_InitPipe(void)
{
    int32 result = CFE_SUCCESS;
    int32 expected = CFE_SB_BAD_ARGUMENT;

    Ut_CFE_SB_SetReturnCode(UT_CFE_SB_CREATEPIPE_INDEX, expected, 1);

    /* Execute the function being tested */
    result = TO_InitApp();

    /* Verify results */
    UtAssert_True (result == expected, "InitApp, fail init pipe");
}


/**
 * Test TO_InitApp(), fail init data.
 * NOTE: no current way to fail TO_InitData() in default
 */
void Test_TO_InitApp_Fail_InitData(void)
{
    int32 result = CFE_SUCCESS;
    int32 expected = CFE_SUCCESS;

    /* Execute the function being tested */
    result = TO_InitApp();

    /* Verify results */
    UtAssert_True (result == expected, "InitApp, fail init data");
}


/**
 * Test TO_InitApp(), fail memory pool creation.
 */
void Test_TO_InitApp_Fail_PoolCreateEx(void)
{
    int32 result = CFE_SUCCESS;
    int32 expected = CFE_ES_BAD_ARGUMENT;

    Ut_CFE_ES_SetReturnCode(UT_CFE_ES_POOLCREATEEX_INDEX, expected, 1);

    /* Execute the function being tested */
    result = TO_InitApp();

    /* Verify results */
    UtAssert_True (result == expected, "InitApp, fail pool create");
}


/**
 * Test TO_InitApp(), fail TO_Channel_InitAll
 */
void Test_TO_InitApp_Fail_ChannelInitAll(void)
{
    int32 result = CFE_SUCCESS;
    int32 expected = OS_SEM_FAILURE;
    
    /* Fail OS_MutSemCreate in TO_Channel_Init with OS_SEM_FAILURE 
     * i.e. the OS call failed. Needs to fail on the second call because
     * OS_MutSemCreate is called in TO_InitData() */
    Ut_OSAPI_SetReturnCode(UT_OSAPI_MUTSEMCREATE_INDEX, OS_SEM_FAILURE, 2);

    /* Execute the function being tested */
    result = TO_InitApp();

    /* Verify results */
    UtAssert_True (result == expected, "InitApp, fail channel init all");
}


/**
 * Test TO_InitApp(), fail TO_Custom_Init()
 */
void Test_TO_InitApp_Fail_CustomInit(void)
{
    int32 result = CFE_SUCCESS;
    int32 expected = -1;
    
    /* Set TO_Custom_Init to fail */
    TO_Custom_Test_Returns.TO_Custom_Init_Return = -1;
    
    /* Execute the function being tested */
    result = TO_InitApp();
    
    /* Verify results */
    UtAssert_True (result == expected, "InitApp, fail custom init all");
}


/**
 * Test TO_InitApp(), Nominal
 */
void Test_TO_InitApp_Nominal(void)
{
    /* Set a fail result for SB */
    int32 result = (CFE_SEVERITY_BITMASK & CFE_SEVERITY_ERROR)
                   | CFE_EXECUTIVE_SERVICE | CFE_ES_ERR_APP_REGISTER;
    int32 expected = CFE_SUCCESS;

    /* Execute the function being tested */
    result = TO_InitApp();

    /* Verify results */
    UtAssert_True (result == expected, "InitApp, nominal");
}


/**************************************************************************
 * Tests for TO_Cleanup()
 **************************************************************************/
/**
 * Test TO_Cleanup(), Nominal
 * NOTE: currently no way to fail TO_Cleanup 
 */
void Test_TO_Cleanup(void)
{
    /* Execute the function being tested */
    TO_Cleanup();
}


/**************************************************************************
 * Tests for TO_AppMain()
 **************************************************************************/
/**
 * Test TO_AppMain(), Fail RegisterApp
 */
void Test_TO_AppMain_Fail_RegisterApp(void)
{
    /* fail the register app */
    Ut_CFE_ES_SetReturnCode(UT_CFE_ES_REGISTERAPP_INDEX, CFE_ES_ERR_APP_REGISTER, 1);

    /* Execute the function being tested */
    TO_AppMain();
}


/**
 * Test TO_AppMain(), Fail InitApp
 */
void Test_TO_AppMain_Fail_InitApp(void)
{
    /* fail the register app */
    Ut_CFE_EVS_SetReturnCode(UT_CFE_EVS_REGISTER_INDEX, CFE_EVS_APP_NOT_REGISTERED, 1);

    /* Execute the function being tested */
    TO_AppMain();
}


/**
 * Test TO_AppMain(), Invalid Schedule Message
 */
void Test_TO_AppMain_InvalidSchMessage(void)
{
    /* The following will emulate behavior of receiving a SCH message to send HK */
    Ut_CFE_SB_SetReturnCode(UT_CFE_SB_RCVMSG_INDEX, CFE_SUCCESS, 1);
    Ut_CFE_SB_SetReturnCode(UT_CFE_SB_GETMSGID_INDEX, 0, 1);

    Ut_CFE_ES_SetReturnCode(UT_CFE_ES_RUNLOOP_INDEX, FALSE, 2);

    /* Execute the function being tested */
    TO_AppMain();

}


/**
 * Hook to support: TO_AppMain(), Nominal - SendHK
 */
int32 Test_TO_AppMain_Nominal_SendHK_SendMsgHook(CFE_SB_Msg_t *MsgPtr)
{
    /* TODO:  Test the contents of your HK message here. */

    hookCalledCount++;

    return CFE_SUCCESS;
}


/**
 * Test TO_AppMain(), Nominal - SendHK
 */
void Test_TO_AppMain_Nominal_SendHK(void)
{
    /* The following will emulate behavior of receiving a SCH message to WAKEUP */
    Ut_CFE_SB_SetReturnCode(UT_CFE_SB_RCVMSG_INDEX, CFE_SUCCESS, 1);
    Ut_CFE_SB_SetReturnCode(UT_CFE_SB_GETMSGID_INDEX, TO_SEND_HK_MID, 1);

    Ut_CFE_ES_SetReturnCode(UT_CFE_ES_RUNLOOP_INDEX, FALSE, 2);

    /* Used to verify HK was transmitted correctly. */
    hookCalledCount = 0;
    Ut_CFE_ES_SetFunctionHook(UT_CFE_SB_SENDMSG_INDEX, &Test_TO_AppMain_Nominal_SendHK_SendMsgHook);

    /* Execute the function being tested */
    TO_AppMain();

    /* Verify results */
    UtAssert_True (hookCalledCount == 1, "AppMain_Nominal_SendHK");

}


/**
 * Test TO_AppMain(), Nominal - Wakeup
 */
void Test_TO_AppMain_Nominal_Wakeup(void)
{
    /* The following will emulate behavior of receiving a SCH message to WAKEUP */
    Ut_CFE_SB_SetReturnCode(UT_CFE_SB_RCVMSG_INDEX, CFE_SUCCESS, 1);
    Ut_CFE_SB_SetReturnCode(UT_CFE_SB_GETMSGID_INDEX, TO_SEND_TLM_MID, 1);

    Ut_CFE_ES_SetReturnCode(UT_CFE_ES_RUNLOOP_INDEX, FALSE, 2);

    /* Execute the function being tested */
    TO_AppMain();

}


/**
 * Test TO_AppMain(), ProcessNewData - InvalidMsgID
 */
void Test_TO_AppMain_ProcessNewData_InvalidMsgID(void)
{
    TO_SendDiagCmd_t  InMsg;
    int32 CmdPipe;

    /* The following will emulate behavior of receiving a SCH message to WAKEUP,
       and gives it data to process. */
    CmdPipe = Ut_CFE_SB_CreatePipe("TO_CMD_PIPE");
    CFE_SB_InitMsg (&InMsg, 0x0000, sizeof(TO_SendDiagCmd_t), TRUE);
    Ut_CFE_SB_AddMsgToPipe(&InMsg, CmdPipe);

    Ut_CFE_SB_SetReturnCode(UT_CFE_SB_RCVMSG_INDEX, CFE_SUCCESS, 1);
    Ut_CFE_SB_SetReturnCode(UT_CFE_SB_GETMSGID_INDEX, TO_SEND_TLM_MID, 1);

    Ut_CFE_ES_SetReturnCode(UT_CFE_ES_RUNLOOP_INDEX, FALSE, 2);

    /* Execute the function being tested */
    TO_AppMain();

    /* Verify results */
    UtAssert_True(Ut_CFE_EVS_GetEventQueueDepth()==2,"Event Count = 2");
    UtAssert_EventSent(TO_MSGID_ERR_EID, CFE_EVS_ERROR, "", "Error Event Sent");
}


/**
 * Test TO_ProcessNewAppCmds(), Invalid Command Code
 */
void Test_TO_ProcessNewAppCmds_InvalidCommand(void)
{
	TO_NoArgCmd_t InSchMsg;
    TO_NoArgCmd_t InInvalidCmd;
    int32         DataPipe;
    int32         CmdPipe;

    /* The following will emulate behavior of receiving a SCH message to WAKEUP,
       and gives it a command to process. */
    DataPipe = Ut_CFE_SB_CreatePipe("TO_SCH_PIPE");
    CFE_SB_InitMsg (&InSchMsg, TO_SEND_TLM_MID, sizeof(InSchMsg), TRUE);
    Ut_CFE_SB_AddMsgToPipe(&InSchMsg, DataPipe);

    CmdPipe = Ut_CFE_SB_CreatePipe("TO_CMD_PIPE");
    CFE_SB_InitMsg ((CFE_SB_MsgPtr_t)&InInvalidCmd, TO_CMD_MID, sizeof(InInvalidCmd), TRUE);
    CFE_SB_SetCmdCode((CFE_SB_MsgPtr_t)&InInvalidCmd, 100);
    Ut_CFE_SB_AddMsgToPipe(&InInvalidCmd, CmdPipe);

    Ut_CFE_ES_SetReturnCode(UT_CFE_ES_RUNLOOP_INDEX, FALSE, 2);

    /* Execute the function being tested */
    TO_AppMain();

    /* Verify results */
    UtAssert_True(Ut_CFE_EVS_GetEventQueueDepth()==2,"Event Count = 2");
    UtAssert_EventSent(TO_MSGID_ERR_EID, CFE_EVS_ERROR, "", "Cmd with Invalid Cmd Code Sent");
}


/**
 * Test TO_ProcessNewAppCmds(), NOOP command, Invalid Size
 */
void Test_TO_ProcessNewAppCmds_Noop_InvalidSize(void)
{
	TO_NoArgCmd_t InSchMsg;
	TO_AddMessageFlowCmd_t InNoopCmd;
    int32         DataPipe;
    int32         CmdPipe;

    /* The following will emulate behavior of receiving a SCH message to WAKEUP,
       and gives it a command to process. */
    DataPipe = Ut_CFE_SB_CreatePipe("TO_SCH_PIPE");
    CFE_SB_InitMsg (&InSchMsg, TO_SEND_TLM_MID, sizeof(InSchMsg), TRUE);
    Ut_CFE_SB_AddMsgToPipe(&InSchMsg, DataPipe);

    CmdPipe = Ut_CFE_SB_CreatePipe("TO_CMD_PIPE");
    CFE_SB_InitMsg (&InNoopCmd, TO_CMD_MID, sizeof(InNoopCmd), TRUE);
    CFE_SB_SetCmdCode((CFE_SB_MsgPtr_t)&InNoopCmd, TO_NOOP_CC);
    Ut_CFE_SB_AddMsgToPipe(&InNoopCmd, CmdPipe);

    Ut_CFE_ES_SetReturnCode(UT_CFE_ES_RUNLOOP_INDEX, FALSE, 2);

    /* Execute the function being tested */
    TO_AppMain();

    /* Verify results */
    UtAssert_True(Ut_CFE_EVS_GetEventQueueDepth()==2,"Event Count = 2");
    UtAssert_EventSent(TO_MSGLEN_ERR_EID, CFE_EVS_ERROR, "", "NOOP Cmd Event Sent");
}


/**
 * Test TO_ProcessNewAppCmds(), NOOP command, Nominal
 */
void Test_TO_ProcessNewAppCmds_Noop_Nominal(void)
{
	TO_NoArgCmd_t InSchMsg;
    TO_NoArgCmd_t InNoopCmd;
    int32         DataPipe;
    int32         CmdPipe;

    /* The following will emulate behavior of receiving a SCH message to WAKEUP,
       and gives it a command to process. */
    DataPipe = Ut_CFE_SB_CreatePipe("TO_SCH_PIPE");
    CFE_SB_InitMsg (&InSchMsg, TO_SEND_TLM_MID, sizeof(InSchMsg), TRUE);
    Ut_CFE_SB_AddMsgToPipe(&InSchMsg, DataPipe);

    CmdPipe = Ut_CFE_SB_CreatePipe("TO_CMD_PIPE");
    CFE_SB_InitMsg (&InNoopCmd, TO_CMD_MID, sizeof(InNoopCmd), TRUE);
    CFE_SB_SetCmdCode((CFE_SB_MsgPtr_t)&InNoopCmd, TO_NOOP_CC);
    Ut_CFE_SB_AddMsgToPipe(&InNoopCmd, CmdPipe);

    Ut_CFE_ES_SetReturnCode(UT_CFE_ES_RUNLOOP_INDEX, FALSE, 2);

    /* Execute the function being tested */
    TO_AppMain();

    /* Verify results */
    UtAssert_True(Ut_CFE_EVS_GetEventQueueDepth()==2,"Event Count = 2");
    UtAssert_EventSent(TO_CMD_NOOP_EID, CFE_EVS_INFORMATION, "", "NOOP Cmd Event Sent");
}


/**
 * Test TO_ProcessNewAppCmds(), Reset command, Nominal
 */
void Test_TO_ProcessNewAppCmds_Reset_Nominal(void)
{
    TO_NoArgCmd_t InSchMsg;
    TO_NoArgCmd_t InResetCmd;
    int32         DataPipe;
    int32         CmdPipe;
    uint32        i = 0;
    uint32        j = 0;

    /* The following will emulate behavior of receiving a SCH message to WAKEUP,
       and gives it a command to process. */
    DataPipe = Ut_CFE_SB_CreatePipe("TO_SCH_PIPE");
    CFE_SB_InitMsg (&InSchMsg, TO_SEND_TLM_MID, sizeof(InSchMsg), TRUE);
    Ut_CFE_SB_AddMsgToPipe(&InSchMsg, DataPipe);

    CmdPipe = Ut_CFE_SB_CreatePipe("TO_CMD_PIPE");
    CFE_SB_InitMsg (&InResetCmd, TO_CMD_MID, sizeof(InResetCmd), TRUE);
    CFE_SB_SetCmdCode((CFE_SB_MsgPtr_t)&InResetCmd, TO_RESET_CC);
    Ut_CFE_SB_AddMsgToPipe(&InResetCmd, CmdPipe);

    Ut_CFE_ES_SetReturnCode(UT_CFE_ES_RUNLOOP_INDEX, FALSE, 2);

    /* Now give all the counters we're going to clear a value to ensure that
     * the reset command actually clears them.
     */
    TO_AppData.HkTlm.usCmdCnt = 1;
    TO_AppData.HkTlm.usCmdErrCnt = 2;
    TO_AppData.HkTlm.usTotalMsgDropped = 3;
    TO_AppData.HkTlm.PeakMemInUse = 4;
    
    for(i = 0; i < TO_MAX_CHANNELS; ++i)
    {
        for(j = 0; j < TO_MAX_MESSAGE_FLOWS; ++j)
        {
            TO_AppData.ChannelData[i].DumpTbl.MessageFlow[j].DroppedMsgCnt = 5;
            TO_AppData.ChannelData[i].DumpTbl.MessageFlow[j].QueuedMsgCnt = 6;
        }
    }
    
    for(i = 0; i < TO_MAX_CHANNELS; ++i)
    {
        for(j = 0; j < TO_MAX_PRIORITY_QUEUES; ++j)
        {
            TO_AppData.ChannelData[i].DumpTbl.PriorityQueue[j].DroppedMsgCnt = 7;
            TO_AppData.ChannelData[i].DumpTbl.PriorityQueue[j].QueuedMsgCnt = 8;
            TO_AppData.ChannelData[i].DumpTbl.PriorityQueue[j].HighwaterMark = 9;
        }
    }
    
    for(i=0; i < TO_MAX_CHANNELS; ++i)
    {
        TO_AppData.ChannelData[i].OutputQueue.SentCount = 10;
        TO_AppData.ChannelData[i].OutputQueue.HighwaterMark = 11;
    }

    /* Execute the function being tested */
    TO_AppMain();

    /* Verify results */
    UtAssert_True(Ut_CFE_EVS_GetEventQueueDepth()==2,"Event Count = 2");
    UtAssert_EventSent(TO_CMD_RESET_EID, CFE_EVS_INFORMATION, "", "RESET Cmd Event Sent");

    UtAssert_True(TO_AppData.HkTlm.usCmdCnt == 0, "TO_AppData.HkTlm.usCmdCnt == 0");
    UtAssert_True(TO_AppData.HkTlm.usCmdErrCnt == 0, "TO_AppData.HkTlm.usCmdErrCnt == 0");
    UtAssert_True(TO_AppData.HkTlm.usTotalMsgDropped == 0, "TO_AppData.HkTlm.usTotalMsgDropped == 0");
    UtAssert_True(TO_AppData.HkTlm.PeakMemInUse == 0, "TO_AppData.HkTlm.PeakMemInUse == 0");

    for(i = 0; i < TO_MAX_CHANNELS; ++i)
    {
        for(j = 0; j < TO_MAX_MESSAGE_FLOWS; ++j)
        {
            UtAssert_True(TO_AppData.ChannelData[i].DumpTbl.MessageFlow[j].DroppedMsgCnt == 0, 
                    "TO_AppData.ChannelData[i].DumpTbl.MessageFlow[j].DroppedMsgCnt == 0");
            UtAssert_True(TO_AppData.ChannelData[i].DumpTbl.MessageFlow[j].QueuedMsgCnt == 0, 
                    "TO_AppData.ChannelData[i].DumpTbl.MessageFlow[j].QueuedMsgCnt == 0");
        }
    }

    for(i = 0; i < TO_MAX_CHANNELS; ++i)
    {
        for(j = 0; j < TO_MAX_PRIORITY_QUEUES; ++j)
        {
            UtAssert_True(TO_AppData.ChannelData[i].DumpTbl.PriorityQueue[j].DroppedMsgCnt == 0, 
                    "TO_AppData.ChannelData[i].DumpTbl.PriorityQueue[j].DroppedMsgCnt == 0");
            UtAssert_True(TO_AppData.ChannelData[i].DumpTbl.PriorityQueue[j].QueuedMsgCnt == 0, 
                    "TO_AppData.ChannelData[i].DumpTbl.PriorityQueue[j].QueuedMsgCnt == 0");
            UtAssert_True(TO_AppData.ChannelData[i].DumpTbl.PriorityQueue[j].HighwaterMark == 0, 
                    "TO_AppData.ChannelData[i].DumpTbl.PriorityQueue[j].HighwaterMark == 0");
        }
    }

    for(i = 0; i < TO_MAX_CHANNELS; ++i)
    {
        UtAssert_True(TO_AppData.ChannelData[i].OutputQueue.SentCount == 0, 
                "TO_AppData.ChannelData[i].OutputQueue.SentCount == 0");
        UtAssert_True(TO_AppData.ChannelData[i].OutputQueue.HighwaterMark == 0, 
                "TO_AppData.ChannelData[i].OutputQueue.HighwaterMark == 0");
    }
}



/**
 * Test TO_ProcessNewAppCmds(), AddMessageFlow command, Nominal
 */
void Test_TO_ProcessNewAppCmds_AddMessageFlow_InvalidPQueueIdx(void)
{
	TO_NoArgCmd_t InSchMsg;
	TO_AddMessageFlowCmd_t InCmd;
    int32         DataPipe;
    int32         CmdPipe;

    CFE_SB_MsgId_t  MsgId = CFE_ES_HK_TLM_MID;
    uint16          MsgLimit = 1;
    uint16          PQueueIdx = TO_MAX_PRIORITY_QUEUES;

    /* The following will emulate behavior of receiving a SCH message to WAKEUP,
       and gives it a command to process. */
    DataPipe = Ut_CFE_SB_CreatePipe("TO_SCH_PIPE");
    CFE_SB_InitMsg (&InSchMsg, TO_SEND_TLM_MID, sizeof(InSchMsg), TRUE);
    Ut_CFE_SB_AddMsgToPipe(&InSchMsg, DataPipe);

    CmdPipe = Ut_CFE_SB_CreatePipe("TO_CMD_PIPE");
    CFE_SB_InitMsg (&InCmd, TO_CMD_MID, sizeof(InCmd), TRUE);
    CFE_SB_SetCmdCode((CFE_SB_MsgPtr_t)&InCmd, TO_ADD_MESSAGE_FLOW_CC);
    InCmd.MsgID = MsgId;
    InCmd.MsgLimit = MsgLimit;
    InCmd.PQueueIdx = PQueueIdx;
    Ut_CFE_SB_AddMsgToPipe(&InCmd, CmdPipe);

    Ut_CFE_ES_SetReturnCode(UT_CFE_ES_RUNLOOP_INDEX, FALSE, 2);
    
    /* Set function hook for TO_Custom_Init */
    TO_Custom_Test_Hooks.TO_Custom_Init_Use_Hook = TRUE;

    /* Execute the function being tested */
    TO_AppMain();

    /* Verify results */
    UtAssert_True(Ut_CFE_EVS_GetEventQueueDepth()==2,"Event Count = 2");
    UtAssert_EventSent(TO_CMD_ADD_MSG_FLOW_EID, CFE_EVS_ERROR, "", "Add Message Flow Cmd Event Sent");
}



/**
 * Test TO_ProcessNewAppCmds(), AddMessageFlow command, AlreadyDefined
 */
void Test_TO_ProcessNewAppCmds_AddMessageFlow_AlreadyDefined(void)
{
    TO_NoArgCmd_t           InSchMsg;
    TO_AddMessageFlowCmd_t  InCmd;
    int32                   DataPipe;
    int32                   CmdPipe;

    CFE_SB_MsgId_t  MsgId = CFE_ES_HK_TLM_MID;
    uint16          MsgLimit = 1;
    uint16          PQueueIdx = 2;

    /* The following will emulate behavior of receiving a SCH message to WAKEUP,
       and gives it a command to process. */
    DataPipe = Ut_CFE_SB_CreatePipe("TO_SCH_PIPE");
    CFE_SB_InitMsg (&InSchMsg, TO_SEND_TLM_MID, sizeof(InSchMsg), TRUE);
    Ut_CFE_SB_AddMsgToPipe(&InSchMsg, DataPipe);

    CmdPipe = Ut_CFE_SB_CreatePipe("TO_CMD_PIPE");
    CFE_SB_InitMsg (&InCmd, TO_CMD_MID, sizeof(InCmd), TRUE);
    CFE_SB_SetCmdCode((CFE_SB_MsgPtr_t)&InCmd, TO_ADD_MESSAGE_FLOW_CC);
    InCmd.MsgID = MsgId;
    InCmd.MsgLimit = MsgLimit;
    InCmd.PQueueIdx = PQueueIdx;
    Ut_CFE_SB_AddMsgToPipe(&InCmd, CmdPipe);

    Ut_CFE_ES_SetReturnCode(UT_CFE_ES_RUNLOOP_INDEX, FALSE, 2);
    
    /* Set function hook for TO_Custom_Init */
    TO_Custom_Test_Hooks.TO_Custom_Init_Use_Hook = TRUE;

    /* Execute the function being tested */
    TO_AppMain();

    /* Verify results */
    UtAssert_True(Ut_CFE_EVS_GetEventQueueDepth()==2,"Event Count = 2");
    UtAssert_EventSent(TO_CMD_ADD_MSG_FLOW_EID, CFE_EVS_ERROR, "", 
            "Add Message Flow Cmd Event Sent");
	UtAssert_True(TO_AppData.ChannelData[0].ConfigTblPtr->MessageFlow[0].MsgId == MsgId,
            "Add Message Flow Cmd set TO_AppData.ChannelData[0].DumpTbl.MessageFlow[0].MsgId");
	UtAssert_True(TO_AppData.ChannelData[0].ConfigTblPtr->MessageFlow[0].PQueueID == PQueueIdx, 
            "Add Message Flow Cmd set TO_AppData.ChannelData[0].DumpTbl.MessageFlow[0].PQueueID");
}



/**
 * Test TO_ProcessNewAppCmds(), AddMessageFlow command, Nominal
 */
void Test_TO_ProcessNewAppCmds_AddMessageFlow_Nominal(void)
{
    TO_NoArgCmd_t           InSchMsg;
    TO_AddMessageFlowCmd_t  InCmd;
    int32                   DataPipe;
    int32                   CmdPipe;

    CFE_SB_MsgId_t  MsgId = CFE_ES_HK_TLM_MID;
    uint16          MsgLimit = 1;
    uint16          PQueueIdx = 2;

    /* The following will emulate behavior of receiving a SCH message to WAKEUP,
       and gives it a command to process. */
    DataPipe = Ut_CFE_SB_CreatePipe("TO_SCH_PIPE");
    CFE_SB_InitMsg (&InSchMsg, TO_SEND_TLM_MID, sizeof(InSchMsg), TRUE);
    Ut_CFE_SB_AddMsgToPipe(&InSchMsg, DataPipe);

    CmdPipe = Ut_CFE_SB_CreatePipe("TO_CMD_PIPE");
    CFE_SB_InitMsg (&InCmd, TO_CMD_MID, sizeof(InCmd), TRUE);
    CFE_SB_SetCmdCode((CFE_SB_MsgPtr_t)&InCmd, TO_ADD_MESSAGE_FLOW_CC);
    InCmd.MsgID = MsgId;
    InCmd.MsgLimit = MsgLimit;
    InCmd.PQueueIdx = PQueueIdx;
    Ut_CFE_SB_AddMsgToPipe(&InCmd, CmdPipe);

    Ut_CFE_ES_SetReturnCode(UT_CFE_ES_RUNLOOP_INDEX, FALSE, 2);
    
    /* Set function hook for TO_Custom_Init */
    TO_Custom_Test_Hooks.TO_Custom_Init_Use_Hook = TRUE;

    /* Execute the function being tested */
    TO_AppMain();

    /* Verify results */
    UtAssert_True(Ut_CFE_EVS_GetEventQueueDepth()==2,"Event Count = 2");
    UtAssert_EventSent(TO_CMD_ADD_MSG_FLOW_EID, CFE_EVS_INFORMATION, "", "Add Message Flow Cmd Event Sent");
    UtAssert_True(TO_AppData.ChannelData[0].ConfigTblPtr->MessageFlow[0].MsgId == MsgId, 
            "Add Message Flow Cmd set TO_AppData.ChannelData[0].ConfigTblPtr->.MessageFlow[0].MsgId");
    UtAssert_True(TO_AppData.ChannelData[0].ConfigTblPtr->MessageFlow[0].MsgLimit == MsgLimit, 
            "Add Message Flow Cmd set TO_AppData.ChannelData[0].ConfigTblPtr->MessageFlow[0].MsgLimit");
    UtAssert_True(TO_AppData.ChannelData[0].ConfigTblPtr->MessageFlow[0].PQueueID == PQueueIdx, 
            "Add Message Flow Cmd set TO_AppData.ChannelData[0].ConfigTblPtr->MessageFlow[0].PQueueID");
}



/**
 * Test TO_ProcessNewAppCmds(), RemoveMessageFlow command, Nominal
 */
void Test_TO_ProcessNewAppCmds_RemoveMessageFlow_Nominal(void)
{
    TO_NoArgCmd_t               InSchMsg;
    TO_RemoveMessageFlowCmd_t   InCmd;
    int32                       DataPipe;
    int32                       CmdPipe;
    CFE_SB_MsgId_t  MsgId = CFE_ES_HK_TLM_MID;

    /* The following will emulate behavior of receiving a SCH message to WAKEUP,
       and gives it a command to process. */
    DataPipe = Ut_CFE_SB_CreatePipe("TO_SCH_PIPE");
    CFE_SB_InitMsg (&InSchMsg, TO_SEND_TLM_MID, sizeof(InSchMsg), TRUE);
    Ut_CFE_SB_AddMsgToPipe(&InSchMsg, DataPipe);

    CmdPipe = Ut_CFE_SB_CreatePipe("TO_CMD_PIPE");
    CFE_SB_InitMsg (&InCmd, TO_CMD_MID, sizeof(InCmd), TRUE);
    CFE_SB_SetCmdCode((CFE_SB_MsgPtr_t)&InCmd, TO_REMOVE_MESSAGE_FLOW_CC);
    InCmd.MsgID = MsgId;

    Ut_CFE_SB_AddMsgToPipe(&InCmd, CmdPipe);

    Ut_CFE_ES_SetReturnCode(UT_CFE_ES_RUNLOOP_INDEX, FALSE, 2);
    
    /* Set function hook for TO_Custom_Init */
    TO_Custom_Test_Hooks.TO_Custom_Init_Use_Hook = TRUE;

    /* Execute the function being tested */
    TO_AppMain();

    /* Verify results */
    UtAssert_True(Ut_CFE_EVS_GetEventQueueDepth()==2,"Event Count = 2");
    UtAssert_EventSent(TO_CMD_REMOVE_MSG_FLOW_EID, CFE_EVS_INFORMATION, "", 
            "Remove Message Flow Cmd Event Sent");
    UtAssert_True(TO_AppData.ChannelData[0].ConfigTblPtr->MessageFlow[0].MsgId == 0, 
            "Remove Message Flow Cmd clear TO_AppData.ChannelData[0].ConfigTblPtr->MessageFlow[0].MsgId");
}



/**
 * Test TO_ProcessNewAppCmds(), QueryMessageFlow command, Nominal
 */
void Test_TO_ProcessNewAppCmds_QueryMessageFlow_Nominal(void)
{
    TO_NoArgCmd_t               InSchMsg;
    TO_QueryMessageFlowCmd_t    InCmd;
    int32                       DataPipe;
    int32                       CmdPipe;
    CFE_SB_MsgId_t  MsgId = CFE_ES_HK_TLM_MID;

    char expEventText[100];

    /* The following will emulate behavior of receiving a SCH message to WAKEUP,
       and gives it a command to process. */
    DataPipe = Ut_CFE_SB_CreatePipe("TO_SCH_PIPE");
    CFE_SB_InitMsg (&InSchMsg, TO_SEND_TLM_MID, sizeof(InSchMsg), TRUE);
    Ut_CFE_SB_AddMsgToPipe(&InSchMsg, DataPipe);

    CmdPipe = Ut_CFE_SB_CreatePipe("TO_CMD_PIPE");
    CFE_SB_InitMsg (&InCmd, TO_CMD_MID, sizeof(InCmd), TRUE);
    CFE_SB_SetCmdCode((CFE_SB_MsgPtr_t)&InCmd, TO_QUERY_MESSAGE_FLOW_CC);
    InCmd.MsgID = MsgId;

    Ut_CFE_SB_AddMsgToPipe(&InCmd, CmdPipe);

    Ut_CFE_ES_SetReturnCode(UT_CFE_ES_RUNLOOP_INDEX, FALSE, 2);
    
    /* Set function hook for TO_Custom_Init */
    TO_Custom_Test_Hooks.TO_Custom_Init_Use_Hook = TRUE;

    /* Execute the function being tested */
    TO_AppMain();

    /* Verify results */
    UtAssert_True(Ut_CFE_EVS_GetEventQueueDepth()==2,"Event Count = 2");
    sprintf(expEventText, "MID=0x%04x ML=%u PQI=%u D=%u Q=%u",
            TO_AppData.ChannelData[0].ConfigTblPtr->MessageFlow[0].MsgId,
            TO_AppData.ChannelData[0].ConfigTblPtr->MessageFlow[0].MsgLimit,
            TO_AppData.ChannelData[0].ConfigTblPtr->MessageFlow[0].PQueueID,
            TO_AppData.ChannelData[0].DumpTbl.MessageFlow[0].DroppedMsgCnt,
            TO_AppData.ChannelData[0].DumpTbl.MessageFlow[0].QueuedMsgCnt);
    UtAssert_EventSent(TO_MSG_FLOW_INFO_EID, CFE_EVS_INFORMATION, expEventText, "Query Message Flow Cmd Event Sent");
}



/**
 * Test TO_ProcessNewAppCmds(), QueryPriorityQueue command, Nominal
 */
void Test_TO_ProcessNewAppCmds_QueryPriorityQueue_Nominal(void)
{
	TO_NoArgCmd_t InSchMsg;
	TO_QueryPriorityQueueCmd_t InCmd;
    int32         DataPipe;
    int32         CmdPipe;
    CFE_SB_MsgId_t  MsgId = CFE_ES_HK_TLM_MID;
    uint16			PQueueIdx = 2;
    char expEventText[100];

    /* The following will emulate behavior of receiving a SCH message to WAKEUP,
       and gives it a command to process. */
    DataPipe = Ut_CFE_SB_CreatePipe("TO_SCH_PIPE");
    CFE_SB_InitMsg (&InSchMsg, TO_SEND_TLM_MID, sizeof(InSchMsg), TRUE);
    Ut_CFE_SB_AddMsgToPipe(&InSchMsg, DataPipe);

    CmdPipe = Ut_CFE_SB_CreatePipe("TO_CMD_PIPE");
    CFE_SB_InitMsg (&InCmd, TO_CMD_MID, sizeof(InCmd), TRUE);
    CFE_SB_SetCmdCode((CFE_SB_MsgPtr_t)&InCmd, TO_QUERY_PRIORITY_QUEUE_CC);
    InCmd.PQueueIndex = PQueueIdx;
    Ut_CFE_SB_AddMsgToPipe(&InCmd, CmdPipe);

    Ut_CFE_ES_SetReturnCode(UT_CFE_ES_RUNLOOP_INDEX, FALSE, 2);
    
    /* Set function hook for TO_Custom_Init */
    TO_Custom_Test_Hooks.TO_Custom_Init_Use_Hook = TRUE;

    /* Execute the function being tested */
    TO_AppMain();

    /* Verify results */
    UtAssert_True(Ut_CFE_EVS_GetEventQueueDepth()==2,"Event Count = 2");
    sprintf(expEventText, "PQI=%u S=%u ML=%u QT=%u D=%u Q=%u CQ=%u HWM=%u",
    		PQueueIdx,
    		TO_AppData.ChannelData[0].ConfigTblPtr->PriorityQueue[PQueueIdx].State,
    		TO_AppData.ChannelData[0].ConfigTblPtr->PriorityQueue[PQueueIdx].MsgLimit,
    		TO_AppData.ChannelData[0].ConfigTblPtr->PriorityQueue[PQueueIdx].QType,
    		TO_AppData.ChannelData[0].DumpTbl.PriorityQueue[PQueueIdx].DroppedMsgCnt,
    		TO_AppData.ChannelData[0].DumpTbl.PriorityQueue[PQueueIdx].QueuedMsgCnt,
    		TO_AppData.ChannelData[0].DumpTbl.PriorityQueue[PQueueIdx].CurrentlyQueuedCnt,
    		TO_AppData.ChannelData[0].DumpTbl.PriorityQueue[PQueueIdx].HighwaterMark);
    UtAssert_EventSent(TO_PQUEUE_INFO_EID, CFE_EVS_INFORMATION, expEventText, "Query Priority Queue Cmd Event Sent");
}



/**
 * Test TO_ProcessNewAppCmds(), QueryChannelQueue command, Nominal
 */
void Test_TO_ProcessNewAppCmds_QueryChannelQueue_Nominal(void)
{
    TO_NoArgCmd_t               InSchMsg;
    TO_QueryOutputChannelCmd_t  InCmd;
    int32                       DataPipe;
    int32                       CmdPipe;
    uint16  ChannelIdx = 0;
    char expEventText[100];

    /* The following will emulate behavior of receiving a SCH message to WAKEUP,
       and gives it a command to process. */
    DataPipe = Ut_CFE_SB_CreatePipe("TO_SCH_PIPE");
    CFE_SB_InitMsg (&InSchMsg, TO_SEND_TLM_MID, sizeof(InSchMsg), TRUE);
    Ut_CFE_SB_AddMsgToPipe(&InSchMsg, DataPipe);

    CmdPipe = Ut_CFE_SB_CreatePipe("TO_CMD_PIPE");
    CFE_SB_InitMsg (&InCmd, TO_CMD_MID, sizeof(InCmd), TRUE);
    CFE_SB_SetCmdCode((CFE_SB_MsgPtr_t)&InCmd, TO_QUERY_OUTPUT_CHANNEL_CC);
    InCmd.ChannelIdx = ChannelIdx;
    Ut_CFE_SB_AddMsgToPipe(&InCmd, CmdPipe);

    Ut_CFE_ES_SetReturnCode(UT_CFE_ES_RUNLOOP_INDEX, FALSE, 2);
    
    /* Set function hook for TO_Custom_Init */
    TO_Custom_Test_Hooks.TO_Custom_Init_Use_Hook = TRUE;

    /* Execute the function being tested */
    TO_AppMain();

    /* Verify results */
    UtAssert_True(Ut_CFE_EVS_GetEventQueueDepth()==2,"Event Count = 2");
    sprintf(expEventText, "S=%u ML=%u SC=%u CQC=%u HWM=%u",
            TO_AppData.ChannelData[0].State,
            TO_OUTPUT_QUEUE_DEPTH,
            TO_AppData.ChannelData[0].OutputQueue.SentCount,
            TO_AppData.ChannelData[0].OutputQueue.CurrentlyQueuedCnt,
            TO_AppData.ChannelData[0].OutputQueue.HighwaterMark);

    UtAssert_EventSent(TO_OUT_CH_INFO_EID, CFE_EVS_INFORMATION, expEventText, 
            "Query Output Queue Cmd Event Sent");
}



/**
 * Test TO_ProcessNewAppCmds(), QueryChannelQueue command, Nominal
 */
void Test_TO_AppMain_ProcessTelemetry_PriorityPreemption1(void)
{
    TO_NoArgCmd_t InSchMsg;
    int32         SchPipe;
    int32         DataPipe;
    TO_HkTlm_t    msgCfeEsHk;
    TO_HkTlm_t    msgCfeEvsHk;
    TO_HkTlm_t    msgCfeSbHk;
    TO_HkTlm_t    msgCfeTblHk;
    TO_HkTlm_t    msgCfeTimeHk;
    TO_HkTlm_t    msgCfeTimeDiag;
    TO_HkTlm_t    msgCfeEvsEvent;
    TO_HkTlm_t    msgCfeSbStats;
    TO_HkTlm_t    msgCfeEsApp;
    TO_HkTlm_t    msgCfeTblReg;
    TO_HkTlm_t    msgCfeSbOneSub;
    TO_HkTlm_t    msgCfeEsShell;
    TO_HkTlm_t    msgCfeEsMemStats;
    TO_HkTlm_t    msgCfeHk;
    TO_HkTlm_t    msgCfTrans;
    TO_HkTlm_t    msgCfConfig;
    TO_HkTlm_t    msgCfSpaceToGndPdu;
    TO_HkTlm_t    msgCsHk;
    uint32        chQueue0;

    /* The following will emulate behavior of receiving a SCH message to WAKEUP,
       and processing a full pipe of telemetry messages. */
    SchPipe = Ut_CFE_SB_CreatePipe("TO_SCH_PIPE");
    CFE_SB_InitMsg (&InSchMsg, TO_SEND_TLM_MID, sizeof(InSchMsg), TRUE);
    Ut_CFE_SB_AddMsgToPipe(&InSchMsg, SchPipe);

    DataPipe = Ut_CFE_SB_CreatePipe("TO_GROUND");

    /* Initialize a bunch of telemetry messages for downlink. */
    CFE_SB_InitMsg (&msgCfeEsHk, CFE_ES_HK_TLM_MID, sizeof(msgCfeEsHk), TRUE);
    CFE_SB_InitMsg (&msgCfeEvsHk, CFE_EVS_HK_TLM_MID, sizeof(msgCfeEvsHk), TRUE);
    CFE_SB_InitMsg (&msgCfeSbHk, CFE_SB_HK_TLM_MID, sizeof(msgCfeSbHk), TRUE);
    CFE_SB_InitMsg (&msgCfeTblHk, CFE_TBL_HK_TLM_MID, sizeof(msgCfeTblHk), TRUE);
    CFE_SB_InitMsg (&msgCfeTimeHk, CFE_TIME_HK_TLM_MID, sizeof(msgCfeTimeHk), TRUE);
    CFE_SB_InitMsg (&msgCfeTimeDiag, CFE_TIME_DIAG_TLM_MID, sizeof(msgCfeTimeDiag), TRUE);
    CFE_SB_InitMsg (&msgCfeEvsEvent, CFE_EVS_EVENT_MSG_MID, sizeof(msgCfeEvsEvent), TRUE);
    CFE_SB_InitMsg (&msgCfeSbStats, CFE_SB_STATS_TLM_MID, sizeof(msgCfeSbStats), TRUE);
    CFE_SB_InitMsg (&msgCfeEsApp, CFE_ES_APP_TLM_MID, sizeof(msgCfeEsApp), TRUE);

    /* Now load up the software bus with all the messages starting with low
     * priority first. */
    Ut_CFE_SB_AddMsgToPipe(&msgCfeEvsEvent, DataPipe);
    Ut_CFE_SB_AddMsgToPipe(&msgCfeSbStats, DataPipe);
    Ut_CFE_SB_AddMsgToPipe(&msgCfeEsApp, DataPipe);
    Ut_CFE_SB_AddMsgToPipe(&msgCfeTblHk, DataPipe);
    Ut_CFE_SB_AddMsgToPipe(&msgCfeTimeHk, DataPipe);
    Ut_CFE_SB_AddMsgToPipe(&msgCfeTimeDiag, DataPipe);
    Ut_CFE_SB_AddMsgToPipe(&msgCfeEsHk, DataPipe);
    Ut_CFE_SB_AddMsgToPipe(&msgCfeEvsHk, DataPipe);
    Ut_CFE_SB_AddMsgToPipe(&msgCfeSbHk, DataPipe);

    /* Set return codes */
    Ut_CFE_ES_SetReturnCode(UT_CFE_ES_RUNLOOP_INDEX, FALSE, 2);
    
    /* Set function hook for TO_Custom_Init */
    TO_Custom_Test_Hooks.TO_Custom_Init_Use_Hook = TRUE;

    /* Set function hooks */
    Ut_OSAPI_SetFunctionHook(UT_OSAPI_QUEUECREATE_INDEX, &Ut_OSAPI_QueueCreateHook);
    Ut_OSAPI_SetFunctionHook(UT_OSAPI_QUEUEPUT_INDEX, &Ut_OSAPI_QueuePutHook);
    Ut_OSAPI_SetFunctionHook(UT_OSAPI_QUEUEGET_INDEX, &Ut_OSAPI_QueueGetHook);
    Ut_CFE_ES_SetFunctionHook(UT_CFE_ES_GETPOOLBUF_INDEX, &Ut_CFE_ES_GetPoolBuf);
    Ut_CFE_ES_SetFunctionHook(UT_CFE_ES_PUTPOOLBUF_INDEX, &Ut_CFE_ES_PutPoolBuf);

    /* Execute the function being tested */
    TO_AppMain();


    /* Verify results */
    Ut_OSAPI_QueueGetIdByName(&chQueue0, "TO_GROUND_OUT");
    CFE_SB_MsgPtr_t   msgPtr = 0;
    uint32 sizeCopied = 0;
    int32 iStatus = 0;

    Ut_OSAPI_QueueGetHook(chQueue0, &msgPtr, sizeof(msgPtr), &sizeCopied, OS_CHECK);
    UtAssert_True(Ut_CFE_SB_GetMsgIdHook(msgPtr) == CFE_ES_HK_TLM_MID, "1-1: High Priority");
    Ut_OSAPI_QueueGetHook(chQueue0, &msgPtr, sizeof(msgPtr), &sizeCopied, OS_CHECK);
    UtAssert_True(Ut_CFE_SB_GetMsgIdHook(msgPtr) == CFE_EVS_HK_TLM_MID, "1-2: High Priority");
    Ut_OSAPI_QueueGetHook(chQueue0, &msgPtr, sizeof(msgPtr), &sizeCopied, OS_CHECK);
    UtAssert_True(Ut_CFE_SB_GetMsgIdHook(msgPtr) == CFE_TBL_HK_TLM_MID, "1-3: Medium Priority");
    Ut_OSAPI_QueueGetHook(chQueue0, &msgPtr, sizeof(msgPtr), &sizeCopied, OS_CHECK);
    UtAssert_True(Ut_CFE_SB_GetMsgIdHook(msgPtr) == CFE_TIME_HK_TLM_MID, "1-4: Medium Priority");
    Ut_OSAPI_QueueGetHook(chQueue0, &msgPtr, sizeof(msgPtr), &sizeCopied, OS_CHECK);
    UtAssert_True(Ut_CFE_SB_GetMsgIdHook(msgPtr) == CFE_TIME_DIAG_TLM_MID, "1-5: Medium Priority");
    Ut_OSAPI_QueueGetHook(chQueue0, &msgPtr, sizeof(msgPtr), &sizeCopied, OS_CHECK);
    UtAssert_True(Ut_CFE_SB_GetMsgIdHook(msgPtr) == CFE_EVS_EVENT_MSG_MID, "1-6: Low Priority");
    Ut_OSAPI_QueueGetHook(chQueue0, &msgPtr, sizeof(msgPtr), &sizeCopied, OS_CHECK);
    UtAssert_True(Ut_CFE_SB_GetMsgIdHook(msgPtr) == CFE_SB_STATS_TLM_MID, "1-7: Low Priority");
    Ut_OSAPI_QueueGetHook(chQueue0, &msgPtr, sizeof(msgPtr), &sizeCopied, OS_CHECK);
    UtAssert_True(Ut_CFE_SB_GetMsgIdHook(msgPtr) == CFE_ES_APP_TLM_MID, "1-8: Low Priority");
    iStatus = Ut_OSAPI_QueueGetHook(chQueue0, &msgPtr, sizeof(msgPtr), &sizeCopied, OS_CHECK);
    UtAssert_True(iStatus == OS_QUEUE_EMPTY, "1-9: EMPTY");
}


/**
 * Test TO_ProcessNewAppCmds(), QueryChannelQueue command, Nominal
 */
void Test_TO_AppMain_ProcessTelemetry_PriorityPreemption2(void)
{
    TO_NoArgCmd_t InSchMsg;
    int32         SchPipe;
    int32         DataPipe;
    TO_HkTlm_t    msgCfeEsHk;
    TO_HkTlm_t    msgCfeEvsHk;
    TO_HkTlm_t    msgCfeSbHk;
    TO_HkTlm_t    msgCfeTblHk;
    TO_HkTlm_t    msgCfeTimeHk;
    TO_HkTlm_t    msgCfeTimeDiag;
    TO_HkTlm_t    msgCfeEvsEvent;
    TO_HkTlm_t    msgCfeSbStats;
    TO_HkTlm_t    msgCfeEsApp;
    TO_HkTlm_t    msgCfeTblReg;
    TO_HkTlm_t    msgCfeSbOneSub;
    TO_HkTlm_t    msgCfeEsShell;
    TO_HkTlm_t    msgCfeEsMemStats;
    TO_HkTlm_t    msgCfeHk;
    TO_HkTlm_t    msgCfTrans;
    TO_HkTlm_t    msgCfConfig;
    TO_HkTlm_t    msgCfSpaceToGndPdu;
    TO_HkTlm_t    msgCsHk;
    uint32        chQueue0;

    /* The following will emulate behavior of receiving a SCH message to WAKEUP,
       and processing a full pipe of telemetry messages. */
    SchPipe = Ut_CFE_SB_CreatePipe("TO_SCH_PIPE");
    CFE_SB_InitMsg (&InSchMsg, TO_SEND_TLM_MID, sizeof(InSchMsg), TRUE);
    Ut_CFE_SB_AddMsgToPipe(&InSchMsg, SchPipe);

    DataPipe = Ut_CFE_SB_CreatePipe("TO_GROUND");

    /* Initialize a bunch of telemetry messages for downlink. */
    CFE_SB_InitMsg (&msgCfeEsHk, CFE_ES_HK_TLM_MID, sizeof(msgCfeEsHk), TRUE);
    CFE_SB_InitMsg (&msgCfeEvsHk, CFE_EVS_HK_TLM_MID, sizeof(msgCfeEvsHk), TRUE);
    CFE_SB_InitMsg (&msgCfeSbHk, CFE_SB_HK_TLM_MID, sizeof(msgCfeSbHk), TRUE);
    CFE_SB_InitMsg (&msgCfeTblHk, CFE_TBL_HK_TLM_MID, sizeof(msgCfeTblHk), TRUE);
    CFE_SB_InitMsg (&msgCfeTimeHk, CFE_TIME_HK_TLM_MID, sizeof(msgCfeTimeHk), TRUE);
    CFE_SB_InitMsg (&msgCfeTimeDiag, CFE_TIME_DIAG_TLM_MID, sizeof(msgCfeTimeDiag), TRUE);
    CFE_SB_InitMsg (&msgCfeEvsEvent, CFE_EVS_EVENT_MSG_MID, sizeof(msgCfeEvsEvent), TRUE);
    CFE_SB_InitMsg (&msgCfeSbStats, CFE_SB_STATS_TLM_MID, sizeof(msgCfeSbStats), TRUE);
    CFE_SB_InitMsg (&msgCfeEsApp, CFE_ES_APP_TLM_MID, sizeof(msgCfeEsApp), TRUE);

    /* Now load up the software bus with all the messages starting with low
     * priority first. */
    Ut_CFE_SB_AddMsgToPipe(&msgCfeEvsEvent, DataPipe);
    Ut_CFE_SB_AddMsgToPipe(&msgCfeSbStats, DataPipe);
    Ut_CFE_SB_AddMsgToPipe(&msgCfeEsApp, DataPipe);
    Ut_CFE_SB_AddMsgToPipe(&msgCfeTblHk, DataPipe);
    Ut_CFE_SB_AddMsgToPipe(&msgCfeTimeHk, DataPipe);
    Ut_CFE_SB_AddMsgToPipe(&msgCfeTimeDiag, DataPipe);
    Ut_CFE_SB_AddMsgToPipe(&msgCfeEsHk, DataPipe);
    Ut_CFE_SB_AddMsgToPipe(&msgCfeEvsHk, DataPipe);
    Ut_CFE_SB_AddMsgToPipe(&msgCfeSbHk, DataPipe);

    /* Set return codes */
    Ut_CFE_ES_SetReturnCode(UT_CFE_ES_RUNLOOP_INDEX, FALSE, 2);
    
    /* Set function hook for TO_Custom_Init */
    TO_Custom_Test_Hooks.TO_Custom_Init_Use_Hook = TRUE;

    /* Set function hooks */
    Ut_OSAPI_SetFunctionHook(UT_OSAPI_QUEUECREATE_INDEX, &Ut_OSAPI_QueueCreateHook);
    Ut_OSAPI_SetFunctionHook(UT_OSAPI_QUEUEPUT_INDEX, &Ut_OSAPI_QueuePutHook);
    Ut_OSAPI_SetFunctionHook(UT_OSAPI_QUEUEGET_INDEX, &Ut_OSAPI_QueueGetHook);
    Ut_CFE_ES_SetFunctionHook(UT_CFE_ES_GETPOOLBUF_INDEX, &Ut_CFE_ES_GetPoolBuf);
    Ut_CFE_ES_SetFunctionHook(UT_CFE_ES_PUTPOOLBUF_INDEX, &Ut_CFE_ES_PutPoolBuf);

    /* Execute the function being tested */
    TO_AppMain();

    /* Verify results */
    Ut_OSAPI_QueueGetIdByName(&chQueue0, "TO_GROUND_OUT");
    CFE_SB_MsgPtr_t   msgPtr = 0;
    uint32 sizeCopied = 0;
    int32 iStatus = 0;

    Ut_OSAPI_QueueGetHook(chQueue0, &msgPtr, sizeof(msgPtr), &sizeCopied, OS_CHECK);
    UtAssert_True(Ut_CFE_SB_GetMsgIdHook(msgPtr) == CFE_ES_HK_TLM_MID, "1-1: High Priority");
    Ut_OSAPI_QueueGetHook(chQueue0, &msgPtr, sizeof(msgPtr), &sizeCopied, OS_CHECK);
    UtAssert_True(Ut_CFE_SB_GetMsgIdHook(msgPtr) == CFE_EVS_HK_TLM_MID, "1-2: High Priority");
    Ut_OSAPI_QueueGetHook(chQueue0, &msgPtr, sizeof(msgPtr), &sizeCopied, OS_CHECK);
    UtAssert_True(Ut_CFE_SB_GetMsgIdHook(msgPtr) == CFE_SB_HK_TLM_MID, "1-3: High Priority");
    Ut_OSAPI_QueueGetHook(chQueue0, &msgPtr, sizeof(msgPtr), &sizeCopied, OS_CHECK);
    UtAssert_True(Ut_CFE_SB_GetMsgIdHook(msgPtr) == CFE_TBL_HK_TLM_MID, "1-4: Medium Priority");
    Ut_OSAPI_QueueGetHook(chQueue0, &msgPtr, sizeof(msgPtr), &sizeCopied, OS_CHECK);
    UtAssert_True(Ut_CFE_SB_GetMsgIdHook(msgPtr) == CFE_TIME_HK_TLM_MID, "1-5: Medium Priority");
    Ut_OSAPI_QueueGetHook(chQueue0, &msgPtr, sizeof(msgPtr), &sizeCopied, OS_CHECK);
    UtAssert_True(Ut_CFE_SB_GetMsgIdHook(msgPtr) == CFE_TIME_DIAG_TLM_MID, "1-6: Medium Priority");
    Ut_OSAPI_QueueGetHook(chQueue0, &msgPtr, sizeof(msgPtr), &sizeCopied, OS_CHECK);
    UtAssert_True(Ut_CFE_SB_GetMsgIdHook(msgPtr) == CFE_EVS_EVENT_MSG_MID, "1-7: Low Priority");
    Ut_OSAPI_QueueGetHook(chQueue0, &msgPtr, sizeof(msgPtr), &sizeCopied, OS_CHECK);
    UtAssert_True(Ut_CFE_SB_GetMsgIdHook(msgPtr) == CFE_SB_STATS_TLM_MID, "1-8: Low Priority");
    iStatus = Ut_OSAPI_QueueGetHook(chQueue0, &msgPtr, sizeof(msgPtr), &sizeCopied, OS_CHECK);
    UtAssert_True(iStatus == OS_QUEUE_EMPTY, "1-9: EMPTY");
}


/**
 * Test TO_ProcessNewAppCmds(), QueryChannelQueue command, Nominal
 * Mixed up message input
 */
void Test_TO_AppMain_ProcessTelemetry_PriorityPreemption3(void)
{
    TO_NoArgCmd_t InSchMsg;
    int32         SchPipe;
    int32         DataPipe;
    TO_HkTlm_t    msgCfeEsHk;
    TO_HkTlm_t    msgCfeEvsHk;
    TO_HkTlm_t    msgCfeSbHk;
    TO_HkTlm_t    msgCfeTblHk;
    TO_HkTlm_t    msgCfeTimeHk;
    TO_HkTlm_t    msgCfeTimeDiag;
    TO_HkTlm_t    msgCfeEvsEvent;
    TO_HkTlm_t    msgCfeSbStats;
    TO_HkTlm_t    msgCfeEsApp;
    TO_HkTlm_t    msgCfeTblReg;
    TO_HkTlm_t    msgCfeSbOneSub;
    TO_HkTlm_t    msgCfeEsShell;
    TO_HkTlm_t    msgCfeEsMemStats;
    TO_HkTlm_t    msgCfeHk;
    TO_HkTlm_t    msgCfTrans;
    TO_HkTlm_t    msgCfConfig;
    TO_HkTlm_t    msgCfSpaceToGndPdu;
    TO_HkTlm_t    msgCsHk;
    uint32        chQueue0;

    /* The following will emulate behavior of receiving a SCH message to WAKEUP,
       and processing a full pipe of telemetry messages. */
    SchPipe = Ut_CFE_SB_CreatePipe("TO_SCH_PIPE");
    CFE_SB_InitMsg (&InSchMsg, TO_SEND_TLM_MID, sizeof(InSchMsg), TRUE);
    Ut_CFE_SB_AddMsgToPipe(&InSchMsg, SchPipe);

    DataPipe = Ut_CFE_SB_CreatePipe("TO_GROUND");

    /* Initialize a bunch of telemetry messages for downlink. */
    CFE_SB_InitMsg (&msgCfeEsHk, CFE_ES_HK_TLM_MID, sizeof(msgCfeEsHk), TRUE);
    CFE_SB_InitMsg (&msgCfeEvsHk, CFE_EVS_HK_TLM_MID, sizeof(msgCfeEvsHk), TRUE);
    CFE_SB_InitMsg (&msgCfeSbHk, CFE_SB_HK_TLM_MID, sizeof(msgCfeSbHk), TRUE);
    CFE_SB_InitMsg (&msgCfeTblHk, CFE_TBL_HK_TLM_MID, sizeof(msgCfeTblHk), TRUE);
    CFE_SB_InitMsg (&msgCfeTimeHk, CFE_TIME_HK_TLM_MID, sizeof(msgCfeTimeHk), TRUE);
    CFE_SB_InitMsg (&msgCfeTimeDiag, CFE_TIME_DIAG_TLM_MID, sizeof(msgCfeTimeDiag), TRUE);
    CFE_SB_InitMsg (&msgCfeEvsEvent, CFE_EVS_EVENT_MSG_MID, sizeof(msgCfeEvsEvent), TRUE);
    CFE_SB_InitMsg (&msgCfeSbStats, CFE_SB_STATS_TLM_MID, sizeof(msgCfeSbStats), TRUE);
    CFE_SB_InitMsg (&msgCfeEsApp, CFE_ES_APP_TLM_MID, sizeof(msgCfeEsApp), TRUE);

    /* Now load up the software bus with all the messages in random 
     * order. */

    /* High priority */
    Ut_CFE_SB_AddMsgToPipe(&msgCfeEsHk, DataPipe);
    Ut_CFE_SB_AddMsgToPipe(&msgCfeEvsHk, DataPipe);
    Ut_CFE_SB_AddMsgToPipe(&msgCfeSbHk, DataPipe);
    /* Low priority */
    Ut_CFE_SB_AddMsgToPipe(&msgCfeEvsEvent, DataPipe);
    Ut_CFE_SB_AddMsgToPipe(&msgCfeSbStats, DataPipe);
    Ut_CFE_SB_AddMsgToPipe(&msgCfeEsApp, DataPipe);
    /* Medium priority */
    Ut_CFE_SB_AddMsgToPipe(&msgCfeTblHk, DataPipe);
    Ut_CFE_SB_AddMsgToPipe(&msgCfeTimeHk, DataPipe);
    Ut_CFE_SB_AddMsgToPipe(&msgCfeTimeDiag, DataPipe);

    /* Set return codes */
    Ut_CFE_ES_SetReturnCode(UT_CFE_ES_RUNLOOP_INDEX, FALSE, 2);
    
    /* Set function hook for TO_Custom_Init */
    TO_Custom_Test_Hooks.TO_Custom_Init_Use_Hook = TRUE;

    /* Set function hooks */
    Ut_OSAPI_SetFunctionHook(UT_OSAPI_QUEUECREATE_INDEX, &Ut_OSAPI_QueueCreateHook);
    Ut_OSAPI_SetFunctionHook(UT_OSAPI_QUEUEPUT_INDEX, &Ut_OSAPI_QueuePutHook);
    Ut_OSAPI_SetFunctionHook(UT_OSAPI_QUEUEGET_INDEX, &Ut_OSAPI_QueueGetHook);
    Ut_CFE_ES_SetFunctionHook(UT_CFE_ES_GETPOOLBUF_INDEX, &Ut_CFE_ES_GetPoolBuf);
    Ut_CFE_ES_SetFunctionHook(UT_CFE_ES_PUTPOOLBUF_INDEX, &Ut_CFE_ES_PutPoolBuf);

    /* Execute the function being tested */
    TO_AppMain();

    /* Verify results */
    Ut_OSAPI_QueueGetIdByName(&chQueue0, "TO_GROUND_OUT");
    CFE_SB_MsgPtr_t   msgPtr = 0;
    uint32 sizeCopied = 0;
    int32 iStatus = 0;

    Ut_OSAPI_QueueGetHook(chQueue0, &msgPtr, sizeof(msgPtr), &sizeCopied, OS_CHECK);
    UtAssert_True(Ut_CFE_SB_GetMsgIdHook(msgPtr) == CFE_ES_HK_TLM_MID, "1-1: High Priority");
    Ut_OSAPI_QueueGetHook(chQueue0, &msgPtr, sizeof(msgPtr), &sizeCopied, OS_CHECK);
    UtAssert_True(Ut_CFE_SB_GetMsgIdHook(msgPtr) == CFE_EVS_HK_TLM_MID, "1-2: High Priority");
    Ut_OSAPI_QueueGetHook(chQueue0, &msgPtr, sizeof(msgPtr), &sizeCopied, OS_CHECK);
    UtAssert_True(Ut_CFE_SB_GetMsgIdHook(msgPtr) == CFE_SB_HK_TLM_MID, "1-3: High Priority");
    Ut_OSAPI_QueueGetHook(chQueue0, &msgPtr, sizeof(msgPtr), &sizeCopied, OS_CHECK);
    UtAssert_True(Ut_CFE_SB_GetMsgIdHook(msgPtr) == CFE_TBL_HK_TLM_MID, "1-4: Medium Priority");
    Ut_OSAPI_QueueGetHook(chQueue0, &msgPtr, sizeof(msgPtr), &sizeCopied, OS_CHECK);
    UtAssert_True(Ut_CFE_SB_GetMsgIdHook(msgPtr) == CFE_TIME_HK_TLM_MID, "1-5: Medium Priority");
    Ut_OSAPI_QueueGetHook(chQueue0, &msgPtr, sizeof(msgPtr), &sizeCopied, OS_CHECK);
    UtAssert_True(Ut_CFE_SB_GetMsgIdHook(msgPtr) == CFE_TIME_DIAG_TLM_MID, "1-6: Medium Priority");
    Ut_OSAPI_QueueGetHook(chQueue0, &msgPtr, sizeof(msgPtr), &sizeCopied, OS_CHECK);
    UtAssert_True(Ut_CFE_SB_GetMsgIdHook(msgPtr) == CFE_EVS_EVENT_MSG_MID, "1-7: Low Priority");
    Ut_OSAPI_QueueGetHook(chQueue0, &msgPtr, sizeof(msgPtr), &sizeCopied, OS_CHECK);
    UtAssert_True(Ut_CFE_SB_GetMsgIdHook(msgPtr) == CFE_SB_STATS_TLM_MID, "1-8: Low Priority");
    iStatus = Ut_OSAPI_QueueGetHook(chQueue0, &msgPtr, sizeof(msgPtr), &sizeCopied, OS_CHECK);
    UtAssert_True(iStatus == OS_QUEUE_EMPTY, "1-9: EMPTY");
}



/**************************************************************************
 * Rollup Test Cases
 **************************************************************************/
void TO_App_Test_AddTestCases(void)
{
    /* Test for TO_InitEvent() */
    UtTest_Add(Test_TO_InitEvent_Fail_Register, TO_Test_Setup_NoConfig, TO_Test_TearDown,
               "Test_TO_InitEvent_Fail_Register");

    /* Test for TO_InitPipe() */
    UtTest_Add(Test_TO_InitPipe_Fail_CreateSCHPipe, TO_Test_Setup_NoConfig, TO_Test_TearDown,
               "Test_TO_InitPipe_Fail_CreateSCHPipe");
    UtTest_Add(Test_TO_InitPipe_Fail_SubscribeWakeup, TO_Test_Setup_NoConfig, TO_Test_TearDown,
               "Test_TO_InitPipe_Fail_SubscribeWakeup");
    UtTest_Add(Test_TO_InitPipe_Fail_SubscribeSendHK, TO_Test_Setup_NoConfig, TO_Test_TearDown,
               "Test_TO_InitPipe_Fail_SubscribeSendHK");
    UtTest_Add(Test_TO_InitPipe_Fail_CreateCMDPipe, TO_Test_Setup_NoConfig, TO_Test_TearDown,
               "Test_TO_InitPipe_Fail_CreateCMDPipe");
    UtTest_Add(Test_TO_InitPipe_Fail_SubscribeCMD, TO_Test_Setup_NoConfig, TO_Test_TearDown,
               "Test_TO_InitPipe_Fail_SubscribeCMD");

    /* Tests for TO_InitData() */
    UtTest_Add(Test_TO_InitData, TO_Test_Setup_NoConfig, TO_Test_TearDown,
               "Test_TO_InitData");

    /* Tests for TO_InitApp() */
    UtTest_Add(Test_TO_InitApp_Fail_InitEvent, TO_Test_Setup_NoConfig, TO_Test_TearDown,
               "Test_TO_InitApp_Fail_InitEvent");
    UtTest_Add(Test_TO_InitApp_Fail_InitPipe, TO_Test_Setup_NoConfig, TO_Test_TearDown,
               "Test_TO_InitApp_Fail_InitPipe");
    UtTest_Add(Test_TO_InitApp_Fail_InitData, TO_Test_Setup_NoConfig, TO_Test_TearDown,
               "Test_TO_InitApp_Fail_InitData");
    UtTest_Add(Test_TO_InitApp_Fail_PoolCreateEx, TO_Test_Setup_NoConfig, TO_Test_TearDown,
               "Test_TO_InitApp_Fail_PoolCreateEx");
    UtTest_Add(Test_TO_InitApp_Fail_ChannelInitAll, TO_Test_Setup_NoConfig, TO_Test_TearDown,
               "Test_TO_InitApp_Fail_ChannelInitAll");
    UtTest_Add(Test_TO_InitApp_Fail_CustomInit, TO_Test_Setup_NoConfig, TO_Test_TearDown,
               "Test_TO_InitApp_Fail_CustomInit");
    UtTest_Add(Test_TO_InitApp_Nominal, TO_Test_Setup_NoConfig, TO_Test_TearDown,
               "Test_TO_InitApp_Nominal");

    /* Test for TO_Cleanup() */
    UtTest_Add(Test_TO_Cleanup, TO_Test_Setup_NoConfig, TO_Test_TearDown,
               "Test_TO_Cleanup");

    /* Test for AppMain() */
    UtTest_Add(Test_TO_AppMain_Fail_RegisterApp, TO_Test_Setup_NoConfig, TO_Test_TearDown,
               "Test_TO_AppMain_Fail_RegisterApp");
    UtTest_Add(Test_TO_AppMain_Fail_InitApp, TO_Test_Setup_NoConfig, TO_Test_TearDown,
               "Test_TO_AppMain_Fail_InitApp");
    UtTest_Add(Test_TO_AppMain_InvalidSchMessage, TO_Test_Setup_NoConfig, TO_Test_TearDown,
               "Test_TO_AppMain_InvalidSchMessage");
    UtTest_Add(Test_TO_AppMain_Nominal_SendHK, TO_Test_Setup_NoConfig, TO_Test_TearDown,
               "Test_TO_AppMain_Nominal_SendHK");
    UtTest_Add(Test_TO_AppMain_Nominal_Wakeup, TO_Test_Setup_NoConfig, TO_Test_TearDown,
               "Test_TO_AppMain_Nominal_Wakeup");
    UtTest_Add(Test_TO_AppMain_ProcessNewData_InvalidMsgID, TO_Test_Setup_NoConfig, TO_Test_TearDown,
               "Test_TO_AppMain_ProcessNewData_InvalidMsgID");

    /* Test for Commands */
    UtTest_Add(Test_TO_ProcessNewAppCmds_InvalidCommand, TO_Test_Setup_NoConfig, TO_Test_TearDown,
               "Test_TO_ProcessNewAppCmds_InvalidCommand");
    UtTest_Add(Test_TO_ProcessNewAppCmds_Noop_InvalidSize, TO_Test_Setup_NoConfig, TO_Test_TearDown,
               "Test_TO_ProcessNewAppCmds_Noop_InvalidSize");
    UtTest_Add(Test_TO_ProcessNewAppCmds_Noop_Nominal, TO_Test_Setup_NoConfig, TO_Test_TearDown,
               "Test_TO_ProcessNewAppCmds_Noop_Nominal");
    UtTest_Add(Test_TO_ProcessNewAppCmds_Reset_Nominal, TO_Test_Setup_EmptyConfig, TO_Test_TearDown,
               "Test_TO_ProcessNewAppCmds_Reset_Nominal");
    UtTest_Add(Test_TO_ProcessNewAppCmds_AddMessageFlow_InvalidPQueueIdx, TO_Test_Setup_EmptyConfig, TO_Test_TearDown,
               "Test_TO_ProcessNewAppCmds_AddMessageFlow_InvalidPQueueIdx");
    UtTest_Add(Test_TO_ProcessNewAppCmds_AddMessageFlow_AlreadyDefined, TO_Test_Setup_FullConfig1, TO_Test_TearDown,
               "Test_TO_ProcessNewAppCmds_AddMessageFlow_AlreadyDefined");
    UtTest_Add(Test_TO_ProcessNewAppCmds_AddMessageFlow_Nominal, TO_Test_Setup_EmptyConfig, TO_Test_TearDown,
               "Test_TO_ProcessNewAppCmds_AddMessageFlow_Nominal");
    UtTest_Add(Test_TO_ProcessNewAppCmds_RemoveMessageFlow_Nominal, TO_Test_Setup_FullConfig1, TO_Test_TearDown,
               "Test_TO_ProcessNewAppCmds_RemoveMessageFlow_Nominal");
    UtTest_Add(Test_TO_ProcessNewAppCmds_QueryMessageFlow_Nominal, TO_Test_Setup_FullConfig1, TO_Test_TearDown,
               "Test_TO_ProcessNewAppCmds_QueryMessageFlow_Nominal");
    UtTest_Add(Test_TO_ProcessNewAppCmds_QueryPriorityQueue_Nominal, TO_Test_Setup_FullConfig1, TO_Test_TearDown,
               "Test_TO_ProcessNewAppCmds_QueryPriorityQueue_Nominal");
    UtTest_Add(Test_TO_ProcessNewAppCmds_QueryChannelQueue_Nominal, TO_Test_Setup_FullConfig1, TO_Test_TearDown,
               "Test_TO_ProcessNewAppCmds_QueryChannelQueue_Nominal");

    /* Traffic shaping algorithm */
    UtTest_Add(Test_TO_AppMain_ProcessTelemetry_PriorityPreemption1, TO_Test_Setup_FullConfig1, TO_Test_TearDown,
               "Test_TO_AppMain_ProcessTelemetry_PriorityPreemption1");
    UtTest_Add(Test_TO_AppMain_ProcessTelemetry_PriorityPreemption2, TO_Test_Setup_FullConfig2, TO_Test_TearDown,
               "Test_TO_AppMain_ProcessTelemetry_PriorityPreemption2");
        UtTest_Add(Test_TO_AppMain_ProcessTelemetry_PriorityPreemption3, TO_Test_Setup_FullConfig2, TO_Test_TearDown,
               "Test_TO_AppMain_ProcessTelemetry_PriorityPreemption3");
}


