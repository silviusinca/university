//
// Created by Silviu-Gabriel Sinca on 16.03.2022.
//

#ifndef LAB5_CAR_H
#define LAB5_CAR_H
#include <iostream>

class Car {
protected:
    float speed{};
    std::string marca;

public:
    Car();
    explicit Car(float speed_, std::string marca_);
    void setSpeed(float speed_);
    float getSpeed() const;
    void setMarca(std::string marca_);
    std::string getMarca();
    bool operator<(const Car &other) const;
    bool operator>(const Car &other) const;
    bool operator==(const Car &other) const;
    bool operator!=(const Car &other) const;
    Car& operator=(const Car &other);
    friend std::istream &operator>>(std::istream &is, Car &car);
    friend std::ostream &operator<<(std::ostream &os, const Car &car);
};


#endif //LAB5_CAR_H
