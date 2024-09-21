#include "Weapon.hpp"

Weapon::Weapon(std::string init_type) {
	this->type = init_type;
}

const std::string&	Weapon::getType(void) {
	return (this->type);
}

void	Weapon::setType(std::string new_type) {
	this->type = new_type;
}
