#include <iostream>
#include <string>
#include "sl_lidar.h"
#include "sl_lidar_driver.h"
#include <vector>
#include <fstream>
using namespace sl;

/* GOALS:
1.) We need to put together our lidar camera to try to handle 3d computing
2.) We need to start implementing the coordinates to send to the csv file
3.) We need to get the iterative closest point algorithm working*/
struct cartesian{
    float x_coordinate, y_coordinate, z_coordinate;
};

int findX(const float &angle, const float &distance);
int findY(const float &angle, const float &distance);
int findZ(const float &angle, const float &distance);
void saveToFile(std::vector<cartesian> points);

int main() {
    std::cout << "Starting LIDAR test..." << std::endl;
    std::string serial_port;
    sl_u32 baudrate = 115200;
    serial_port = "/dev/ttyUSB0";

    std::cout << "Using port: " << serial_port << " at baud " << baudrate << std::endl;

    ILidarDriver* drv = *createLidarDriver();
    if (!drv) {
        std::cerr << "Failed to create LIDAR driver." << std::endl;
        return -1;
    }

    IChannel* channel = (*createSerialPortChannel(serial_port.c_str(), baudrate));
    if (!channel) {
        std::cerr << "Failed to create serial channel." << std::endl;
        return -1;
    }

    if (SL_IS_FAIL(drv->connect(channel))) {
        std::cerr << "Error: cannot connect to LIDAR on " << serial_port << std::endl;
        return -1;
    }

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


    if (SL_IS_FAIL(drv->startScan(0, 1))) {
        std::cerr << "Failed to start scan." << std::endl;
        return -1;
    }



    sl_lidar_response_measurement_node_hq_t nodes[8192];
    size_t   count = sizeof(nodes) / sizeof(nodes[0]);
    const float min_distance = 0.0f;
    const float max_distance = 250.0f;
    const float min_angle = 0.0f;
    const float max_angle = 2500.0f;
    
    std::vector<cartesian> finished_points;

    if (SL_IS_OK(drv->grabScanDataHq(nodes, count))) {
        drv->ascendScanData(nodes, count);

        for (size_t i = 0; i < count; ++i) {
            float angle = (nodes[i].angle_z_q14 * 90.f) / 16384.f;
            float dist  = nodes[i].dist_mm_q2 / 4.0f;

            if(dist >= min_distance || dist <= max_distance) continue;
            if(angle >= min_angle || angle <= max_angle) continue;

            cartesian coordinate;

            coordinate.x_coordinate = findX(angle, dist);
            coordinate.y_coordinate = findY(angle, dist);
            coordinate.z_coordinate = findZ(angle, dist);

            finished_points.push_back(coordinate);
        }
    } else {
        std::cerr << "Failed to grab scan data." << std::endl;
    }

    saveToFile(finished_points);
    drv->stop();
    drv->setMotorSpeed(0);

    if (drv) {
        delete drv;
    }

    return 0;
}
int findX(const float &angle, const float &distance){
    int x;
    return x; 
}


int findY(const float &angle, const float &distance){
    int x;
    return x; 
}



int findZ(const float &angle, const float &distance){
    int x;
    return x; 
}

void saveToFile(std::vector<cartesian> points){
    std::string file_name = "sorted_xyz.csv";
    std::ofstream file(file_name);

    if(!file.is_open()){
        std::cerr << "The file has failed to open; possibly failed" << std::endl;
        std::cout << "Filename tried: " << file_name << std::endl;
    }

    for(const auto& p: points){
        file << p.x_coordinate << p.y_coordinate << p.z_coordinate << std::endl; 
    }
}
