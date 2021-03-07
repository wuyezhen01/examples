#pragma once

#include "message.pb.h"
#include <vector>

typedef std::string Buffer;

// ʹ�÷���
void initProtoRegistry(const char* filename);
uint32_t getMessageID(google::protobuf::Message*);
google::protobuf::Message* createMessage(uint32_t msgId);


// ʹ��MessageOption
void initProtoRegistryV2(const char* filename);
google::protobuf::Message* createMessageV2(protocol::MessageID msgId);
