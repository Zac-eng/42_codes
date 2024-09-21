#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

# include "ClapTrap.hpp"

# define DEFAULT_FRAG_HP 100
# define DEFAULT_FRAG_EP 100
# define DEFAULT_FRAG_AP 30

class FragTrap: public ClapTrap {

public:
    FragTrap(void);
    FragTrap(const FragTrap& object);
    FragTrap(std::string init_name);
    ~FragTrap();
    FragTrap& operator = (const FragTrap& object);
    void attack(const std::string& target);
    void highFivesGuys(void);
};

#endif
