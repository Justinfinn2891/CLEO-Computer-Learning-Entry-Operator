#include "../include/coordinates.h"
#include <cmath>

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