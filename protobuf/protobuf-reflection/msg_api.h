#pragma once

#include "message.pb.h"
#include <vector>

typedef std::string Buffer;

// 使用反射
void initProtoRegistryV1();
uint32_t getMessageID(google::protobuf::Message*);
google::protobuf::Message* createMessage(uint32_t msgId);


// 使用MessageOption
void initProtoRegistryV2();
google::protobuf::Message* createMessageV2(protocol::MessageID msgId);
