# CLEO - Computer Learning Educational Operator

Project Tracker -> https://docs.google.com/spreadsheets/d/12y3wJU4cHn6q5bq1VsLETFq5kpCxoWj3vPIzxyNg8aM/edit?usp=sharing
g++ lidar.cpp -o mylidar -I./rplidar_sdk-master/sdk/include -I./rplidar_sdk-master/sdk/src ./rplidar_sdk-master/output/Linux/Release/libsl_lidar_sdk.a
/usr/bin/ld: cannot find ./rplidar_sdk-master/output/Linux/Release/libsl_lidar_sdk.a: No such file or directory
collect2: error: ld returned 1 exit status
Guys we need to a git ignore file 

its now leo :( lidar entry operator



g++ lidar.cpp -o mylidar -I./rplidar_sdk-master/sdk/include -I./rplidar_sdk-master/sdk/src ~/rplidar_sdk-maste
r/output/Linux/Release/libsl_lidar_sdk.a
/usr/bin/ld: /tmp/ccHum8mq.o: in function `main':
lidar.cpp:(.text+0x54): undefined reference to `rp::standalone::rplidar::RPlidarDriver::CreateDriver(unsigned int)'
/usr/bin/ld: lidar.cpp:(.text+0xc0): undefined reference to `rp::standalone::rplidar::RPlidarDriver::connect(char const*, unsigned int, unsigned int)'
/usr/bin/ld: lidar.cpp:(.text+0x128): undefined reference to `rp::standalone::rplidar::RPlidarDriver::startMotor()'
/usr/bin/ld: lidar.cpp:(.text+0x144): undefined reference to `rp::standalone::rplidar::RPlidarDriver::startScan(bool, bool, unsigned int, sl::LidarScanMode*)'
/usr/bin/ld: lidar.cpp:(.text+0x1a4): undefined reference to `rp::standalone::rplidar::RPlidarDriver::grabScanDataHq(sl_lidar_response_measurement_node_hq_t*, unsigned long&, unsigned int)'
/usr/bin/ld: lidar.cpp:(.text+0x1e0): undefined reference to `rp::standalone::rplidar::RPlidarDriver::ascendScanData(sl_lidar_response_measurement_node_hq_t*, unsigned long)'
/usr/bin/ld: lidar.cpp:(.text+0x3b8): undefined reference to `rp::standalone::rplidar::RPlidarDriver::stop(unsigned int)'
/usr/bin/ld: lidar.cpp:(.text+0x3c4): undefined reference to `rp::standalone::rplidar::RPlidarDriver::stopMotor()'
/usr/bin/ld: lidar.cpp:(.text+0x3d0): undefined reference to `rp::standalone::rplidar::RPlidarDriver::DisposeDriver(rp::standalone::rplidar::RPlidarDriver*)'
collect2: error: ld returned 1 exit status
