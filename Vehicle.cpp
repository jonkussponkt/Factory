//
// Created by Admin on 05.01.2021.
//

#include "Vehicle.h"
#include "Input_Output.h"
#include <iostream>
#include <algorithm>
#include <cctype>

void Vehicle::create_vehicle() {
    do {
        try {
            std::cout << "Type price of the vehicle\n";
            price = Input_Output::Input_Double();
        }
        catch (...) {
            std::cout << "The value is incorrect! Type the number!\n";
        }
    } while(price < 4000);
    do {
        std::cout << "Type color of the vehicle\n";
        colour = Input_Output::Input_String();
    } while(colour.empty());
    std::for_each(colour.begin(), colour.end(), [](char & c) -> void { if(isblank(c)) c='-'; });
}

std::string Vehicle::print_veh_data() {
    std::cout.precision(2);
    return owner + " " + colour + " " + std::to_string(price) + " "  + std::to_string(trunk_capacity);
}
