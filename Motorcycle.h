//
// Created by Admin on 05.01.2021.
//

#ifndef FABRYKA_MOTORCYCLE_H
#define FABRYKA_MOTORCYCLE_H

#include "Motor_Vehicle.h"

class Motorcycle : public Motor_Vehicle{
public:
    void create_motor_vehicle(int ID) override;
    void drive(int ID, const std::string & file_name) override;
    friend std::ostream & operator << (std::ostream & file, const Motorcycle & motorcycle);
    Motorcycle(std::string who_owns = "Factory", std::string colour = "", double capacity = 0.0, double gas = 0.0,
               double miles = 0.0, long double money = 0.0)
    : Motor_Vehicle(who_owns, colour, capacity, gas, miles, money){}
    ~Motorcycle() = default;
};


#endif //FABRYKA_MOTORCYCLE_H
