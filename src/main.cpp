#include <iostream>
// #include "controller/controller product.h"

#include "controller/controller.h"
#include "controller/retroid_controller.h"
#include "controller/skydroid_controller.h"
#include "network/udp_receiver.h"
#include "controller/controller_keys.h"
#include "can2udp/rt_can.h"
#include "network/udp_socket.h"
struct time_test{
  uint32_t tv_sec;
  uint32_t tv_nsec;

};
struct Motor{
  float pos;
  float vel;
  float tor;
  union {
    float motor_temp;  // kp 别名为电机温度
    float kp;
  };
  union {
    float drive_temp;  // kd 别名为驱动温度
    float kd;
  };
  union {
    uint32_t status_word;  // control_word 别名为状态字
    uint32_t control_word;
  };
};
// int main(int argc, char* argv[]) {
//   UdpReceiver udpReceiver(43893);
//   time_test time_;
//   timespec now_time;
//   RtCan can_;
//   float delay_time = 0.0f;
//   int index = 0;
//   // while(1){
//   //   for(int i = 0; i < 2 ;i++){
//   //     can_.send2mcu();

//   //   }
//   //   index ++;
//   //   can_.index = index;
//   //   std::vector<uint8_t> receivedData = udpReceiver.ReceiveData();
//   //   clock_gettime(1, &now_time);
//   //   memcpy(&time_, receivedData.data(), 8);
//   //   delay_time = (float)now_time.tv_sec + (float)now_time.tv_nsec/1e9 - (float)time_.tv_sec - (float)time_.tv_nsec/1e9;
//   //   printf("delay time %+3.3f  ms  %d", delay_time*1e3,time_.tv_nsec);
//   //   // std::cout << "Data " << time_.tv_sec << "." << time_.tv_nsec << "  now " << now_time.tv_sec << "." << now_time.tv_nsec << std::endl;
//   //   std::cout << std::endl;
//   //   // std::this_thread::sleep_for(std::chrono::seconds(1));

//   // // std::cout << "rec data " << std::endl;
//   // }

//   return 0;
// }
int main(int argc, char* argv[]) {
  // UdpReceiver udpReceiver(43893);
  time_test time_;
  timespec now_time;
  // RtCan can_;
  float delay_time = 0.0f;
  int index = 0;
  UdpSocket socket_(43893);
  Motor send_mcu_data[6] = {
    {1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 0x11111111},
    {6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 0x22222222},
    {1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 0x11111111},
    {6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 0x22222222},
    {1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 0x11111111},
    {6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 0x22222222},
  };
  socket_.InitSend("192.168.1.101", 1234);
  size_t bytes_to_copy = sizeof(send_mcu_data);

    // 创建并分配足够空间的 send_data 向量
  std::vector<uint8_t> send_data(bytes_to_copy);
  memcpy(send_data.data(), send_mcu_data, bytes_to_copy);
  while(1){
    socket_.SendData(send_data);
    std::vector<uint8_t> receivedData = socket_.ReceiveData();
    std::cout << " hello world " << receivedData.size() << std::endl;
  }

  // Define a lambda function for the while loop
  // auto whileLoop = [&]() {
  //   while (true) {
  //     std::vector<uint8_t> receivedData = udpReceiver.ReceiveData();
  //     std::cout << " hello world " << receivedData.size() << std::endl;
  //     clock_gettime(1, &now_time);
  //     memcpy(&time_, receivedData.data(), 8);
  //     // for(int i = 0; i < receivedData.size(); i++){
  //     //   printf("%02x ", receivedData.data()[i]);
  //     // }
  //     delay_time = (float)now_time.tv_sec + (float)now_time.tv_nsec / 1e9 - (float)time_.tv_sec - (float)time_.tv_nsec / 1e9;
  //     printf("delay time %+3.3f  ms  %d", delay_time * 1e3, time_.tv_nsec);
  //     std::cout << std::endl;
  //   }
  // };
  
  // // Create a thread and run the while loop in that thread
  // std::thread whileThread(whileLoop);
  // while(1){
  //   for (int i = 0; i < 6; i++) {
  //     can_.send2mcu();
  //   }
  //   index++;
  //   can_.index = index;
  //   usleep(1000);
  // }
  // // Do other tasks in the main thread if needed

  // // Wait for the while thread to finish (which it won't in this case)
  // whileThread.join();

  return 0;
}