//
// Created by Admin on 05.01.2021.
//

#include <fstream>
#include "Car.h"
#include "Input_Output.h"

void Car::create_motor_vehicle(int ID) {
    int number, spaces, first_space, second_space;
    double money;
    std::string str_vehicle;
    std::fstream Key_To_Data;

    number = 1;
    Key_To_Data.open("Car_Parking.txt", std::ios::in);
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
    set_colour(colour);
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
            else if (spaces == 3) {
                first_space = second_space;
                second_space = i;
                mileage = std::stod(str_vehicle.substr(first_space, second_space));
                spaces++;
            }
            else if (spaces == 4){
                first_space = second_space;
                second_space = i;
                number_of_doors = std::stoi(str_vehicle.substr(first_space, second_space));
                money = std::stod(str_vehicle.substr(second_space + 1, str_vehicle.find('\n')));
                set_price(money);
                spaces++;
            }
        }
    }
}

void Car::drive(int ID, const std::string & file_name) {
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
    i = 0;
    while(i < Produced_Vehicles.size()){
        if (i == ID)
            Save_To_File << *this;
        else
            Save_To_File << Produced_Vehicles.at(i);
        if(i != Produced_Vehicles.size() - 1)
            Save_To_File << '\n';
        i++;
    }
    Save_To_File.close();
}

std::ostream & operator<<(std::ostream & file, const Car & car) {
    file << car.get_colour() << " " << car.capacity << " "  << car.gas_capacity << " "
         << car.mileage << " " << car.number_of_doors << " " << car.get_price();
    return file;
}


