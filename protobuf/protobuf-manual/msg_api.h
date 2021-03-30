#pragma once

#include "message.pb.h"
#include <vector>

typedef std::string Buffer;

// 通过message名称的hash
google::protobuf::Message* parseMessageV1(protocol::MessageID msgid, Buffer& buf);

// 通过message指定的option
google::protobuf::Message* parseMessageV2(protocol::MessageID msgid, Buffer& buf);
