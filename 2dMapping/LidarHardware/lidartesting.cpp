#include <fstream>
#include <iostream>
#include <cmath>
#include <vector>
#include <sstream>
#include <cstdlib>  // for system()
// Keeping std for testing purposes
using namespace std;

/* Purpose of this script is to help fix our cartesian math issue. 
We will grab data from previous scans to see if we can accurately plot a 3d plane */
const int MAX = 10000;

struct cartesian{
    float x_coordinate, y_coordinate, z_coordinate;
};

float findX(const float &horizontalAngle, const float &verticleAngle, const float &distance);
float findY(const float &horizontalAngle, const float &verticleAngle, const float &distance);
float findZ(const float &verticleAngle, const float &distance);
void saveToFile(std::vector<cartesian> points);

int main(){

    ifstream file;

    // put in a testing script, something we previously scan from lidar.cpp 
    //system("./lidar");
    file.open("raw_lidar.csv");

    int i = 0;
    float angle[MAX]; 
    float distance[MAX];
    int testHorizontalAngle = 0;
    std::string line;
    cout << "Loading the file, extracting data now..." << endl; 
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string angleStr, distStr;

        if (std::getline(ss, angleStr, ',') && std::getline(ss, distStr, ',')) {
            angle[i] = std::stof(angleStr);
            distance[i] = std::stof(distStr);
            i++;
        }
    }

    cout << "data extraction: COMPLETE" << endl; 

    vector <cartesian> finished_points;
    for(int j = 0; j < i; j++) {
        float horizRad = (angle[j] * 90.f) / 16384.f; 
        horizRad *= M_PI / 180.0f;

        float verticalAngle = testHorizontalAngle * M_PI / 180.0f;  
        float dist = distance[j] / 4.0f;

        
        cartesian coordinate;
        coordinate.x_coordinate = findX(horizRad, verticalAngle, dist);
        coordinate.y_coordinate = findY(horizRad, verticalAngle, dist);
        coordinate.z_coordinate = findZ(verticalAngle, dist);

        if(coordinate.x_coordinate == 0 && coordinate.y_coordinate == 0 && coordinate.z_coordinate == 0) continue;
        if(coordinate.x_coordinate == NULL && coordinate.y_coordinate == NULL && coordinate.z_coordinate == NULL) continue;
        
        finished_points.push_back(coordinate);
    }
    saveToFile(finished_points);
    file.close();
    return 0;
}


/* All of this stuff remains the same from the other .cpp file */
//Find the x based on two angles and a distance
float findX(const float &horizontalAngle, const float &verticleAngle, const float &distance){
    return (distance * cos(verticleAngle) * cos(horizontalAngle));
}

//Find the y based on two angles and a distance
float findY(const float &horizontalAngle, const float &verticleAngle, const float &distance){
    return (distance * cos(verticleAngle) * sin(horizontalAngle)); 
}

//Find the z based on one angle and a distance
float findZ(const float &verticleAngle, const float &distance){
    return (distance * sin(verticleAngle));
}



//Attemps to create or open a csv file for storing the refind points
void saveToFile(std::vector<cartesian> points){
    std::string file_name = "test.csv";
    std::ofstream file(file_name, std::ios::app);
    cout << "IT SAVED";
    if(!file.is_open()){
        std::cerr << "The file has failed to open; possibly failed" << std::endl;
        std::cout << "Filename tried: " << file_name << std::endl;
    }


    for(const auto& p: points){
        file << p.x_coordinate << "," << p.y_coordinate << "," << p.z_coordinate << std::endl; 
    }
}