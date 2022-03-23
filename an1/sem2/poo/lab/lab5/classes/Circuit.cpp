//
// Created by Silviu-Gabriel Sinca on 16.03.2022.
//

#include "Circuit.h"
#include <iostream>
#include <utility>

using namespace std;

void Circuit::addCar(Car car) {
    cars.push_back(car);
}

void Circuit::showFinalRound(std::vector<Car> cars_) {
    std::sort(cars_.begin(), cars_.end());
    for (auto & car : cars_) {
        cout << ": " << car;
    }
}

Circuit::Circuit(std::vector<Car> cars_) {
    cars = std::move(cars_);
}
