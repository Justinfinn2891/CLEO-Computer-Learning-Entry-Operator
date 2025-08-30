#include <iostream>
#include <fstream>
#include <random>

int main(){

    std::ofstream file("Random_coordinates.csv");

    srand(time(0));
    int y = 0;
    for(int i = 0; i < 9999; i++){
        file << ((rand() % 830) + 100);
        file << ',';
    }
    file << ((rand() % 830) + 100) << ",";

    file.close();
    return 0;

}