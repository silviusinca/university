//
// Created by Silviu-Gabriel Sinca on 16.03.2022.
//

#include "Car.h"
#include <iostream>
#include <utility>

Car::Car(float speed_) {
    speed = speed_;
}

Car::Car() {
    speed = 0;
}

float Car::getSpeed() const {
    return speed;
}

void Car::setSpeed(float speed_) {
    speed = speed_;
}

std::string Car::getMarca() {
    return marca;
}

void Car::setMarca(std::string marca_) {
    marca = std::move(marca_);
}

bool Car::operator<(const Car &other) const {
    return speed < other.speed;
}

bool Car::operator>(const Car &other) const {
    return speed > other.speed;
}

bool Car::operator==(const Car &other) const {
    return speed == other.speed;
}

bool Car::operator!=(const Car &other) const {
    return !(other == *this);
}

Car &Car::operator=(const Car &other) {
    speed = other.speed;
    return *this;
}

std::istream &operator>>(std::istream &is, Car &car) {
    is >> car.speed;
    return is;
}

std::ostream &operator<<(std::ostream &os, const Car &car) {
    os << car.speed;
    return os;
}
