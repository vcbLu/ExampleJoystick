#include <iostream>
// #include "controller/controller product.h"

#include "controller/controller.h"
#include "controller/retroid_controller.h"

#include "network/udp_receiver.h"
#include "controller/controller_keys.h"


int main(int argc, char* argv[]) {
  RetroidController rc(43893);
  const RetroidKeys *keys = &rc.GetKeys();
  rc.updateCallback_ = [&](int32_t count){
    std::cout << rc << std::endl;
  };
    
  for(int i = 0; i < 100000; i ++){
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
  return 0;
}
