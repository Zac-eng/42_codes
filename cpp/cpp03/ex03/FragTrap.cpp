#include "FragTrap.hpp"

FragTrap::FragTrap(void): ClapTrap() {
    std::cout << "FragTrap: default constructor called" << std::endl;
    this->hit_point = DEFAULT_FRAG_HP;
    this->energy_point = DEFAULT_FRAG_EP;
    this->attack_damage = DEFAULT_FRAG_AP;
}

FragTrap::FragTrap(const FragTrap& object) {
    std::cout << "FragTrap: copy constructor called" << std::endl;
    *this = object;
}

FragTrap::FragTrap(std::string init_name): ClapTrap(init_name) {
    std::cout << "FragTrap: constructor with name string is called" << std::endl;
    this->hit_point = DEFAULT_FRAG_HP;
    this->energy_point = DEFAULT_FRAG_EP;
    this->attack_damage = DEFAULT_FRAG_AP;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap: destructor called" << std::endl;
}

FragTrap& FragTrap::operator = (const FragTrap& object) {
    std::cout << "FragTrap: copy assignment operator called" << std::endl;
    this->name = object.getName();
    this->hit_point = object.getHP();
    this->energy_point = object.getEP();
    this->attack_damage = object.getAP();
    return *this;
}

void FragTrap::attack(const std::string& target) {
    if (this->canMove() == false) {
        std::cerr << "Lack of ENERGY or HP" << std::endl;
        return ;
    }
    std::cout << "FragTrap " << this->getName() << " attacks " << target << ", causing " << this->getAP() << " points of damage!" << std::endl;
    this->consumeEP();
}

void FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << this->getName() << ", high fives guys!!." << std::endl;
}
