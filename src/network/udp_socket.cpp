#include "udp_socket.h"
#include <iostream>
#include <cstring>


/**
 * @brief Constructor for UdpSocket.
 * @param port The port to listen for UDP data.
 */
UdpSocket::UdpSocket(int port) : socket_fd_(-1), port_(port) {
    // 创建 UDP 套接字
    socket_fd_ = socket(AF_INET, SOCK_DGRAM, 0);
    if (socket_fd_ == -1) {
        std::cerr << "Failed to create socket." << std::endl;
        return;
    }

    // 设置服务器地址结构体
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(port);

    // 将套接字与地址绑定
    if (bind(socket_fd_, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
        std::cerr << "Failed to bind socket." << std::endl;
        close(socket_fd_);
        return;
    }
}

/**
 * @brief Initialize the destination address and port for sending.
 * @param destAddr The destination IP address.
 * @param destPort The destination port.
 */
void UdpSocket::InitSend(const std::string& destAddr, int destPort) {
    // 初始化目标地址结构体
    destSocketAddress_.sin_family = AF_INET;
    destSocketAddress_.sin_addr.s_addr = inet_addr(destAddr.c_str());
    destSocketAddress_.sin_port = htons(destPort);
}

/**
 * @brief Receive UDP data.
 * @return A vector containing received data as uint8_t.
 */
std::vector<uint8_t> UdpSocket::ReceiveData() {
    // 创建一个缓冲区来存储接收到的数据
    std::vector<uint8_t> buffer(1024);
    sockaddr_in clientAddress;
    socklen_t clientAddressLen = sizeof(clientAddress);

    // 从套接字接收数据
    int bytesRead = recvfrom(socket_fd_, buffer.data(), buffer.size(), 0, (struct sockaddr*)&clientAddress, &clientAddressLen);
    if (bytesRead == -1) {
        std::cerr << "Failed to receive data." << std::endl;
        return std::vector<uint8_t>();
    }

    // 调整缓冲区的大小以匹配接收到的数据量
    buffer.resize(bytesRead);

    return buffer;
}

/**
 * @brief Send UDP data.
 * @param data The data to send as a vector of uint8_t.
 * @return True if the data is sent successfully, false otherwise.
 */
bool UdpSocket::SendData(const std::vector<uint8_t>& data) {
    int bytesSent = sendto(socket_fd_, data.data(), data.size(), 0, (struct sockaddr*)&destSocketAddress_, sizeof(destSocketAddress_));
    if (bytesSent == -1) {
        std::cerr << "Failed to send data." << std::endl;
        return false;
    }

    return true;
}

/**
 * @brief Destructor for UdpSocket.
 */
UdpSocket::~UdpSocket() {
    // 关闭套接字
    if (socket_fd_ != -1) {
        close(socket_fd_);
    }
}

/**
 * @brief Set the destination address and port.
 * @param destAddr The destination IP address.
 * @param destPort The destination port.
 */
void UdpSocket::SetDestination(const std::string& destAddr, int destPort) {
    destAddr_ = destAddr;
    destPort_ = destPort;

    InitSend(destAddr, destPort);
}
