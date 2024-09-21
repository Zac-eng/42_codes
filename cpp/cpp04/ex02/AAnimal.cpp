#include "AAnimal.hpp"

AAnimal::AAnimal(void) {
    std::cout << "AAnimal: default constructor called" << std::endl;
    this->type = "AAnimal";
}

AAnimal::AAnimal(const AAnimal& object) {
    std::cout << "AAnimal: copy constructor called" << std::endl;
    *this = object;
}

AAnimal::~AAnimal() {
    std::cout << "AAnimal: destructor called" << std::endl;
}

AAnimal& AAnimal::operator = (const AAnimal& object) {
    std::cout << "AAnimal: copy assignment operator called" << std::endl;
    this->type = object.getType();
    return *this;
}

std::string AAnimal::getType(void) const {
    return this->type;
}

void AAnimal::makeSound(void) const {
    std::cout << "Mmm..." << std::endl;
}
