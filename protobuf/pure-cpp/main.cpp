#include "protocol.h"
#include <iostream>

using namespace std;

void printLoginReq(const LoginReq& req)
{
    cout << req.user << endl
        << req.token << endl
        << req.unix_time << endl
        << req.lang << endl
        << req.client_os << endl
        << req.app_version << endl
        ;
}


int main()
{
    LoginReq req;
    req.user = "user001";
    req.token = "pnyuza0h2cdkvxvh54v3dn";
    req.unix_time = 1615004452;
    req.lang = "zh-CN";
    req.client_os = "Windows 10";
    req.app_version = "1.0.1";
    printLoginReq(req);

    Buffer buf;
    req.encodeTo(buf);
    LoginReq req2;
    int pos = 0;
    req2.decodeFrom(buf, pos);
    cout << "after decode:" << endl;
    printLoginReq(req2);
    
    
    return 0;
}
