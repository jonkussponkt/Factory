//
// Created by Admin on 05.01.2021.
//

#ifndef FABRYKA_VEHICLE_H
#define FABRYKA_VEHICLE_H

#include <string>

class Vehicle {
    std::string owner;
    std::string colour;
    double price;
protected:
    double trunk_capacity;
public:
    virtual void create_vehicle();
    virtual std::string print_veh_data();
    explicit Vehicle(std::string who_owns = "Factory", std::string painted_in = "", double trunk = 0.0, double money = 0) :
            owner(std::move(who_owns)), colour(std::move(painted_in)), trunk_capacity(trunk), price(money){};
    virtual ~Vehicle() = default;
};


#endif //FABRYKA_VEHICLE_H
