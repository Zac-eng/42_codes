#include "Brain.hpp"

Brain::Brain(void) {
    std::cout << "Brain: default constructor called" << std::endl;
}

Brain::Brain(Brain& object) {
    std::cout << "Brain: copy constructor called" << std::endl;
    *this = object;
}

Brain::~Brain() {
    std::cout << "Brain: destructor called" << std::endl;
}

Brain& Brain::operator = (const Brain& object) {
    std::cout << "Brain: copy assignment operator called" << std::endl;
    for (int i = 0; i < IDEA_CAP; i++) {
        this->ideas[i] = object.ideas[i];
    }
    return *this;
}
