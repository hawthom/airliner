# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: _py_CF_AppTransStat_t.proto

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
  name='_py_CF_AppTransStat_t.proto',
  package='',
  serialized_pb=_b('\n\x1b_py_CF_AppTransStat_t.proto\"\xd5\x01\n\x14\x43\x46_AppTransStat_t_pb\x12\x0f\n\x07\x44stFile\x18\x01 \x02(\t\x12\x0e\n\x06Status\x18\x02 \x02(\r\x12\x10\n\x08NodeType\x18\x03 \x02(\r\x12\x0f\n\x07SrcFile\x18\x04 \x02(\t\x12\x0f\n\x07\x43hanNum\x18\x05 \x02(\r\x12\x10\n\x08Priority\x18\x06 \x02(\r\x12\x0e\n\x06Source\x18\x07 \x02(\r\x12\x13\n\x0bSrcEntityId\x18\x08 \x02(\t\x12\r\n\x05\x43lass\x18\t \x02(\r\x12\x10\n\x08TransNum\x18\n \x02(\r\x12\x10\n\x08\x43ondCode\x18\x0b \x02(\r')
)
_sym_db.RegisterFileDescriptor(DESCRIPTOR)




_CF_APPTRANSSTAT_T_PB = _descriptor.Descriptor(
  name='CF_AppTransStat_t_pb',
  full_name='CF_AppTransStat_t_pb',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='DstFile', full_name='CF_AppTransStat_t_pb.DstFile', index=0,
      number=1, type=9, cpp_type=9, label=2,
      has_default_value=False, default_value=_b("").decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='Status', full_name='CF_AppTransStat_t_pb.Status', index=1,
      number=2, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='NodeType', full_name='CF_AppTransStat_t_pb.NodeType', index=2,
      number=3, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='SrcFile', full_name='CF_AppTransStat_t_pb.SrcFile', index=3,
      number=4, type=9, cpp_type=9, label=2,
      has_default_value=False, default_value=_b("").decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='ChanNum', full_name='CF_AppTransStat_t_pb.ChanNum', index=4,
      number=5, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='Priority', full_name='CF_AppTransStat_t_pb.Priority', index=5,
      number=6, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='Source', full_name='CF_AppTransStat_t_pb.Source', index=6,
      number=7, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='SrcEntityId', full_name='CF_AppTransStat_t_pb.SrcEntityId', index=7,
      number=8, type=9, cpp_type=9, label=2,
      has_default_value=False, default_value=_b("").decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='Class', full_name='CF_AppTransStat_t_pb.Class', index=8,
      number=9, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='TransNum', full_name='CF_AppTransStat_t_pb.TransNum', index=9,
      number=10, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='CondCode', full_name='CF_AppTransStat_t_pb.CondCode', index=10,
      number=11, type=13, cpp_type=3, label=2,
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
  serialized_start=32,
  serialized_end=245,
)

DESCRIPTOR.message_types_by_name['CF_AppTransStat_t_pb'] = _CF_APPTRANSSTAT_T_PB

CF_AppTransStat_t_pb = _reflection.GeneratedProtocolMessageType('CF_AppTransStat_t_pb', (_message.Message,), dict(
  DESCRIPTOR = _CF_APPTRANSSTAT_T_PB,
  __module__ = '_py_CF_AppTransStat_t_pb2'
  # @@protoc_insertion_point(class_scope:CF_AppTransStat_t_pb)
  ))
_sym_db.RegisterMessage(CF_AppTransStat_t_pb)


# @@protoc_insertion_point(module_scope)
