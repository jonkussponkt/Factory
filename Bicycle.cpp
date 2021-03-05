//
// Created by Admin on 05.01.2021.
//

#include <iostream>
#include "Bicycle.h"

std::ostream & operator << (std::ostream & file, const Bicycle & bicycle) {
    file << bicycle.get_colour() << " " << bicycle.capacity << " " << bicycle.get_price();
    return file;
}
