#include "controller.h"
#include "udp_receiver.h"
#include <iostream>
#include <thread>
#include <chrono>

/**
 * @brief Constructor for the Controller class.
 *
 * Initializes the controller with the specified UDP port for data reception.
 *
 * @param port The UDP port to use for receiving controller data.
 */
template <typename KeysType>
Controller<KeysType>::Controller(int port) : stop_thread_(false), port_(port) {
  // Start the data thread
  StartDataThread();
}

/**
 * @brief Starts the data thread for continuous data reception.
 */
template <typename KeysType>
void Controller<KeysType>::StartDataThread() {
  data_thread_ = std::thread([this]() {
    uint32_t updateCount = 0;
    UdpReceiver udpReceiver(port_);

    // Loop to continuously receive data
    while (!stop_thread_) {
      std::vector<uint8_t> receivedData = udpReceiver.ReceiveData();
      bool ret = false;
      if(true){
        std::lock_guard<std::mutex> lock(mutex_);
        ret = UpdateData(receivedData, keys_);
      }
      // If data is valid and updated, increase the update count
      if (ret) {
        updateCount++;

        // If there is an update callback function, call the callback and pass the update count
        if (updateCallback_) {
          updateCallback_(updateCount);
        }
      }
    }
  });
}

/**
 * @brief Stops the data thread.
 */
template <typename KeysType>
void Controller<KeysType>::StopDataThread() {
  stop_thread_ = true;

  // Detach the thread after it has been stopped
  data_thread_.detach();
}

/**
 * @brief Gets the current keys data.
 *
 * @return Reference to the keys data.
 */
template <typename KeysType>
const KeysType& Controller<KeysType>::GetKeys() {
  std::lock_guard<std::mutex> lock(mutex_);
  return keys_;
}

/**
 * @brief Calculates the CRC-16 checksum for a given data array.
 *
 * @param data Pointer to the data array.
 * @param length Length of the data array.
 * @return The calculated CRC-16 checksum.
 */
template <typename KeysType>
uint16_t Controller<KeysType>::CalculateCrc16(const uint8_t* data, size_t length) {
  uint16_t crc = 0x00;

  // Calculate the CRC-16 checksum
  for (int i = 0; i < length; i++) {
    crc += data[i];
  }

  return crc;
}

/**
 * @brief Sets a callback function to be called on data update.
 *
 * @param callback The callback function taking an update count as a parameter.
 */
template <typename KeysType>
void Controller<KeysType>::SetUpdateCallback(const std::function<void(uint32_t)>& callback) {
  updateCallback_ = callback;
}

// Explicitly instantiate the template class for specific controller types
template class Controller<RetroidKeys>;
