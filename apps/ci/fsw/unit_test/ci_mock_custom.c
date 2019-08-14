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

#include "ci_mock_custom.h"
#include "ci_test_utils.h"
#include "ci_serialization.h"

int INIT_CUSTOM_RET = NOMINAL;
int READ_MSG_RET;

uint8 ci_noop_buf[CI_MAX_CMD_INGEST] = {25,5,192,0,0,1,0,0};
uint8 ext_buf[CI_MAX_CMD_INGEST] = {28,41,192,0,0,1,0,0};
int TEST_MSG_ID = 0x1900;
int TEST_CC = 0;

int32 CI_InitCustom(void)
{
	int32 Status = -1;

    if(INIT_CUSTOM_RET == NOMINAL)
    {
    	CFE_EVS_SendEvent(CI_ENA_INF_EID, CFE_EVS_INFORMATION,
					  "UDP command input enabled on port");
		Status = 0;
    }	
    else if(INIT_CUSTOM_RET == SOCK_ERR)
    {
    	CFE_EVS_SendEvent(CI_SOCKET_ERR_EID, CFE_EVS_ERROR, "Socket errno");
    }
    else if(INIT_CUSTOM_RET == BIND_ERR)
    {
    	CFE_EVS_SendEvent(CI_SOCKET_ERR_EID, CFE_EVS_ERROR,"Bind socket failed");
    }

	return Status;
}

void CI_ReadMessage(char* buffer, uint32* size)
{
	if(READ_MSG_RET == CI_CMD)
	{
		CI_NoArgCmd_t 	cmd;
		uint32  		MsgSize = sizeof(cmd);
		CFE_SB_InitMsg(&cmd, CI_CMD_MID, MsgSize, TRUE);
		*size = MsgSize;
		int32 i = 0;

		for (i = 0; i < MsgSize; i++)
		{
			CI_AppData.IngestBuffer[i] = ci_noop_buf[i];
		}
	}
	else if(READ_MSG_RET == EXT_STEP_1)
	{
		CI_CmdRegData_t 	*regDataPtr = (CI_CmdRegData_t*)buffer;
		int32 i = 0;
		*size = sizeof(CI_CmdRegData_t);

		CFE_SB_InitMsg(regDataPtr, TEST_MSG_ID, *size, TRUE);
		regDataPtr->msgID = TEST_MSG_ID;
		regDataPtr->step = STEP_1;
		CI_CmdRegister((CFE_SB_MsgPtr_t)regDataPtr);
	}
	else if(READ_MSG_RET == EXT_STEP_2)
	{
		CI_CmdRegData_t 	*regDataPtr = (CI_CmdRegData_t*)buffer;
		int32 i = 0;
		*size = sizeof(CI_CmdRegData_t);

		CFE_SB_InitMsg(regDataPtr, TEST_MSG_ID, *size, TRUE);
		regDataPtr->msgID = TEST_MSG_ID;
		regDataPtr->step = STEP_2;
		CI_CmdRegister((CFE_SB_MsgPtr_t)regDataPtr);
	}
	else if(READ_MSG_RET == EXT_STEP_2_AUTH)
	{
		CI_CmdData_t		*CmdData = NULL;
		CI_CmdRegData_t 	*regDataPtr = (CI_CmdRegData_t*)buffer;
		int32 i = 0;
		*size = sizeof(CI_CmdRegData_t);

		CFE_SB_InitMsg(regDataPtr, TEST_MSG_ID, *size, TRUE);
		regDataPtr->msgID = TEST_MSG_ID;
		regDataPtr->step = STEP_2;
		CI_CmdRegister((CFE_SB_MsgPtr_t)regDataPtr);

		CmdData = CI_GetRegisterdCmd(TEST_MSG_ID, TEST_CC, &i);
		CmdData->state = AUTHORIZED;
	}
	else if(READ_MSG_RET == LONG_CMD)
	{
		*size = CI_MAX_CMD_INGEST + 1;
	}

	else if(READ_MSG_RET == INV_CMD)
	{
		CI_NoArgCmd_t 	cmd;
		uint32  		MsgSize = sizeof(cmd);
		CFE_SB_MsgPtr_t CmdMsgPtr;//

		CFE_SB_InitMsg(&cmd, CI_CMD_MID, MsgSize, TRUE);
		CmdMsgPtr = (CFE_SB_MsgPtr_t)&cmd;
		CCSDS_WR_VERS(CmdMsgPtr->Hdr, 1);
		*size = MsgSize;
		buffer = (char *)&cmd;
	}
}

void CI_ReadSerializedMessage(char* buffer, uint32* size)
{
	if(READ_MSG_RET == CI_CMD)
	{
		CI_NoArgCmd_t 	cmd;
		uint32  		MsgSize = sizeof(cmd);
		CFE_SB_InitMsg(&cmd, CI_CMD_MID, MsgSize, TRUE);
		*size = MsgSize;
		int32 i = 0;

		for (i = 0; i < MsgSize; i++)
		{
			CI_AppData.SerialIngestBuffer[i] = ci_noop_buf[i];
		}
	}
	else if(READ_MSG_RET == EXT_STEP_1)
	{
		CI_CmdRegData_t 	cmd;
		CI_CmdRegData_t 	*regDataPtr;
		uint32  			MsgSize = sizeof(cmd);
		CFE_SB_MsgPtr_t 	CmdMsgPtr;
		int32 i = 0;

		CFE_SB_InitMsg(&cmd, TEST_MSG_ID, MsgSize, TRUE);
		regDataPtr = ((CI_CmdRegData_t *) &cmd);
		regDataPtr->msgID = TEST_MSG_ID;
		regDataPtr->step = STEP_1;
		CmdMsgPtr = (CFE_SB_MsgPtr_t)&cmd;
		CI_CmdRegister(CmdMsgPtr);

		MsgSize = sizeof(CI_NoArgCmd_t);
		*size = MsgSize;
		for (i = 0; i < MsgSize; i++)
		{
			CI_AppData.IngestBuffer[i] = ext_buf[i];
		}
	}
	else if(READ_MSG_RET == EXT_STEP_2)
	{
		CI_CmdRegData_t 	cmd;
		CI_CmdRegData_t 	*regDataPtr;
		CI_CmdData_t		*CmdData = NULL;
		uint32  			MsgSize = sizeof(cmd);
		CFE_SB_MsgPtr_t 	CmdMsgPtr;
		int32 i = 0;

		CFE_SB_InitMsg(&cmd, TEST_MSG_ID, MsgSize, TRUE);
		regDataPtr = ((CI_CmdRegData_t *) &cmd);
		regDataPtr->msgID = TEST_MSG_ID;
		regDataPtr->step = STEP_2;
		CmdMsgPtr = (CFE_SB_MsgPtr_t)&cmd;
		CI_CmdRegister(CmdMsgPtr);

		MsgSize = sizeof(CI_NoArgCmd_t);
		*size = MsgSize;
		for (i = 0; i < MsgSize; i++)
		{
			CI_AppData.IngestBuffer[i] = ext_buf[i];
		}
	}
	else if(READ_MSG_RET == EXT_STEP_2_AUTH)
	{
		CI_CmdRegData_t 	cmd;
		CI_CmdRegData_t 	*regDataPtr;
		CI_CmdData_t		*CmdData = NULL;
		uint32  			MsgSize = sizeof(cmd);
		CFE_SB_MsgPtr_t 	CmdMsgPtr;
		int32               i = 0;

		CFE_SB_InitMsg(&cmd, TEST_MSG_ID, MsgSize, TRUE);
		regDataPtr = ((CI_CmdRegData_t *) &cmd);
		regDataPtr->msgID = TEST_MSG_ID;
		regDataPtr->step = STEP_2;
		CmdMsgPtr = (CFE_SB_MsgPtr_t)&cmd;
		CI_CmdRegister(CmdMsgPtr);

		CmdData = CI_GetRegisterdCmd(TEST_MSG_ID, TEST_CC, &i);
		CmdData->state = AUTHORIZED;

		MsgSize = sizeof(CI_NoArgCmd_t);
		*size = MsgSize;
		for (i = 0; i < MsgSize; i++)
		{
			CI_AppData.IngestBuffer[i] = ext_buf[i];
		}
	}
	else if(READ_MSG_RET == LONG_CMD)
	{
		*size = CI_MAX_CMD_INGEST + 1;
	}

	else if(READ_MSG_RET == INV_CMD)
	{
		CI_NoArgCmd_t 	cmd;
		uint32  		MsgSize = sizeof(cmd);
		CFE_SB_MsgPtr_t CmdMsgPtr;//

		CFE_SB_InitMsg(&cmd, CI_CMD_MID, MsgSize, TRUE);
		CmdMsgPtr = (CFE_SB_MsgPtr_t)&cmd;
		CCSDS_WR_VERS(CmdMsgPtr->Hdr, 1);
		*size = MsgSize;
		buffer = (char *)&cmd;
	}

	else if(READ_MSG_RET == SERIALIZED_CMD)
	{
		CI_CmdRegData_t 	cmdReg;
		uint32  			MsgSize = sizeof(cmdReg);
		CFE_SB_MsgPtr_t 	CmdMsgPtr;
		uint32  			payloadSize = 0;
		uint32  			hdrSize = 0;
		char 				encBuffer[CI_MAX_ENC_LEN];

		/* Create CFE_SB_Msg_t */
		CFE_SB_InitMsg(&cmdReg, CI_CMD_MID, MsgSize, TRUE);
		CmdMsgPtr = (CFE_SB_MsgPtr_t)&cmdReg;
		CFE_SB_SetCmdCode(CmdMsgPtr, CI_REG_CMD_CC);

		/* Set cmd attributes */
		cmdReg.msgID = TEST_MSG_ID;
		cmdReg.cmdCode = TEST_CC;
		cmdReg.step = STEP_2;
		cmdReg.log = LOG;

		/* Encode message */
		hdrSize = CFE_SB_MsgHdrSize(CI_CMD_MID);
		payloadSize = CI_CmdRegData_Enc(&cmdReg, &encBuffer[hdrSize], CI_MAX_ENC_LEN - hdrSize);

		/* Create new SB msg from serialized data */
		CFE_SB_InitMsg(encBuffer, CI_CMD_MID, MsgSize, FALSE);
		CmdMsgPtr = (CFE_SB_MsgPtr_t)encBuffer;

		/* Update header info */
		CFE_SB_SetCmdCode(CmdMsgPtr, CI_REG_CMD_CC);
		CFE_SB_GenerateChecksum(CmdMsgPtr);

		*size = MsgSize;
		buffer = (char *)CmdMsgPtr;
	}
}


void CI_CleanupCustom(void)
{
}


