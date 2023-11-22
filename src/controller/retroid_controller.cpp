#include "retroid_controller.h"
#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <bitset>


/**
 * @brief Constructor for the RetroidController class.
 *
 * Initializes the Retroid controller with the specified UDP port for data reception.
 *
 * @param port The UDP port to use for receiving controller data.
 */
RetroidController::RetroidController(int port) : Controller(port) {

  std::string pressed  = fmt::format("\x1b[32m{:^20}\x1b[0m", "pressed");
  std::string released = fmt::format("\x1b[37m{:^20}\x1b[0m", "released");
  kButtonStatus.push_back(released);
  kButtonStatus.push_back(pressed);

}

/**
 * @brief Updates the RETROID controller data buffer and keys.
 *
 * @param buffer The data buffer to be updated.
 * @param keys The RETROID controller keys to be updated.
 * @return True if the data is valid and updated, false otherwise.
 */
bool RetroidController::UpdateData(std::vector<uint8_t>& buffer, RetroidKeys& keys) {
  ControllerData data;
  memcpy(&data, buffer.data(), buffer.size()*sizeof(uint8_t));
  // Perform data validity check in the child class
  if (DataIsValid(data)) {
    std::bitset<kRetroidButtonSize> keys_value_bit(0);
    int16_t keys_ch[kRetroidButtonSize];
    memcpy(keys_ch, data.buttons, sizeof(keys_ch));
    for(int i = 0; i < kRetroidButtonSize; i++){
      keys_value_bit[i] = keys_ch[i];
    }
    keys.keys_value = keys_value_bit.to_ulong();

    keys.left  = (data.left_axis_x == -kJoystickRange) ? (uint8_t)KeyStatus::kPressed 
                  : ((data.left_axis_x ==  kJoystickRange) ? (uint8_t)KeyStatus::kReleased : (uint8_t)KeyStatus::kReleased);
    keys.right = (data.left_axis_x ==  kJoystickRange) ? (uint8_t)KeyStatus::kPressed 
                  : ((data.left_axis_x == -kJoystickRange) ? (uint8_t)KeyStatus::kReleased : (uint8_t)KeyStatus::kReleased);
    keys.up    = (data.left_axis_y ==  kJoystickRange) ? (uint8_t)KeyStatus::kPressed 
                  : ((data.left_axis_y == -kJoystickRange) ? (uint8_t)KeyStatus::kReleased : (uint8_t)KeyStatus::kReleased);
    keys.down  = (data.left_axis_y == -kJoystickRange) ? (uint8_t)KeyStatus::kPressed 
                  : ((data.left_axis_y ==  kJoystickRange) ? (uint8_t)KeyStatus::kReleased : (uint8_t)KeyStatus::kReleased);

    keys.left_axis_x = data.left_axis_x/(float)kJoystickRange;
    keys.left_axis_y = data.left_axis_y/(float)kJoystickRange;
    keys.right_axis_x = data.right_axis_x/(float)kJoystickRange;
    keys.right_axis_y = data.right_axis_y/(float)kJoystickRange;

    return true;
  }
  return false;
}

/**
 * @brief Checks if the received data from the RETROID controller is valid.
 *
 * @param data The controller data to be validated.
 * @return True if the data is valid, false otherwise.
 */
bool RetroidController::DataIsValid(const ControllerData& data) {

  // 1. check STX   
  if (data.stx[0] != kHeader[0] || data.stx[1] != kHeader[1]) {
    return false;
  }

  // 2. check device ID
  if (data.id != (uint8_t)ControllerType::kRetroid) {
    return false;
  }
  
  // 3. CRC16
  if(data.crc16 != CalculateCrc16(data.data, data.data_len)){
    return false;
  }

  return true;  
}

std::ostream& operator<<(std::ostream& o, RetroidController& is){
  
  RetroidKeys keys = is.GetKeys();
  o << "\033c";
  std::string  s = fmt::format(
	"┌{0:─^{1}}┐\n"
	"│{2: ^{1}}│\n"
	"└{0:─^{1}}┘\n", "", 86 ,"Joystick Device: Retroid(Lite3)");
  o<<s ;
  s = fmt::format(
    "┌{2:─^{1}}┐┌{3:─^{1}}┐┌{4:─^{1}}┐┌{5:─^{1}}┐\n"
    "│{6: ^{1}}││{7: ^{1}}││{8: ^{1}}││{9: ^{1}}│\n"
    "└{0:─^{1}}┘└{0:─^{1}}┘└{0:─^{1}}┘└{0:─^{1}}┘\n", 
    "", 20, "L2", "L1", "R1", "R2", 
    is.kButtonStatus[keys.L2], is.kButtonStatus[keys.L1], is.kButtonStatus[keys.R1], is.kButtonStatus[keys.R2]);
  o<<s ;
  s = fmt::format(
    "┌{2:─^{1}}┐┌{3:─^{1}}┐┌{4:─^{1}}┐┌{5:─^{1}}┐\n"
    "│{6: ^{1}}││{7: ^{1}}││{8: ^{1}}││{9: ^{1}}│\n"
    "└{0:─^{1}}┘└{0:─^{1}}┘└{0:─^{1}}┘└{0:─^{1}}┘\n", 
    "", 20, "X", "Y", "A", "B", 
    is.kButtonStatus[keys.X], is.kButtonStatus[keys.Y], is.kButtonStatus[keys.A], is.kButtonStatus[keys.B]);
  o<<s ;

  s = fmt::format(
    "┌{2:─^{1}}┐┌{3:─^{1}}┐┌{4:─^{1}}┐┌{5:─^{1}}┐\n"
    "│{6: ^{1}}││{7: ^{1}}││{8: ^{1}}││{9: ^{1}}│\n"
    "└{0:─^{1}}┘└{0:─^{1}}┘└{0:─^{1}}┘└{0:─^{1}}┘\n",
    "", 20, "up", "down", "left", "right", 
    is.kButtonStatus[keys.up], is.kButtonStatus[keys.down], is.kButtonStatus[keys.left], is.kButtonStatus[keys.right]);
  o<<s ;



  s = fmt::format(
    "┌{2:─^{1}}┐┌{3:─^{1}}┐┌{4:─^{1}}┐┌{5:─^{1}}┐\n"
    "│{6: ^{1}}││{7: ^{1}}││{8: ^{1}}││{9: ^{1}}│\n"
    "└{0:─^{1}}┘└{0:─^{1}}┘└{0:─^{1}}┘└{0:─^{1}}┘\n", 
    "", 20, "select", "start", "left_axis_button", "right_axis_button", 
    is.kButtonStatus[keys.select], is.kButtonStatus[keys.start], is.kButtonStatus[keys.left_axis_button], is.kButtonStatus[keys.right_axis_button]);
  // fmt::print(s);
  o<<s ;
  s = fmt::format(
    "┌{2:─^{1}}┐┌{3:─^{1}}┐┌{4:─^{1}}┐┌{5:─^{1}}┐\n"
    "│{6: ^{1}}││{7: ^{1}}││{8: ^{1}}││{9: ^{1}}│\n"
    "└{0:─^{1}}┘└{0:─^{1}}┘└{0:─^{1}}┘└{0:─^{1}}┘\n", 
    "", 20, "left_axis_x", "left_axis_y", "right_axis_x", "right_axis_y", 
    keys.left_axis_x, keys.left_axis_y, keys.right_axis_x, keys.right_axis_y);
  o<<s ;
  // o<<str_button ;
  return o;
}

