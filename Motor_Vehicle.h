//
// Created by Admin on 05.01.2021.
//

#ifndef FABRYKA_MOTOR_VEHICLE_H
#define FABRYKA_MOTOR_VEHICLE_H

#include "Vehicle.h"
#include <iostream>

using std::cout;

class Motor_Vehicle : public Vehicle {
protected:
    double gas_capacity;
    double gas_in_engine;
    double mileage;
public:
    virtual void drive() = 0;
    void fuel_up();
    void print_info();
    explicit Motor_Vehicle(std::string who_owns, std::string colour, double capacity, double gas = 0.0,
                           double length = 0.0, long double money = 0.0)
                            : Vehicle(who_owns, colour, capacity, money), gas_capacity(gas), gas_in_engine(gas),
                              mileage(length){};
    virtual ~Motor_Vehicle(){};
};


#endif //FABRYKA_MOTOR_VEHICLE_H