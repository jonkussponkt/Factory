//
// Created by Admin on 16.02.2021.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Input_Output.h"

std::vector<std::string> Input_Output::read_the_vector(const std::string &file_name) {
    std::fstream Key_To_Data;
    std::string From_File;
    std::vector<std::string> data;

    Key_To_Data.open(file_name.c_str(), std::ios::in);
    std::getline(Key_To_Data, From_File);
    if(!From_File.empty()) {
        data.emplace_back(From_File);
        while (std::getline(Key_To_Data, From_File))
            data.emplace_back(From_File);
    }
    Key_To_Data.close();
    return data;

}

void Input_Output::save_the_vector(int ID, std::vector<std::string> &vehicles, const std::string &file_name) {
    int number = 1;
    std::fstream Temp;
    Temp.open("Temp.txt", std::ios::out);
    for (auto & vehicle : vehicles) {
        if(number != ID)
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

int Input_Output::Input_Number() {
    std::string get_str = Input_String();
    int number = std::stoi(get_str);
    return number;
}

int Input_Output::Input_Number_From_Range(int left_lim, int right_lim) {
    std::string get_str = Input_String();
    int choose_type = std::stoi(get_str);
    if(choose_type < left_lim || choose_type > right_lim)
        throw Wrong_Input();
    else
        return choose_type;
}

double Input_Output::Input_Double(){
    std::string choose = Input_String();
    double number = std::stod(choose);
    return number;
}

double Input_Output::Input_Double_From_Range(double left_lim, double right_lim) {
    std::string choose = Input_String();
    double number = std::stod(choose);
    if(number < left_lim || number > right_lim)
        throw Way_Too_Long();
    else
        return number;
}

std::string Input_Output::Input_String() {
    std::string input;
    getline(std::cin, input);
    return input;
}
