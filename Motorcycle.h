//
// Created by Admin on 05.01.2021.
//

#ifndef FABRYKA_MOTORCYCLE_H
#define FABRYKA_MOTORCYCLE_H

#include "Motor_Vehicle.h"

class Motorcycle : public Motor_Vehicle{
public:
    void create_motor_vehicle(int ID);
    void drive() override;
    friend std::ostream & operator << (std::ostream & file, const Motorcycle & motorcycle);
    Motorcycle(std::string who_owns, std::string colour, double capacity, double gas,
               double miles, long double money)
    : Motor_Vehicle(who_owns, colour, capacity, gas, miles, money){};
    ~Motorcycle() = default;
};


#endif //FABRYKA_MOTORCYCLE_H
