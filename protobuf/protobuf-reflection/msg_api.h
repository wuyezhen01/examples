#pragma once

#include "message.pb.h"
#include <vector>

typedef std::string Buffer;

void initProtoRegistry(const char* filename);

//  π”√∑¥…‰
uint32_t getMessageID(google::protobuf::Message*);
google::protobuf::Message* createMessage(uint32_t msgId);
