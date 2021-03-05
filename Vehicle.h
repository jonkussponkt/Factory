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
    double capacity; ///capacity of car's trunk
public:
    long double get_price() const;
    std::string get_colour() const;
    void set_price(double new_price);
    Vehicle(std::string who_owns = "Factory", std::string painted_in = "", double trunk = 0.0, long double money = 0) :
            owner(who_owns), colour(painted_in), capacity(trunk), price(money){};
    virtual ~Vehicle(){}

};


#endif //FABRYKA_VEHICLE_H
