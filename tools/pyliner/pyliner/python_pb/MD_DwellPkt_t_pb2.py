# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: _py_MD_DwellPkt_t.proto

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
  name='_py_MD_DwellPkt_t.proto',
  package='',
  serialized_pb=_b('\n\x17_py_MD_DwellPkt_t.proto\"\x8b\x01\n\x10MD_DwellPkt_t_pb\x12\x0c\n\x04Rate\x18\x01 \x02(\r\x12\x11\n\tAddrCount\x18\x02 \x02(\r\x12\x11\n\tByteCount\x18\x03 \x02(\r\x12\x11\n\tTlmHeader\x18\x04 \x03(\r\x12\x0f\n\x07TableId\x18\x05 \x02(\r\x12\x11\n\tSignature\x18\x06 \x02(\t\x12\x0c\n\x04\x44\x61ta\x18\x07 \x03(\r')
)
_sym_db.RegisterFileDescriptor(DESCRIPTOR)




_MD_DWELLPKT_T_PB = _descriptor.Descriptor(
  name='MD_DwellPkt_t_pb',
  full_name='MD_DwellPkt_t_pb',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='Rate', full_name='MD_DwellPkt_t_pb.Rate', index=0,
      number=1, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='AddrCount', full_name='MD_DwellPkt_t_pb.AddrCount', index=1,
      number=2, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='ByteCount', full_name='MD_DwellPkt_t_pb.ByteCount', index=2,
      number=3, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='TlmHeader', full_name='MD_DwellPkt_t_pb.TlmHeader', index=3,
      number=4, type=13, cpp_type=3, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='TableId', full_name='MD_DwellPkt_t_pb.TableId', index=4,
      number=5, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='Signature', full_name='MD_DwellPkt_t_pb.Signature', index=5,
      number=6, type=9, cpp_type=9, label=2,
      has_default_value=False, default_value=_b("").decode('utf-8'),
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='Data', full_name='MD_DwellPkt_t_pb.Data', index=6,
      number=7, type=13, cpp_type=3, label=3,
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
  serialized_start=28,
  serialized_end=167,
)

DESCRIPTOR.message_types_by_name['MD_DwellPkt_t_pb'] = _MD_DWELLPKT_T_PB

MD_DwellPkt_t_pb = _reflection.GeneratedProtocolMessageType('MD_DwellPkt_t_pb', (_message.Message,), dict(
  DESCRIPTOR = _MD_DWELLPKT_T_PB,
  __module__ = '_py_MD_DwellPkt_t_pb2'
  # @@protoc_insertion_point(class_scope:MD_DwellPkt_t_pb)
  ))
_sym_db.RegisterMessage(MD_DwellPkt_t_pb)


# @@protoc_insertion_point(module_scope)
