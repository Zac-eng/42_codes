#include "ScavTrap.hpp"

int main() {
    ClapTrap clap_trap("clap");
    ScavTrap scav_trap("scav");
    ScavTrap scav_trap_dup(scav_trap);
    ScavTrap scav_trap_another;
    scav_trap_another = scav_trap;

    clap_trap.attack("scav");
    scav_trap.takeDamage(clap_trap.getAP());
    std::cout << "clap trap STATUS: " << clap_trap.getHP() << ":" << clap_trap.getEP() << std::endl;
    std::cout << "scav trap STATUS: " << scav_trap.getHP() << ":" << scav_trap.getEP() << std::endl;
    scav_trap.attack("clap");
    clap_trap.takeDamage(scav_trap.getAP());
    std::cout << "clap trap STATUS: " << clap_trap.getHP() << ":" << clap_trap.getEP() << std::endl;
    std::cout << "scav trap STATUS: " << scav_trap.getHP() << ":" << scav_trap.getEP() << std::endl;
    scav_trap.guardGate();
    return 0;
}
