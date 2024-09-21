#include "FragTrap.hpp"

int main() {
    ClapTrap clap_trap("clap");
    FragTrap frag_trap("frag");
    FragTrap frag_trap_dup(frag_trap);
    FragTrap frag_trap_another;
    frag_trap_another = frag_trap;

    clap_trap.attack("frag");
    frag_trap.takeDamage(clap_trap.getAP());
    std::cout << "clap trap STATUS: " << clap_trap.getHP() << ":" << clap_trap.getEP() << std::endl;
    std::cout << "frag trap STATUS: " << frag_trap.getHP() << ":" << frag_trap.getEP() << std::endl;
    clap_trap.beRepaired(100);
    frag_trap.attack("clap");
    clap_trap.takeDamage(frag_trap.getAP());
    std::cout << "clap trap STATUS: " << clap_trap.getHP() << ":" << clap_trap.getEP() << std::endl;
    std::cout << "frag trap STATUS: " << frag_trap.getHP() << ":" << frag_trap.getEP() << std::endl;
    frag_trap.highFivesGuys();
    return 0;
}
