/* Automatically generated nanopb constant definitions */
/* Generated by nanopb-0.3.6 at Wed Oct 26 00:46:16 2016. */

#include "sensor_mag.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif



const pb_field_t px4_sensor_mag_pb_fields[13] = {
    PB_FIELD(  1, UINT64  , REQUIRED, STATIC  , FIRST, px4_sensor_mag_pb, timestamp, timestamp, 0),
    PB_FIELD(  2, UINT64  , REQUIRED, STATIC  , OTHER, px4_sensor_mag_pb, error_count, timestamp, 0),
    PB_FIELD(  3, FLOAT   , REQUIRED, STATIC  , OTHER, px4_sensor_mag_pb, x, error_count, 0),
    PB_FIELD(  4, FLOAT   , REQUIRED, STATIC  , OTHER, px4_sensor_mag_pb, y, x, 0),
    PB_FIELD(  5, FLOAT   , REQUIRED, STATIC  , OTHER, px4_sensor_mag_pb, z, y, 0),
    PB_FIELD(  6, FLOAT   , REQUIRED, STATIC  , OTHER, px4_sensor_mag_pb, range_ga, z, 0),
    PB_FIELD(  7, FLOAT   , REQUIRED, STATIC  , OTHER, px4_sensor_mag_pb, scaling, range_ga, 0),
    PB_FIELD(  8, FLOAT   , REQUIRED, STATIC  , OTHER, px4_sensor_mag_pb, temperature, scaling, 0),
    PB_FIELD(  9, UINT32  , REQUIRED, STATIC  , OTHER, px4_sensor_mag_pb, device_id, temperature, 0),
    PB_FIELD( 10, INT32   , REQUIRED, STATIC  , OTHER, px4_sensor_mag_pb, x_raw, device_id, 0),
    PB_FIELD( 11, INT32   , REQUIRED, STATIC  , OTHER, px4_sensor_mag_pb, y_raw, x_raw, 0),
    PB_FIELD( 12, INT32   , REQUIRED, STATIC  , OTHER, px4_sensor_mag_pb, z_raw, y_raw, 0),
    PB_LAST_FIELD
};


/* @@protoc_insertion_point(eof) */
