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

#include "to_app.h"
#include <string.h>



/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* Clear all dynamics metrics.                                     */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void TO_PriorityQueue_ResetCountsAll(TO_ChannelData_t* channel)
{
	uint32 i = 0;

	for(i=0; i < TO_MAX_PRIORITY_QUEUES; ++i)
	{
		channel->DumpTbl.PriorityQueue[i].DroppedMsgCnt = 0;
		channel->DumpTbl.PriorityQueue[i].QueuedMsgCnt = 0;
		channel->DumpTbl.PriorityQueue[i].HighwaterMark = 0;
	}
}



/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* Buildup all priority queues after a reconfiguration.            */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int32 TO_PriorityQueue_BuildupAll(TO_ChannelData_t* channel)
{
	uint32 i = 0;
	int32 iStatus = CFE_SUCCESS;

    /*
     * Create the priority queues.
     */
    for(i=0; i < TO_MAX_PRIORITY_QUEUES; ++i)
    {
    	if(channel->ConfigTblPtr->PriorityQueue[i].State != TO_PQUEUE_UNUSED)
    	{
			char QueueName[OS_MAX_API_NAME];
			snprintf(QueueName, OS_MAX_API_NAME, "TO_%s_%u", channel->ChannelName, (unsigned int)i);
			iStatus = OS_QueueCreate(
					&channel->DumpTbl.PriorityQueue[i].OSALQueueID,
					QueueName,
					channel->ConfigTblPtr->PriorityQueue[i].MsgLimit,
					sizeof(CFE_SB_Msg_t*),
					0);
			if (iStatus != OS_SUCCESS)
			{
				 CFE_EVS_SendEvent(TO_CONFIG_TABLE_ERR_EID, CFE_EVS_ERROR,
										  "Failed to create '%s' priority queue #%u. (%i)",
										  channel->ChannelName,
										  (unsigned int)i,
										  (int)iStatus);
				 goto end_of_function;

			}
    	}
    }

    end_of_function:
    	return iStatus;
}



/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* Teardown all priority queues after a reconfiguration.           */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
int32 TO_PriorityQueue_TeardownAll(TO_ChannelData_t *channel)
{
	uint32 i = 0;
	int32 iStatus = 0;

	for(i=0; i < TO_MAX_PRIORITY_QUEUES; ++i)
	{
		if(channel->ConfigTblPtr != 0)
		{
			if(channel->ConfigTblPtr->PriorityQueue[i].State != TO_PQUEUE_UNUSED)
			{
				if(channel->DumpTbl.PriorityQueue[i].OSALQueueID !=0)
				{
					void *buffer;
					uint32 bufferSize = 0;
					while(iStatus == OS_SUCCESS)
					{
						iStatus =  OS_QueueGet(
								channel->DumpTbl.PriorityQueue[i].OSALQueueID,
								&buffer, sizeof(buffer), &bufferSize, OS_CHECK);
						if(iStatus == OS_SUCCESS)
						{
							iStatus = CFE_ES_PutPoolBuf(TO_AppData.HkTlm.MemPoolHandle, (uint32*)buffer);
							if(iStatus < 0)
							{
								(void) CFE_EVS_SendEvent(TO_CONFIG_TABLE_ERR_EID, CFE_EVS_ERROR,
										"Failed to return message back to memory pool on tbl load. (%i)",
										(unsigned int)iStatus);
								goto end_of_function;
							}
							OS_MutSemTake(TO_AppData.MutexID);
							TO_AppData.HkTlm.MemInUse -= iStatus;
							OS_MutSemGive(TO_AppData.MutexID);
						}
					}
					if(iStatus != OS_QUEUE_EMPTY)
					{
						(void) CFE_EVS_SendEvent(TO_CONFIG_TABLE_ERR_EID, CFE_EVS_ERROR,
								"Message flow failed to pop all messages from pqueue %u. (%i)",
								(unsigned int)i,
								(unsigned int)iStatus);
						goto end_of_function;
					}
					else
					{
						/* Queue is empty.  Delete the queue. */
						iStatus = OS_QueueDelete(
								channel->DumpTbl.PriorityQueue[i].OSALQueueID);
						if(iStatus != OS_SUCCESS)
						{
							(void) CFE_EVS_SendEvent(TO_CONFIG_TABLE_ERR_EID, CFE_EVS_ERROR,
									"Failed to delete priority queue %u. (%i)",
									(unsigned int)i,
									(unsigned int)iStatus);
							goto end_of_function;
						}
					}
				}
			}
		}
	}

end_of_function:
	return iStatus;
}



/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* Cleanup all priority queues for termination.                    */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void TO_PriorityQueue_CleanupAll(TO_ChannelData_t *channel)
{
	TO_PriorityQueue_TeardownAll(channel);
}



/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* Push a message on a priority queue.                             */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void *TO_CopyBuffer;
int32 TO_PriorityQueue_QueueMsg(TO_ChannelData_t *channel, CFE_SB_MsgPtr_t MsgPtr, uint32 PQueueIndex)
{
	int32 iStatus = 0;
	uint32 bufferSize = 0;

	TO_PriorityQueue_t* PQueue = &channel->ConfigTblPtr->PriorityQueue[PQueueIndex];
	TO_PriorityQueueMetrics_t* PQueueDump = &channel->DumpTbl.PriorityQueue[PQueueIndex];

	if(PQueue == 0)
	{
		iStatus = -2;
		goto end_of_function;
	}

	bufferSize = CFE_SB_GetTotalMsgLength(MsgPtr);

	/* Allocate a chunk of memory from the memory pool to store the message
	 * copy.
	 */
    iStatus = CFE_ES_GetPoolBuf ((uint32 **) &TO_CopyBuffer,
    		TO_AppData.HkTlm.MemPoolHandle, bufferSize);
    if((iStatus < 0) || (TO_CopyBuffer == 0))
    {
    	OS_MutSemTake(TO_AppData.MutexID);
        (void) CFE_EVS_SendEvent(TO_GET_POOL_ERR_EID, CFE_EVS_ERROR,
                          "GetPoolBuf failed: size=%lu error=0x%08xi. CN='%s' MIU=%u PMIU=%u OQCC=%u",
						  bufferSize, (int)iStatus,
						  channel->ChannelName,
						  (unsigned int)TO_AppData.HkTlm.MemInUse,
						  (unsigned int)TO_AppData.HkTlm.PeakMemInUse,
						  (unsigned int)channel->OutputQueue.CurrentlyQueuedCnt);
    	OS_MutSemGive(TO_AppData.MutexID);
        iStatus = -1;
        goto end_of_function;
    }

	OS_MutSemTake(TO_AppData.MutexID);
    TO_AppData.HkTlm.MemInUse += iStatus;
    if(TO_AppData.HkTlm.MemInUse > TO_AppData.HkTlm.PeakMemInUse)
    {
    	TO_AppData.HkTlm.PeakMemInUse = TO_AppData.HkTlm.MemInUse;
    }
	OS_MutSemGive(TO_AppData.MutexID);

    /* Copy the message into the newly allocated memory. */
    memcpy(TO_CopyBuffer, MsgPtr, bufferSize);

    /* Queue the pointer to the message copy. */
    iStatus = OS_QueuePut(PQueueDump->OSALQueueID, &TO_CopyBuffer, sizeof(TO_CopyBuffer), 0);
    if(iStatus == OS_QUEUE_FULL)
    {
    	/* This is ok.  Just let the caller no the queue is full.  But,
    	 * deallocate the memory allocated first since we don't need it
    	 * anymore.
    	 */
		iStatus = CFE_ES_PutPoolBuf(TO_AppData.HkTlm.MemPoolHandle, (uint32*)TO_CopyBuffer);
	    if(iStatus < 0)
    	{
        	(void) CFE_EVS_SendEvent(TO_GET_POOL_ERR_EID, CFE_EVS_ERROR,
                             "PutPoolBuf: error=%i",
                             (int)iStatus);
        	goto end_of_function;
    	}
    	OS_MutSemTake(TO_AppData.MutexID);
	    TO_AppData.HkTlm.MemInUse -= iStatus;
    	OS_MutSemGive(TO_AppData.MutexID);
	    iStatus = -1;
    }
    else if(iStatus != CFE_SUCCESS)
    {
        (void) CFE_EVS_SendEvent(TO_GET_POOL_ERR_EID, CFE_EVS_ERROR,
                          "OS_QueuePut failed: size=%u error=%i",
						  sizeof(TO_CopyBuffer), (int)iStatus);
        goto end_of_function;
    }

end_of_function:
    return iStatus;
}



/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* Query a priority queue.                                         */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
boolean TO_PriorityQueue_Query(uint16 ChannelIdx, uint16 PQueueIdx)
{
	boolean rc = FALSE;

    TO_ChannelData_t *channel;

    /* First, check if the channel index is valid. */
    if(ChannelIdx >= TO_MAX_CHANNELS)
    {
    	(void) CFE_EVS_SendEvent(TO_PQUEUE_INFO_EID, CFE_EVS_ERROR,
    		"Invalid channel index.");
    	goto end_of_function;
    }
    channel = &TO_AppData.ChannelData[ChannelIdx];

	TO_Channel_LockByRef(channel);

    /* Next, see if the channel is open. */
    if(channel->State != TO_CHANNEL_OPENED)
    {
    	(void) CFE_EVS_SendEvent(TO_PQUEUE_INFO_EID, CFE_EVS_ERROR,
    		"Channel not open.");
    	TO_Channel_UnlockByRef(channel);
    	goto end_of_function;
    }

	if(PQueueIdx >= TO_MAX_PRIORITY_QUEUES)
	{
		(void) CFE_EVS_SendEvent(TO_PQUEUE_INFO_EID, CFE_EVS_ERROR,
		                      "PQueueIdx %u out of bounds", PQueueIdx);
	}
	else
	{
		(void) CFE_EVS_SendEvent(TO_PQUEUE_INFO_EID, CFE_EVS_INFORMATION,
							  "PQI=%u S=%u ML=%u QT=%u D=%u Q=%u CQ=%u HWM=%u",
							  PQueueIdx,
							  channel->ConfigTblPtr->PriorityQueue[PQueueIdx].State,
							  channel->ConfigTblPtr->PriorityQueue[PQueueIdx].MsgLimit,
							  channel->ConfigTblPtr->PriorityQueue[PQueueIdx].QType,
							  channel->DumpTbl.PriorityQueue[PQueueIdx].DroppedMsgCnt,
							  channel->DumpTbl.PriorityQueue[PQueueIdx].QueuedMsgCnt,
							  channel->DumpTbl.PriorityQueue[PQueueIdx].CurrentlyQueuedCnt,
							  channel->DumpTbl.PriorityQueue[PQueueIdx].HighwaterMark);
		rc = TRUE;
	}

	TO_Channel_UnlockByRef(channel);

end_of_function:
	return rc;

}



/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                                 */
/* Is this index a valid priority queue?                           */
/*                                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
boolean TO_PriorityQueue_IsValid(TO_ChannelData_t *channel, uint32 PQueueIdx)
{
	boolean isValid = TRUE;

	if(PQueueIdx >= TO_MAX_PRIORITY_QUEUES)
	{
		isValid = FALSE;
	}
	else if(channel->ConfigTblPtr->PriorityQueue[PQueueIdx].State != TO_PQUEUE_ENA)
	{
		isValid = FALSE;
	}

	return isValid;
}
