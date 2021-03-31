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
    double profit;
    int nr_of_cars;
    int nr_of_motorbikes;
    int nr_of_bicycles;
    int sold_cars;
    int sold_motorbikes;
    int sold_bicycles;
    friend void hello();
public:
    void create_a_factory();
    void close_factory() const;
    void produce(int type);
    void sell(const std::string &file_name);
    static void see_chosen_list(const std::string &file_name);
    friend std::ostream & operator << (std::ostream & str, const Factory & factory);
    explicit Factory(std::string mark = "Mercedes") : label(std::move(mark)) {
        profit = 0.0;
        nr_of_cars = 0;
        nr_of_motorbikes = 0;
        nr_of_bicycles = 0;
        sold_cars = 0;
        sold_motorbikes = 0;
        sold_bicycles = 0;
    };
    ~Factory() = default;

};

#endif //FABRYKA_FACTORY_H
