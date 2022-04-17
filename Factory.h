//
// Created by Admin on 05.01.2021.
//

#ifndef FABRYKA_FACTORY_H
#define FABRYKA_FACTORY_H

#include <string>
#include <utility>
#include <vector>
#include <fstream>
#include "Car.h"
#include "Bicycle.h"
#include "Motorcycle.h"
#include "Vehicle.h"

class Factory {
    const std::string label;
    long double profit;
    int Produced_Cars;
    int Produced_Motorbikes;
    int Produced_Bicycles;
    friend void hello();
public:
    void prepare_factory(std::string & file_name);
    void produce(int type);
    void sell(int type);
    void see_the_vehicles(const std::string& File_Name) const;
    void get_profit() const;
    explicit Factory(std::string mark = "Mercedes", long double money = 0.0) : label(std::move(mark)), profit(money) {
        Produced_Cars = 0;
        Produced_Motorbikes = 0;
        Produced_Bicycles = 0;
    };
    ~Factory() = default;
};


#endif //FABRYKA_FACTORY_H
