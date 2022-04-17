//
// Created by Admin on 05.01.2021.
//

#include <iostream>
#include "Input_Output.h"
#include "Motorcycle.h"

void Motorcycle::create_vehicle() {
    std::string basket;
    Motor_Vehicle::create_vehicle();
    std::cout << "Decide if vehicle has got a basket\nPress 1 - if so, otherwise press anything\n";
    basket = Input_Output::Input_String();
    if(basket == "1") {
        std::cout << "Type capacity of vehicle's basket\n";
        trunk_capacity = Input_Output::Input_Double();
    }
}

std::string Motorcycle::print_veh_data() {
    cout.precision(2);
    return Motor_Vehicle::print_veh_data() + " " + std::to_string(trunk_capacity);
}
