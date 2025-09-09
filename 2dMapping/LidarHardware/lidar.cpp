#include "sl_lidar.h"
#include "sl_lidar_driver.h"
#include <iostream>
#include <fstream>
#include <cmath>

using namespace sl;

/*
float findX(float angle_deg, float distance_mm) {

}
float findY(float angle_deg, float distance_mm) {
 
}
*/
int main() {
    const char* serial_port = "/dev/ttyUSB0";
    sl_u32 baudrate = 115200;

    ILidarDriver* driver = *createLidarDriver();
    if (!driver) {
        std::cerr << "Failed to create LIDAR driver!" << std::endl;
        return -1;
    }

    IChannel* channel = *createSerialPortChannel(serial_port, baudrate);
    if (!channel) {
        std::cerr << "Failed to create serial channel." << std::endl;
        delete driver;
        return -1;
    }

    sl_result res = driver->connect(channel);
    if (SL_IS_FAIL(res)) {
        std::cerr << "Failed to connect to LIDAR!" << std::endl;
        delete driver;
        return -1;
    }

    std::ofstream csv("lidar_data.csv");
    if (!csv.is_open()) {
        std::cerr << "Cannot open CSV file for writing!" << std::endl;
        driver->stop();
        delete driver;
        return -1;
    }

    csv << "angle_deg,distance_mm,x_mm,y_mm,z_mm\n";

    std::cout << "Starting scan. Press Ctrl+C to stop..." << std::endl;

    // Start motor and scan
    driver->setMotorSpeed(660);
    res = driver->startScan(false, true);
    if (SL_IS_FAIL(res)) {
        std::cerr << "Failed to start scan!" << std::endl;
        driver->setMotorSpeed(0);
        delete driver;
        return -1;
    }

    sl_lidar_response_measurement_node_hq_t nodes[8192];
    size_t count;

    while (true) {
        count = sizeof(nodes) / sizeof(nodes[0]);
        res = driver->grabScanDataHq(nodes, count);
        if (SL_IS_OK(res)) {
            driver->ascendScanData(nodes, count);

            for (size_t i = 0; i < count; ++i) {
                float angle = nodes[i].angle_z_q14 * 90.f / 16384.f;
                float distance = nodes[i].dist_mm_q2 / 4.0f;

                float x = findX(angle, distance);
                float y = findY(angle, distance);
                float z = findZ(angle, distance);

                csv << angle << "," << distance << "," << x << "," << y << "," << z << "\n";
            }
        }
    }

    csv.close();
    driver->stop();
    driver->setMotorSpeed(0);
    delete driver;

    return 0;
}
