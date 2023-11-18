#ifndef CONTROLLER_KEYS_H
#define CONTROLLER_KEYS_H

/**
 * @file controller_keys.h
 * @brief Defines structures and constants related to controller keys and data.
 */

#include <cstddef>  
#include <cstdint> 
#include <cmath>    
#include <array>    

/** @brief Size of the header in bytes. */
const size_t kHeaderSize = 2;

/** @brief Total number of channels for controller keys. */
const size_t kChannlSize = 16;

/** @brief Number of channels dedicated to axis values in the controller data. */
const size_t kAxisChannlSize = 4;

/** @brief Number of channels dedicated to axis buttons in the controller data. */
const size_t kAxisButtonSize = 2;

/** @brief Maximum range of the joystick axis values. */
const uint16_t kJoystickRange = 1000;

/** @brief Default UDP port for controller data reception. */
const uint16_t kDefaultPort = 43893;

/** @brief Header bytes for identifying controller data. */
const unsigned char kHeader[kHeaderSize] = {0x55, 0x66};

/** @brief Enumerates different types of controllers. */
enum class ControllerType {
  kRetroid = 1, /**< RETROID controller type. */
};

/** @brief Enumerates the status of keys, whether pressed or released. */
enum class KeyStatus {
  kReleased = 0, /**< Key is released. */
  kPressed = 1,  /**< Key is pressed. */
};

/**
 * @brief Structure representing the keys of a Retroid controller.
 */
struct RetroidKeys {
  union {
    uint16_t value; /**< Union to represent the keys as a single value. */
    struct {
      uint8_t R1 : 1; /**< R1 button. */
      uint8_t L1 : 1; /**< L1 button. */
      uint8_t start : 1; /**< Start button. */
      uint8_t select : 1; /**< Select button. */

      uint8_t R2 : 1; /**< R2 button. */
      uint8_t L2 : 1; /**< L2 button. */

      uint8_t A : 1; /**< A button. */
      uint8_t B : 1; /**< B button. */
      uint8_t X : 1; /**< X button. */
      uint8_t Y : 1; /**< Y button. */

      uint8_t left : 1; /**< Left button on the directional pad. */
      uint8_t right : 1; /**< Right button on the directional pad. */
      uint8_t up : 1; /**< Up button on the directional pad. */
      uint8_t down : 1; /**< Down button on the directional pad. */

      uint8_t left_axis_button : 1; /**< Left analog stick button. */
      uint8_t right_axis_button : 1; /**< Right analog stick button. */
    };
  };
  union {
    float axis_values[kAxisChannlSize]; /**< Array representing axis values. */
    struct {
      float left_axis_x; /**< X-axis value of the left analog stick. */
      float left_axis_y; /**< Y-axis value of the left analog stick. */
      float right_axis_x; /**< X-axis value of the right analog stick. */
      float right_axis_y; /**< Y-axis value of the right analog stick. */
    };
  };
};

#pragma pack(1)

/**
 * @brief Structure representing the complete controller data packet.
 */
struct ControllerData {
  uint8_t stx[kHeaderSize]; /**< Start-of-text bytes for identifying the start of data. */
  uint8_t ctrl; /**< Control byte for additional flags or information. */
  uint16_t data_len; /**< Length of the data in the packet. */
  uint16_t seq; /**< Sequence number for tracking packet order or identifying duplicates. */
  uint8_t id; /**< Identifier for the type of controller. */
  uint16_t crc16; /**< CRC-16 checksum for data integrity verification. */
  union {
    uint8_t data[kChannlSize * sizeof(uint16_t)]; /**< Array representing raw data channels. */
    struct {
      uint16_t buttons[kChannlSize - kAxisChannlSize - kAxisButtonSize]; /**< Array representing button values. */
      int16_t left_axis_x; /**< X-axis value of the left analog stick. */
      int16_t left_axis_y; /**< Y-axis value of the left analog stick. */
      int16_t right_axis_x; /**< X-axis value of the right analog stick. */
      int16_t right_axis_y; /**< Y-axis value of the right analog stick. */
      uint16_t axis_buttons[kAxisButtonSize]; /**< Array representing axis button values. */
    };
  };
};
#pragma pack()

#endif
