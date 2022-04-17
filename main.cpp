#include <iostream>
#include "Factory.h"
#include "Input_Output.h"

void hello() {
    int choice;
    Factory Mercedes;
    std::string File_Name, str_choice;
    File_Name = "Car_Parking.txt";
    Mercedes.prepare_factory(File_Name);
    File_Name = "Motorbike_Parking.txt";
    Mercedes.prepare_factory(File_Name);
    File_Name = "Bicycle_Parking.txt";
    Mercedes.prepare_factory(File_Name);
    File_Name.clear();
    do {
        do {
            try {
                std::cout << "Welcome to our factory with long traditions of producing mechanical vehicle\n"
                             "We are excited and satisfied to see you here :))\n"
                             "Please choose one of the sections enlisted below:\n"
                             "Press 1 - to produce the vehicle\nPress 2 - to see the list of vehicles\n"
                             "Press 3 - to sell the vehicle\nPress 4 - to exit the program\n";
                choice = Input_Output::Input_Number_From_Range(1, 4);
            }
            catch (const Wrong_Input &wrong_input) {
                std::cout << wrong_input.what();
            }
            catch (...) {
                std::cout << "Your input is wrong! Type it once more!\n";
            }
        }
        while(choice < 1 || choice > 4);

        int choose_type = -1;
        switch(choice) {
            case 1:
                do {
                    std::cout << "Input type of vehicle you want to produce\n";
                    Input_Output::info(3);
                    std::cout << "To come back to main menu press 0\n";
                    try {
                        choose_type = Input_Output::Input_Number_From_Range(0, 3);
                    }
                    catch (const Wrong_Input &wrong_input) {
                        std::cout << wrong_input.what();
                    }
                    catch(...) {
                        std::cout << "The value is incorrect! Type correct number!!\n";
                    }
                } while (choose_type < 0 || choose_type > 3);
                if(choose_type > 0)
                    Mercedes.produce(choose_type);
                break;
            case 2:
                do {
                    std::cout << "Input type of vehicle you want to see\n";
                    Input_Output::info(3);
                    std::cout << "To come back to main menu press 0\n";
                    try {
                        choose_type = Input_Output::Input_Number_From_Range(0, 3);
                    }
                    catch (const Wrong_Input &wrong_input) {
                        std::cout << wrong_input.what();
                    }
                    catch(...){
                        std::cout << "The value is incorrect! Type correct number!!\n";
                    }
                } while (choose_type < 0 || choose_type > 3);
                if(choose_type > 0) {
                    if (choose_type == 1)
                        File_Name = "Car_Parking.txt";
                    else if (choose_type == 2)
                        File_Name = "Motorbike_Parking.txt";
                    else if (choose_type == 3)
                        File_Name = "Bicycle_Parking.txt";
                    Mercedes.see_the_vehicles(File_Name);
                }
                break;
            case 3:
                std::cout << "Input type of vehicle you want to sell\nTo come back to main menu press 0\n";
                do {
                    Input_Output::info(3);
                    try {
                        choose_type = Input_Output::Input_Number_From_Range(0, 3);
                    }
                    catch (const Wrong_Input &wrong_input) {
                        std::cout << wrong_input.what();
                    }
                    catch (...) {
                        std::cout << "Invalid input! Choose it once more!\n";
                    }
                } while (choose_type < 0 || choose_type > 3);
                if(choose_type > 0) {
                    Mercedes.sell(choose_type);
                }
                break;
            case 4:
                std::cout << "Are you sure you want to leave? Press 1, otherwise press anything else\n";
                str_choice = Input_Output::Input_String();
                if(str_choice == "1")
                    std::cout << "Thanks and see you again!\n";
                else
                    choice = 1;
                break;
            default:
                std::cout << "Invalid input! Choose it once more!\n";
                break;
        }
    }
    while(choice != 4);
}

int main() {
    hello();
    return 0;
}
