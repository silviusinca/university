cmake_minimum_required(VERSION 3.21)
project(lab5)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab5 main.cpp classes/Car.cpp classes/Car.h classes/Dacia.cpp classes/Dacia.h classes/Renault.cpp classes/Renault.h classes/Toyota.cpp classes/Toyota.h classes/Circuit.cpp classes/Circuit.h)
