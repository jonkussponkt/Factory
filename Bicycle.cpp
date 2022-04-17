//
// Created by Admin on 05.01.2021.
//

#include <iostream>
#include "Bicycle.h"
#include "Input_Output.h"

void Bicycle::create_vehicle() {
    std::string basket;
    Vehicle::create_vehicle();
    std::cout << "Decide if vehicle has got a basket\nPress 1 - if so, otherwise press anything\n";
    basket = Input_Output::Input_String();
    if(basket == "1") {
        do {
            std::cout << "Type capacity of vehicle's basket (up to 1000)\n";
            try {
                trunk_capacity = Input_Output::Input_Double();
            }
            catch (...) {
                std::cout << "The value is incorrect! Type the number!";
            }
        }
        while(trunk_capacity < 0 && trunk_capacity > 1000);
    }
}
