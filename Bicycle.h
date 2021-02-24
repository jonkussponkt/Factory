//
// Created by Admin on 05.01.2021.
//

#ifndef FABRYKA_BICYCLE_H
#define FABRYKA_BICYCLE_H

#include "Vehicle.h"

class Bicycle : public Vehicle {
public:
    double get_capacity() override;
    Bicycle(std::string painted_in, double how_much) : Vehicle("Factory", painted_in, how_much){};
    ~Bicycle() override {};
};


#endif //FABRYKA_BICYCLE_H
