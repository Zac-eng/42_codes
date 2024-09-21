#include "Zombie.hpp"

Zombie::Zombie(std::string name) {
	this->_name = name;
	this->_next = NULL;
}

Zombie::~Zombie() {
	std::cout << this->_name << std::endl;
}

void	Zombie::announce(void) const {
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
};

Zombie*	Zombie::get_next(void) const {
	return (this->_next);
}

void	Zombie::set_next(Zombie *next_zombie) {
	this->_next = next_zombie;
}
