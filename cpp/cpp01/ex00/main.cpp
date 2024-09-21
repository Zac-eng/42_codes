#include "Zombie.hpp"

int	main() {
	Zombie *tom = newZombie("TOM");
	tom->announce();
	randomChump("JELLY");
	delete tom;
	return (0);
}
