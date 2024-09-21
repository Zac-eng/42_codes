#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void): ClapTrap("DEFAULT_clap_name"), name("DEFAULT") {
    std::cout << "DiamondTrap: default constructor called" << std::endl;
    this->hit_point = FragTrap::hit_point;
    this->energy_point = ScavTrap::energy_point;
    this->attack_damage = FragTrap::attack_damage;
}

DiamondTrap::DiamondTrap(const DiamondTrap& object) {
    std::cout << "DiamondTrap: copy constructor called" << std::endl;
    *this = object;
}

DiamondTrap::DiamondTrap(std::string init_name): ClapTrap(init_name + "_clap_name"), name(init_name) {
    std::cout << "DiamondTrap: constructor with name string is called" << std::endl;
    this->hit_point = FragTrap::hit_point;
    this->energy_point = ScavTrap::energy_point;
    this->attack_damage = FragTrap::attack_damage;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap: destructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator = (const DiamondTrap& object) {
    std::cout << "DiamondTrap: copy assignment operator called" << std::endl;
    this->name = object.getName();
    ClapTrap::name = object.getClapName();
    this->hit_point = object.getHP();
    this->energy_point = object.getEP();
    this->attack_damage = object.getAP();
    return *this;
}

std::string DiamondTrap::getName(void) const {
    return this->name;
}

std::string DiamondTrap::getClapName(void) const {
    return ClapTrap::name;
}

void DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
    std::cout << "My diamond name is " << this->name << std::endl;
    std::cout << "My clap name is " << ClapTrap::name << std::endl;
}
