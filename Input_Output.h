//
// Created by Admin on 16.02.2021.
//

#ifndef FABRYKA_INPUT_OUTPUT_H
#define FABRYKA_INPUT_OUTPUT_H

#include <string>
#include <vector>

class Wrong_Input : std::exception {
    std::string message;
public:
    const char * what() const noexcept override {
        return message.c_str();
    }
    explicit Wrong_Input(std::string msg = "Wrong input! Type it once more!\n") : message(std::move(msg)) {};
};


class Bad_File : std::exception {
    std::string message;
public:
    const char * what() const noexcept override {
        return message.c_str();
    }
    explicit Bad_File(std::string msg = "The file is bad! An error occurred\n") : message(std::move(msg)) {};
};

class Input_Output {
public:
    static void read_the_vector(std::vector<std::string> & data, const std::string &file_name);
    static void save_the_vector(std::vector<std::string> &vehicles, const std::string &file_name);
    static void info(int right_lim);
    static bool convertible(const std::string & to_convert);
    static int Input_Number();
    static int Input_Number_From_Range(int left_lim, int right_lim);
    static double Input_Double();
    static double Input_Double_From_Range(double left_lim, double right_lim);
    static std::string Input_String();
};

#endif //FABRYKA_INPUT_OUTPUT_H
