#pragma once

#include "message.pb.h"
#include <vector>

typedef std::string Buffer;

google::protobuf::Message* parseMessageV1(protocol::MessageID msgid, Buffer& buf);

google::protobuf::Message* parseMessageV2(protocol::MessageID msgid, Buffer& buf);
