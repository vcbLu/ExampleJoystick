#ifndef RETROID_CONTROLLER_H
#define RETROID_CONTROLLER_H

#include <iostream>
#include <ostream>
#include "controller.h"
#include "fmt/format.h"
#include "fmt/core.h"
#include "fmt/chrono.h"

/**
 * @brief A specialized class for RETROID controller.
 *
 * This class specializes the generic Controller class for RETROID controller.
 */
class RetroidController : public Controller<RetroidKeys> {
public:
  /**
   * @brief Constructor for the RetroidController class.
   *
   * Initializes the Retroid controller with the specified UDP port for data reception.
   *
   * @param port The UDP port to use for receiving controller data.
   */
  RetroidController(int port = kDefaultPort);

  /**
   * @brief Overloaded output stream operator for RetroidController.
   *
   * Allows printing RetroidController information to an output stream.
   *
   * @param o The output stream.
   * @param is The RetroidController object.
   * @return Reference to the output stream.
   */
  friend std::ostream& operator<<(std::ostream& o, RetroidController& is);

protected:
  /**
   * @brief Updates the RETROID controller data buffer and keys.
   *
   * @param buffer The data buffer to be updated.
   * @param keys The RETROID controller keys to be updated.
   * @return True if the data is valid and updated, false otherwise.
   */
  bool UpdateData(std::vector<uint8_t>& buffer, RetroidKeys& keys) override;

  /**
   * @brief Checks if the received data from the RETROID controller is valid.
   *
   * @param data The controller data to be validated.
   * @return True if the data is valid, false otherwise.
   */
  bool DataIsValid(const ControllerData& data);
};

/**
 * @brief Overloaded output stream operator for RetroidController.
 *
 * Allows printing RetroidController information to an output stream.
 *
 * @param o The output stream.
 * @param is The RetroidController object.
 * @return Reference to the output stream.
 */
std::ostream& operator<<(std::ostream& o, RetroidController& is);

#endif // RETROID_CONTROLLER_H
