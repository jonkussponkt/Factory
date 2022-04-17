//
// Created by Admin on 05.01.2021.
//

#include "Factory.h"
#include "Input_Output.h"

#include <iostream>
#include <string>
#include <sstream>

void Factory::prepare_factory(std::string & file_name) {
    std::fstream Key_File(file_name, std::ios::out | std::ios::in);
    long long sum = 0;
    std::string car_line;
    if(Key_File.is_open()){
        while(std::getline(Key_File, car_line)) {
            sum += static_cast<long long>(car_line.size());
            if(file_name.at(0) == 'C')
                Produced_Cars++;
            else if(file_name.at(0) == 'M')
                Produced_Motorbikes++;
            else if(file_name.at(0) == 'B')
                Produced_Bicycles++;
        }
    }
}

void Factory::produce(int type) {
    int how_many = -1;
    int ID = 1;
    std::string the_same;
    std::string file_name;
    std::fstream Key_To_File;

    std::cout << "Input how many ";
    if(type == 1) {
        std::cout << "cars ";
        file_name = "Car_Parking.txt";
    }
    else if(type == 2) {
        std::cout << "motorbikes ";
        file_name = "Motorbike_Parking.txt";
    }
    else if(type == 3) {
        std::cout << "bicycles ";
        file_name = "Bicycle_Parking.txt";
    }
    std::cout << "you want to add\n";
    do {
        try {
            how_many = Input_Output::Input_Number();
        }
        catch (...) {
            std::cout << "The value is incorrect! Type correct number!\n";
        }
    } while(how_many < 1);
    if(how_many > 1) {
        std::cout << "Decide if they are to be the same vehicles - press 1, otherwise press anything\n";
        the_same = Input_Output::Input_String();
    }
    Vehicle * vehicle_ptr;
    while (how_many > 0) {
        std::cout << "VEHICLE NR " << ID << std::endl;
        int internal_iterator;
        if (the_same == "1")
            internal_iterator = how_many;
        else
            internal_iterator = 1;
        Key_To_File.open(file_name, std::ios::out | std::ios::app);
        if(Key_To_File.good()) {
            if (type == 1) {
                vehicle_ptr = new Car();
                vehicle_ptr->create_vehicle();
                while (internal_iterator > 0) {
                    Key_To_File << vehicle_ptr->print_veh_data() << "\n";
                    internal_iterator--;
                    Produced_Cars++;
                }
                delete vehicle_ptr;
            } else if (type == 2) {
                Motor_Vehicle *motor_ptr;
                motor_ptr = new Motorcycle();
                motor_ptr->create_vehicle();
                while (internal_iterator > 0) {
                    Key_To_File << motor_ptr->print_veh_data() << "\n";
                    internal_iterator--;
                    Produced_Motorbikes++;
                }
                delete motor_ptr;
            } else if (type == 3) {
                vehicle_ptr = new Bicycle();
                vehicle_ptr->create_vehicle();
                while (internal_iterator > 0) {
                    Key_To_File << vehicle_ptr->print_veh_data() << "\n";
                    internal_iterator--;
                    Produced_Bicycles++;
                }
                delete vehicle_ptr;
            }
            internal_iterator--;
            ID++;
            Key_To_File.close();
            if(the_same == "1")
                how_many = 0;
            else
                how_many--;
        }
    }
}

void Factory::sell(int type) {
    int ID, comparator;
    std::string From_File, File_Name;
    std::fstream Key_To_File;
    if (type == 1) {
        File_Name = "Car_Parking.txt";
        comparator = Produced_Cars;
    } else if (type == 2) {
        File_Name = "Motorbike_Parking.txt";
        comparator = Produced_Motorbikes;
    } else if (type == 3) {
        File_Name = "Bicycle_Parking.txt";
        comparator = Produced_Bicycles;
    }
    if (comparator == 0) {
        std::cout << "There are no such vehicles in the factory\n"; //exception!!!
    } else {
        see_the_vehicles(File_Name);
        std::cout << "Type the ID of the vehicle you want to buy\nTo come back to main menu press 0\n";
        do {
            try {
                ID = Input_Output::Input_Number_From_Range(1, comparator);
            }
            catch (const Wrong_Input &wrongInput) {
                std::cout << wrongInput.what();
            }
            catch (...) {
                std::cout << "The value is incorrect! Type correct number!\n";
            }
        } while (ID < 1 || ID > comparator);
        std::cout << "Press anything to confirm your choice\nTo come back to main menu press 0\n";
        if (Input_Output::Input_String() != "0") {
            Key_To_File.open(File_Name, std::ios::in | std::ios::out);
            std::ostringstream parking;
            parking << Key_To_File.rdbuf();
            From_File = parking.str();
            std::string temp_str = From_File;
            int endline_counter = 0, endline_pos;
            if (!temp_str.empty()) {
                endline_pos = (int) temp_str.find('\n');
                while (endline_counter < ID - 1) {
                    temp_str = temp_str.erase(0, endline_pos + 1);
                    endline_pos = (int) temp_str.find('\n');
                    endline_counter++;
                }
                temp_str = temp_str.erase(endline_pos + 1);
            }
            From_File = From_File.replace(From_File.find(temp_str), temp_str.length(), "");
            Key_To_File.close();

            Key_To_File.open(File_Name, std::ios::out | std::ios::trunc);
            if (Key_To_File.is_open()) {
                Key_To_File << From_File;
                Key_To_File.close();
            }

            switch (type) {
                case 1:
                    Produced_Cars--;
                    break;
                case 2:
                    Produced_Motorbikes--;
                    break;
                case 3:
                    Produced_Bicycles--;
                    break;
            }
            std::cout << "Thanks for purchase and see you again!!!\n\n-----------\n\n";
        }
    }
}

void Factory::see_the_vehicles(const std::string& File_Name) const {
    int ID = 1;
    std::string vehicle;
    std::fstream file;
    file.open(File_Name);

    if (file) {
        while (std::getline(file, vehicle)) {
            std::cout << ID << ". " << vehicle << "\n";
            ID++;
        }
        file.close();
    }
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
