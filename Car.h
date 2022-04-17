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
    [[noreturn]] void create_vehicle() override;
    std::string print_veh_data() override;
    explicit Car(std::string who_owns = "Factory", std::string colour = "", double capacity = 0.0, double gas = 0.0,
        double miles = 0.0, int doors = 0, long double money = 0.0) :
        Motor_Vehicle(std::move(who_owns), std::move(colour), capacity, money), number_of_doors(doors){};
    ~Car() override = default;
};

#endif //FABRYKA_CAR_H
