//
// Created by Admin on 05.01.2021.
//

#include "Vehicle.h"
#include "Input_Output.h"
#include <iostream>


long double Vehicle::get_price() const {
    return price;
}

std::string Vehicle::get_colour() const {
    return colour;
}

void Vehicle::set_price(double new_price) {
    Vehicle::price = new_price;
}
