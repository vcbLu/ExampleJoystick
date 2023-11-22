#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <functional>
#include <thread>
#include <mutex>
#include <atomic>
#include <vector>
#include "controller_keys.h"
#include <iostream>

/**
 * @brief A template class for a generic controller.
 *
 * This class serves as a generic controller template. It can be specialized for specific controller types.
 *
 * @tparam KeysType The type of keys for the controller (e.g., XboxKeys, PlayStationKeys).
 */
template <typename KeysType>
class Controller {
public:
    std::vector<std::string> kButtonStatus;
    /**
     * @brief Constructor for the Controller class.
     *
     * Initializes the controller with the specified UDP port for data reception.
     *
     * @param port The UDP port to use for receiving controller data.
     */
    Controller(int port = kDefaultPort);

    /**
     * @brief Destructor for the Controller class.
     *
     * This destructor stops the data thread to clean up resources when the controller instance is destroyed.
     */
    virtual ~Controller(){
      StopDataThread();
    }

    /**
     * @brief Starts the data thread for simulating controller data.
     */
    void StartDataThread();

    /**
     * @brief Stops the data thread.
     */
    void StopDataThread();

    /**
     * @brief Gets the controller keys.
     * @return The current controller keys.
     */
    KeysType& GetKeys();

    /**
     * @brief Sets a callback function to be called on each data update.
     * @param callback The callback function that takes an update count as an argument.
     */
    void SetUpdateCallback(const std::function<void(uint32_t)>& callback);

    /**
     * @brief Calculate the CRC-16 checksum for a given data buffer.
     *
     * @param data Pointer to the data buffer.
     * @param length Length of the data buffer.
     * @return The CRC-16 checksum of the data.
     */
    uint16_t CalculateCrc16(const uint8_t* data, size_t length);

    std::function<void(uint32_t)> updateCallback_; ///< Callback function for data updates.

protected:
    std::thread data_thread_;                 ///< Thread for generating simulated data.
    std::atomic<bool> stop_thread_;           ///< Flag to signal the data thread to stop.
    mutable std::mutex mutex_;              ///< Mutex for data access synchronization.
    KeysType keys_;                         ///< Controller keys.
    int port_;                              ///< The UDP port for data reception.
    
    /**
     * @brief Updates the controller data buffer and keys.
     *
     * @param buffer The data buffer to be updated.
     * @param keys The keys to be updated.
     * @return True if the data is valid and updated, false otherwise.
     */
    virtual bool UpdateData(std::vector<uint8_t>& buffer, KeysType& keys) = 0;
};

#endif
