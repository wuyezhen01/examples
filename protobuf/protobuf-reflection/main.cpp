#include "msg_api.h"
#include <iostream>

using namespace std;

// 使用反射
void test_reflection()
{
    initProtoRegistry("message.proto");

    protocol::LoginReq req;
    req.set_user("user001");
    req.set_token("pnyuza0h2cdkvxvh54v3dn");
    req.set_unix_time(1615004452);
    req.set_language("zh-CN");
    req.set_client_os("Windows 10");
    req.set_app_version("1.0.1");
    cout << req.DebugString() << endl;

    auto bytes = req.SerializeAsString();

    uint32_t msgId = getMessageID(&req);
    auto msg = (protocol::LoginReq*)createMessage(msgId);
    if (msg != nullptr)
    {
        msg->ParseFromArray(bytes.data(), bytes.size());
        cout << req.DebugString() << endl;
    }
}

// 使用MessageOption
void test_msg_option()
{
    initProtoRegistryV2("message.proto");

    protocol::LoginReq req;
    req.set_user("user001");
    req.set_token("pnyuza0h2cdkvxvh54v3dn");
    req.set_unix_time(1615004452);
    req.set_language("zh-CN");
    req.set_client_os("Windows 10");
    req.set_app_version("1.0.1");
    cout << req.DebugString() << endl;

    auto bytes = req.SerializeAsString();
    auto msg = (protocol::LoginReq*)createMessageV2(protocol::MSG_LOGIN_REQUEST);
    if (msg != nullptr)
    {
        msg->ParseFromArray(bytes.data(), bytes.size());
        cout << req.DebugString() << endl;
    }
}

int main(int argc, char* argv[])
{
    //test_reflection();
    test_msg_option();

    return 0;
}