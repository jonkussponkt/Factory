//
// Created by Admin on 05.01.2021.
//

#include <iostream>
#include "Input_Output.h"
#include "Motorcycle.h"


double Motorcycle::get_capacity() {
    return capacity;
}

void Motorcycle::drive() {
    double driven_road = 0.0;
    double maximum = gas_capacity / 0.045;
    std::string fuel;

    do {
        try {
            std::cout << "Input driven road in kilometers:\n";
            driven_road = Input_Output::Input_Double_From_Range(0, maximum);
        }
        catch (const Way_Too_Long &way_too_long) {
            std::cout << way_too_long.what() << std::endl;
        }
    }
    while(driven_road < 0 || driven_road >= maximum);
    gas_in_engine -= driven_road * 0.045;
    mileage += driven_road;
    std::cout << "Gas in engine currently: " << gas_in_engine << "\nDo you want to fuel the motorcycle up? "
                                                                 " If so, press 1, otherwise press anything\n";
    fuel = Input_Output::Input_String();
    if(fuel == "1")
        fuel_up();
}
