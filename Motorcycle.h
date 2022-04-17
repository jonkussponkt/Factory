//
// Created by Admin on 05.01.2021.
//

#ifndef FABRYKA_MOTORCYCLE_H
#define FABRYKA_MOTORCYCLE_H

#include "Motor_Vehicle.h"

class Motorcycle : public Motor_Vehicle{
public:
    void create_vehicle() override;
    std::string print_veh_data() override;
    explicit Motorcycle(std::string who_owns="", std::string colour="", double capacity=0.0, double gas=0.0, long double money=0.0)
    : Motor_Vehicle(std::move(who_owns), std::move(colour), gas, money){};
    ~Motorcycle() override = default;
};


#endif //FABRYKA_MOTORCYCLE_H
