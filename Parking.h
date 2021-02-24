//
// Created by Admin on 21.02.2021.
//

#ifndef FABRYKA_PARKING_H
#define FABRYKA_PARKING_H

#include <fstream>
#include <vector>

class Parking {
    std::fstream Car_Parking;
    std::fstream Motorbike_Parking;
    std::fstream Bicycle_Parking;
    std::vector<int> Car_Off {};
    std::vector<int> Motor_Off {};
    std::vector<int> Bicycle_Off {};
};


#endif //FABRYKA_PARKING_H
