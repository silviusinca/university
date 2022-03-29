#include <iostream>
#include "./classes/Dacia.h"
#include "./classes/Renault.h"
#include "./classes/Toyota.h"
#include "./classes/Circuit.h"
#include <vector>

int main() {
    Dacia dacie;
    dacie.setSpeed(350);
    dacie.setMarca(Dacia::getMarca());
    Renault renault;
    renault.setSpeed(100);
    renault.setMarca(Renault::getMarca());
    Toyota toyota;
    toyota.setSpeed(125);
    toyota.setMarca(Toyota::getMarca());

    std::vector<Car> test {dacie, renault, toyota};

//    for (auto car : test)
//        std::cout << car << std::endl;

    Circuit circuit(test);
    Renault renault2;
    renault2.setSpeed(75);
    renault2.setMarca(Renault::getMarca());
    circuit.addCar(renault2);

    circuit.showFinalRound();

    return 0;
}
