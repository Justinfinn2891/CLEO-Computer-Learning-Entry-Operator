# CLEO - Computer Learning Educational Operator

Project Tracker -> https://docs.google.com/spreadsheets/d/12y3wJU4cHn6q5bq1VsLETFq5kpCxoWj3vPIzxyNg8aM/edit?usp=sharing
g++ lidar.cpp -o mylidar -I./rplidar_sdk-master/sdk/include -I./rplidar_sdk-master/sdk/src ./rplidar_sdk-master/output/Linux/Release/libsl_lidar_sdk.a
/usr/bin/ld: cannot find ./rplidar_sdk-master/output/Linux/Release/libsl_lidar_sdk.a: No such file or directory
collect2: error: ld returned 1 exit status
Guys we need to a git ignore file 

its now leo :( lidar entry operator



g++ lidar.cpp -o mylidar -I./rplidar_sdk-master/sdk/include -I./rplidar_sdk-master/sdk/src ~/rplidar_sdk-maste
r/output/Linux/Release/libsl_lidar_sdk.a



cmake_minimum_required(VERSION 3.10)
project(MyRPLidarProject)

# Use C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Path to the SDK
set(RPLIDAR_SDK_PATH "${CMAKE_SOURCE_DIR}/rplidar_sdk-master/sdk")

# Include SDK headers
include_directories(
    "${RPLIDAR_SDK_PATH}/include"
)

# Add your program
add_executable(mylidar
    "${CMAKE_SOURCE_DIR}/lidar.cpp"
)

# Link against the prebuilt SDK library
# Make sure you built the SDK first with 'make' inside sdk/
target_link_libraries(mylidar
    "${RPLIDAR_SDK_PATH}/output/Linux/Release/libsl_lidar_sdk.a"
)

# Optional: add pthread if needed by SDK
find_package(Threads REQUIRED)
target_link_libraries(mylidar Threads::Threads)
