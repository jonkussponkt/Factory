//
// Created by Admin on 05.01.2021.
//

#include "Car.h"
#include "Input_Output.h"

double Car::get_capacity() {
    return capacity;
}

void Car::drive() {
    double driven_road = -1.0;
    std::cout << "UDALO SIEEEEEEEEEE\n";
    do {
        try {
            std::cout << "Input driven road in kilometers - max 40 kms";
            driven_road = Input_Output::Input_Double_From_Range(0, 40);
        }
        catch (const Way_Too_Long &way_too_long) {
            std::cout << way_too_long.what() << std::endl;
        }
    }
    while(driven_road < 0 || driven_road > 40);
    gas_in_engine -= driven_road * 0.062;
    mileage += driven_road;
    std::cout << "Gas in engine currently: " << gas_in_engine;

}

std::ostream & operator<<(std::ostream & file, const Car & car) {
    file << car.get_colour() << " " << car.capacity << " "  << car.gas_capacity << " " << car.gas_in_engine
         << " " << car.mileage << " " << car.number_of_doors << " " << car.get_price();
    return file;
}
