# CLEO - Computer Learning Educational Operator

Project Tracker -> https://docs.google.com/spreadsheets/d/12y3wJU4cHn6q5bq1VsLETFq5kpCxoWj3vPIzxyNg8aM/edit?usp=sharing
g++ lidar.cpp -o mylidar -I./rplidar_sdk-master/sdk/include -I./rplidar_sdk-master/sdk/src ./rplidar_sdk-master/output/Linux/Release/libsl_lidar_sdk.a
/usr/bin/ld: cannot find ./rplidar_sdk-master/output/Linux/Release/libsl_lidar_sdk.a: No such file or directory
collect2: error: ld returned 1 exit status
Guys we need to a git ignore file 

its now leo :( lidar entry operator



g++ lidar.cpp -o mylidar -I./rplidar_sdk-master/sdk/include -I./rplidar_sdk-master/sdk/src ~/rplidar_sdk-maste
r/output/Linux/Release/libsl_lidar_sdk.a



#include "sl_lidar_driver.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

int main() {
    // Output file
    std::ofstream file("data.csv");
    if (!file.is_open()) {
        std::cerr << "Failed to open file for writing" << std::endl;
        return -1;
    }

    // Create the driver object
    sl::SlamtecLidarDriver driver;

    // Initialize the driver with the serial port
    const char* port = "/dev/ttyUSB0";
    const uint32_t baudrate = 115200;
    if (!driver.initialize(port, baudrate)) {
        std::cerr << "Failed to initialize LIDAR on port " << port << std::endl;
        return -1;
    }

    // Start motor and scanning
    driver.startMotor();
    driver.startScan();

    // Grab a single scan frame
    std::vector<sl::LidarMeasurement> measurements;
    if (!driver.grabScanData(measurements)) {
        std::cerr << "Failed to grab scan data" << std::endl;
        driver.stopMotor();
        return -1;
    }

    // Ascend (sort) the data by angle
    driver.ascendScanData(measurements);

    // Print and store
    for (auto &m : measurements) {
        float angle = m.angle;       // in degrees
        float distance = m.distance; // in mm
        std::cout << "Angle: " << angle << "  Distance: " << distance << std::endl;
        file << angle << "," << distance << "\n";
    }

    // Stop scanning and motor
    driver.stopScan();
    driver.stopMotor();

    file.close();
    std::cout << "Scan complete, data saved to data.csv" << std::endl;

    return 0;
}
