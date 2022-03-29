//
// Created by Silviu-Gabriel Sinca on 16.03.2022.
//

#ifndef LAB5_CIRCUIT_H
#define LAB5_CIRCUIT_H

#include "Car.h"
#include <vector>

class Circuit {
private:
    std::vector<Car> cars;

public:
    explicit Circuit(std::vector<Car> cars_);

    void addCar(Car car);
    void showFinalRound();
};


#endif //LAB5_CIRCUIT_H
