/* Automatically generated nanopb constant definitions */
/* Generated by nanopb-0.3.6 at Sat Oct 29 18:17:59 2016. */

#include "transponder_report.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif



const pb_field_t px4_transponder_report_pb_fields[15] = {
    PB_FIELD(  1, UINT64  , REQUIRED, STATIC  , FIRST, px4_transponder_report_pb, timestamp, timestamp, 0),
    PB_FIELD(  2, DOUBLE  , REQUIRED, STATIC  , OTHER, px4_transponder_report_pb, lat, timestamp, 0),
    PB_FIELD(  3, DOUBLE  , REQUIRED, STATIC  , OTHER, px4_transponder_report_pb, lon, lat, 0),
    PB_FIELD(  4, UINT32  , REQUIRED, STATIC  , OTHER, px4_transponder_report_pb, ICAO_address, lon, 0),
    PB_FIELD(  5, FLOAT   , REQUIRED, STATIC  , OTHER, px4_transponder_report_pb, altitude, ICAO_address, 0),
    PB_FIELD(  6, FLOAT   , REQUIRED, STATIC  , OTHER, px4_transponder_report_pb, heading, altitude, 0),
    PB_FIELD(  7, FLOAT   , REQUIRED, STATIC  , OTHER, px4_transponder_report_pb, hor_velocity, heading, 0),
    PB_FIELD(  8, FLOAT   , REQUIRED, STATIC  , OTHER, px4_transponder_report_pb, ver_velocity, hor_velocity, 0),
    PB_FIELD(  9, UINT32  , REQUIRED, STATIC  , OTHER, px4_transponder_report_pb, flags, ver_velocity, 0),
    PB_FIELD( 10, UINT32  , REQUIRED, STATIC  , OTHER, px4_transponder_report_pb, squawk, flags, 0),
    PB_FIELD( 11, UINT32  , REQUIRED, STATIC  , OTHER, px4_transponder_report_pb, altitude_type, squawk, 0),
    PB_FIELD( 12, STRING  , REQUIRED, STATIC  , OTHER, px4_transponder_report_pb, callsign, altitude_type, 0),
    PB_FIELD( 13, UINT32  , REQUIRED, STATIC  , OTHER, px4_transponder_report_pb, emitter_type, callsign, 0),
    PB_FIELD( 14, UINT32  , REQUIRED, STATIC  , OTHER, px4_transponder_report_pb, tslc, emitter_type, 0),
    PB_LAST_FIELD
};


/* On some platforms (such as AVR), double is really float.
 * These are not directly supported by nanopb, but see example_avr_double.
 * To get rid of this error, remove any double fields from your .proto.
 */
PB_STATIC_ASSERT(sizeof(double) == 8, DOUBLE_MUST_BE_8_BYTES)

/* @@protoc_insertion_point(eof) */
