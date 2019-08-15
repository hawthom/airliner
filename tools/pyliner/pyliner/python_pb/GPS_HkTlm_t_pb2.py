# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: _py_GPS_HkTlm_t.proto

import sys
_b=sys.version_info[0]<3 and (lambda x:x) or (lambda x:x.encode('latin1'))
from google.protobuf import descriptor as _descriptor
from google.protobuf import message as _message
from google.protobuf import reflection as _reflection
from google.protobuf import symbol_database as _symbol_database
from google.protobuf import descriptor_pb2
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()




DESCRIPTOR = _descriptor.FileDescriptor(
  name='_py_GPS_HkTlm_t.proto',
  package='',
  serialized_pb=_b('\n\x15_py_GPS_HkTlm_t.proto\"\xd6\x03\n\x1ePX4_VehicleGpsPositionMsg_t_pb\x12\x0f\n\x07\x46ixType\x18\x01 \x02(\r\x12\x16\n\x0eSatellitesUsed\x18\x02 \x02(\r\x12\x0b\n\x03Lon\x18\x03 \x02(\x05\x12\x11\n\tVel_d_m_s\x18\x04 \x02(\x02\x12\x0b\n\x03\x43OG\x18\x05 \x02(\x02\x12\x11\n\tSVariance\x18\x06 \x02(\x02\x12\x18\n\x10JammingIndicator\x18\x07 \x02(\x05\x12\x11\n\tTimestamp\x18\x08 \x02(\x04\x12\x13\n\x0bVelNedValid\x18\t \x02(\x08\x12\x11\n\tTlmHeader\x18\n \x03(\r\x12\x0b\n\x03Lat\x18\x0b \x02(\x05\x12\x0c\n\x04VDOP\x18\x0c \x02(\x02\x12\x0c\n\x04HDOP\x18\r \x02(\x02\x12\x1d\n\x15TimestampTimeRelative\x18\x0e \x02(\x05\x12\x11\n\tCVariance\x18\x0f \x02(\x02\x12\x13\n\x0bTimeUtcUsec\x18\x10 \x02(\x04\x12\x14\n\x0c\x41ltEllipsoid\x18\x11 \x02(\x05\x12\x12\n\nNoisePerMs\x18\x12 \x02(\x05\x12\x0b\n\x03\x45pV\x18\x13 \x02(\x02\x12\x11\n\tVel_n_m_s\x18\x14 \x02(\x02\x12\x0f\n\x07Vel_m_s\x18\x15 \x02(\x02\x12\x0b\n\x03\x45pH\x18\x16 \x02(\x02\x12\x0b\n\x03\x41lt\x18\x17 \x02(\x05\x12\x11\n\tVel_e_m_s\x18\x18 \x02(\x02\"\x91\x01\n\x0eGPS_HkTlm_t_pb\x12\x10\n\x08usCmdCnt\x18\x01 \x02(\r\x12\x36\n\rVehicleGpsMsg\x18\x02 \x02(\x0b\x32\x1f.PX4_VehicleGpsPositionMsg_t_pb\x12\x11\n\tTlmHeader\x18\x03 \x03(\r\x12\r\n\x05State\x18\x04 \x02(\r\x12\x13\n\x0busCmdErrCnt\x18\x05 \x02(\r')
)
_sym_db.RegisterFileDescriptor(DESCRIPTOR)




_PX4_VEHICLEGPSPOSITIONMSG_T_PB = _descriptor.Descriptor(
  name='PX4_VehicleGpsPositionMsg_t_pb',
  full_name='PX4_VehicleGpsPositionMsg_t_pb',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='FixType', full_name='PX4_VehicleGpsPositionMsg_t_pb.FixType', index=0,
      number=1, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='SatellitesUsed', full_name='PX4_VehicleGpsPositionMsg_t_pb.SatellitesUsed', index=1,
      number=2, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='Lon', full_name='PX4_VehicleGpsPositionMsg_t_pb.Lon', index=2,
      number=3, type=5, cpp_type=1, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='Vel_d_m_s', full_name='PX4_VehicleGpsPositionMsg_t_pb.Vel_d_m_s', index=3,
      number=4, type=2, cpp_type=6, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='COG', full_name='PX4_VehicleGpsPositionMsg_t_pb.COG', index=4,
      number=5, type=2, cpp_type=6, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='SVariance', full_name='PX4_VehicleGpsPositionMsg_t_pb.SVariance', index=5,
      number=6, type=2, cpp_type=6, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='JammingIndicator', full_name='PX4_VehicleGpsPositionMsg_t_pb.JammingIndicator', index=6,
      number=7, type=5, cpp_type=1, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='Timestamp', full_name='PX4_VehicleGpsPositionMsg_t_pb.Timestamp', index=7,
      number=8, type=4, cpp_type=4, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='VelNedValid', full_name='PX4_VehicleGpsPositionMsg_t_pb.VelNedValid', index=8,
      number=9, type=8, cpp_type=7, label=2,
      has_default_value=False, default_value=False,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='TlmHeader', full_name='PX4_VehicleGpsPositionMsg_t_pb.TlmHeader', index=9,
      number=10, type=13, cpp_type=3, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='Lat', full_name='PX4_VehicleGpsPositionMsg_t_pb.Lat', index=10,
      number=11, type=5, cpp_type=1, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='VDOP', full_name='PX4_VehicleGpsPositionMsg_t_pb.VDOP', index=11,
      number=12, type=2, cpp_type=6, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='HDOP', full_name='PX4_VehicleGpsPositionMsg_t_pb.HDOP', index=12,
      number=13, type=2, cpp_type=6, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='TimestampTimeRelative', full_name='PX4_VehicleGpsPositionMsg_t_pb.TimestampTimeRelative', index=13,
      number=14, type=5, cpp_type=1, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='CVariance', full_name='PX4_VehicleGpsPositionMsg_t_pb.CVariance', index=14,
      number=15, type=2, cpp_type=6, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='TimeUtcUsec', full_name='PX4_VehicleGpsPositionMsg_t_pb.TimeUtcUsec', index=15,
      number=16, type=4, cpp_type=4, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='AltEllipsoid', full_name='PX4_VehicleGpsPositionMsg_t_pb.AltEllipsoid', index=16,
      number=17, type=5, cpp_type=1, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='NoisePerMs', full_name='PX4_VehicleGpsPositionMsg_t_pb.NoisePerMs', index=17,
      number=18, type=5, cpp_type=1, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='EpV', full_name='PX4_VehicleGpsPositionMsg_t_pb.EpV', index=18,
      number=19, type=2, cpp_type=6, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='Vel_n_m_s', full_name='PX4_VehicleGpsPositionMsg_t_pb.Vel_n_m_s', index=19,
      number=20, type=2, cpp_type=6, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='Vel_m_s', full_name='PX4_VehicleGpsPositionMsg_t_pb.Vel_m_s', index=20,
      number=21, type=2, cpp_type=6, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='EpH', full_name='PX4_VehicleGpsPositionMsg_t_pb.EpH', index=21,
      number=22, type=2, cpp_type=6, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='Alt', full_name='PX4_VehicleGpsPositionMsg_t_pb.Alt', index=22,
      number=23, type=5, cpp_type=1, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='Vel_e_m_s', full_name='PX4_VehicleGpsPositionMsg_t_pb.Vel_e_m_s', index=23,
      number=24, type=2, cpp_type=6, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=26,
  serialized_end=496,
)


_GPS_HKTLM_T_PB = _descriptor.Descriptor(
  name='GPS_HkTlm_t_pb',
  full_name='GPS_HkTlm_t_pb',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='usCmdCnt', full_name='GPS_HkTlm_t_pb.usCmdCnt', index=0,
      number=1, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='VehicleGpsMsg', full_name='GPS_HkTlm_t_pb.VehicleGpsMsg', index=1,
      number=2, type=11, cpp_type=10, label=2,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='TlmHeader', full_name='GPS_HkTlm_t_pb.TlmHeader', index=2,
      number=3, type=13, cpp_type=3, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='State', full_name='GPS_HkTlm_t_pb.State', index=3,
      number=4, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='usCmdErrCnt', full_name='GPS_HkTlm_t_pb.usCmdErrCnt', index=4,
      number=5, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
  ],
  extensions=[
  ],
  nested_types=[],
  enum_types=[
  ],
  options=None,
  is_extendable=False,
  extension_ranges=[],
  oneofs=[
  ],
  serialized_start=499,
  serialized_end=644,
)

_GPS_HKTLM_T_PB.fields_by_name['VehicleGpsMsg'].message_type = _PX4_VEHICLEGPSPOSITIONMSG_T_PB
DESCRIPTOR.message_types_by_name['PX4_VehicleGpsPositionMsg_t_pb'] = _PX4_VEHICLEGPSPOSITIONMSG_T_PB
DESCRIPTOR.message_types_by_name['GPS_HkTlm_t_pb'] = _GPS_HKTLM_T_PB

PX4_VehicleGpsPositionMsg_t_pb = _reflection.GeneratedProtocolMessageType('PX4_VehicleGpsPositionMsg_t_pb', (_message.Message,), dict(
  DESCRIPTOR = _PX4_VEHICLEGPSPOSITIONMSG_T_PB,
  __module__ = '_py_GPS_HkTlm_t_pb2'
  # @@protoc_insertion_point(class_scope:PX4_VehicleGpsPositionMsg_t_pb)
  ))
_sym_db.RegisterMessage(PX4_VehicleGpsPositionMsg_t_pb)

GPS_HkTlm_t_pb = _reflection.GeneratedProtocolMessageType('GPS_HkTlm_t_pb', (_message.Message,), dict(
  DESCRIPTOR = _GPS_HKTLM_T_PB,
  __module__ = '_py_GPS_HkTlm_t_pb2'
  # @@protoc_insertion_point(class_scope:GPS_HkTlm_t_pb)
  ))
_sym_db.RegisterMessage(GPS_HkTlm_t_pb)


# @@protoc_insertion_point(module_scope)
