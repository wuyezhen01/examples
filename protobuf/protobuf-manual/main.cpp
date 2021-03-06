
#include "msg_api.h"
#include <vector>
#include <iostream>


using namespace std;


int main()
{
    protocol::LoginReq req;
    req.set_user("user001");
    req.set_token("pnyuza0h2cdkvxvh54v3dn");
    req.set_unix_time(1615004452);
    req.set_language("zh-CN");
    req.set_client_os("Windows 10");
    req.set_app_version("1.0.1");
    cout << req.DebugString() << endl;

    Buffer bytes = req.SerializeAsString();
    // auto msg = parseMessageV1(protocol::MSG_LOGIN_REQUEST, bytes);
    auto msg = parseMessageV2(protocol::MSG_LOGIN_REQUEST, bytes);
    if (msg != nullptr)
    {
        cout << msg->DebugString() << endl;
    }
	return 0;
}

