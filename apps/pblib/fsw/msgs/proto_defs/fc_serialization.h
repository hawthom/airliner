/* This file was autogenerated from template version 0.0.0.1 and autogenerator version 0.0.0.1 */

#include "pb.h"
#include "pb_encode.h"
#include "pb_decode.h"
#include "pb_lib.h"
#include "px4_vehicle_command_msg.pb.h"
#include "px4_position_setpoint_triplet.pb.h"
#include "px4_manual_control_setpoint.pb.h"
#include "px4_msgs.h"

#ifdef __cplusplus
extern "C" {
#endif

uint32 PX4_VehicleCommandMsg_t_Enc(const PX4_VehicleCommandMsg_t *inObject, char *inOutBuffer, uint32 inSize);
uint32 PX4_VehicleCommandMsg_t_Dec(const char *inBuffer, uint32 inSize, PX4_VehicleCommandMsg_t *inOutObject);

uint32 PX4_PositionSetpointTripletMsg_t_Enc(const PX4_PositionSetpointTripletMsg_t *inObject, char *inOutBuffer, uint32 inSize);
uint32 PX4_PositionSetpointTripletMsg_t_Dec(const char *inBuffer, uint32 inSize, PX4_PositionSetpointTripletMsg_t *inOutObject);

uint32 PX4_ManualControlSetpointMsg_t_Enc(const PX4_ManualControlSetpointMsg_t *inObject, char *inOutBuffer, uint32 inSize);
uint32 PX4_ManualControlSetpointMsg_t_Dec(const char *inBuffer, uint32 inSize, PX4_ManualControlSetpointMsg_t *inOutObject);

#ifdef __cplusplus
} /* extern "C" */
#endif
