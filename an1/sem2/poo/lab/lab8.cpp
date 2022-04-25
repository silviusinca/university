#include <string>
#include <iostream>
#include <vector>
#include <memory>

enum class PetType {
    Dog,
    Cat
};

class Pet {
    std::string name;
    int age;

public:
    Pet(std::string name, int age) : name(std::move(name)), age(age) {}

    virtual std::string makeSound() = 0;

    virtual PetType getPetType() = 0;

    void sayHello() {
        std::cout << makeSound() << "! Hello, I am " << name << "\n";
    }

    const std::string &getName() const {
        return name;
    }

    void setName(const std::string &name) {
        Pet::name = name;
    }

    int getAge() const {
        return age;
    }

    void setAge(int age) {
        Pet::age = age;
    }

    virtual void print(std::ostream &os) const = 0;
};

class Dog : public Pet {
public:
    PetType getPetType() override {
        return PetType::Dog;
    }

    Dog(std::string name, int age) : Pet(std::move(name), age) { }

    std::string makeSound() override {
        return "Woof";
    }

    void print(std::ostream &os) const override {
        os << "Dog " << this->getName() << ' ';
    }

    friend std::ostream &operator<<(std::ostream &os, const Dog &dog) {
        dog.print(os);
        return os;
    }

    void fetch() {
        std::cout << "Fetch!";
    }
};

class Cat : public Pet {
public:
    PetType getPetType() override {
        return PetType::Cat;
    }

public:
    Cat(std::string name, int age) : Pet(std::move(name), age) {}

    std::string makeSound() override {
        return "Meow";
    }

    friend std::ostream &operator<<(std::ostream &os, const Cat &cat) {
        os << "Cat: " << cat.getName();
        return os;
    }

    void print(std::ostream &os) const override {
        os << "Cat " << this->getName() << ' ';
    }
};

class PetStore {
    static std::vector<std::shared_ptr<Pet>> pets;
public:
    static const std::vector<std::shared_ptr<Pet>> &getPets() {
        return pets;
    }

    static void addPet(const std::shared_ptr<Pet> &pet) {
        pets.push_back(pet);
//        PetStore::pets.push_back(pet);
    }

    static void printAllDogs() {
        for (auto &pet : PetStore::getPets()) {
            if (pet->getPetType() == PetType::Dog) {
                auto dog = std::dynamic_pointer_cast<Dog>(pet);
                dog->fetch();
            }
        }
    }
};

std::vector<std::shared_ptr<Pet>> PetStore::pets;

std::ostream& operator<<(std::ostream& os, Pet *pet) {
    std::cout << pet->getName() << ' ';
    return os;
}

int main() {
    auto dog = std::make_shared<Dog>("Scooby", 3);
    auto cat = std::make_shared<Cat>("Kitty", 3);

    PetStore::addPet(dog);
    PetStore::addPet(cat);

//    for (auto &pet : PetStore::getPets())
//        std::cout << pet;

    PetStore::printAllDogs();
}
