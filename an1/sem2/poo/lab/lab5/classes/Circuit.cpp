//
// Created by Silviu-Gabriel Sinca on 16.03.2022.
//

#include "Circuit.h"
#include <iostream>
#include <utility>

using namespace std;

Circuit::Circuit(std::vector<Car*> cars_) {
    cars = std::move(cars_);
}

void Circuit::addCar(Car* car) {
    cars.push_back(car);
}

void Circuit::showFinalRound() {
    vector<Car*> aux = cars;
    std::sort(aux.begin(), aux.end());
    for (int i = 0; i < (int)aux.size(); i++) {
        cout << i+1 << "." << aux[i]->getMarca() << ": " << aux[i]->getSpeed() << endl;
    }
}

