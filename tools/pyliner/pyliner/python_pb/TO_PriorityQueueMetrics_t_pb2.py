# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: _py_TO_PriorityQueueMetrics_t.proto

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
  name='_py_TO_PriorityQueueMetrics_t.proto',
  package='',
  serialized_pb=_b('\n#_py_TO_PriorityQueueMetrics_t.proto\"\x93\x01\n\x1cTO_PriorityQueueMetrics_t_pb\x12\x1a\n\x12\x43urrentlyQueuedCnt\x18\x01 \x02(\r\x12\x13\n\x0bOSALQueueID\x18\x02 \x02(\r\x12\x14\n\x0cQueuedMsgCnt\x18\x03 \x02(\r\x12\x15\n\rHighwaterMark\x18\x04 \x02(\r\x12\x15\n\rDroppedMsgCnt\x18\x05 \x02(\r')
)
_sym_db.RegisterFileDescriptor(DESCRIPTOR)




_TO_PRIORITYQUEUEMETRICS_T_PB = _descriptor.Descriptor(
  name='TO_PriorityQueueMetrics_t_pb',
  full_name='TO_PriorityQueueMetrics_t_pb',
  filename=None,
  file=DESCRIPTOR,
  containing_type=None,
  fields=[
    _descriptor.FieldDescriptor(
      name='CurrentlyQueuedCnt', full_name='TO_PriorityQueueMetrics_t_pb.CurrentlyQueuedCnt', index=0,
      number=1, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='OSALQueueID', full_name='TO_PriorityQueueMetrics_t_pb.OSALQueueID', index=1,
      number=2, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='QueuedMsgCnt', full_name='TO_PriorityQueueMetrics_t_pb.QueuedMsgCnt', index=2,
      number=3, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='HighwaterMark', full_name='TO_PriorityQueueMetrics_t_pb.HighwaterMark', index=3,
      number=4, type=13, cpp_type=3, label=2,
      has_default_value=False, default_value=0,
      message_type=None, enum_type=None, containing_type=None,
      is_extension=False, extension_scope=None,
      options=None),
    _descriptor.FieldDescriptor(
      name='DroppedMsgCnt', full_name='TO_PriorityQueueMetrics_t_pb.DroppedMsgCnt', index=4,
      number=5, type=13, cpp_type=3, label=2,
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
  serialized_start=40,
  serialized_end=187,
)

DESCRIPTOR.message_types_by_name['TO_PriorityQueueMetrics_t_pb'] = _TO_PRIORITYQUEUEMETRICS_T_PB

TO_PriorityQueueMetrics_t_pb = _reflection.GeneratedProtocolMessageType('TO_PriorityQueueMetrics_t_pb', (_message.Message,), dict(
  DESCRIPTOR = _TO_PRIORITYQUEUEMETRICS_T_PB,
  __module__ = '_py_TO_PriorityQueueMetrics_t_pb2'
  # @@protoc_insertion_point(class_scope:TO_PriorityQueueMetrics_t_pb)
  ))
_sym_db.RegisterMessage(TO_PriorityQueueMetrics_t_pb)


# @@protoc_insertion_point(module_scope)
