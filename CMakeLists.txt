cmake_minimum_required(VERSION 3.17)
project(Fabryka)

set(CMAKE_CXX_STANDARD 14)

add_executable(Fabryka main.cpp Factory.cpp Factory.h Car.cpp Car.h Bicycle.cpp Bicycle.h Motorcycle.cpp Motorcycle.h Vehicle.cpp Vehicle.h Motor_Vehicle.cpp Motor_Vehicle.h Input_Output.cpp Input_Output.h)