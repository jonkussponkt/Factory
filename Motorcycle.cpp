//
// Created by Admin on 05.01.2021.
//

#include <iostream>
#include <fstream>
#include "Input_Output.h"
#include "Motorcycle.h"

void Motorcycle::create_motor_vehicle(int ID) {
    int number, spaces, first_space, second_space;
    double money;
    std::string str_vehicle;
    std::fstream Key_To_Data;
    number = 1;
    Key_To_Data.open("Motorbike_Parking.txt", std::ios::in);
    std::getline(Key_To_Data, str_vehicle);
    if(str_vehicle.empty())
        std::cout << "There are no such vehicles in factory\n";
    while(number < ID && std::getline(Key_To_Data, str_vehicle)){
        number++;
    }
    Key_To_Data.close();

    spaces = 1;
    first_space = 0;
    second_space = str_vehicle.find_first_of(' ');
    int i = second_space;
    std::string colour = str_vehicle.substr(first_space, second_space);
    while(spaces < 5 && i < str_vehicle.size()){
        i++;
        if(str_vehicle[i] == ' ') {
            if (spaces == 1) {
                first_space = second_space;
                second_space = i;
                capacity = std::stod(str_vehicle.substr(first_space, second_space));
                spaces++;
            }
            else if (spaces == 2) {
                first_space = second_space;
                second_space = i;
                gas_capacity = std::stod(str_vehicle.substr(first_space, second_space));
                spaces++;
            }
            else if (spaces == 3){
                first_space = second_space;
                second_space = i;
                spaces++;
            }
            else if (spaces == 4) {
                first_space = second_space;
                second_space = i;
                mileage = std::stod(str_vehicle.substr(first_space, second_space));
                money = std::stod(str_vehicle.substr(second_space + 1, str_vehicle.find('\n')));
                set_price(money);
                spaces++;
            }
        }
    }
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

std::ostream & operator<<(std::ostream & file, const Motorcycle &motorcycle) {
    file << motorcycle.get_colour() << " " << motorcycle.capacity << " " << motorcycle.gas_capacity << " "
         << motorcycle.gas_in_engine << " " << motorcycle.get_price();
    return file;
}

