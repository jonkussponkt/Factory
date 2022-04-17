//
// Created by Admin on 05.01.2021.
//

#include <iostream>
#include "Motor_Vehicle.h"
#include "Input_Output.h"

void Motor_Vehicle::create_vehicle() {
    Vehicle::create_vehicle();
    do {
        try {
            std::cout << "Type capacity of vehicle's engine\n";
            gas_capacity = Input_Output::Input_Double();
        }
        catch(const Wrong_Input & wrong_input) {
            std::cout << wrong_input.what();
        }
        catch(...) {
            std::cout << "The value is incorrect! Type the number!\n";
        }
    } while(gas_capacity <= 0 || gas_capacity > 60);
}

std::string Motor_Vehicle::print_veh_data() {
    return Vehicle::print_veh_data() + " " + std::to_string(gas_capacity);
}
