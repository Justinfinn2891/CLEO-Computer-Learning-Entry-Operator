#include <iostream>
#include <string>

#include "sl_lidar.h"
#include "sl_lidar_driver.h"

using namespace sl;

int main() {
    std::cout << "Starting LIDAR test..." << std::endl;

    // ---------------------------
    // Detect platform and set port
    // ---------------------------
    std::string serial_port;
    sl_u32 baudrate = 115200; // adjust if your model needs 256000 or 1000000

#ifdef _WIN32
    // Windows (COM4 for your setup)
    serial_port = "\\\\.\\COM4";
#else
    // Linux (after usbipd or native Linux USB driver)
    serial_port = "/dev/ttyUSB0";
#endif

    std::cout << "Using port: " << serial_port << " at baud " << baudrate << std::endl;

    // ---------------------------
    // Create driver
    // ---------------------------
    ILidarDriver* drv = *createLidarDriver();
    if (!drv) {
        std::cerr << "Failed to create LIDAR driver." << std::endl;
        return -1;
    }

    // ---------------------------
    // Create serial channel
    // ---------------------------
    IChannel* channel = (*createSerialPortChannel(serial_port.c_str(), baudrate));
    if (!channel) {
        std::cerr << "Failed to create serial channel." << std::endl;
        return -1;
    }

    // ---------------------------
    // Connect
    // ---------------------------
    if (SL_IS_FAIL(drv->connect(channel))) {
        std::cerr << "Error: cannot connect to LIDAR on " << serial_port << std::endl;
        return -1;
    }

    // ---------------------------
    // Get device info
    // ---------------------------
    sl_lidar_response_device_info_t devinfo;
    if (SL_IS_FAIL(drv->getDeviceInfo(devinfo))) {
        std::cerr << "Failed to get device info." << std::endl;
        return -1;
    }

    std::cout << "LIDAR connected. Firmware: "
              << (devinfo.firmware_version >> 8) << "."
              << (devinfo.firmware_version & 0xFF)
              << "  Hardware: " << (int)devinfo.hardware_version
              << std::endl;

    // ---------------------------
    // Start scanning
    // ---------------------------
    if (SL_IS_FAIL(drv->startScan(0, 1))) {
        std::cerr << "Failed to start scan." << std::endl;
        return -1;
    }

    // ---------------------------
    // Grab a batch of data
    // ---------------------------
    sl_lidar_response_measurement_node_hq_t nodes[8192];
    size_t   count = sizeof(nodes) / sizeof(nodes[0]);

    if (SL_IS_OK(drv->grabScanDataHq(nodes, count))) {
        drv->ascendScanData(nodes, count);

        for (size_t i = 0; i < count; ++i) {
            float angle = (nodes[i].angle_z_q14 * 90.f) / 16384.f;
            float dist  = nodes[i].dist_mm_q2 / 4.0f;
            std::cout << angle << "," << dist << std::endl;
        }
    } else {
        std::cerr << "Failed to grab scan data." << std::endl;
    }

    drv->stop();
    drv->setMotorSpeed(0);

    if (drv) {
        delete drv;
    }

    return 0;
}
