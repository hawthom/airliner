/* Automatically generated nanopb constant definitions */
/* Generated by nanopb-0.3.6 at Wed Oct 26 00:46:17 2016. */

#include "vehicle_force_setpoint.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif



const pb_field_t px4_vehicle_force_setpoint_pb_fields[6] = {
    PB_FIELD(  1, UINT64  , REQUIRED, STATIC  , FIRST, px4_vehicle_force_setpoint_pb, timestamp, timestamp, 0),
    PB_FIELD(  2, FLOAT   , REQUIRED, STATIC  , OTHER, px4_vehicle_force_setpoint_pb, x, timestamp, 0),
    PB_FIELD(  3, FLOAT   , REQUIRED, STATIC  , OTHER, px4_vehicle_force_setpoint_pb, y, x, 0),
    PB_FIELD(  4, FLOAT   , REQUIRED, STATIC  , OTHER, px4_vehicle_force_setpoint_pb, z, y, 0),
    PB_FIELD(  5, FLOAT   , REQUIRED, STATIC  , OTHER, px4_vehicle_force_setpoint_pb, yaw, z, 0),
    PB_LAST_FIELD
};


/* @@protoc_insertion_point(eof) */
