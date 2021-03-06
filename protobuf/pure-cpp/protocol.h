#pragma once

#include <stdint.h>
#include <string>
#include <vector>


using std::string;
typedef std::vector<char> Buffer;


// 消息ID枚举
enum MessageID
{
    MSG_DISCONNECT_NOTIFY = 1000,
    MSG_LOGIN_REQUEST = 1001,
    MSG_LOGIN_REPLY = 1002,
};

// 下线通知
struct DisconnectNotify
{
    int32_t err_code;   // 错误码
    string reason;      // 原因(重复登录或者被踢下线)

    // 编解码
    void encodeTo(Buffer& buf);
    void decodeFrom(Buffer& buf, int& pos);
};


// 登录请求
struct LoginReq
{
    string user;            // 账号
    string token;           // 令牌
    int64_t unix_time;      // 时间戳
    string lang;            // 区域和语言
    string client_os;       // iOS, Android, Web
    string app_version;     // 客户端版本

    // 编解码
    void encodeTo(Buffer& buf);
    void decodeFrom(Buffer& buf, int& pos);
};

// 登录响应
struct LoginAck
{
    int32_t err_code;       // 错误码
    string access_token;    // 访问令牌
    int32_t session;        // 会话

    // 编解码
    void encodeTo(Buffer& buf);
    void decodeFrom(Buffer& buf, int& pos);
};


