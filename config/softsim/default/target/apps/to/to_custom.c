
/************************************************************************
** Pragmas
*************************************************************************/

/************************************************************************
** Includes
*************************************************************************/

#include "to_custom_udp.h"
#include "to_platform_cfg.h"
#include <fcntl.h>
#include <errno.h>
#include "to_events.h"
#include <strings.h>
#include <string.h>
#include <unistd.h>

/************************************************************************
** Local Defines
*************************************************************************/

/************************************************************************
** Local Structure Declarations
*************************************************************************/

/************************************************************************
** External Global Variables
*************************************************************************/

/************************************************************************
** Global Variables
*************************************************************************/

/************************************************************************
** Local Variables
*************************************************************************/

/************************************************************************
** Local Function Definitions
*************************************************************************/



TO_AppCustomData_t TO_AppCustomData;



uint8 TO_OutputChannel_Status(uint32 index)
{
    return TO_AppCustomData.Channel[index].Mode;
}



/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* Custom Initialize All.  Nothing to do here.                     */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int32 TO_Custom_Init(void)
{
    int32 iStatus = 0;
    uint32 i = 0;

    TO_AppCustomData.Channel[0].Mode = TO_CHANNEL_ENABLED;
    strcpy(TO_AppCustomData.Channel[0].IP, "127.0.0.1");
    TO_AppCustomData.Channel[0].DstPort = 5011;
    TO_AppCustomData.Channel[0].Priority = 50;
    TO_AppCustomData.Channel[0].ListenerTask = TO_OutputChannel_GroundChannelTask;

    TO_AppCustomData.Channel[1].Mode = TO_CHANNEL_ENABLED;
    strcpy(TO_AppCustomData.Channel[1].IP, "127.0.0.1");
    TO_AppCustomData.Channel[1].DstPort = 5012;
    TO_AppCustomData.Channel[1].Priority = 50;
    TO_AppCustomData.Channel[1].ListenerTask = TO_OutputChannel_OnboardChannelTask;

    iStatus = TO_Channel_OpenChannel(0, "GROUND", TO_GROUND_CONFIG_TABLENAME, TO_GROUND_CONFIG_TABLE_FILENAME, TO_GROUND_DUMP_TABLENAME);
    if(iStatus != 0)
    {
        goto end_of_function;
    }

    iStatus = TO_Channel_OpenChannel(1, "ONBOARD", TO_ONBOARD_CONFIG_TABLENAME, TO_ONBOARD_CONFIG_TABLE_FILENAME, TO_ONBOARD_DUMP_TABLENAME);

    for (i=0; i < TO_MAX_CHANNELS; i++)
    {
        if(TO_AppCustomData.Channel[i].Mode == TO_CHANNEL_ENABLED)
        {
            if(TO_OutputChannel_Enable(i, TO_AppCustomData.Channel[i].IP, TO_AppCustomData.Channel[i].DstPort))
            {
                TO_AppCustomData.Channel[i].Mode = TO_CHANNEL_DISABLED;
            }
            else
            {
                CFE_EVS_SendEvent(TO_TLMOUTENA_INF_EID, CFE_EVS_INFORMATION,
                        "UDP telemetry output enabled channel %u to %s:%u",
                        (unsigned int)i, TO_AppCustomData.Channel[i].IP,
                        (unsigned int)TO_AppCustomData.Channel[i].DstPort);
            }
        }
    }

end_of_function:

    return iStatus;
}



/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* Custom Send.  Send the message out the socket.                  */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int32 TO_OutputChannel_Send(uint32 ChannelID, const char* Buffer, uint32 Size)
{
    static struct sockaddr_in s_addr;
    int                       status = 0;
    int32                     returnCode = 0;

    bzero((char *) &s_addr, sizeof(s_addr));
    s_addr.sin_family      = AF_INET;

    if(ChannelID < TO_MAX_CHANNELS)
    {
        TO_TlmChannels_t *channel = &TO_AppCustomData.Channel[ChannelID];

        if(channel->Mode == TO_CHANNEL_ENABLED)
        {
            CFE_ES_PerfLogEntry(TO_SOCKET_SEND_PERF_ID);
            /* Send message via UDP socket */
            s_addr.sin_addr.s_addr = inet_addr(channel->IP);
            s_addr.sin_port        = htons(channel->DstPort);
            status = sendto(channel->Socket, (char *)Buffer, Size, 0,
                                    (struct sockaddr *) &s_addr,
                                     sizeof(s_addr));
            if (status < 0)
            {
                CFE_EVS_SendEvent(TO_TLMOUTSTOP_ERR_EID,CFE_EVS_ERROR,
                            "L%d TO sendto errno %d.", __LINE__, errno);
                    channel->Mode = TO_CHANNEL_DISABLED;
                returnCode = -1;
            }
            CFE_ES_PerfLogExit(TO_SOCKET_SEND_PERF_ID);
        }
    }

    return returnCode;
}



/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* Custom Cleanup All.  Disable all the enable channels so we      */
/* don't try sending messages when the sealed framework is torn    */
/* down.                                                           */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void TO_OutputChannel_CustomCleanupAll()
{
	int32 iStatus = 0;
	uint32 i = 0;

    for (i=0; i < TO_MAX_CHANNELS; i++)
    {
		if(TO_AppCustomData.Channel[i].Mode == TO_CHANNEL_ENABLED)
		{
			uint32 taskID = TO_AppCustomData.Channel[i].ChildTaskID;

			TO_OutputChannel_Disable(i);

			OS_TaskDelay(100);
		}
    }
}



/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* Custom Buildup All.  Enable all the 'enabled' channels.  If it  */
/* fails, disable it.                                              */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int32 TO_OutputChannel_CustomBuildupAll(uint32 index)
{
    return 0;
}



/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* Custom Teardown All.  Nothing to do here.                       */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int32 TO_OutputChannel_CustomTeardown(uint32 index)
{
    return 0;
}



/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* Process New Custom Commands.  Raise an error event if the       */
/* command is unknown.                                             */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void TO_OutputChannel_ProcessNewCustomCmds(CFE_SB_Msg_t* MsgPtr)
{
    uint32  uiCmdCode=0;

    if (MsgPtr != NULL)
    {
    	uint16 inSize = CFE_SB_GetTotalMsgLength(MsgPtr);
        uiCmdCode = CFE_SB_GetCmdCode(MsgPtr);

    	OS_MutSemTake(TO_AppData.MutexID);
        switch (uiCmdCode)
        {
            case TO_ENABLE_CHANNEL_CC:
            {
            	TO_EnableChannelCmd_t *cmd = (TO_EnableChannelCmd_t*) MsgPtr;
            	/* Validate arguments. */
            	if(inSize != sizeof(TO_EnableChannelCmd_t))
            	{
                    TO_AppData.HkTlm.usCmdErrCnt++;
                    (void) CFE_EVS_SendEvent(TO_MSGLEN_ERR_EID, CFE_EVS_ERROR,
                                      "Invalid message length.  Received %u.  Expected %u.",
									  (unsigned int)inSize, sizeof(TO_EnableChannelCmd_t));
                    break;
            	}

            	if(TO_OutputChannel_Enable(cmd->ChannelID, cmd->DestinationAddress, cmd->DestinationPort))
            	{
                    TO_AppData.HkTlm.usCmdErrCnt++;
                    break;
            	}

                TO_AppData.HkTlm.usCmdCnt++;
                (void) CFE_EVS_SendEvent(TO_CMD_INF_EID, CFE_EVS_INFORMATION,
                                  "Enabled channel %u to %s:%u.",
								  cmd->ChannelID,
								  cmd->DestinationAddress,
								  cmd->DestinationPort);
                break;
            }

            case TO_DISABLE_CHANNEL_CC:
            {
            	TO_DisableChannelCmd_t *cmd = (TO_DisableChannelCmd_t*) MsgPtr;
            	/* Validate arguments. */
            	if(inSize != sizeof(TO_DisableChannelCmd_t))
            	{
                    TO_AppData.HkTlm.usCmdErrCnt++;
                    (void) CFE_EVS_SendEvent(TO_MSGLEN_ERR_EID, CFE_EVS_ERROR,
                                      "Invalid message length.  Received %u.  Expected %u.",
									  (unsigned int)inSize, sizeof(TO_DisableChannelCmd_t));
                    break;
            	}

            	if(TO_OutputChannel_Disable(cmd->ChannelID))
            	{
                    TO_AppData.HkTlm.usCmdErrCnt++;
                    break;
            	}

                TO_AppData.HkTlm.usCmdCnt++;
                break;
            }

            default:
                TO_AppData.HkTlm.usCmdErrCnt++;
                (void) CFE_EVS_SendEvent(TO_MSGID_ERR_EID, CFE_EVS_ERROR,
                                  "Recvd invalid cmdId (%u)", (unsigned int)uiCmdCode);
                break;
        }
    	OS_MutSemGive(TO_AppData.MutexID);
    }
}



/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* Enable Channel.  This will bind the socket for transmission.    */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int32 TO_OutputChannel_Enable(uint8 ChannelID, const char *DestinationAddress, uint16 DestinationPort)
{
    int32 returnCode = 0;
    uint32 i = 0;
    struct sockaddr_in servaddr;
    int status;
    int reuseaddr=1;

    //if(TO_AppCustomData.Channel[ChannelID].Mode == TO_CHANNEL_ENABLED)
    //{
    //  CFE_EVS_SendEvent(TO_TLMOUTENA_ERR_EID, CFE_EVS_ERROR,
    //                "UDP telemetry for channel %u already enabled.", (unsigned int)i);
    //  returnCode = -1;
    //  goto end_of_function;
    //}

    if(DestinationAddress == 0)
    {
        CFE_EVS_SendEvent(TO_TLMOUTENA_ERR_EID, CFE_EVS_ERROR,
                "Destination address for channel %u is null.", (unsigned int)i);
        returnCode = -1;
        goto end_of_function;
    }

    if(ChannelID >= TO_MAX_CHANNELS)
    {
        CFE_EVS_SendEvent(TO_TLMOUTENA_ERR_EID, CFE_EVS_ERROR,
                "ChannelID (%u) invalid.", (unsigned int)ChannelID);
        returnCode = -1;
        goto end_of_function;
    }

    if((TO_AppCustomData.Channel[ChannelID].Socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0)
    {
        TO_AppCustomData.Channel[ChannelID].Mode = TO_CHANNEL_DISABLED;
        CFE_EVS_SendEvent(TO_TLMOUTSOCKET_ERR_EID, CFE_EVS_ERROR,
                "TLM socket errno: %i on channel %u", errno, (unsigned int)ChannelID);
        returnCode = -1;
        goto end_of_function;
    }

    /* Set the Reuse Address flag.  If we don't set this flag, the socket will
     * lock the port on termination and the kernel won't unlock it until it
     * times out after a minute or so.
     */
    setsockopt(TO_AppCustomData.Channel[i].Socket, SOL_SOCKET, SO_REUSEADDR, &reuseaddr, sizeof(reuseaddr));

    memcpy(TO_AppCustomData.Channel[ChannelID].IP, DestinationAddress, sizeof(TO_AppCustomData.Channel[ChannelID].IP));
    TO_AppCustomData.Channel[ChannelID].DstPort = DestinationPort;

    /* Set the input arguments to the socket bind.
     */
    bzero(&servaddr,sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port=0;
    status = bind(TO_AppCustomData.Channel[ChannelID].Socket,
            (struct sockaddr *)&servaddr,sizeof(servaddr));
    if(status < 0)
    {
        CFE_EVS_SendEvent(TO_TLMOUTSOCKET_ERR_EID, CFE_EVS_ERROR,
                "TLM bind errno: %i on channel %u", errno, (unsigned int)i);
        TO_AppCustomData.Channel[ChannelID].Mode = TO_CHANNEL_DISABLED;
        returnCode = -1;
        goto end_of_function;
    }

    /* Enable the channel for transmission. */
    TO_AppCustomData.Channel[ChannelID].Mode = TO_CHANNEL_ENABLED;

    /* Create the child listener task. */
    char TaskName[OS_MAX_API_NAME];
    snprintf(TaskName, OS_MAX_API_NAME, "TO_OUTCH_%u", ChannelID);
    returnCode = CFE_ES_CreateChildTask(
            &TO_AppCustomData.Channel[ChannelID].ChildTaskID,
            (const char *)TaskName,
            TO_AppCustomData.Channel[ChannelID].ListenerTask,
            0,
            CFE_ES_DEFAULT_STACK_SIZE,
            TO_AppCustomData.Channel[ChannelID].Priority,
            0);

end_of_function:
    return returnCode;
}



/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* Disable channel.  Close the socket.                             */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int32 TO_OutputChannel_Disable(uint8 ChannelID)
{
    int32 returnCode = 0;
    uint32 i = 0;
	struct sockaddr_in servaddr;
	int status;
	int reuseaddr=1;

	if(TO_AppCustomData.Channel[ChannelID].Mode != TO_CHANNEL_ENABLED)
	{
		CFE_EVS_SendEvent(TO_TLMOUTENA_ERR_EID, CFE_EVS_ERROR,
						  "UDP telemetry for channel %u is not enabled.", (unsigned int)i);
		returnCode = -1;
		goto end_of_function;
	}

	/* Disable the channel before we close the socket so if the handler
	 * task is in the loop it will know the reason why the send
	 * function failed is because the channel is disabled.
	 */
	TO_AppCustomData.Channel[ChannelID].Mode = TO_CHANNEL_DISABLED;
	close(TO_AppCustomData.Channel[ChannelID].Socket);
	TO_AppCustomData.Channel[ChannelID].Socket = 0;

	CFE_EVS_SendEvent(TO_CMD_INF_EID, CFE_EVS_INFORMATION,
                      "Disabled channel %u.",
					  ChannelID);

end_of_function:
	return returnCode;
}



/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* Ground Channel Task Entry Point                                 */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void TO_OutputChannel_GroundChannelTask(void)
{
	CFE_ES_RegisterChildTask();

	TO_OutputChannel_ChannelHandler(0);

	CFE_ES_ExitChildTask();
}



/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* Onboard Channel Task Entry Point                                */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

void TO_OutputChannel_OnboardChannelTask(void)
{
	CFE_ES_RegisterChildTask();

	TO_OutputChannel_ChannelHandler(1);

	CFE_ES_ExitChildTask();
}



/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* Channel Handler                                                 */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void TO_OutputChannel_ChannelHandler(uint32 ChannelIdx)
{
    int32 iStatus = CFE_SUCCESS;
    int32 msgSize = 0;
    char *buffer;

    TO_TlmChannels_t *channel = &TO_AppCustomData.Channel[ChannelIdx];
    while(TO_OutputChannel_Status(ChannelIdx) == TO_CHANNEL_ENABLED)
    {
        if(TO_Channel_State(ChannelIdx) == TO_CHANNEL_OPENED)
        {
            TO_OutputQueue_t *chQueue = &TO_AppData.ChannelData[ChannelIdx].OutputQueue;
            iStatus =  OS_QueueGet(
                    chQueue->OSALQueueID,
                    &buffer, sizeof(buffer), &msgSize, OS_PEND);
            if(iStatus == OS_SUCCESS)
            {
                CFE_SB_MsgId_t msgID = CFE_SB_GetMsgId((CFE_SB_MsgPtr_t)buffer);

                static struct sockaddr_in s_addr;
                int                       status = 0;
                int32                     returnCode = 0;
                uint16  actualMessageSize = CFE_SB_GetTotalMsgLength((CFE_SB_MsgPtr_t)buffer);

                bzero((char *) &s_addr, sizeof(s_addr));
                s_addr.sin_family      = AF_INET;

                CFE_ES_PerfLogEntry(TO_SOCKET_SEND_PERF_ID);
                /* Send message via UDP socket */
                s_addr.sin_addr.s_addr = inet_addr(channel->IP);
                s_addr.sin_port        = htons(channel->DstPort);
                status = sendto(channel->Socket, (char *)buffer, actualMessageSize, 0,
                                        (struct sockaddr *) &s_addr,
                                         sizeof(s_addr));
                if (status < 0)
                {
                    if(TO_AppCustomData.Channel[ChannelIdx].Mode == TO_CHANNEL_ENABLED)
                    {
                        CFE_EVS_SendEvent(TO_TLMOUTSTOP_ERR_EID,CFE_EVS_ERROR,
                                "L%d TO sendto errno %d.", __LINE__, errno);
                        TO_OutputChannel_Disable(ChannelIdx);
                    }
                }
                CFE_ES_PerfLogExit(TO_SOCKET_SEND_PERF_ID);

                iStatus = CFE_ES_PutPoolBuf(TO_AppData.HkTlm.MemPoolHandle, (uint32 *)buffer);
                if(iStatus < 0)
                {
                    (void) CFE_EVS_SendEvent(TO_GET_POOL_ERR_EID, CFE_EVS_ERROR,
                                "PutPoolBuf: error=0x%08lx",
                                    iStatus);
                }
                else
                {
                    OS_MutSemTake(TO_AppData.MutexID);
                    TO_AppData.HkTlm.MemInUse -= iStatus;
                    OS_MutSemGive(TO_AppData.MutexID);

                    TO_Channel_LockByIndex(ChannelIdx);
                    chQueue->CurrentlyQueuedCnt--;
                    chQueue->SentCount++;
                    TO_Channel_UnlockByIndex(ChannelIdx);
                }

            }
            else
            {
                CFE_EVS_SendEvent(TO_TLM_LISTEN_ERR_EID, CFE_EVS_ERROR,
                                "Listener failed to pop message from queue. (%i).", (unsigned int)iStatus);
                TO_Channel_State(ChannelIdx) == TO_CHANNEL_CLOSED;
            }
        }
    }
}


