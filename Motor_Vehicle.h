//
// Created by Admin on 05.01.2021.
//

#ifndef FABRYKA_MOTOR_VEHICLE_H
#define FABRYKA_MOTOR_VEHICLE_H

#include "Vehicle.h"
#include <iostream>
#include <vector>

class Motor_Vehicle : public Vehicle {
protected:
    double gas_capacity;
    double mileage;
public:
    virtual void create_motor_vehicle(int ID) = 0;
    virtual void drive(int ID, const std::string & file_name) = 0;
    Motor_Vehicle(std::string who_owns, std::string colour, double capacity, double gas = 0.0,
                  double length = 0.0, long double money = 0.0)
                  : Vehicle(who_owns, colour, capacity, money), gas_capacity(gas), mileage(length){};
    virtual ~Motor_Vehicle(){};
};


#endif //FABRYKA_MOTOR_VEHICLE_H