#include "HumanB.hpp"

HumanB::HumanB(std::string init_name) {
	this->name = init_name;
	this->weapon = NULL;
}

void	HumanB::attack(void) {
	std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &new_weapon) {
	this->weapon = &new_weapon;
}
