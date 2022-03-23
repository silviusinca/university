//
// Created by Silviu-Gabriel Sinca on 16.03.2022.
//

#ifndef LAB5_DACIA_H
#define LAB5_DACIA_H

#include "Car.h"

class Dacia : public Car {
private:
    const std::string marca = "Dacia";
public:
    std::string getMarca() const;
};


#endif //LAB5_DACIA_H
