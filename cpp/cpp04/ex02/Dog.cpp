#include "Dog.hpp"

Dog::Dog(void) {
    std::cout << "Dog: default constructor called" << std::endl;
    this->type = "Dog";
    this->brain = new Brain();
}

Dog::Dog(const Dog& object) {
    std::cout << "Dog: copy constructor called" << std::endl;
    *this = object;
}

Dog::~Dog() {
    std::cout << "Dog: destructor called" << std::endl;
    delete this->brain;
}

Dog& Dog::operator = (const Dog& object) {
    std::cout << "Dog: copy assignment operator called" << std::endl;
    this->type = object.getType();
    this->brain = new Brain();
    *(this->brain) = *(object.brain);
    return *this;
}

void Dog::makeSound(void) const {
    std::cout << "Woof!!!" << std::endl;
}
