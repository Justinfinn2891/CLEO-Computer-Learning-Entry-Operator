#ifndef COORDINATES_H
#define COORDINATES_H

class Coordinates{
 
    public:

    float findX(const float &horizontalAngle, const float &verticleAngle, const float &distance);
    float findY(const float &horizontalAngle, const float &verticleAngle, const float &distance);
    float findZ(const float &verticleAngle, const float &distance);

    struct cartesian{
    float x_coordinate, y_coordinate, z_coordinate;
    };

    struct raw_data{
    float distance, angleH, angleV; 
    };

};
#endif //COORDINATES_H