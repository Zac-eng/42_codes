#include "Zombie.hpp"

Zombie::Zombie(std::string init_name) {
	this->name = init_name;
}

Zombie::~Zombie() {
	std::cout << this->name << std::endl;
}

void Zombie::announce(void) const {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
};
