#include "rt_can.h"
#include <time.h>
#include <iostream>


void RtCan::init_can() {
  system("ip link set can1 down");
  system("ip link set can1 up type can bitrate 1000000");


  /*can0*/
  struct sockaddr_can addr;
  struct ifreq ifr;
  socket_can0_fd = socket(PF_CAN, SOCK_RAW, CAN_RAW);  // 创建套接字
  strcpy(ifr.ifr_name, "can1");
  ioctl(socket_can0_fd, SIOCGIFINDEX, &ifr);  // 指定 can0 设备
  addr.can_family = AF_CAN;
  addr.can_ifindex = ifr.ifr_ifindex;
  bind(socket_can0_fd, (struct sockaddr *)&addr,
       sizeof(addr));  // 将套接字与 can0 绑定

  /*消息过滤，只接受制定ID的数据，如需过滤取消以下注释*/
  struct can_filter rfilter[1];  // 过滤规则
  rfilter[0].can_id = 0x111;
  rfilter[0].can_mask = CAN_SFF_MASK;
  setsockopt(socket_can0_fd, SOL_CAN_RAW, CAN_RAW_FILTER, &rfilter,
             sizeof(rfilter));

}

void RtCan::send2mcu(void){
  can_cmd data_test;

  struct can_frame can0_frame;
  can0_frame.can_id = 0x112;
  can0_frame.can_dlc = 8;
  if(last_index != index){
    clock_gettime(1,&time_test);
    data_test.tv_sec = time_test.tv_sec;
    data_test.tv_nsec = time_test.tv_nsec;
    last_index = index;
  }
  // clock_gettime(1,&time_test);
  // data_test.tv_sec = time_test.tv_sec;
  // data_test.tv_nsec = time_test.tv_nsec;
  memcpy(&can0_frame.data, &data_test.data, sizeof(data_test.data));
  write(socket_can0_fd, &can0_frame, sizeof(can0_frame));
  std::cout << "sec " << time_test.tv_sec << "." << time_test.tv_nsec << std::endl;
}

// int32_t RtCan::SendToDriver(void) {
//   struct can_frame can0_frame;
//   struct can_frame can0_frame_1;
//   struct can_frame can1_frame;
//   // struct can_frame can2_frame;
//   int nbytes = 0;
// #if DEBUG_CAN
//   for (int i = 0; i < 3; i++) {
//     can0_frame.can_id = 0x001 + i;
//     // can1_frame.can_id = i + 0x01;
//     // can2_frame.can_id = i + 0x01;
//     can0_frame.can_dlc = 8;
//     can1_frame.can_dlc = 8;
//     can2_frame.can_dlc = 8;
//     // can1_cmd[0].position = float_to_uint(20.357, ARM_CMD_P_MIN,
//     // ARM_CMD_P_MAX,16); can1_cmd[0].velocity = float_to_uint(20.357,
//     // ARM_CMD_V_MIN, ARM_CMD_V_MAX,16);

//     // can1_cmd[0].torque = float_to_uint(20.357, ARM_CMD_T_MIN,
//     // ARM_CMD_T_MAX,16);

//     // can1_cmd[0].kp = float_to_uint(20.357, ARM_CMD_KP_MIN, ARM_CMD_KP_MAX,8);
//     // can1_cmd[0].kd = float_to_uint(2.33, ARM_CMD_KD_MIN, ARM_CMD_KD_MAX,8);

//     memcpy(&can0_frame.data, &can0_cmd[i].data, sizeof(can0_cmd[i].data));
//     nbytes = write(socket_can0_fd, &can0_frame, sizeof(can0_frame));
//     if (nbytes < 0) {
//       printf("[Error] can0 0x%x send error\r\n", can1_frame.can_id);
//     }
//   }
//   // memcpy(&can1_frame.data, &can1_cmd[1].data, sizeof(can1_cmd[1].data));
//   // can1_frame.can_id = 0x002;
//   // nbytes = write(socket_can1_fd, &can1_frame, sizeof(can1_frame));

//   // memcpy(&can1_frame.data, &can1_cmd[3].data, sizeof(can1_cmd[3].data));
//   // can1_frame.can_id = 0x004;
//   // nbytes = write(socket_can1_fd, &can1_frame, sizeof(can1_frame));
//   // memcpy(&can1_frame.data, &can1_cmd[i].data, sizeof(can1_cmd[i].data));
//   // memcpy(&can2_frame.data, &can2_cmd[2].data, sizeof(can2_cmd[2].data));
//   // nbytes = write(socket_can0_fd, &can0_frame, sizeof(can0_frame));
//   // nbytes = write(socket_can0_fd, &can0_frame_1, sizeof(can0_frame_1));
//   // nbytes = write(socket_can2_fd, &can2_frame, sizeof(can2_frame));

//   // nbytes = write(socket_can1_fd, &can1_frame, sizeof(can1_frame));
//   // if(nbytes < 0){
//   //   printf("[Error] can1 0x%x send error\r\n", can1_frame.can_id);
//   // }
//   // nbytes = write(socket_can2_fd, &can2_frame, sizeof(can2_frame));
//   // if(nbytes < 0){
//   //   printf("[Error] can2 0x%x send error\r\n", can2_frame.can_id);
//   // }
//   // }
// #else
//   for (int i = 0; i < 3; i++) {
//     can0_frame.can_id = i + 0x011;
//     // can2_frame.can_id = i + 0x004;
//     can0_frame.can_dlc = 8;
//     can0_cmd[i].vel = i + 0x011;
//     // can2_frame.can_dlc = 8;
//     memcpy(&can0_frame.data, &can0_cmd[i].data, sizeof(can0_cmd[i].data));
//     // memcpy(&can1_frame.data, &can1_cmd[i].data, sizeof(can1_cmd[i].data));
//     nbytes = write(socket_can0_fd, &can0_frame, sizeof(can0_frame));
//     if (nbytes < 0) {
//       printf("[Error] can0 0x%x send error\r\n", can0_frame.can_id);
//     }
//   }

// #endif
// }
