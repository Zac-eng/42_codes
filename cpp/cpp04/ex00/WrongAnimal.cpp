#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) {
    std::cout << "WrongAnimal: default constructor called" << std::endl;
    this->type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal& object) {
    std::cout << "WrongAnimal: copy constructor called" << std::endl;
    *this = object;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal: destructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator = (const WrongAnimal& object) {
    std::cout << "WrongAnimal: copy assignment operator called" << std::endl;
    this->type = object.getType();
    return *this;
}

std::string WrongAnimal::getType(void) const {
    return this->type;
}

void WrongAnimal::makeSound(void) const {
    std::cout << "Mmm..." << std::endl;
}
