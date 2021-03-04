#include <iostream>
#include "Car.h"
#include "Factory.h"
#include "Input_Output.h"

void hello(){
    int choice = 0;
    std::string type;
    std::string str_vehicle;
    std::fstream Key_To_Data;
    Factory Mercedes;
    do {
        do {
            try {
                std::cout << "Welcome to our factory with long traditions of producing mechanical vehicle\n"
                             "We are excited and satisfied to see you here :))\n"
                             "Please choose one of the sections enlisted below:\n"
                             "Press 1 - to produce the vehicle\nPress 2 - to see the list of vehicles\n"
                             "Press 3 - to sell the vehicle\nPress 4 - to drive for a test\n"
                             "Press 5 - to repaint the vehicle\nPress 6 - to see the current profit\n"
                             "Press 7 - to exit the program\n";
                choice = Input_Output::Input_Number_From_Range(1, 7);
            }
            catch (const Wrong_Input &wrong_input) {
                std::cout << wrong_input.what();
            }
        }
        while(choice < 1 || choice > 7);

        int choose_type;
        switch(choice) {
            case 1:
                do {
                    std::cout << "Input type of vehicle you want to produce\n";
                    Input_Output::info(3);
                    try {
                        choose_type = Input_Output::Input_Number_From_Range(1, 3);
                    }
                    catch (const Wrong_Input &wrong_input) {
                        std::cout << wrong_input.what();
                    }
                    Factory::produce(choose_type);
                }
                while (choose_type < 1 || choose_type > 3);
                break;
            case 2:
                do {
                    std::cout << "Input type of vehicle you want to see\n";
                    Input_Output::info(3);
                    try {
                        choose_type = Input_Output::Input_Number_From_Range(1, 3);
                    }
                    catch (const Wrong_Input &wrong_input) {
                        std::cout << wrong_input.what();
                    }
                }
                while (choose_type < 1 || choose_type > 3);
                if (choose_type == 1)
                    Factory::see_chosen_list("Car_Parking.txt");
                else if (choose_type == 2)
                    Factory::see_chosen_list("Motorbike_Parking.txt");
                else if (choose_type == 3)
                    Factory::see_chosen_list("Bicycle_Parking.txt");
                break;
            case 3:
                std::cout << "Input type of vehicle you want to sell\n";
                do {
                    Input_Output::info(3);
                    try {
                        choose_type = Input_Output::Input_Number_From_Range(1, 3);
                    }
                    catch (const Wrong_Input &wrong_input) {
                        std::cout << wrong_input.what();
                    }
                }
                while (choose_type < 1 || choose_type > 3);
                if(choose_type == 1)
                    type = "Car_Parking.txt";
                else if(choose_type == 2)
                    type = "Motorbike_Parking.txt";
                else if(choose_type == 3)
                    type = "Bicycle_Parking.txt";
                Mercedes.sell(type);
                break;
            case 4:
                Motor_Vehicle * test_drive;
                //TODO: PRZENIEŚĆ TO W INNE MIEJSCE!!!!

                int ID;
                int number;
                int spaces;
                do {
                    std::cout << "Input type of vehicle you want to drive for a test\n";
                    Input_Output::info(2);
                    try {
                        choose_type = Input_Output::Input_Number_From_Range(1, 2);
                    }
                    catch (const Wrong_Input &wrong_input) {
                        std::cout << wrong_input.what();
                    }
                }
                while (choose_type != 1 && choose_type != 2);

                if (choose_type == 1) {
                    do {
                        try {
                            std::cout << "Input ID of vehicle you want to drive";
                            ID = Input_Output::Input_Number_From_Range(1, 500);
                        }
                        catch (const Wrong_Input &wrong_input) {
                            std::cout << wrong_input.what();
                        }
                    }
                    while (ID < 1 || ID > 500);//TODO wywalić 100 i zrobić odczyt ostatniej linii

                    number = 1;
                    Key_To_Data.open("Car_Parking.txt", std::ios::in);
                    std::getline(Key_To_Data, str_vehicle);
                    if(str_vehicle.empty())
                        std::cout << "There are no such vehicles in factory\n";
                    while(number < ID || std::getline(Key_To_Data, str_vehicle)){
                        number++;
                    }
                    Key_To_Data.close();

                    spaces = 0;
                    std::string colour = str_vehicle.substr(0, str_vehicle.find_first_of(' '));
                    while(str_vehicle.find(' ')){

                    }

                    //test_drive = new Car("Factory", colour, );
                    //test_drive->drive();
                    //delete test_drive;
                }
                else if (choose_type == 2) {
                    do {
                        try {
                            ID = Input_Output::Input_Number_From_Range(1, 100);
                            std::cout << "Input ID of vehicle you want to drive";
                        }
                        catch (const Wrong_Input &wrong_input) {
                            std::cout << wrong_input.what();
                        }
                    }
                    while(ID < 1 || ID > 100);
                    //test_drive = &Mercedes.Produced_Motorbikes[ID - 1];
                }
                //test_drive->drive();
                break;
            case 5:
                std::cout << "To see the profit";
                Mercedes.get_profit();
                break;
            case 6:
                std::cout << "Thanks and see you again!\n";
                break;
            default:
                std::cout << "Invalid input! Choose it once more!\n";
                break;
        }
    }
    while(choice != 6);
}

int main() {
    hello();
    return 0;
}
