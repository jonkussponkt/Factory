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
    double gas_capacity{};
public:
    void create_vehicle() override;
    std::string print_veh_data() override;
    Motor_Vehicle(std::string who_owns, std::string colour, double capacity, double money)
                            : Vehicle(std::move(who_owns), std::move(colour), capacity, money){};
    ~Motor_Vehicle() override = default;
};


#endif //FABRYKA_MOTOR_VEHICLE_H