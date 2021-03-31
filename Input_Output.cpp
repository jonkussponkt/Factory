//
// Created by Admin on 16.02.2021.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Input_Output.h"

void Input_Output::read_the_vector(std::vector<std::string> & data, const std::string &file_name) {
    std::fstream Key_To_Data;
    std::string From_File;

    Key_To_Data.open(file_name.c_str(), std::ios::in);
    if(Key_To_Data.good()) {
        std::getline(Key_To_Data, From_File);
        if (!From_File.empty()) {
            data.emplace_back(From_File);
            while (std::getline(Key_To_Data, From_File))
                data.emplace_back(From_File);
        }
        for (int i = 0; i < data.size(); i++) {
            if (data.at(i).empty())
                data.erase(data.begin() + i);
        }
        Key_To_Data.close();
    }
}

void Input_Output::save_the_vector(std::vector<std::string> &vehicles, const std::string &file_name) {
    int number = 1;
    std::fstream Temp;
    Temp.open("Temp.txt", std::ios::out);
    for (auto & vehicle : vehicles) {
            Temp << vehicle << '\n';
        number++;
    }
    Temp.close();
    remove(file_name.c_str());
    rename("Temp.txt", file_name.c_str());
}

void Input_Output::info(int right_lim) {
    std::cout << "Press 1 - car\n"
                 "Press 2 - motorbike\n";
    if(right_lim == 3)
        std::cout << "Press 3 - bicycle\n";
}

bool Input_Output::convertible(const std::string & to_convert) {
    int i = 0;
    if(to_convert.empty())
        return false;
    while(i < to_convert.length()){
        if(!isdigit(to_convert[i]) && to_convert[i] != 46)
            return false;
        i++;
    }
    return true;
}

int Input_Output::Input_Number() {
    std::string get_str = Input_String();
    int number;
    if(!convertible(get_str))
        throw Wrong_Input("You have to input a number!\n");
    number = std::stoi(get_str);
    return number;
}

int Input_Output::Input_Number_From_Range(int left_lim, int right_lim) {
    std::string get_str = Input_String();
    int choose;
    if(!convertible(get_str))
        throw Wrong_Input("You have to input a number!\n");
    choose = std::stoi(get_str);
    if(choose < left_lim || choose > right_lim)
        throw Wrong_Input("You have to input a number from range " + std::to_string(left_lim)
                          + " and " + std::to_string(right_lim) + "\n");
    else
        return choose;
}

double Input_Output::Input_Double(){
    std::string get_str = Input_String();
    double number;
    if(!convertible(get_str))
        throw Wrong_Input("You have to input a number!\n");
    number = std::stod(get_str);
    return number;
}

double Input_Output::Input_Double_From_Range(double left_lim, double right_lim) {
    std::string get_str = Input_String();
    double number;
    if(!convertible(get_str))
        throw Wrong_Input("You have to input a number!\n");
    number = std::stod(get_str);
    if(number < left_lim || number > right_lim)
        throw Wrong_Input("You have to input a number from range " + std::to_string(left_lim)
                          + " and " + std::to_string(right_lim) + "\n");
    else
        return number;
}

std::string Input_Output::Input_String() {
    std::string input;
    getline(std::cin, input);
    return input;
}
