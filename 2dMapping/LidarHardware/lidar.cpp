#include "rplidar.h" // Need for the functions in the SDK
#include <iostream>
#include <fstream>
#include <string> 
/* For the objects we are going to make*/
using namespace rp::standalone::rplidar;

int main(int argc, const char *argv[]){
  
    ofstream file; 
    bool isFailed = false;
    const char *serial_port = "/dev/ttyUSB0"; // port we will need for rasberry to talk to lidar
    _u32 baudrate = 115200; // communication speed for our lidar 

    RPlidarDriver *driver = RPlidarDriver::CreateDriver(DRIVER_TYPE_SERIALPORT);

    if(!driver){
        std::cerr << "Creating the driver has failed!" << std::endl; 
        isFailed = true
        return -1;
    }

    if(IS_FAIL(driver->connect(serial_port, baudrate))){
        std::cerr << "Communication between PI and Lidar FAILED" << std::endl;
        isFailed = true;
        return -1;
    }

    if(!isFailed)
         driver->startMotor();
    
    if(IS_FAIL(driver->startScan(0,1))){ // Start normal scan
        std::cerr << "Error to start the scan" << std::endl;
        return -1
    }

    // This array will hold all the scan measurements that we get 
    rplidar_response_measurement_node_hq_t nodes[8192];
    size_t count; // The amount of actual points that we have 

    while(true){
        count = sizeof(nodes) / sizeof(nodes[0]); // Maximum number of nodes that it can carry
        u_result result = driver->grabScanDataHq(nodes, count) // Asking the lidar for the scan
        std::string userInput; 
        if(IS_OK(result)){
            driver->ascendScanData(nodes, count); // puts the nodes in an ascending order based off angle            
            std::cout << "Are you ready for the data?: " << endl;
            std::cin >> userInput; 
            file.open("data.txt");
            if(userInput.upper() == "YES"){
                for(size_t pos = 0; pos < count; pos++){
                    float angle = nodes[pos].angle_z_q14 * 90.f / (1 << 14); // takes the raw data and coverts it into degrees
                    float distance = nodes[pos].dist_mm_q2 / 4.0f; // raw distance / 4 to get millimeters
                    std::cout << "Angle: " << angle << "distance: " << distance << std::endl; 
                    file << angle << distance; 
                }
            }
            else{
                return -1;
            }
        }
    }

    file.close();
    driver->stop();
    driver->stopMotor();
    RPlidarDriver::DisposeDriver(drv);

    return 0; 

}