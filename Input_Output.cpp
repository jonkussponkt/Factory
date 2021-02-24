//
// Created by Admin on 16.02.2021.
//

#include <iostream>
#include <string>
#include "Input_Output.h"

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
