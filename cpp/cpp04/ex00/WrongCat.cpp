#include "WrongCat.hpp"

WrongCat::WrongCat(void) {
    std::cout << "WrongCat: default constructor called" << std::endl;
    this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& object) {
    std::cout << "WrongCat: copy constructor called" << std::endl;
    *this = object;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat: destructor called" << std::endl;
}

WrongCat& WrongCat::operator = (const WrongCat& object) {
    std::cout << "WrongCat: copy assignment operator called" << std::endl;
    this->type = object.getType();
    return *this;
}

void WrongCat::makeSound(void) const {
    std::cout << "Meow!!!" << std::endl;
}
