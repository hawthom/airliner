# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: _py_CFE_EVS_TlmPkt_t.proto

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
  name='_py_CFE_EVS_TlmPkt_t.proto',
  package='',
  serialized_pb=_b('\n\x1a_py_CFE_EVS_TlmPkt_t.proto\"\x89\x03\n\x1b\x43\x46\x45_EVS_TlmPkt_Payload_t_pb\x12\x12\n\nOutputPort\x18\x01 \x02(\r\x12\x19\n\x11MessageFormatMode\x18\x02 \x02(\r\x12\x16\n\x0e\x43ommandCounter\x18\x03 \x02(\r\x12\x0e\n\x06Spare1\x18\x04 \x02(\r\x12)\n\x07\x41ppData\x18\x05 \x03(\x0b\x32\x18.CFE_EVS_AppTlmData_t_pb\x12\x0e\n\x06Spare3\x18\x06 \x02(\r\x12\x0e\n\x06Spare2\x18\x07 \x02(\r\x12\x1b\n\x13MessageTruncCounter\x18\x08 \x02(\r\x12\x1e\n\x16UnregisteredAppCounter\x18\t \x02(\r\x12\x0f\n\x07LogMode\x18\n \x02(\r\x12\x1a\n\x12LogOverflowCounter\x18\x0b \x02(\r\x12\x1a\n\x12MessageSendCounter\x18\x0c \x02(\r\x12\x13\n\x0bLogFullFlag\x18\r \x02(\r\x12\x19\n\x11\x43ommandErrCounter\x18\x0e \x02(\r\x12\x12\n\nLogEnabled\x18\x0f \x02(\r\"q\n\x17\x43\x46\x45_EVS_AppTlmData_t_pb\x12\x0f\n\x07Padding\x18\x01 \x02(\r\x12\x1d\n\x15\x41ppMessageSentCounter\x18\x02 \x02(\r\x12\x17\n\x0f\x41ppEnableStatus\x18\x03 \x02(\r\x12\r\n\x05\x41ppID\x18\x04 \x02(\r\"W\n\x13\x43\x46\x45_EVS_TlmPkt_t_pb\x12\x11\n\tTlmHeader\x18\x01 \x03(\r\x12-\n\x07Payload\x18\x02 \x02(\x0b\x32\x1c.CFE_EVS_TlmPkt_Payload_t_pb')
)
_sym_db.RegisterFileDescriptor(DESCRIPTOR)




_CFE_EVS_TLMPKT_PAYLOAD_T_PB = _descriptor.Descriptor(
  name='CFE_EVS_TlmPkt_Payload_t_pb',
  full_name='CFE_EVS_TlmPkt_Payload_t_pb',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='OutputPort', full_name='CFE_EVS_TlmPkt_Payload_t_pb.OutputPort', index=0,
      number=1, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='MessageFormatMode', full_name='CFE_EVS_TlmPkt_Payload_t_pb.MessageFormatMode', index=1,
      number=2, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='CommandCounter', full_name='CFE_EVS_TlmPkt_Payload_t_pb.CommandCounter', index=2,
      number=3, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='Spare1', full_name='CFE_EVS_TlmPkt_Payload_t_pb.Spare1', index=3,
      number=4, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='AppData', full_name='CFE_EVS_TlmPkt_Payload_t_pb.AppData', index=4,
      number=5, type=11, cpp_type=10, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='Spare3', full_name='CFE_EVS_TlmPkt_Payload_t_pb.Spare3', index=5,
      number=6, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='Spare2', full_name='CFE_EVS_TlmPkt_Payload_t_pb.Spare2', index=6,
      number=7, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='MessageTruncCounter', full_name='CFE_EVS_TlmPkt_Payload_t_pb.MessageTruncCounter', index=7,
      number=8, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='UnregisteredAppCounter', full_name='CFE_EVS_TlmPkt_Payload_t_pb.UnregisteredAppCounter', index=8,
      number=9, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='LogMode', full_name='CFE_EVS_TlmPkt_Payload_t_pb.LogMode', index=9,
      number=10, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='LogOverflowCounter', full_name='CFE_EVS_TlmPkt_Payload_t_pb.LogOverflowCounter', index=10,
      number=11, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='MessageSendCounter', full_name='CFE_EVS_TlmPkt_Payload_t_pb.MessageSendCounter', index=11,
      number=12, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='LogFullFlag', full_name='CFE_EVS_TlmPkt_Payload_t_pb.LogFullFlag', index=12,
      number=13, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='CommandErrCounter', full_name='CFE_EVS_TlmPkt_Payload_t_pb.CommandErrCounter', index=13,
      number=14, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='LogEnabled', full_name='CFE_EVS_TlmPkt_Payload_t_pb.LogEnabled', index=14,
      number=15, type=13, cpp_type=3, label=2,
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
  serialized_start=31,
  serialized_end=424,
)


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
  serialized_start=426,
  serialized_end=539,
)


_CFE_EVS_TLMPKT_T_PB = _descriptor.Descriptor(
  name='CFE_EVS_TlmPkt_t_pb',
  full_name='CFE_EVS_TlmPkt_t_pb',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='TlmHeader', full_name='CFE_EVS_TlmPkt_t_pb.TlmHeader', index=0,
      number=1, type=13, cpp_type=3, label=3,
      has_default_value=False, default_value=[],
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='Payload', full_name='CFE_EVS_TlmPkt_t_pb.Payload', index=1,
      number=2, type=11, cpp_type=10, label=2,
      has_default_value=False, default_value=None,
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
  serialized_start=541,
  serialized_end=628,
)

_CFE_EVS_TLMPKT_PAYLOAD_T_PB.fields_by_name['AppData'].message_type = _CFE_EVS_APPTLMDATA_T_PB
_CFE_EVS_TLMPKT_T_PB.fields_by_name['Payload'].message_type = _CFE_EVS_TLMPKT_PAYLOAD_T_PB
DESCRIPTOR.message_types_by_name['CFE_EVS_TlmPkt_Payload_t_pb'] = _CFE_EVS_TLMPKT_PAYLOAD_T_PB
DESCRIPTOR.message_types_by_name['CFE_EVS_AppTlmData_t_pb'] = _CFE_EVS_APPTLMDATA_T_PB
DESCRIPTOR.message_types_by_name['CFE_EVS_TlmPkt_t_pb'] = _CFE_EVS_TLMPKT_T_PB

CFE_EVS_TlmPkt_Payload_t_pb = _reflection.GeneratedProtocolMessageType('CFE_EVS_TlmPkt_Payload_t_pb', (_message.Message,), dict(
  DESCRIPTOR = _CFE_EVS_TLMPKT_PAYLOAD_T_PB,
  __module__ = '_py_CFE_EVS_TlmPkt_t_pb2'
  # @@protoc_insertion_point(class_scope:CFE_EVS_TlmPkt_Payload_t_pb)
  ))
_sym_db.RegisterMessage(CFE_EVS_TlmPkt_Payload_t_pb)

CFE_EVS_AppTlmData_t_pb = _reflection.GeneratedProtocolMessageType('CFE_EVS_AppTlmData_t_pb', (_message.Message,), dict(
  DESCRIPTOR = _CFE_EVS_APPTLMDATA_T_PB,
  __module__ = '_py_CFE_EVS_TlmPkt_t_pb2'
  # @@protoc_insertion_point(class_scope:CFE_EVS_AppTlmData_t_pb)
  ))
_sym_db.RegisterMessage(CFE_EVS_AppTlmData_t_pb)

CFE_EVS_TlmPkt_t_pb = _reflection.GeneratedProtocolMessageType('CFE_EVS_TlmPkt_t_pb', (_message.Message,), dict(
  DESCRIPTOR = _CFE_EVS_TLMPKT_T_PB,
  __module__ = '_py_CFE_EVS_TlmPkt_t_pb2'
  # @@protoc_insertion_point(class_scope:CFE_EVS_TlmPkt_t_pb)
  ))
_sym_db.RegisterMessage(CFE_EVS_TlmPkt_t_pb)


# @@protoc_insertion_point(module_scope)
