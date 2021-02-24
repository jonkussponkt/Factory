#include <iostream>
#include "Car.h"
#include "Factory.h"
#include "Input_Output.h"

void hello(){
    int choice = 0;
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
                    Mercedes.produce(choose_type);
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
                    Mercedes.see_the_cars();
                else if (choose_type == 2)
                    Mercedes.see_the_motorbikes();
                else if (choose_type == 3)
                    Mercedes.see_the_bicycles();
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
                Mercedes.sell(choose_type);
                break;
            case 4:
                Motor_Vehicle * test_drive;
                int ID;
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
                            ID = Input_Output::Input_Number_From_Range(1, Mercedes.Produced_Cars.size());
                        }
                        catch (const Wrong_Input &wrong_input) {
                            std::cout << wrong_input.what();
                        }

                    }
                    while (ID < 1 || ID > Mercedes.Produced_Cars.size());
                    //test_drive = &Mercedes.Produced_Cars[ID - 1];
                }
                else if (choose_type == 2) {
                    do {
                        try {
                            ID = Input_Output::Input_Number_From_Range(1, Mercedes.Produced_Motorbikes.size());
                            std::cout << "Input ID of vehicle you want to drive";
                        }
                        catch (const Wrong_Input &wrong_input) {
                            std::cout << wrong_input.what();
                        }
                    }
                    while(ID < 1 || ID > Mercedes.Produced_Motorbikes.size());
                    //test_drive = &Mercedes.Produced_Motorbikes[ID - 1];
                }
                //test_drive->drive();
                break;
            case 5:
                do {
                    try {
                        std::cout << "Input type of vehicle you want to repaint\n";
                        Input_Output::info(3);
                        choose_type = Input_Output::Input_Number_From_Range(1, 3);
                    }
                    catch (const Wrong_Input &wrong_input) {
                        std::cout << wrong_input.what();
                    }
                }
                while(choose_type < 1 || choose_type > 3);

                if(choose_type == 1) {
                    do {
                        std::cout << "Input ID of vehicle you want to repaint";
                        try {
                            ID = Input_Output::Input_Number_From_Range(1, Mercedes.Produced_Cars.size());
                        }
                        catch (const Wrong_Input & wrong_input){
                            std::cout << wrong_input.what();
                        }
                    }
                    while (ID < 1 || ID > Mercedes.Produced_Cars.size());
                    //Mercedes.Produced_Cars[ID - 1].paint_a_vehicle();
                }
                else if (choose_type == 2) {
                    do {
                        std::cout << "Input ID of vehicle you want to repaint";
                        try {
                            ID = Input_Output::Input_Number_From_Range(1, Mercedes.Produced_Motorbikes.size());
                        }
                        catch (const Wrong_Input & wrong_input){
                            std::cout << wrong_input.what();
                        }
                    }
                    while (ID < 1 || ID > Mercedes.Produced_Motorbikes.size());
                    //Mercedes.Produced_Motorbikes[ID - 1].paint_a_vehicle();
                }
                else if(choose_type == 3){
                    do{
                        std::cout << "Input ID of vehicle you want to repaint";
                        try {
                            ID = Input_Output::Input_Number_From_Range(1, Mercedes.Produced_Bicycles.size());
                        }
                        catch (const Wrong_Input & wrong_input){
                            std::cout << wrong_input.what();
                        }
                    }
                    while (ID < 1 || ID > Mercedes.Produced_Bicycles.size());
                    //Mercedes.Produced_Bicycles[ID - 1].paint_a_vehicle();
                }
                break;
            case 6:
                std::cout << "To see the profit";
                Mercedes.get_profit();
                break;
            case 7:
                std::cout << "Thanks and see you again!\n";
                break;
            default:
                std::cout << "Invalid input! Choose it once more!\n";
                break;
        }
    }
    while(choice != 7);
}

int main() {
    hello();
    return 0;
}
