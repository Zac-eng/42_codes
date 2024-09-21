#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

# include "ClapTrap.hpp"

# define DEFAULT_SCAV_HP 100
# define DEFAULT_SCAV_EP 50
# define DEFAULT_SCAV_AP 20

class ScavTrap: public ClapTrap {

public:
    ScavTrap(void);
    ScavTrap(const ScavTrap& object);
    ScavTrap(std::string init_name);
    ~ScavTrap();
    ScavTrap& operator = (const ScavTrap& object);
    void attack(const std::string& target);
    void guardGate();

};

#endif
