#ifndef DIAMOND_TRAP_HPP
# define DIAMOND_TRAP_HPP

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap {

private:
    std::string name;

public:
    DiamondTrap(void);
    DiamondTrap(const DiamondTrap& object);
    DiamondTrap(std::string init_name);
    ~DiamondTrap();
    DiamondTrap& operator = (const DiamondTrap& object);
    std::string getName(void) const;
    std::string getClapName(void) const;
    void attack(const std::string& target);
    void whoAmI();

};

#endif
