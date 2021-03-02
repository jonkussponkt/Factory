//
// Created by Admin on 05.01.2021.
//

#ifndef FABRYKA_BICYCLE_H
#define FABRYKA_BICYCLE_H

#include "Vehicle.h"

class Bicycle : public Vehicle {
public:
    double get_capacity() override;
    friend std::ostream & operator << (std::ostream & file, const Bicycle & bicycle);
    Bicycle(std::string painted_in, double trunk, long double how_much) : Vehicle("Factory", painted_in, trunk, how_much){};
    ~Bicycle() override {};
};


#endif //FABRYKA_BICYCLE_H
