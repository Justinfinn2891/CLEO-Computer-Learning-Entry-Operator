#include "sl_lidar.h"
#include "sl_lidar_driver.h"

#include <iostream>
#include <fstream>
#include <cmath>

using namespace sl;
/*
// Convert polar to Cartesian
float findX(const float &angle, const float &distance) {
  
}
float findY(const float &angle, const float &distance) {
 
}
float findZ(const float &angle, const float &distance) {
    
}
*/
int main() {
    const char* serial_port = "/dev/ttyUSB0";
    sl_u32 baudrate = 115200;
    std::cout << "Test";
  
    ILidarDriver* driver = *createLidarDriver();
    if (!driver) {
        std::cerr << "Failed to create LIDAR driver!" << std::endl;
        return -1;
    }

    IChannel* channel = *createSerialPortChannel(serial_port, baudrate);
    if (!channel) {
        std::cerr << "Failed to create serial channel!" << std::endl;
        delete driver;
        return -1;
    }

  
    if (SL_IS_FAIL(driver->connect(channel))) {
        std::cerr << "Failed to connect to LIDAR!" << std::endl;
        delete driver;
        return -1;
    }


    driver->setMotorSpeed(660);

 
    if (SL_IS_FAIL(driver->startScan(false, true))) {
        std::cerr << "Failed to start scan!" << std::endl;
        driver->setMotorSpeed(0);

        delete driver;
        return -1;
    }

    // Buffer for scan points
    sl_lidar_response_measurement_node_hq_t nodes[8192];
    size_t count = sizeof(nodes)/sizeof(nodes[0]);

    // Grab data once
    if (SL_IS_OK(driver->grabScanDataHq(nodes, count))) {
        driver->ascendScanData(nodes, count);

        std::ofstream file("data.csv");
        for (size_t i = 0; i < count; ++i) {
            float angle = nodes[i].angle_z_q14 * 90.f / 16384.f;
            float distance = nodes[i].dist_mm_q2 / 4.0f;

            file << angle << "," << distance << "," << std::endl; 
        }
        file.close();
        std::cout << "Scan saved to data.csv" << std::endl;
    } else {

        std::cerr << "Failed to grab scan data!" << std::endl;
    }

    driver->stop();
    driver->setMotorSpeed(0);
    delete driver;

    return 0;
}
