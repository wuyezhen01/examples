
#include "msg_api.h"
#include <unordered_map>

using namespace google::protobuf;
using namespace protocol;

static std::unordered_map<uint32_t, const Descriptor*> registry;


static bool endsWith(const std::string& name, const std::string& suffix)
{
    if (name.length() < suffix.length())
    {
        return false;
    }
    int j = name.length() - suffix.length();
    for (int i = 0; i < suffix.length() && j < name.length(); i++, j++)
    {
        if (name[j] != suffix[i])
            return false;
    }
    return true;
}

static uint32_t fnvHash(const std::string& name)
{
    uint32_t hash = (2166136261);
    for (int i = 0; i < name.length(); i++)
    {
        char ch = name[i];
        hash ^= uint32(ch);
        hash *= 16777619;
    }
    return hash;
}

// Req结尾代表请求
// Ack结尾代表响应
// Ntf结尾代表通知
void initProtoRegistry(const char* filename)
{
    const FileDescriptor* fileDescriptor = DescriptorPool::generated_pool()->FindFileByName(filename);
    if (fileDescriptor == nullptr)
    {
        return;
    }
    int msgcount = fileDescriptor->message_type_count();
    for (int i = 0; i < msgcount; i++)
    {
        const Descriptor* msgDescriptor = fileDescriptor->message_type(i);
        if (msgDescriptor != nullptr)
        {
            const std::string& name = msgDescriptor->name();
            if (endsWith(name, "Ntf") || endsWith(name, "Req") || endsWith(name, "Ack")) {
                uint32_t hash = fnvHash(name);
                registry[hash] = msgDescriptor;
            }
        }
    }
}

uint32_t getMessageID(google::protobuf::Message* message)
{
    const Descriptor* descriptor = message->GetDescriptor();
    if (descriptor != nullptr)
    {
        uint32_t hash = fnvHash(descriptor->name());
        return hash;
    }
    return 0;
}

google::protobuf::Message* createMessage(uint32_t msgId)
{
    uint32_t hash = msgId;
    auto iter = registry.find(hash);
    if (iter == registry.end()) 
    {
        return nullptr;
    }
    const Message* protoType = MessageFactory::generated_factory()->GetPrototype(iter->second);
    if (protoType != nullptr)
    {
        return protoType->New();
    }
    return nullptr;
}
