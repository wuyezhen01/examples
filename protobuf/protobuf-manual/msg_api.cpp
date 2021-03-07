
#include "msg_api.h"


using namespace google::protobuf;
using namespace protocol;


Message* parseMessageV1(MessageID msgid, Buffer& buf)
{
    Message* msg = nullptr;
    switch (msgid)
    {
    case MSG_DISCONNECT_NOTIFY:
        msg = new DisconnectNtf();
        break;
    case MSG_LOGIN_REQUEST:
        msg = new LoginReq();
        break;
    case MSG_LOGIN_REPLY:
        msg = new LoginAck();
        break;
    }
    if (msg->ParseFromArray(buf.data(), (int)buf.size()))
    {
        return msg;
    }
    delete msg;
    return nullptr;
}


// 使用宏映射消息ID和消息名称
#define GEN_MESSAGE_MAP(XX) \
	XX(MSG_DISCONNECT_NOTIFY, DisconnectNtf) \
	XX(MSG_LOGIN_REQUEST, LoginReq) \
	XX(MSG_LOGIN_REPLY, LoginAck) 


Message* createMessageBy(MessageID msgid)
{
    switch (msgid)
    {
#define XX(msgid, msgname) case msgid: return new msgname;
        GEN_MESSAGE_MAP(XX)
#undef XX
    };
    return nullptr;
}

Message* parseMessageV2(MessageID msgid, Buffer& buf)
{
    auto msg = createMessageBy(msgid);
    if (msg != nullptr)
    {
        if (msg->ParseFromArray(buf.data(), (int)buf.size()))
        {
            return msg;
        }
        delete msg;
    }
    return nullptr;
}
