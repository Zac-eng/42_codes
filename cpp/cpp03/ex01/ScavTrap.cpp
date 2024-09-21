#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap() {
    std::cout << "ScavTrap: default constructor called" << std::endl;
    this->hit_point = DEFAULT_SCAV_HP;
    this->energy_point = DEFAULT_SCAV_EP;
    this->attack_damage = DEFAULT_SCAV_AP;
}

ScavTrap::ScavTrap(const ScavTrap& object) {
    std::cout << "ScavTrap: copy constructor called" << std::endl;
    *this = object;
}

ScavTrap::ScavTrap(std::string init_name): ClapTrap(init_name) {
    std::cout << "ScavTrap: constructor with name string is called" << std::endl;
    this->hit_point = DEFAULT_SCAV_HP;
    this->energy_point = DEFAULT_SCAV_EP;
    this->attack_damage = DEFAULT_SCAV_AP;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap: destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator = (const ScavTrap& object) {
    std::cout << "ScavTrap: copy assignment operator called" << std::endl;
    this->name = object.getName();
    this->hit_point = object.getHP();
    this->energy_point = object.getEP();
    this->attack_damage = object.getAP();
    return *this;
}

void ScavTrap::attack(const std::string& target) {
    if (this->canMove() == false) {
        std::cerr << "Lack of ENERGY or HP" << std::endl;
        return ;
    }
    std::cout << "ScavTrap " << this->getName() << " attacks " << target << ", causing " << this->getAP() << " points of damage!" << std::endl;
    this->consumeEP();
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << this->getName() << " is now GUARD GATE MODE." << std::endl;
}
