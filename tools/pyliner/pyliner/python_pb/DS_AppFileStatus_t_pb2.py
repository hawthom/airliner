# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: _py_DS_AppFileStatus_t.proto

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
  name='_py_DS_AppFileStatus_t.proto',
  package='',
  serialized_pb=_b('\n\x1c_py_DS_AppFileStatus_t.proto\"\xbc\x01\n\x15\x44S_AppFileStatus_t_pb\x12\x11\n\tFileState\x18\x01 \x02(\r\x12\x0f\n\x07\x46ileAge\x18\x02 \x02(\r\x12\x12\n\nFileGrowth\x18\x03 \x02(\r\x12\x10\n\x08\x46ileName\x18\x04 \x02(\t\x12\x0e\n\x06Unused\x18\x05 \x02(\r\x12\x10\n\x08\x46ileRate\x18\x06 \x02(\r\x12\x10\n\x08\x46ileSize\x18\x07 \x02(\r\x12\x12\n\nFileHandle\x18\x08 \x02(\x05\x12\x11\n\tFileCount\x18\t \x02(\r')
)
_sym_db.RegisterFileDescriptor(DESCRIPTOR)




_DS_APPFILESTATUS_T_PB = _descriptor.Descriptor(
  name='DS_AppFileStatus_t_pb',
  full_name='DS_AppFileStatus_t_pb',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='FileState', full_name='DS_AppFileStatus_t_pb.FileState', index=0,
      number=1, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='FileAge', full_name='DS_AppFileStatus_t_pb.FileAge', index=1,
      number=2, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='FileGrowth', full_name='DS_AppFileStatus_t_pb.FileGrowth', index=2,
      number=3, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='FileName', full_name='DS_AppFileStatus_t_pb.FileName', index=3,
      number=4, type=9, cpp_type=9, label=2,
      has_default_value=False, default_value=_b("").decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='Unused', full_name='DS_AppFileStatus_t_pb.Unused', index=4,
      number=5, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='FileRate', full_name='DS_AppFileStatus_t_pb.FileRate', index=5,
      number=6, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='FileSize', full_name='DS_AppFileStatus_t_pb.FileSize', index=6,
      number=7, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='FileHandle', full_name='DS_AppFileStatus_t_pb.FileHandle', index=7,
      number=8, type=5, cpp_type=1, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='FileCount', full_name='DS_AppFileStatus_t_pb.FileCount', index=8,
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
  serialized_start=33,
  serialized_end=221,
)

DESCRIPTOR.message_types_by_name['DS_AppFileStatus_t_pb'] = _DS_APPFILESTATUS_T_PB

DS_AppFileStatus_t_pb = _reflection.GeneratedProtocolMessageType('DS_AppFileStatus_t_pb', (_message.Message,), dict(
  DESCRIPTOR = _DS_APPFILESTATUS_T_PB,
  __module__ = '_py_DS_AppFileStatus_t_pb2'
  # @@protoc_insertion_point(class_scope:DS_AppFileStatus_t_pb)
  ))
_sym_db.RegisterMessage(DS_AppFileStatus_t_pb)


# @@protoc_insertion_point(module_scope)
