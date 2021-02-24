//
// Created by Admin on 05.01.2021.
//

#ifndef FABRYKA_MOTORCYCLE_H
#define FABRYKA_MOTORCYCLE_H

#include "Motor_Vehicle.h"

class Motorcycle : public Motor_Vehicle{
public:
    void drive() override;
    double get_capacity() override;
    Motorcycle(std::string who_owns, std::string colour, double capacity, double gas,
               double miles, long double money)
    : Motor_Vehicle(who_owns, colour, capacity, gas, miles, money){};
    ~Motorcycle() = default;
};


#endif //FABRYKA_MOTORCYCLE_H
