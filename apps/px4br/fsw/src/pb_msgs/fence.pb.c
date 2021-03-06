/* Automatically generated nanopb constant definitions */
/* Generated by nanopb-0.3.6 at Wed Oct 26 00:46:11 2016. */

#include "fence.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif



const pb_field_t px4_fence_pb_fields[4] = {
    PB_FIELD(  1, UINT64  , REQUIRED, STATIC  , FIRST, px4_fence_pb, timestamp, timestamp, 0),
    PB_FIELD(  2, UINT32  , REQUIRED, STATIC  , OTHER, px4_fence_pb, count, timestamp, 0),
    PB_FIELD(  3, MESSAGE , REPEATED, STATIC  , OTHER, px4_fence_pb, vertices, count, &px4_fence_vertex_pb_fields),
    PB_LAST_FIELD
};


/* Check that field information fits in pb_field_t */
#if !defined(PB_FIELD_32BIT)
/* If you get an error here, it means that you need to define PB_FIELD_32BIT
 * compile-time option. You can do that in pb.h or on compiler command line.
 * 
 * The reason you need to do this is that some of your messages contain tag
 * numbers or field sizes that are larger than what can fit in 8 or 16 bit
 * field descriptors.
 */
PB_STATIC_ASSERT((pb_membersize(px4_fence_pb, vertices[0]) < 65536), YOU_MUST_DEFINE_PB_FIELD_32BIT_FOR_MESSAGES_px4_fence_pb)
#endif

#if !defined(PB_FIELD_16BIT) && !defined(PB_FIELD_32BIT)
/* If you get an error here, it means that you need to define PB_FIELD_16BIT
 * compile-time option. You can do that in pb.h or on compiler command line.
 * 
 * The reason you need to do this is that some of your messages contain tag
 * numbers or field sizes that are larger than what can fit in the default
 * 8 bit descriptors.
 */
PB_STATIC_ASSERT((pb_membersize(px4_fence_pb, vertices[0]) < 256), YOU_MUST_DEFINE_PB_FIELD_16BIT_FOR_MESSAGES_px4_fence_pb)
#endif


/* @@protoc_insertion_point(eof) */
