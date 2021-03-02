//
// Created by Admin on 05.01.2021.
//

#include "Vehicle.h"
#include "Input_Output.h"
#include <iostream>

void Vehicle::paint_a_vehicle() {
    std::string new_colour;
    std::cout << "Input new colour of vehicle";
    new_colour = Input_Output::Input_String();
    colour = new_colour;
}

void Vehicle::print_veh_data() {
    std::cout << "  OWNER: " << owner << "  COLOUR: " << colour << "  TRUNK'S CAPACITY: " << capacity;
}

long double Vehicle::get_price() const {
    return price;
}

std::string Vehicle::get_colour() const {
    return colour;
}
