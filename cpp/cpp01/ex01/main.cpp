#include "Zombie.hpp"

int	main(void) {
	Zombie	*jiangshi_leader = zombieHorde(100, "JIANGSHI");
	Zombie	*jiangshi_alive;
	Zombie	*next_jiangshi;

	jiangshi_alive = jiangshi_leader;
	next_jiangshi = jiangshi_leader;
	while(next_jiangshi != NULL) {
		next_jiangshi->announce();
		next_jiangshi = next_jiangshi->get_next();
	}
	while (jiangshi_alive != NULL) {
		next_jiangshi = jiangshi_alive->get_next();
		delete jiangshi_alive;
		jiangshi_alive = next_jiangshi;
	}
	return (0);
}
