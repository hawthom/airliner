# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: _py_CFE_ES_DumpCDSRegCmd_t.proto

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
  name='_py_CFE_ES_DumpCDSRegCmd_t.proto',
  package='',
  serialized_pb=_b('\n _py_CFE_ES_DumpCDSRegCmd_t.proto\"\x1c\n\x04\x63har\x12\x14\n\x0c\x44umpFilename\x18\x01 \x02(\t\"F\n\x19\x43\x46\x45_ES_DumpCDSRegCmd_t_pb\x12\x16\n\x07Payload\x18\x01 \x02(\x0b\x32\x05.char\x12\x11\n\tCmdHeader\x18\x02 \x03(\r')
)
_sym_db.RegisterFileDescriptor(DESCRIPTOR)




_CHAR = _descriptor.Descriptor(
  name='char',
  full_name='char',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='DumpFilename', full_name='char.DumpFilename', index=0,
      number=1, type=9, cpp_type=9, label=2,
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
  serialized_start=36,
  serialized_end=64,
)


_CFE_ES_DUMPCDSREGCMD_T_PB = _descriptor.Descriptor(
  name='CFE_ES_DumpCDSRegCmd_t_pb',
  full_name='CFE_ES_DumpCDSRegCmd_t_pb',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='Payload', full_name='CFE_ES_DumpCDSRegCmd_t_pb.Payload', index=0,
      number=1, type=11, cpp_type=10, label=2,
      has_default_value=False, default_value=None,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='CmdHeader', full_name='CFE_ES_DumpCDSRegCmd_t_pb.CmdHeader', index=1,
      number=2, type=13, cpp_type=3, label=3,
      has_default_value=False, default_value=[],
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
  serialized_start=66,
  serialized_end=136,
)

_CFE_ES_DUMPCDSREGCMD_T_PB.fields_by_name['Payload'].message_type = _CHAR
DESCRIPTOR.message_types_by_name['char'] = _CHAR
DESCRIPTOR.message_types_by_name['CFE_ES_DumpCDSRegCmd_t_pb'] = _CFE_ES_DUMPCDSREGCMD_T_PB

char = _reflection.GeneratedProtocolMessageType('char', (_message.Message,), dict(
  DESCRIPTOR = _CHAR,
  __module__ = '_py_CFE_ES_DumpCDSRegCmd_t_pb2'
  # @@protoc_insertion_point(class_scope:char)
  ))
_sym_db.RegisterMessage(char)

CFE_ES_DumpCDSRegCmd_t_pb = _reflection.GeneratedProtocolMessageType('CFE_ES_DumpCDSRegCmd_t_pb', (_message.Message,), dict(
  DESCRIPTOR = _CFE_ES_DUMPCDSREGCMD_T_PB,
  __module__ = '_py_CFE_ES_DumpCDSRegCmd_t_pb2'
  # @@protoc_insertion_point(class_scope:CFE_ES_DumpCDSRegCmd_t_pb)
  ))
_sym_db.RegisterMessage(CFE_ES_DumpCDSRegCmd_t_pb)


# @@protoc_insertion_point(module_scope)
