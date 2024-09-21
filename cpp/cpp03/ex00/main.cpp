#include "ClapTrap.hpp"

int main() {
    ClapTrap clap_trap("clptrp");
    ClapTrap clappy("clappy");
    ClapTrap clap_trap_dup(clap_trap);
    ClapTrap clap_trap_another;
    clap_trap_another = clap_trap;

    clap_trap.attack(clappy.getName());
    clappy.takeDamage(clap_trap.getAP());
    clap_trap_dup.beRepaired(5);
    clap_trap_dup.attack(clap_trap.getName());
    clap_trap.takeDamage(clap_trap_dup.getAP());
    clap_trap.beRepaired(4);
    for (int i = 0; i < 10; i++) {
        clap_trap_another.takeDamage(4);
        clap_trap_another.beRepaired(3);
    }
    std::cout << "HP: " << clap_trap_another.getHP() << " EP: " << clap_trap_another.getEP() << std::endl;
    return 0;
}
