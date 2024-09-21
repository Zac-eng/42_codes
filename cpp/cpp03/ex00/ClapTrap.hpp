#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

# include <string>
# include <iostream>

# define DEFAULT_CLAP_HP 10
# define DEFAULT_CLAP_EP 10
# define DEFAULT_CLAP_AP 0

class ClapTrap {

private:
    std::string name;
    int         hit_point;
    int         energy_point;
    int         attack_damage;
    bool        canMove(void) const;
    void        consumeEP(void);

public:
    ClapTrap(void);
    ClapTrap(const ClapTrap& object);
    ClapTrap(std::string init_name);
    ~ClapTrap();
    ClapTrap& operator = (const ClapTrap& object);
    std::string getName() const;
    int getHP(void) const;
    int getEP(void) const;
    int getAP(void) const;
    virtual void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

};

#endif
