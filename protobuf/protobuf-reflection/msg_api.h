#pragma once

#include "message.pb.h"
#include <vector>

typedef std::string Buffer;

// ʹ�÷���
void initProtoRegistryV1();
uint32_t getMessageID(google::protobuf::Message*);
google::protobuf::Message* createMessage(uint32_t msgId);


// ʹ��MessageOption
void initProtoRegistryV2();
google::protobuf::Message* createMessageV2(protocol::MessageID msgId);
