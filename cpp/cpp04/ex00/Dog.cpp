#include "Dog.hpp"

Dog::Dog(void) {
    std::cout << "Dog: default constructor called" << std::endl;
    this->type = "Dog";
}

Dog::Dog(const Dog& object) {
    std::cout << "Dog: copy constructor called" << std::endl;
    *this = object;
}

Dog::~Dog() {
    std::cout << "Dog: destructor called" << std::endl;
}

Dog& Dog::operator = (const Dog& object) {
    std::cout << "Dog: copy assignment operator called" << std::endl;
    this->type = object.getType();
    return *this;
}

void Dog::makeSound(void) const {
    std::cout << "Woof!!!" << std::endl;
}
