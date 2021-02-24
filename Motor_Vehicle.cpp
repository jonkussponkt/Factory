//
// Created by Admin on 05.01.2021.
//

#include <iostream>
#include "Motor_Vehicle.h"

void Motor_Vehicle::fuel_up() {
    gas_in_engine = gas_capacity;
}

void Motor_Vehicle::print_info() {
    print_veh_data();
    std::cout << "  GAS IN ENGINE: " << gas_in_engine << "  ENGINE'S CAPACITY : " << gas_capacity << "  MILEAGE: " << mileage;
}

