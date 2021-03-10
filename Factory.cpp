//
// Created by Admin on 05.01.2021.
//

#include <iostream>
#include <string>
#include "Factory.h"
#include "Input_Output.h"

void Factory::create_a_factory() {
    int nr_of_line = 1;
    std::string From_File;
    std::fstream Key_To_Data;
    Key_To_Data.open("Report.txt", std::ios::in);
    if(Key_To_Data.good()){
        while(std::getline(Key_To_Data, From_File)){
            if(!From_File.empty()) {
                if (nr_of_line == 1)
                    profit = std::stod(From_File);
                else if (nr_of_line == 2)
                    nr_of_cars = std::stoi(From_File);
                else if (nr_of_line == 3)
                    nr_of_motorbikes = std::stoi(From_File);
                else if (nr_of_line == 4)
                    nr_of_bicycles = std::stoi(From_File);
                else if (nr_of_line == 5)
                    sold_cars = std::stoi(From_File);
                else if(nr_of_line == 6)
                    sold_motorbikes = std::stoi(From_File);
                else if(nr_of_line == 7)
                    sold_bicycles = std::stoi(From_File);
                nr_of_line++;
            }
        }
        Key_To_Data.close();
    }
}

void Factory::close_factory() const {
    std::fstream Key_To_Data;
    Key_To_Data.open("Report.txt", std::ios::out);
    Key_To_Data << profit << '\n';
    Key_To_Data << nr_of_cars << '\n';
    Key_To_Data << nr_of_motorbikes << '\n';
    Key_To_Data << nr_of_bicycles << '\n';
    Key_To_Data << sold_cars << '\n';
    Key_To_Data << sold_motorbikes << '\n';
    Key_To_Data << sold_bicycles << '\n';
    Key_To_Data.close();
}

void Factory::get_info() const {
    int i = 1;
    std::string From_File;
    std::fstream Key_To_Data;
    Key_To_Data.open("Report.txt", std::ios::in);
    if(Key_To_Data.good()){
        while(std::getline(Key_To_Data, From_File)){
            if(i == 1)
                std::cout << "Current profit: " << From_File << '\n';
            else if(i == 2)
                std::cout << "Cars in factory: " << From_File << '\n';
            else if(i == 3)
                std::cout << "Motorbikes in factory: " << From_File << '\n';
            else if(i == 4)
                std::cout << "Bicycles in factory " << From_File << '\n';
            else if(i == 5)
                std::cout << "Sold cars: " << From_File << '\n';
            else if(i == 6)
                std::cout << "Sold motorbikes: " << From_File << '\n';
            else if(i == 7)
                std::cout << "Sold bicycles: " << From_File << '\n';
            i++;
        }
        Key_To_Data.close();
    }
    else
        std::cout << "An unexpected error occurred\n";
}

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
                    nr_of_cars++;
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
                    nr_of_motorbikes++;
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
                nr_of_bicycles++;
            }
            Key_To_Data.close();

        }
        ID++;
    }
}

void Factory::sell(const std::string &file_name) {
    int ID, payment, number;
    std::string decision, From_File;
    std::vector<std::string> Produced_Vehicles;
    std::fstream Key_To_Data;
    std::fstream Temp;
    Key_To_Data.open(file_name.c_str(), std::ios::in);
    if (Key_To_Data.good()) {
        std::getline(Key_To_Data, From_File);

        if (From_File.empty())
            std::cout << "There are no such vehicles in factory\n";
        else {
            Produced_Vehicles.emplace_back(From_File);
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
            Key_To_Data.close();

            while (std::getline(Key_To_Data, From_File)) {
                if (number == ID) {
                    space_position = From_File.find_last_of(' ');
                    last_character = From_File.find('\n');
                    payment = std::stoi(From_File.substr(space_position, last_character - space_position));
                    profit += payment;
                    if (file_name[0] == 'C') {
                        nr_of_cars--;
                        sold_cars++;
                    } else if (file_name[0] == 'M') {
                        nr_of_motorbikes--;
                        sold_motorbikes++;
                    } else if (file_name[0] == 'B') {
                        nr_of_bicycles--;
                        sold_bicycles++;
                    }
                } else
                    Produced_Vehicles.emplace_back(From_File);
                number++;
            }
            Input_Output::save_the_vector(ID, Produced_Vehicles, file_name);
        }
    }
}

void Factory::see_chosen_list(const std::string & file_name) {
    int ID = 1;
    std::vector<std::string> Produced_Vehicles = Input_Output::read_the_vector(file_name);

    if(Produced_Vehicles.empty())
        std::cout << "There are no such vehicles in our factory\n";
    else{
        while(ID < Produced_Vehicles.size() + 1) {
            std::cout << ID << ". " << Produced_Vehicles.at(ID - 1) << std::endl;
            ID++;
        }
    }
}
