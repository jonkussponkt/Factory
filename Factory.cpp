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
    double trunk = 0.0;
    double gas;
    long double money;
    unsigned long long temp;
    std::string position;
    std::string basket = "1";
    std::string the_same;
    std::string colour;
    std::fstream Key_To_File;


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

                if(the_same == "1")
                    internal_iterator = how_many;
                else
                    internal_iterator = 1;
                Produced_Cars.open("Car_Positions.txt", std::ios::in | std::ios::ate);
                std::getline(Produced_Cars, position);
                temp = std::stoull(position);
                Produced_Cars.close();

                while (internal_iterator > 0) {
                    Produced_Cars.open("Car_Parking.txt", std::ios::out | std::ios::ate);
                    Produced_Cars.seekg(temp);
                    Produced_Cars <<'\n' << colour << " " << trunk << " " << gas << " " << gas << " "
                                  << doors << 0.0 << " ";
                    temp = sizeof('\n') + 4 * sizeof(" ") + colour.size() + sizeof(trunk)
                           + 2 * sizeof (gas) + sizeof(doors) + sizeof(0.0) + sizeof(money);
                    Produced_Cars.open("Car_Positions.txt", std::ios::out | std::ios::ate);
                    Produced_Cars << '\n' << temp;
                    Produced_Cars.close();
                    internal_iterator--;
                    how_many--;
                    temp += temp;
                }
                Key_To_File.close();
            }
            else {
                Produced_Motorbikes.open("Motorbike_Positions.txt", std::ios::in | std::ios::ate);
                std::getline(Produced_Motorbikes, position);
                temp = std::stoull(position);
                Produced_Motorbikes.close();
                if (the_same == "1")
                    internal_iterator = how_many;
                else
                    internal_iterator = 1;
                while (internal_iterator > 0) {
                    Produced_Motorbikes.open("Motorbike_Parking.txt", std::ios::out | std::ios::ate);
                    Produced_Motorbikes.seekg(temp);
                    Produced_Motorbikes << '\n' << colour << " " << trunk << " " << gas << " " << gas << " "
                                  << 0.0 << " " << money;
                    temp = sizeof('\n') + 4 * sizeof(" ") + colour.size() + sizeof(trunk)
                           + 2 * sizeof(gas) + sizeof(0.0) + sizeof(money);
                    Produced_Motorbikes.open("Motorbike_Positions.txt", std::ios::out | std::ios::ate);
                    Produced_Motorbikes << '\n' << temp;
                    Produced_Motorbikes.close();
                    internal_iterator--;
                    how_many--;
                    temp += temp;
                }
                Key_To_File.close();
            }
        }
        else {
            Produced_Bicycles.open("Bicycle_Positions.txt", std::ios::in | std::ios::ate);
            std::getline(Produced_Bicycles, position);
            temp = std::stoull(position);
            Produced_Bicycles.close();

            if(the_same == "1")
                internal_iterator = how_many;
            else
                internal_iterator = 1;
            while (internal_iterator > 0) {
                Produced_Bicycles.open("Bicycle_Parking.txt", std::ios::out | std::ios::ate);
                Produced_Bicycles.seekg(temp);
                Produced_Bicycles <<'\n' << colour << " " << trunk << " " << gas << " " << gas << " "
                              << 0.0 << " " << money;
                temp = sizeof('\n') + 4 * sizeof(" ") + colour.size() + sizeof(trunk)
                       + 2 * sizeof (gas) + sizeof(0.0) + sizeof(money);
                Produced_Bicycles.open("Bicycle_Positions.txt", std::ios::out | std::ios::ate);
                Produced_Bicycles << '\n' << temp;
                Produced_Bicycles.close();
                internal_iterator--;
                how_many--;
                temp += temp;
            }
            Key_To_File.close();
        }
        ID++;
    }
}

void Factory::sell(int type) {
    int ID;
    std::string From_File;
    std::fstream Key_To_File;
    if(type == 1) {
        if(Produced_Cars.empty())
            std::cout << "There are no such vehicles in factory\n";
        else {
            //see_the_cars();
            std::cout << "Type the ID of the vehicle you want to buy\n";
            ID = Input_Output::Input_Number_From_Range(1, Produced_Cars.size());
            std::cout << "Press anything to confirm your choice\n";
            Input_Output::Input_String();


            Key_To_File.open("Car_Parking.txt", std::ios::out | std::ios::ate);
            Key_To_File.seekg(Produced_Cars.at(ID - 1), std::ios::beg);
            getline(Key_To_File, From_File);
            From_File.replace(From_File.find(From_File), From_File.length(), "");
            Key_To_File >> From_File;
            Key_To_File.close();


            //TODO Produced_Cars.erase(Produced_Cars.begin() + ID - 1);
            //TODO profit += Produced_Cars.at(ID - 1).get_price();
            std::cout << "Thanks for purchase and see you again!!!";
        }

    }
    else if(type == 2) {
        if(Produced_Motorbikes.empty())
            std::cout << "There are no such vehicles in factory\n";
        else {
            //see_the_motorbikes();
            std::cout << "Type the ID of the vehicle you want to buy\n";
            ID = Input_Output::Input_Number_From_Range(1, Produced_Motorbikes.size());
            std::cout << "Press anything to confirm your choice\n";
            Input_Output::Input_String();
            Produced_Motorbikes.erase(Produced_Motorbikes.begin() + ID - 1);
            //TODO profit += Produced_Motorbikes.at(ID - 1).get_price();
            std::cout << "Thanks for purchase and see you again!!!";
        }
    }
    else if(type == 3) {
        if(Produced_Bicycles.empty())
            std::cout << "There are no such vehicles in factory\n";
        else {
            //see_the_bicycles();
            std::cout << "Type the ID of the vehicle you want to buy\n";
            ID = Input_Output::Input_Number_From_Range(1, Produced_Bicycles.size());
            std::cout << "Press anything to confirm your choice\n";
            Input_Output::Input_String();
            //TODO profit += Produced_Bicycles.at(ID - 1).get_price();
            Produced_Bicycles.erase(Produced_Bicycles.begin() + ID - 1);
            std::cout << "Thanks for purchase and see you again!!!";
        }
    }
}

void Factory::see_the_cars() const {
    if(Produced_Cars.empty())
        std::cout << "The list of cars is empty :(\n";
    else {
        int ID = 1;
        for (auto i : Produced_Cars) {
            std::cout << ID << ". ";
            //TODO i.print_info();
            cout << std::endl;
            ID++;
        }
    }
}

void Factory::see_the_bicycles() const {
    if (Produced_Bicycles.empty())
        std::cout << "The list of bicycles is empty :(\n";
    else {
        int ID = 1;
        for (auto i : Produced_Bicycles) {
            std::cout << ID << ".";
            //TODO i.print_veh_data();
            cout << std::endl;
            ID++;
        }
    }
}

void Factory::see_the_motorbikes() const {
    if (Produced_Motorbikes.empty())
        std::cout << "The list of motorbikes is empty :(\n";
    else {
        int ID = 1;
        for (auto i : Produced_Motorbikes) {
            std::cout << ID << ".";
            //TODO i.print_info();
            cout << std::endl;
            ID++;
        }
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


//TODO 2) Zapisywanie dodanych samochodów do pliku
//TODO 3) Odczyt zapisanych samochodów z pliku
