/* Automatically generated nanopb constant definitions */
/* Generated by nanopb-0.3.6 at Wed Oct 26 00:46:11 2016. */

#include "follow_target.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif



const pb_field_t px4_follow_target_pb_fields[9] = {
    PB_FIELD(  1, UINT64  , REQUIRED, STATIC  , FIRST, px4_follow_target_pb, timestamp, timestamp, 0),
    PB_FIELD(  2, DOUBLE  , REQUIRED, STATIC  , OTHER, px4_follow_target_pb, lat, timestamp, 0),
    PB_FIELD(  3, DOUBLE  , REQUIRED, STATIC  , OTHER, px4_follow_target_pb, lon, lat, 0),
    PB_FIELD(  4, FLOAT   , REQUIRED, STATIC  , OTHER, px4_follow_target_pb, alt, lon, 0),
    PB_FIELD(  5, FLOAT   , REQUIRED, STATIC  , OTHER, px4_follow_target_pb, vy, alt, 0),
    PB_FIELD(  6, FLOAT   , REQUIRED, STATIC  , OTHER, px4_follow_target_pb, vx, vy, 0),
    PB_FIELD(  7, FLOAT   , REQUIRED, STATIC  , OTHER, px4_follow_target_pb, vz, vx, 0),
    PB_FIELD(  8, UINT32  , REQUIRED, STATIC  , OTHER, px4_follow_target_pb, est_cap, vz, 0),
    PB_LAST_FIELD
};


/* On some platforms (such as AVR), double is really float.
 * These are not directly supported by nanopb, but see example_avr_double.
 * To get rid of this error, remove any double fields from your .proto.
 */
PB_STATIC_ASSERT(sizeof(double) == 8, DOUBLE_MUST_BE_8_BYTES)

/* @@protoc_insertion_point(eof) */
