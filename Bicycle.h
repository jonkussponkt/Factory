//
// Created by Admin on 05.01.2021.
//

#ifndef FABRYKA_BICYCLE_H
#define FABRYKA_BICYCLE_H

#include "Vehicle.h"

class Bicycle : public Vehicle {
public:
    void create_vehicle() override;
    explicit Bicycle(std::string painted_in="", double how_much=0.0) : Vehicle("Factory", std::move(painted_in), how_much){};
    ~Bicycle() override = default;
};

#endif //FABRYKA_BICYCLE_H
