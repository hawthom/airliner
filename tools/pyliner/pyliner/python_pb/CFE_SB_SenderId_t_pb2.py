# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: _py_CFE_SB_SenderId_t.proto

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
  name='_py_CFE_SB_SenderId_t.proto',
  package='',
  serialized_pb=_b('\n\x1b_py_CFE_SB_SenderId_t.proto\"<\n\x14\x43\x46\x45_SB_SenderId_t_pb\x12\x13\n\x0bProcessorId\x18\x01 \x02(\r\x12\x0f\n\x07\x41ppName\x18\x02 \x02(\t')
)
_sym_db.RegisterFileDescriptor(DESCRIPTOR)




_CFE_SB_SENDERID_T_PB = _descriptor.Descriptor(
  name='CFE_SB_SenderId_t_pb',
  full_name='CFE_SB_SenderId_t_pb',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='ProcessorId', full_name='CFE_SB_SenderId_t_pb.ProcessorId', index=0,
      number=1, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='AppName', full_name='CFE_SB_SenderId_t_pb.AppName', index=1,
      number=2, type=9, cpp_type=9, label=2,
      has_default_value=False, default_value=_b("").decode('utf-8'),
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
  serialized_start=31,
  serialized_end=91,
)

DESCRIPTOR.message_types_by_name['CFE_SB_SenderId_t_pb'] = _CFE_SB_SENDERID_T_PB

CFE_SB_SenderId_t_pb = _reflection.GeneratedProtocolMessageType('CFE_SB_SenderId_t_pb', (_message.Message,), dict(
  DESCRIPTOR = _CFE_SB_SENDERID_T_PB,
  __module__ = '_py_CFE_SB_SenderId_t_pb2'
  # @@protoc_insertion_point(class_scope:CFE_SB_SenderId_t_pb)
  ))
_sym_db.RegisterMessage(CFE_SB_SenderId_t_pb)


# @@protoc_insertion_point(module_scope)