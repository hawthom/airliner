# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: _py_CFE_EVS_AppTlmData_t.proto

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
  name='_py_CFE_EVS_AppTlmData_t.proto',
  package='',
  serialized_pb=_b('\n\x1e_py_CFE_EVS_AppTlmData_t.proto\"q\n\x17\x43\x46\x45_EVS_AppTlmData_t_pb\x12\x0f\n\x07Padding\x18\x01 \x02(\r\x12\x1d\n\x15\x41ppMessageSentCounter\x18\x02 \x02(\r\x12\x17\n\x0f\x41ppEnableStatus\x18\x03 \x02(\r\x12\r\n\x05\x41ppID\x18\x04 \x02(\r')
)
_sym_db.RegisterFileDescriptor(DESCRIPTOR)




_CFE_EVS_APPTLMDATA_T_PB = _descriptor.Descriptor(
  name='CFE_EVS_AppTlmData_t_pb',
  full_name='CFE_EVS_AppTlmData_t_pb',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='Padding', full_name='CFE_EVS_AppTlmData_t_pb.Padding', index=0,
      number=1, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='AppMessageSentCounter', full_name='CFE_EVS_AppTlmData_t_pb.AppMessageSentCounter', index=1,
      number=2, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='AppEnableStatus', full_name='CFE_EVS_AppTlmData_t_pb.AppEnableStatus', index=2,
      number=3, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='AppID', full_name='CFE_EVS_AppTlmData_t_pb.AppID', index=3,
      number=4, type=13, cpp_type=3, label=2,
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
  serialized_start=34,
  serialized_end=147,
)

DESCRIPTOR.message_types_by_name['CFE_EVS_AppTlmData_t_pb'] = _CFE_EVS_APPTLMDATA_T_PB

CFE_EVS_AppTlmData_t_pb = _reflection.GeneratedProtocolMessageType('CFE_EVS_AppTlmData_t_pb', (_message.Message,), dict(
  DESCRIPTOR = _CFE_EVS_APPTLMDATA_T_PB,
  __module__ = '_py_CFE_EVS_AppTlmData_t_pb2'
  # @@protoc_insertion_point(class_scope:CFE_EVS_AppTlmData_t_pb)
  ))
_sym_db.RegisterMessage(CFE_EVS_AppTlmData_t_pb)


# @@protoc_insertion_point(module_scope)
