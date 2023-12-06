#ifndef UDP_SOCKET_H
#define UDP_SOCKET_H

#include <vector>
#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
class UdpSocket {
public:
    UdpSocket(int port);
    ~UdpSocket();

    // 初始化发送目标地址和端口
    void InitSend(const std::string& destAddr, int destPort);

    // 设置发送目标地址和端口
    void SetDestination(const std::string& destAddr, int destPort);

    // 接收UDP数据
    std::vector<uint8_t> ReceiveData();

    // 发送UDP数据
    bool SendData(const std::vector<uint8_t>& data);

private:
    int socket_fd_;
    int port_;
    std::string destAddr_;
    int destPort_;
    sockaddr_in destSocketAddress_;
};

#endif // UDP_SOCKET_H
