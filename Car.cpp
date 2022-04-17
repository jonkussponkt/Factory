//
// Created by Admin on 05.01.2021.
//

#include "Car.h"
#include "Input_Output.h"

void Car::create_vehicle() {
    Motor_Vehicle::create_vehicle();
    do {
        try {
            std::cout << "Type number of doors of vehicle\n";
            number_of_doors = Input_Output::Input_Number();
        }
        catch (...) {
            std::cout << "The value is incorrect! Type the right number - 2, 4 or 6!";
        }
    } while(number_of_doors < 2 || number_of_doors == 3 || number_of_doors == 5 || number_of_doors > 6);
    do {
        try {
            std::cout << "Type capacity of vehicle's trunk\n";
            trunk_capacity = Input_Output::Input_Double();
        }
        catch(const Wrong_Input &wrong_input){
            std::cout << wrong_input.what();
        }
        catch (...) {
            std::cout << "The value is incorrect! Type the right number - 2, 4 or 6!";
        }
    }
    while(trunk_capacity <= 0 || trunk_capacity > 1000);
}

std::string Car::print_veh_data() {
    cout.precision(2);
    return Motor_Vehicle::print_veh_data() + " " + std::to_string(number_of_doors);
}


