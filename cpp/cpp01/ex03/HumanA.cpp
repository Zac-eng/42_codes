#include "HumanA.hpp"

HumanA::HumanA(std::string init_name, Weapon &init_weapon): weapon(init_weapon) {
	this->name = init_name;
}

void	HumanA::attack(void) {
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}
