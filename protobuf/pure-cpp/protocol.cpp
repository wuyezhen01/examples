#include "protocol.h"
#include <type_traits>
#include <algorithm>


// ��������
template <typename T>
typename std::enable_if <
    std::is_integral<T>::value
    || std::is_floating_point<T>::value,
    void>::type
encodeNumber(const T& number, Buffer& buf)
{
    size_t current = buf.size();
    buf.resize(current + sizeof(T));
    memcpy(&buf[current], &number, sizeof(T));
}

// ��������
template <typename T>
typename std::enable_if <
    std::is_integral<T>::value
    || std::is_floating_point<T>::value,
    void>::type
    decodeNumber(T* number, Buffer& buf, int& pos)
{
    int remain = (int)buf.size() - pos;
    if (remain <= 0) {
        return;
    }
    int size = std::min((int)sizeof(T), remain);
    memcpy(number, &buf[pos], size);
    pos += size;
}

// �����ַ���
static void encodeString(const std::string& s, Buffer& buf)
{
    encodeNumber(int32_t(s.length()), buf);
    size_t current = buf.size();
    buf.resize(current + s.length());
    memcpy(&buf[current], s.data(), s.length());
}

// �����ַ���
static void decodeString(std::string& s, Buffer& buf, int& pos)
{
    int32_t length = 0;
    decodeNumber(&length, buf, pos);
    s.resize(length);
    int remain = (int)buf.size() - pos;
    if (remain <= 0) {
        return;
    }
    int size = std::min((int)s.length(), remain);
    memcpy(&s[0], &buf[pos], size);
    pos += size;
}

// ����DisconnectNotify
void DisconnectNotify::encodeTo(Buffer& buf)
{
    encodeNumber(this->err_code, buf);
    encodeString(this->reason, buf);
}

void DisconnectNotify::decodeFrom(Buffer& buf, int& pos)
{
    decodeNumber(&this->err_code, buf, pos);
    decodeString(this->reason, buf, pos);
}

void LoginReq::encodeTo(Buffer& buf)
{
    encodeString(this->user, buf);
    encodeString(this->token, buf);
    encodeNumber(this->unix_time, buf);
    encodeString(this->lang, buf);
    encodeString(this->client_os, buf);
    encodeString(this->app_version, buf);
}

void LoginReq::decodeFrom(Buffer& buf, int& pos)
{
    decodeString(this->user, buf, pos);
    decodeString(this->token, buf, pos);
    decodeNumber(&this->unix_time, buf, pos);
    decodeString(this->lang, buf, pos);
    decodeString(this->client_os, buf, pos);
    decodeString(this->app_version, buf, pos);
}

void LoginAck::encodeTo(Buffer& buf)
{
    encodeNumber(this->err_code, buf);
    encodeString(this->access_token, buf);
    encodeNumber(this->session, buf);
}

void LoginAck::decodeFrom(Buffer& buf, int& pos)
{
    decodeNumber(&this->err_code, buf, pos);
    decodeString(this->access_token, buf, pos);
    decodeNumber(&this->session, buf, pos);
}

