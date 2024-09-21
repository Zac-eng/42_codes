#include "DiamondTrap.hpp"

int main() {
    std::cout << "---test for diamond trap---" << std::endl;
    DiamondTrap diamond_trap("diamond");
    DiamondTrap diamond_two = diamond_trap;
    FragTrap    frag;
    ScavTrap    scav;

    std::cout << diamond_trap.getName() << std::endl;
    std::cout << diamond_trap.getClapName() << std::endl;
    std::cout << diamond_two.getName() << std::endl;
    std::cout << diamond_two.getClapName() << std::endl;
    std::cout << diamond_trap.getHP() << ":(fragtrap)" << frag.getHP() << std::endl;
    std::cout << diamond_trap.getEP() << ":(scavtrap)" << scav.getEP() << std::endl;
    std::cout << diamond_two.getAP() << ":(fragtrap)" << frag.getAP() << std::endl;
    diamond_trap.attack(diamond_two.getName());
    diamond_two.takeDamage(diamond_trap.getAP());
    diamond_trap.beRepaired(10);
    diamond_trap.guardGate();
    diamond_trap.highFivesGuys();
    diamond_trap.whoAmI();

    return 0;
}
