# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: _py_MD.proto

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
  name='_py_MD.proto',
  package='',
  serialized_pb=_b('\n\x0c_py_MD.proto\"\x81\x01\n\x05MD_pb\x12\x18\n\x10source_file_name\x18\x01 \x02(\t\x12\x11\n\tfile_size\x18\x02 \x02(\r\x12\x1c\n\x14segmentation_control\x18\x03 \x02(\t\x12\x15\n\rfile_transfer\x18\x04 \x02(\t\x12\x16\n\x0e\x64\x65st_file_name\x18\x05 \x02(\t')
)
_sym_db.RegisterFileDescriptor(DESCRIPTOR)




_MD_PB = _descriptor.Descriptor(
  name='MD_pb',
  full_name='MD_pb',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='source_file_name', full_name='MD_pb.source_file_name', index=0,
      number=1, type=9, cpp_type=9, label=2,
      has_default_value=False, default_value=_b("").decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='file_size', full_name='MD_pb.file_size', index=1,
      number=2, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='segmentation_control', full_name='MD_pb.segmentation_control', index=2,
      number=3, type=9, cpp_type=9, label=2,
      has_default_value=False, default_value=_b("").decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='file_transfer', full_name='MD_pb.file_transfer', index=3,
      number=4, type=9, cpp_type=9, label=2,
      has_default_value=False, default_value=_b("").decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='dest_file_name', full_name='MD_pb.dest_file_name', index=4,
      number=5, type=9, cpp_type=9, label=2,
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
  serialized_start=17,
  serialized_end=146,
)

DESCRIPTOR.message_types_by_name['MD_pb'] = _MD_PB

MD_pb = _reflection.GeneratedProtocolMessageType('MD_pb', (_message.Message,), dict(
  DESCRIPTOR = _MD_PB,
  __module__ = '_py_MD_pb2'
  # @@protoc_insertion_point(class_scope:MD_pb)
  ))
_sym_db.RegisterMessage(MD_pb)


# @@protoc_insertion_point(module_scope)
