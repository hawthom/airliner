# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: _py_SIMLIB_PressureAltitudeData_t.proto

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
  name='_py_SIMLIB_PressureAltitudeData_t.proto',
  package='',
  serialized_pb=_b('\n\'_py_SIMLIB_PressureAltitudeData_t.proto\"G\n SIMLIB_PressureAltitudeData_t_pb\x12\x10\n\x08\x41ltitude\x18\x01 \x02(\x02\x12\x11\n\tDataState\x18\x02 \x02(\r')
)
_sym_db.RegisterFileDescriptor(DESCRIPTOR)




_SIMLIB_PRESSUREALTITUDEDATA_T_PB = _descriptor.Descriptor(
  name='SIMLIB_PressureAltitudeData_t_pb',
  full_name='SIMLIB_PressureAltitudeData_t_pb',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='Altitude', full_name='SIMLIB_PressureAltitudeData_t_pb.Altitude', index=0,
      number=1, type=2, cpp_type=6, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='DataState', full_name='SIMLIB_PressureAltitudeData_t_pb.DataState', index=1,
      number=2, type=13, cpp_type=3, label=2,
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
  serialized_start=43,
  serialized_end=114,
)

DESCRIPTOR.message_types_by_name['SIMLIB_PressureAltitudeData_t_pb'] = _SIMLIB_PRESSUREALTITUDEDATA_T_PB

SIMLIB_PressureAltitudeData_t_pb = _reflection.GeneratedProtocolMessageType('SIMLIB_PressureAltitudeData_t_pb', (_message.Message,), dict(
  DESCRIPTOR = _SIMLIB_PRESSUREALTITUDEDATA_T_PB,
  __module__ = '_py_SIMLIB_PressureAltitudeData_t_pb2'
  # @@protoc_insertion_point(class_scope:SIMLIB_PressureAltitudeData_t_pb)
  ))
_sym_db.RegisterMessage(SIMLIB_PressureAltitudeData_t_pb)


# @@protoc_insertion_point(module_scope)
