#ifndef SKYDROID_CONTROLLER_H
#define SKYDROID_CONTROLLER_H

#include <iostream>
#include <ostream>
#include "controller.h"
#include "fmt/format.h"
#include "fmt/core.h"
#include "fmt/chrono.h"

/**
 * @brief A specialized class for Skydroid controller.
 *
 * This class specializes the generic Controller class for Skydroid controller.
 */
class SkydroidController : public Controller<SkydroidKeys> {
public:
  /**
   * @brief Constructor for the SkydroidController class.
   *
   * Initializes the Skydroid controller with the specified UDP port for data reception.
   *
   * @param port The UDP port to use for receiving controller data.
   */
  SkydroidController(int port = kDefaultPort);

  /**
   * @brief Overloaded output stream operator for SkydroidController.
   *
   * Allows printing SkydroidController information to an output stream.
   *
   * @param o The output stream.
   * @param is The SkydroidController object.
   * @return Reference to the output stream.
   */
  friend std::ostream& operator<<(std::ostream& o, SkydroidController& is);

protected:
  /**
   * @brief Updates the Skydroid controller data buffer and keys.
   *
   * @param buffer The data buffer to be updated.
   * @param keys The Skydroid controller keys to be updated.
   * @return True if the data is valid and updated, false otherwise.
   */
  bool UpdateData(std::vector<uint8_t>& buffer, SkydroidKeys& keys) override;

  /**
   * @brief Checks if the received data from the Skydroid controller is valid.
   *
   * @param data The controller data to be validated.
   * @return True if the data is valid, false otherwise.
   */
  bool DataIsValid(const SkydroidControllerData& data);
};

/**
 * @brief Overloaded output stream operator for SkydroidController.
 *
 * Allows printing SkydroidController information to an output stream.
 *
 * @param o The output stream.
 * @param is The SkydroidController object.
 * @return Reference to the output stream.
 */
std::ostream& operator<<(std::ostream& o, SkydroidController& is);

#endif // Skydroid_CONTROLLER_H
