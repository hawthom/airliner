/* Automatically generated nanopb header */
/* Generated by nanopb-0.3.6 at Wed Oct 26 00:46:17 2016. */

#ifndef PB_VISION_POSITION_ESTIMATE_PB_H_INCLUDED
#define PB_VISION_POSITION_ESTIMATE_PB_H_INCLUDED
#include <pb.h>

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* Struct definitions */
typedef struct _px4_vision_position_estimate_pb {
    uint64_t timestamp;
    uint64_t timestamp_received;
    uint32_t id;
    float x;
    float y;
    float z;
    float vx;
    float vy;
    float vz;
    pb_size_t q_count;
    float q[4];
    float pos_err;
    float ang_err;
/* @@protoc_insertion_point(struct:px4_vision_position_estimate_pb) */
} px4_vision_position_estimate_pb;

/* Default values for struct fields */

/* Initializer values for message structs */
#define px4_vision_position_estimate_pb_init_default {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, {0, 0, 0, 0}, 0, 0}
#define px4_vision_position_estimate_pb_init_zero {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, {0, 0, 0, 0}, 0, 0}

/* Field tags (for use in manual encoding/decoding) */
#define px4_vision_position_estimate_pb_timestamp_tag 1
#define px4_vision_position_estimate_pb_timestamp_received_tag 2
#define px4_vision_position_estimate_pb_id_tag   3
#define px4_vision_position_estimate_pb_x_tag    4
#define px4_vision_position_estimate_pb_y_tag    5
#define px4_vision_position_estimate_pb_z_tag    6
#define px4_vision_position_estimate_pb_vx_tag   7
#define px4_vision_position_estimate_pb_vy_tag   8
#define px4_vision_position_estimate_pb_vz_tag   9
#define px4_vision_position_estimate_pb_q_tag    10
#define px4_vision_position_estimate_pb_pos_err_tag 11
#define px4_vision_position_estimate_pb_ang_err_tag 12

/* Struct field encoding specification for nanopb */
extern const pb_field_t px4_vision_position_estimate_pb_fields[13];

/* Maximum encoded size of messages (where known) */
#define px4_vision_position_estimate_pb_size     88

/* Message IDs (where set with "msgid" option) */
#ifdef PB_MSGID

#define VISION_POSITION_ESTIMATE_MESSAGES \


#endif

#ifdef __cplusplus
} /* extern "C" */
#endif
/* @@protoc_insertion_point(eof) */

#endif
