//
// Created by Admin on 05.01.2021.
//

#include "Vehicle.h"

long double Vehicle::get_price() const {
    return price;
}

std::string Vehicle::get_colour() const {
    return colour;
}

void Vehicle::set_price(double new_price) {
    price = new_price;
}

void Vehicle::set_colour(std::string & new_color) {
    colour = new_color;
}
