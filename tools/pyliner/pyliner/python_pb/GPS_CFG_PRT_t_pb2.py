# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: _py_GPS_CFG_PRT_t.proto

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
  name='_py_GPS_CFG_PRT_t.proto',
  package='',
  serialized_pb=_b('\n\x17_py_GPS_CFG_PRT_t.proto\"\xb3\x01\n\x10GPS_CFG_PRT_t_pb\x12\x10\n\x08\x62\x61udRate\x18\x01 \x02(\r\x12\x0e\n\x06portID\x18\x02 \x02(\r\x12\x14\n\x0coutProtoMask\x18\x03 \x02(\r\x12\x0f\n\x07txReady\x18\x04 \x02(\r\x12\x0c\n\x04mode\x18\x05 \x02(\r\x12\r\n\x05\x66lags\x18\x06 \x02(\r\x12\x13\n\x0binProtoMask\x18\x07 \x02(\r\x12\x11\n\treserved1\x18\x08 \x02(\r\x12\x11\n\treserved2\x18\t \x02(\r')
)
_sym_db.RegisterFileDescriptor(DESCRIPTOR)




_GPS_CFG_PRT_T_PB = _descriptor.Descriptor(
  name='GPS_CFG_PRT_t_pb',
  full_name='GPS_CFG_PRT_t_pb',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='baudRate', full_name='GPS_CFG_PRT_t_pb.baudRate', index=0,
      number=1, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='portID', full_name='GPS_CFG_PRT_t_pb.portID', index=1,
      number=2, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='outProtoMask', full_name='GPS_CFG_PRT_t_pb.outProtoMask', index=2,
      number=3, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='txReady', full_name='GPS_CFG_PRT_t_pb.txReady', index=3,
      number=4, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='mode', full_name='GPS_CFG_PRT_t_pb.mode', index=4,
      number=5, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='flags', full_name='GPS_CFG_PRT_t_pb.flags', index=5,
      number=6, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='inProtoMask', full_name='GPS_CFG_PRT_t_pb.inProtoMask', index=6,
      number=7, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='reserved1', full_name='GPS_CFG_PRT_t_pb.reserved1', index=7,
      number=8, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='reserved2', full_name='GPS_CFG_PRT_t_pb.reserved2', index=8,
      number=9, type=13, cpp_type=3, label=2,
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
  serialized_start=28,
  serialized_end=207,
)

DESCRIPTOR.message_types_by_name['GPS_CFG_PRT_t_pb'] = _GPS_CFG_PRT_T_PB

GPS_CFG_PRT_t_pb = _reflection.GeneratedProtocolMessageType('GPS_CFG_PRT_t_pb', (_message.Message,), dict(
  DESCRIPTOR = _GPS_CFG_PRT_T_PB,
  __module__ = '_py_GPS_CFG_PRT_t_pb2'
  # @@protoc_insertion_point(class_scope:GPS_CFG_PRT_t_pb)
  ))
_sym_db.RegisterMessage(GPS_CFG_PRT_t_pb)


# @@protoc_insertion_point(module_scope)
