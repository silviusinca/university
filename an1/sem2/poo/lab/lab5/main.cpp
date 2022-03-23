#include <iostream>
#include "./classes/Dacia.h"
#include "./classes/Renault.h"
#include "./classes/Toyota.h"
#include <vector>

int main() {
    Dacia dacie;
    dacie.setSpeed(350);
    Renault renault;
    renault.setSpeed(100);
    Toyota toyota;
    toyota.setSpeed(125);

//    Toyota toyota(10);

    std::vector<Car> test {dacie, renault, toyota};

    for (auto car : test)
        std::cout << car << std::endl;

    return 0;
}
