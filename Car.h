//
// Created by Admin on 05.01.2021.
//

#ifndef FABRYKA_CAR_H
#define FABRYKA_CAR_H

#include <string>
#include "Motor_Vehicle.h"

class Car : public Motor_Vehicle {
    int number_of_doors;
public:
    void drive() override;
    double get_capacity() override;
    Car(std::string who_owns = "Factory", std::string colour = "", double capacity = 0.0, double gas = 0.0,
        double miles = 0.0, int doors = 0, long double money = 0.0) :
        Motor_Vehicle(who_owns, colour, capacity, gas, miles, money), number_of_doors(doors){};
    ~Car() override{};
};

#endif //FABRYKA_CAR_H
