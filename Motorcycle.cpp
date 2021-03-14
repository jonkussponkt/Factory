//
// Created by Admin on 05.01.2021.
//

#include <iostream>
#include <fstream>
#include "Input_Output.h"
#include "Motorcycle.h"

void Motorcycle::create_motor_vehicle(int ID) {
    int number, spaces, first_space, second_space;
    double money, new_capacity, new_gas;
    std::string str_vehicle;
    std::fstream Key_To_Data;
    number = 1;
    Key_To_Data.open("Motorbike_Parking.txt", std::ios::in);
    if(Key_To_Data.good()) {
        std::getline(Key_To_Data, str_vehicle);
        if (str_vehicle.empty())
            std::cout << "There are no such vehicles in factory\n";
        while (number < ID && std::getline(Key_To_Data, str_vehicle)) {
            number++;
        }
        Key_To_Data.close();

        spaces = 1;
        first_space = 0;
        second_space = str_vehicle.find_first_of(' ');
        int i = second_space;
        std::string colour = str_vehicle.substr(first_space, second_space);
        set_colour(colour);
        while (spaces < 4 && i < str_vehicle.size()) {
            i++;
            if (str_vehicle[i] == ' ') {
                if (spaces == 1) {
                    first_space = second_space;
                    second_space = i;
                    new_capacity = std::stod(str_vehicle.substr(first_space, second_space));
                    set_capacity(new_capacity);
                    spaces++;
                }
                else if (spaces == 2) {
                    first_space = second_space;
                    second_space = i;
                    new_gas = std::stod(str_vehicle.substr(first_space, second_space));
                    set_gas_capacity(new_gas);
                    spaces++;
                }
                else if (spaces == 3) {
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
    else
        throw Bad_File();
}

void Motorcycle::drive(int ID, const std::string &file_name) {
    std::vector<std::string> Produced_Vehicles;
    int i;
    std::fstream Save_To_File;
    Produced_Vehicles = Input_Output::read_the_vector(file_name);

    double driven_road = -1.0;
    do {
        try {
            std::cout << "Input driven road in kilometers - max 40 kms";
            driven_road = Input_Output::Input_Double_From_Range(0, 40);
        }
        catch (const Way_Too_Long &way_too_long) {
            std::cout << way_too_long.what() << std::endl;
        }
    }
    while(driven_road < 0 || driven_road > 40);
    mileage += driven_road;
    Save_To_File.open(file_name, std::ios::out);
    if(Save_To_File.good()) {
        i = 0;
        while (i < Produced_Vehicles.size()) {
            if (i == ID - 1)
                Save_To_File << *this << '\n';
            else
                Save_To_File << Produced_Vehicles.at(i) << '\n';
            i++;
        }
        Save_To_File.close();
    }
}

std::ostream & operator<<(std::ostream & file, const Motorcycle &motorcycle) {
    file << motorcycle.get_colour() << " " << motorcycle.get_capacity() << " " << motorcycle.get_gas_capacity()
         << " " << motorcycle.mileage << " " << motorcycle.get_price();
    return file;
}
