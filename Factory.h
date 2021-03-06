//
// Created by Admin on 05.01.2021.
//

#ifndef FABRYKA_FACTORY_H
#define FABRYKA_FACTORY_H

#include <string>
#include <vector>
#include <fstream>
#include "Car.h"
#include "Bicycle.h"
#include "Motorcycle.h"
#include "Vehicle.h"

class Factory {
    const std::string label;
    long double profit;
    std::vector<long long> Produced_Cars;
    std::vector<long long> Produced_Motorbikes;
    std::vector<long long> Produced_Bicycles;
    friend void hello();
public:
    void produce(int type);
    void sell(int type);
    void see_the_cars() const;
    void see_the_bicycles() const;
    void see_the_motorbikes() const;
    void get_profit() const;
    explicit Factory(std::string mark = "Mercedes", long double money = 0.0) : label(mark), profit(money) {
        Produced_Cars.emplace_back(0);
        Produced_Cars.emplace_back(0);
        Produced_Cars.emplace_back(0);
    };
    ~Factory() = default;
};


#endif //FABRYKA_FACTORY_H
