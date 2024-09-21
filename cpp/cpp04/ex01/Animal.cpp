#include "Animal.hpp"

Animal::Animal(void) {
    std::cout << "Animal: default constructor called" << std::endl;
    this->type = "Animal";
}

Animal::Animal(const Animal& object) {
    std::cout << "Animal: copy constructor called" << std::endl;
    *this = object;
}

Animal::~Animal() {
    std::cout << "Animal: destructor called" << std::endl;
}

Animal& Animal::operator = (const Animal& object) {
    std::cout << "Animal: copy assignment operator called" << std::endl;
    this->type = object.getType();
    return *this;
}

std::string Animal::getType(void) const {
    return this->type;
}

void Animal::makeSound(void) const {
    std::cout << "Mmm..." << std::endl;
}
