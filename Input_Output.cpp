//
// Created by Admin on 16.02.2021.
//

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

#include "Input_Output.h"


bool Input_Output::check_if_valid(const std::string & str) {
    return std::all_of(str.begin(), str.end(), [](char c){ return isdigit(c) || c == '.'; });
}

void Input_Output::info(int right_lim) {
    std::cout << "Press 1 - car\n"
                 "Press 2 - motorbike\n";
    if(right_lim == 3)
        std::cout << "Press 3 - bicycle\n";
}

int Input_Output::Input_Number() {
    std::string get_str = Input_String();
    if(get_str.empty())
        throw Wrong_Input("Invalid input! Empty number!\n");
    int number;
    if (!check_if_valid(get_str))
        throw Wrong_Input("Invalid input! You have to input a number!\n");
    number = std::stoi(get_str);
    return number;
}

int Input_Output::Input_Number_From_Range(int left_lim, int right_lim) {
    std::string get_str = Input_String();
    if(get_str.empty())
        throw Wrong_Input("Invalid input! Empty number!\n");
    if (!check_if_valid(get_str))
        throw Wrong_Input("Invalid input! You have to input a number!\n");
    int choose_type = std::stoi(get_str);
    if(choose_type < left_lim || choose_type > right_lim)
        throw Wrong_Input();
    else
        return choose_type;
}

double Input_Output::Input_Double() {
    std::string choice = Input_String();
    if(choice.empty())
        throw Wrong_Input("Invalid input! Empty number!\n");
    if (!check_if_valid(choice))
        throw Wrong_Input("Invalid input! You have to input a number!\n");
    double number = std::stod(choice);
    return number;
}

double Input_Output::Input_Double_From_Range(double left_lim, double right_lim) {
    std::string choice = Input_String();
    if(choice.empty())
        throw Wrong_Input("Invalid input! Empty number!\n");
    if (!check_if_valid(choice))
        throw Wrong_Input("Invalid input! You have to input a number!\n");
    double number = std::stod(choice);
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
