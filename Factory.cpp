//
// Created by Admin on 05.01.2021.
//

#include "Factory.h"
#include "Input_Output.h"

#include <iostream>
#include <string>
#include <fstream>

void Factory::produce(int type) {
    int how_many;
    int doors;
    int ID = 1;
    bool empty_file = false;
    double trunk = 0.0;
    double gas;
    long double money;
    std::string basket = "1";
    std::string the_same;
    std::string colour;
    std::string first_line;
    std::fstream Key_To_Data;


    std::cout << "Input how many ";
    if(type == 1)
        std::cout << "cars ";
    else if(type == 2)
        std::cout << "motorbikes ";
    else if(type == 3)
        std::cout << "bicycles ";
    std::cout << "you want to add\n";
    how_many = Input_Output::Input_Number();
    if(how_many > 1) {
        std::cout << "Decide if they are to be the same vehicles - press 1, otherwise press anything\n";
        the_same = Input_Output::Input_String();
    }

    while (how_many > 0) {
        std::cout << "VEHICLE NR " << ID << std::endl;
        std::cout << "Type price of the vehicle\n";
        money = Input_Output::Input_Number();
        std::cout << "Type color of the vehicle\n";
        colour = Input_Output::Input_String();

        if (type != 1) {
            std::cout << "Decide if vehicle has got a basket\nPress 1 - if so, otherwise press anything\n";
            basket = Input_Output::Input_String();
        }


        if(basket == "1") {
            std::cout << "Type capacity of vehicle's";
            if (type == 1)
                std::cout << " trunk\n";
            else
                std::cout << " basket\n";
            trunk = Input_Output::Input_Double();
        }

        int internal_iterator;
        if (type != 3) {
            std::cout << "Type capacity of vehicle's engine\n";
            gas = Input_Output::Input_Double();
            if (type == 1) {
                std::cout << "Type number of doors of vehicle\n";
                doors = Input_Output::Input_Number();

                Key_To_Data.open("Car_Parking.txt", std::ios::in);
                std::getline(Key_To_Data, first_line);
                if(first_line.empty())
                    empty_file = true;
                Key_To_Data.close();

                if(the_same == "1")
                    internal_iterator = how_many;
                else
                    internal_iterator = 1;

                Key_To_Data.open("Car_Parking.txt", std::ios::out | std::ios::app);
                Car new_vehicle = Car("Factory", colour, trunk, gas, 0.0, doors, money);
                while (internal_iterator > 0) {
                    if(!empty_file)
                        Key_To_Data << '\n';
                    empty_file = false;
                    Key_To_Data << new_vehicle;
                    internal_iterator--;
                    how_many--;
                }
                Key_To_Data.close();
            }
            else {

                Key_To_Data.open("Motorbike_Parking.txt", std::ios::in);
                std::getline(Key_To_Data, first_line);
                if(first_line.empty())
                    empty_file = true;
                Key_To_Data.close();


                if(the_same == "1")
                    internal_iterator = how_many;
                else
                    internal_iterator = 1;
                Key_To_Data.open("Motorbike_Parking.txt", std::ios::out | std::ios::app);
                Motorcycle new_motor = Motorcycle("Factory", colour, trunk, gas, 0.0, money);
                while (internal_iterator > 0) {
                    if(!empty_file)
                        Key_To_Data << '\n';
                    Key_To_Data << new_motor;
                    empty_file = false;
                    internal_iterator--;
                    how_many--;
                }
                Key_To_Data.close();
            }
        }
        else {
            Key_To_Data.open("Bicycle_Parking.txt", std::ios::in);
            std::getline(Key_To_Data, first_line);
            if(first_line.empty())
                empty_file = true;
            Key_To_Data.close();

            Key_To_Data.open("Bicycle_Parking.txt", std::ios::out | std::ios::app);
            Bicycle new_bic = Bicycle(colour, trunk, money);
            if(the_same == "1")
                internal_iterator = how_many;
            else
                internal_iterator = 1;
            while (internal_iterator > 0) {
                if(!empty_file)
                    Key_To_Data << '\n';
                Key_To_Data << new_bic;
                empty_file = false;
                internal_iterator--;
                how_many--;
            }
            Key_To_Data.close();

        }
        ID++;
    }
}

void Factory::sell(const std::string &file_name) {
    int ID;
    int payment;
    int number;
    std::string decision;
    std::string From_File;
    std::fstream Key_To_Data;
    std::fstream Temp;
    std::vector<std::string> Produced_Vehicles;

    Key_To_Data.open(file_name.c_str(), std::ios::in);
    std::getline(Key_To_Data, From_File);

    Produced_Vehicles.emplace_back(From_File);
    if (From_File.empty())
        std::cout << "There are no such vehicles in factory\n";
    else {
//TODO
        do {
            std::cout << "Type ID of the vehicle you want to buy\n";
            ID = Input_Output::Input_Number();
            std::cout << "Press anything to confirm your choice\nIf you want to decide once more - press 1";
            decision = Input_Output::Input_String();
        }
        while (decision == "1");

        number = 1;
        int space_position;
        int last_character;

        while (std::getline(Key_To_Data, From_File)) {
            if (number == ID) {
                space_position = From_File.find_last_of(' ');
                last_character = From_File.find('\n');
                payment = std::stoi(From_File.substr(space_position, last_character - space_position));
            }
            else
                Produced_Vehicles.emplace_back(From_File);
            number++;
        }

        Key_To_Data.close();

        Temp.open("Temp.txt", std::ios::out);
        for (auto & Produced_Vehicle : Produced_Vehicles) {
            Temp << Produced_Vehicle << '\n';
        }
        Temp.close();
        remove(file_name.c_str());
        rename("Temp.txt", file_name.c_str());


        Key_To_Data.open("profit.txt", std::ios::in | std::ios::out);
        Key_To_Data >> profit;
        profit += payment;
        Key_To_Data << profit;
        Key_To_Data.close();

        std::cout << "Thanks for purchase and see you again!!!";
    }
}

void Factory::see_chosen_list(const std::string & file_name) {
    std::string From_File;
    std::fstream Key_To_Data;

    Key_To_Data.open(file_name.c_str(), std::ios::in);
    std::getline(Key_To_Data, From_File);

    if(From_File.empty())
        std::cout << "There are no such vehicles in factory\n";
    else {
        int ID = 1;
        std::cout << ID << ". " << From_File << std::endl;
        while(std::getline(Key_To_Data, From_File)) {
            ID++;
            std::cout << ID << ". " << From_File << std::endl;
        }
    }
    Key_To_Data.close();
}

void Factory::get_profit() const {
    std::fstream file_var;
    file_var.open("profit.txt", std::ios::in | std::ios::out | std::ios::trunc);
    if(file_var.good()){
        file_var << profit;
        std::cout << profit << std::endl;
        file_var.close();
    }
    else
        std::cout << "An unexpected error occurred\n";
}
