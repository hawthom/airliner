# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: _py_FM_DirListFileStats_t.proto

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
  name='_py_FM_DirListFileStats_t.proto',
  package='',
  serialized_pb=_b('\n\x1f_py_FM_DirListFileStats_t.proto\"T\n\x18\x46M_DirListFileStats_t_pb\x12\x13\n\x0b\x46ileEntries\x18\x01 \x02(\r\x12\x0f\n\x07\x44irName\x18\x02 \x02(\t\x12\x12\n\nDirEntries\x18\x03 \x02(\r')
)
_sym_db.RegisterFileDescriptor(DESCRIPTOR)




_FM_DIRLISTFILESTATS_T_PB = _descriptor.Descriptor(
  name='FM_DirListFileStats_t_pb',
  full_name='FM_DirListFileStats_t_pb',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='FileEntries', full_name='FM_DirListFileStats_t_pb.FileEntries', index=0,
      number=1, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='DirName', full_name='FM_DirListFileStats_t_pb.DirName', index=1,
      number=2, type=9, cpp_type=9, label=2,
      has_default_value=False, default_value=_b("").decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='DirEntries', full_name='FM_DirListFileStats_t_pb.DirEntries', index=2,
      number=3, type=13, cpp_type=3, label=2,
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
  serialized_start=35,
  serialized_end=119,
)

DESCRIPTOR.message_types_by_name['FM_DirListFileStats_t_pb'] = _FM_DIRLISTFILESTATS_T_PB

FM_DirListFileStats_t_pb = _reflection.GeneratedProtocolMessageType('FM_DirListFileStats_t_pb', (_message.Message,), dict(
  DESCRIPTOR = _FM_DIRLISTFILESTATS_T_PB,
  __module__ = '_py_FM_DirListFileStats_t_pb2'
  # @@protoc_insertion_point(class_scope:FM_DirListFileStats_t_pb)
  ))
_sym_db.RegisterMessage(FM_DirListFileStats_t_pb)


# @@protoc_insertion_point(module_scope)
