#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void): name("DEFAULT"), hit_point(DEFAULT_CLAP_HP), energy_point(DEFAULT_CLAP_EP), attack_damage(DEFAULT_CLAP_AP) {
    std::cout << "ClapTrap: default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& object) {
    std::cout << "ClapTrap: copy constructor called" << std::endl;
    *this = object;
}

ClapTrap::ClapTrap(std::string init_name): name(init_name), hit_point(DEFAULT_CLAP_HP), energy_point(DEFAULT_CLAP_EP), attack_damage(DEFAULT_CLAP_AP) {
    std::cout << "ClapTrap: constructor with name string is called" << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap: destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator = (const ClapTrap& object) {
    std::cout << "ClapTrap: copy assignment operator called" << std::endl;
    this->name = object.getName();
    this->hit_point = object.getHP();
    this->energy_point = object.getEP();
    this->attack_damage = object.getAP();
    return *this;
}

std::string ClapTrap::getName(void) const {
    return this->name;
}

int ClapTrap::getHP(void) const {
    return this->hit_point;
}

int ClapTrap::getEP(void) const {
    return this->energy_point;
}

int ClapTrap::getAP(void) const {
    return this->attack_damage;
}

bool ClapTrap::canMove(void) const {
    return (this->hit_point > 0 && this->energy_point > 0);
}

void ClapTrap::consumeEP(void) {
    if (this->energy_point > 0)
        this->energy_point -= 1;
}

void ClapTrap::attack(const std::string& target) {
    if (this->canMove() == false) {
        std::cerr << "Lack of ENERGY or HP" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attack_damage << " points of damage!" << std::endl;
    this->consumeEP();
}

void ClapTrap::takeDamage(unsigned int amount) {
    std::cout << "ClapTrap " << this->name << " was attacked, took " << amount << " points of damage!" << std::endl;
    this->hit_point -= amount;
    if (this->hit_point < 0)
        this->hit_point = 0;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->canMove() == false) {
        std::cerr << "Lack of ENERGY or HP" << std::endl;
        return ;
    }
    std::cout << "ClapTrap " << this->name << " was repaired, be cured for " << amount << " points!" << std::endl;
    this->hit_point += amount;
    this->consumeEP();
}
