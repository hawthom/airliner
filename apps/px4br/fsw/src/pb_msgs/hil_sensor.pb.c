/* Automatically generated nanopb constant definitions */
/* Generated by nanopb-0.3.6 at Wed Oct 26 00:46:12 2016. */

#include "hil_sensor.pb.h"

/* @@protoc_insertion_point(includes) */
#if PB_PROTO_HEADER_VERSION != 30
#error Regenerate this file with the current version of nanopb generator.
#endif



const pb_field_t px4_hil_sensor_pb_fields[68] = {
    PB_FIELD(  1, UINT64  , REQUIRED, STATIC  , FIRST, px4_hil_sensor_pb, timestamp, timestamp, 0),
    PB_FIELD(  2, UINT64  , REQUIRED, STATIC  , OTHER, px4_hil_sensor_pb, accelerometer_timestamp, timestamp, 0),
    PB_FIELD(  3, UINT64  , REQUIRED, STATIC  , OTHER, px4_hil_sensor_pb, magnetometer_timestamp, accelerometer_timestamp, 0),
    PB_FIELD(  4, UINT64  , REQUIRED, STATIC  , OTHER, px4_hil_sensor_pb, gyro1_timestamp, magnetometer_timestamp, 0),
    PB_FIELD(  5, UINT64  , REQUIRED, STATIC  , OTHER, px4_hil_sensor_pb, accelerometer1_timestamp, gyro1_timestamp, 0),
    PB_FIELD(  6, UINT64  , REQUIRED, STATIC  , OTHER, px4_hil_sensor_pb, magnetometer1_timestamp, accelerometer1_timestamp, 0),
    PB_FIELD(  7, UINT64  , REQUIRED, STATIC  , OTHER, px4_hil_sensor_pb, gyro2_timestamp, magnetometer1_timestamp, 0),
    PB_FIELD(  8, UINT64  , REQUIRED, STATIC  , OTHER, px4_hil_sensor_pb, accelerometer2_timestamp, gyro2_timestamp, 0),
    PB_FIELD(  9, UINT64  , REQUIRED, STATIC  , OTHER, px4_hil_sensor_pb, magnetometer2_timestamp, accelerometer2_timestamp, 0),
    PB_FIELD( 10, UINT64  , REQUIRED, STATIC  , OTHER, px4_hil_sensor_pb, baro_timestamp, magnetometer2_timestamp, 0),
    PB_FIELD( 11, UINT64  , REQUIRED, STATIC  , OTHER, px4_hil_sensor_pb, baro1_timestamp, baro_timestamp, 0),
    PB_FIELD( 12, UINT64  , REQUIRED, STATIC  , OTHER, px4_hil_sensor_pb, differential_pressure_timestamp, baro1_timestamp, 0),
    PB_FIELD( 13, UINT64  , REQUIRED, STATIC  , OTHER, px4_hil_sensor_pb, differential_pressure1_timestamp, differential_pressure_timestamp, 0),
    PB_FIELD( 14, FLOAT   , REPEATED, STATIC  , OTHER, px4_hil_sensor_pb, gyro_rad_s, differential_pressure1_timestamp, 0),
    PB_FIELD( 15, UINT32  , REQUIRED, STATIC  , OTHER, px4_hil_sensor_pb, gyro_errcount, gyro_rad_s, 0),
    PB_FIELD( 16, FLOAT   , REQUIRED, STATIC  , OTHER, px4_hil_sensor_pb, gyro_temp, gyro_errcount, 0),
    PB_FIELD( 17, FLOAT   , REPEATED, STATIC  , OTHER, px4_hil_sensor_pb, accelerometer_m_s2, gyro_temp, 0),
    PB_FIELD( 18, FLOAT   , REQUIRED, STATIC  , OTHER, px4_hil_sensor_pb, accelerometer_range_m_s2, accelerometer_m_s2, 0),
    PB_FIELD( 19, UINT32  , REQUIRED, STATIC  , OTHER, px4_hil_sensor_pb, accelerometer_errcount, accelerometer_range_m_s2, 0),
    PB_FIELD( 20, FLOAT   , REQUIRED, STATIC  , OTHER, px4_hil_sensor_pb, accelerometer_temp, accelerometer_errcount, 0),
    PB_FIELD( 21, FLOAT   , REPEATED, STATIC  , OTHER, px4_hil_sensor_pb, magnetometer_ga, accelerometer_temp, 0),
    PB_FIELD( 22, FLOAT   , REQUIRED, STATIC  , OTHER, px4_hil_sensor_pb, magnetometer_range_ga, magnetometer_ga, 0),
    PB_FIELD( 23, FLOAT   , REQUIRED, STATIC  , OTHER, px4_hil_sensor_pb, magnetometer_cuttoff_freq_hz, magnetometer_range_ga, 0),
    PB_FIELD( 24, UINT32  , REQUIRED, STATIC  , OTHER, px4_hil_sensor_pb, magnetometer_errcount, magnetometer_cuttoff_freq_hz, 0),
    PB_FIELD( 25, FLOAT   , REQUIRED, STATIC  , OTHER, px4_hil_sensor_pb, magnetometer_temp, magnetometer_errcount, 0),
    PB_FIELD( 26, FLOAT   , REPEATED, STATIC  , OTHER, px4_hil_sensor_pb, gyro1_rad_s, magnetometer_temp, 0),
    PB_FIELD( 27, UINT32  , REQUIRED, STATIC  , OTHER, px4_hil_sensor_pb, gyro1_errcount, gyro1_rad_s, 0),
    PB_FIELD( 28, FLOAT   , REQUIRED, STATIC  , OTHER, px4_hil_sensor_pb, gyro1_temp, gyro1_errcount, 0),
    PB_FIELD( 29, FLOAT   , REPEATED, STATIC  , OTHER, px4_hil_sensor_pb, accelerometer1_m_s2, gyro1_temp, 0),
    PB_FIELD( 30, UINT32  , REQUIRED, STATIC  , OTHER, px4_hil_sensor_pb, accelerometer1_errcount, accelerometer1_m_s2, 0),
    PB_FIELD( 31, FLOAT   , REQUIRED, STATIC  , OTHER, px4_hil_sensor_pb, accelerometer1_temp, accelerometer1_errcount, 0),
    PB_FIELD( 32, FLOAT   , REPEATED, STATIC  , OTHER, px4_hil_sensor_pb, magnetometer1_ga, accelerometer1_temp, 0),
    PB_FIELD( 33, UINT32  , REQUIRED, STATIC  , OTHER, px4_hil_sensor_pb, magnetometer1_errcount, magnetometer1_ga, 0),
    PB_FIELD( 34, FLOAT   , REQUIRED, STATIC  , OTHER, px4_hil_sensor_pb, magnetometer1_temp, magnetometer1_errcount, 0),
    PB_FIELD( 35, FLOAT   , REPEATED, STATIC  , OTHER, px4_hil_sensor_pb, gyro2_rad_s, magnetometer1_temp, 0),
    PB_FIELD( 36, UINT32  , REQUIRED, STATIC  , OTHER, px4_hil_sensor_pb, gyro2_errcount, gyro2_rad_s, 0),
    PB_FIELD( 37, FLOAT   , REQUIRED, STATIC  , OTHER, px4_hil_sensor_pb, gyro2_temp, gyro2_errcount, 0),
    PB_FIELD( 38, FLOAT   , REPEATED, STATIC  , OTHER, px4_hil_sensor_pb, accelerometer2_m_s2, gyro2_temp, 0),
    PB_FIELD( 39, UINT32  , REQUIRED, STATIC  , OTHER, px4_hil_sensor_pb, accelerometer2_errcount, accelerometer2_m_s2, 0),
    PB_FIELD( 40, FLOAT   , REQUIRED, STATIC  , OTHER, px4_hil_sensor_pb, accelerometer2_temp, accelerometer2_errcount, 0),
    PB_FIELD( 41, FLOAT   , REPEATED, STATIC  , OTHER, px4_hil_sensor_pb, magnetometer2_ga, accelerometer2_temp, 0),
    PB_FIELD( 42, UINT32  , REQUIRED, STATIC  , OTHER, px4_hil_sensor_pb, magnetometer2_errcount, magnetometer2_ga, 0),
    PB_FIELD( 43, FLOAT   , REQUIRED, STATIC  , OTHER, px4_hil_sensor_pb, magnetometer2_temp, magnetometer2_errcount, 0),
    PB_FIELD( 44, FLOAT   , REQUIRED, STATIC  , OTHER, px4_hil_sensor_pb, baro_pres_mbar, magnetometer2_temp, 0),
    PB_FIELD( 45, FLOAT   , REQUIRED, STATIC  , OTHER, px4_hil_sensor_pb, baro_alt_meter, baro_pres_mbar, 0),
    PB_FIELD( 46, FLOAT   , REQUIRED, STATIC  , OTHER, px4_hil_sensor_pb, baro_temp_celcius, baro_alt_meter, 0),
    PB_FIELD( 47, FLOAT   , REQUIRED, STATIC  , OTHER, px4_hil_sensor_pb, baro1_pres_mbar, baro_temp_celcius, 0),
    PB_FIELD( 48, FLOAT   , REQUIRED, STATIC  , OTHER, px4_hil_sensor_pb, baro1_alt_meter, baro1_pres_mbar, 0),
    PB_FIELD( 49, FLOAT   , REQUIRED, STATIC  , OTHER, px4_hil_sensor_pb, baro1_temp_celcius, baro1_alt_meter, 0),
    PB_FIELD( 50, FLOAT   , REPEATED, STATIC  , OTHER, px4_hil_sensor_pb, adc_voltage_v, baro1_temp_celcius, 0),
    PB_FIELD( 51, FLOAT   , REQUIRED, STATIC  , OTHER, px4_hil_sensor_pb, mcu_temp_celcius, adc_voltage_v, 0),
    PB_FIELD( 52, FLOAT   , REQUIRED, STATIC  , OTHER, px4_hil_sensor_pb, differential_pressure_pa, mcu_temp_celcius, 0),
    PB_FIELD( 53, FLOAT   , REQUIRED, STATIC  , OTHER, px4_hil_sensor_pb, differential_pressure_filtered_pa, differential_pressure_pa, 0),
    PB_FIELD( 54, FLOAT   , REQUIRED, STATIC  , OTHER, px4_hil_sensor_pb, differential_pressure1_pa, differential_pressure_filtered_pa, 0),
    PB_FIELD( 55, FLOAT   , REQUIRED, STATIC  , OTHER, px4_hil_sensor_pb, differential_pressure1_filtered_pa, differential_pressure1_pa, 0),
    PB_FIELD( 56, INT32   , REPEATED, STATIC  , OTHER, px4_hil_sensor_pb, gyro_raw, differential_pressure1_filtered_pa, 0),
    PB_FIELD( 57, INT32   , REPEATED, STATIC  , OTHER, px4_hil_sensor_pb, accelerometer_raw, gyro_raw, 0),
    PB_FIELD( 58, INT32   , REQUIRED, STATIC  , OTHER, px4_hil_sensor_pb, accelerometer_mode, accelerometer_raw, 0),
    PB_FIELD( 59, INT32   , REPEATED, STATIC  , OTHER, px4_hil_sensor_pb, magnetometer_raw, accelerometer_mode, 0),
    PB_FIELD( 60, INT32   , REQUIRED, STATIC  , OTHER, px4_hil_sensor_pb, magnetometer_mode, magnetometer_raw, 0),
    PB_FIELD( 61, INT32   , REPEATED, STATIC  , OTHER, px4_hil_sensor_pb, gyro1_raw, magnetometer_mode, 0),
    PB_FIELD( 62, INT32   , REPEATED, STATIC  , OTHER, px4_hil_sensor_pb, accelerometer1_raw, gyro1_raw, 0),
    PB_FIELD( 63, INT32   , REPEATED, STATIC  , OTHER, px4_hil_sensor_pb, magnetometer1_raw, accelerometer1_raw, 0),
    PB_FIELD( 64, INT32   , REPEATED, STATIC  , OTHER, px4_hil_sensor_pb, gyro2_raw, magnetometer1_raw, 0),
    PB_FIELD( 65, INT32   , REPEATED, STATIC  , OTHER, px4_hil_sensor_pb, accelerometer2_raw, gyro2_raw, 0),
    PB_FIELD( 66, INT32   , REPEATED, STATIC  , OTHER, px4_hil_sensor_pb, magnetometer2_raw, accelerometer2_raw, 0),
    PB_FIELD( 67, UINT32  , REPEATED, STATIC  , OTHER, px4_hil_sensor_pb, adc_mapping, magnetometer2_raw, 0),
    PB_LAST_FIELD
};


/* @@protoc_insertion_point(eof) */
