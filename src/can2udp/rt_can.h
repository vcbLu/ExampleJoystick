#ifndef _rt_can
#define _rt_can

#include <linux/can.h>
#include <linux/can/raw.h>
#include <net/if.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <unistd.h>

#include <fcntl.h>
#include <signal.h>
#include <sys/epoll.h>
#include <sys/ioctl.h>
#include <sys/resource.h> /*setrlimit */
#include <unistd.h>
#include <stdint.h>

#pragma pack(1)
struct can_cmd {
  union {
    uint8_t data[8];
    struct {
      uint32_t tv_sec : 32;
      uint32_t tv_nsec : 32;
      /* data */
    };
  };
};
#pragma pack()



class RtCan  {
 private:

  int socket_can0_fd;
  int socket_can1_fd;
  int socket_can2_fd;
  void init_can();
  struct timespec time_test;

 public:
  RtCan(/* args */) { init_can(); };
  void send2mcu(void);
  int32_t index;
  int32_t last_index;
  ~RtCan(){

  };
};
#endif