#include "Cat.hpp"

Cat::Cat(void) {
    std::cout << "Cat: default constructor called" << std::endl;
    this->type = "Cat";
}

Cat::Cat(const Cat& object) {
    std::cout << "Cat: copy constructor called" << std::endl;
    *this = object;
}

Cat::~Cat() {
    std::cout << "Cat: destructor called" << std::endl;
}

Cat& Cat::operator = (const Cat& object) {
    std::cout << "Cat: copy assignment operator called" << std::endl;
    this->type = object.getType();
    return *this;
}

void Cat::makeSound(void) const {
    std::cout << "Meow!!!" << std::endl;
}
