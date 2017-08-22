    
#ifndef TO_PLATFORM_CFG_H
#define TO_PLATFORM_CFG_H

#ifdef __cplusplus
extern "C" {
#endif

#include "cfe_platform_cfg.h"

/*
** to Platform Configuration Parameter Definitions
*/

/** \brief Mission specific version number for TO application
**  
**  \par Description:
**       An application version number consists of four parts:
**       major version number, minor version number, revision
**       number and mission specific revision number. The mission
**       specific revision number is defined here and the other
**       parts are defined in "to_version.h".
**
**  \par Limits:
**       Must be defined as a numeric value that is greater than
**       or equal to zero.
*/
#define TO_MISSION_REV                (0)

/** \brief Pipe depth for the Scheduler pipe 
**
**  \par Limits:
**       minimum of 1, max of CFE_SB_MAX_PIPE_DEPTH.
*/
#define TO_SCH_PIPE_DEPTH             (2)

/** \brief Pipe name for the Scheduler pipe 
**
**  \par Limits:
**       Note, this name must fit in OS_MAX_API_NAME.
*/
#define TO_SCH_PIPE_NAME              ("TO_SCH_PIPE")

/** \brief The SB pend behavior type for the Scheduler pipe.
**
**  \par Limits:
**       One of: CFE_SB_POLL, CFE_SB_PEND_FOREVER, or the 
**       number of milliseconds to wait for a new message (recommended).
**       Note, using CFE_SB_PEND_FOREVER may cause an unresponsive
**       application if no messages arrive on this pipe.
*/
#define TO_SCH_PIPE_PEND_TIME         (2000)

/** \brief The number of WAKEUP messages to reserve on the Scheduler pipe.
**
**  \par Limits:
**       minimum of 1, max limited to CFE_SB_MAX_PIPE_DEPTH-1.  Note the
**       TO_SCH_PIPE_WAKEUP_RESERVED and TO_SCH_PIPE_SEND_HK_RESERVED
**       must be less than TO_SCH_PIPE_DEPTH.
*/
#define TO_SCH_PIPE_WAKEUP_RESERVED   (1)

/** \brief The number of SEND_HK messages to reserve on the Scheduler pipe.
**
**  \par Limits:
**       minimum of 1, max of CFE_SB_MAX_PIPE_DEPTH.  Note the
**       TO_SCH_PIPE_WAKEUP_RESERVED and TO_SCH_PIPE_SEND_HK_RESERVED
**       must be less than TO_SCH_PIPE_DEPTH.
*/
#define TO_SCH_PIPE_SEND_HK_RESERVED  (1)

/** \brief Pipe depth for the command pipe
**
**  \par Limits:
**       minimum of 1, max of CFE_SB_MAX_PIPE_DEPTH.
*/
#define TO_CMD_PIPE_DEPTH             (4)

/** \brief Pipe name for the Scheduler pipe 
**
**  \par Limits:
**       Note, this name must fit in OS_MAX_API_NAME.
*/
#define TO_CMD_PIPE_NAME              ("TO_CMD_PIPE")

/** \brief Pipe depth for the data pipe 
**
**  \par Limits:
**       minimum of 1, max of CFE_SB_MAX_PIPE_DEPTH.
*/
#define TO_DATA_PIPE_DEPTH            (CFE_SB_MAX_PIPE_DEPTH)

/** \brief The config table default filename
**
**  \par Limits:
**       The length of each string, including the NULL terminator cannot exceed
**       the #OS_MAX_PATH_LEN value.
*/
#define TO_GROUND_CONFIG_TABLE_FILENAME      ("/cf/apps/to_ground.tbl")
#define TO_ONBOARD_CONFIG_TABLE_FILENAME     ("/cf/apps/to_onboard.tbl")

/**
 * \brief Defines the table identification name used for table registration.
 */
#define TO_GROUND_CONFIG_TABLENAME        ("GROUND_CFG")
#define TO_GROUND_DUMP_TABLENAME          ("GROUND_DMP")
#define TO_ONBOARD_CONFIG_TABLENAME       ("ONBOARD_CFG")
#define TO_ONBOARD_DUMP_TABLENAME         ("ONBOARD_DMP")

/** \brief The timeout value, in milliseconds, to wait for ES application startup sync.
**
**  \par Limits:
**       This parameter must be at least 1000 (ms).
*/
#define TO_STARTUP_TIMEOUT_MSEC    (1000)

/**
**  \tocfg Number of bytes in the Message Memory Pool
**
**  \par Description:
**       The message memory pool contains the memory needed for the queued messages packets.
**       The queued messages are dynamically allocated from this pool when the
**       messages are received and queued, and deallocated when messages are transmitted
**       or a new table is loaded.
**
**  \par Limits
**       The Telemetry Output app does not place a limit on this parameter, but there is
**       an overhead cost in the memory pool.  The value must be larger than what is
**       needed.
*/
#define TO_NUM_BYTES_IN_MEM_POOL        (20 * 1024)

/* TODO:  Add more platform configuration parameter definitions here, if necessary. */
#define TO_MAX_MSGS_OUT_PER_FRAME (100)
#define TO_MAX_CHANNELS			  (5)
#define TO_OUTPUT_QUEUE_DEPTH     (100)



#ifdef __cplusplus
}
#endif

#endif /* TO_PLATFORM_CFG_H */

/************************/
/*  End of File Comment */
/************************/
    
