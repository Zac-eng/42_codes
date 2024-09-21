#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie	*zombie_leader = NULL;
	Zombie	*zombie_tail = NULL;
	Zombie	*new_zombie;

	for (int i = 0; i < N; i++) {
		new_zombie = new Zombie(name);
		if (zombie_leader == NULL) {
			zombie_leader = new_zombie;
		}
		if (zombie_tail != NULL) {
			zombie_tail->set_next(new_zombie);
		}
		zombie_tail = new_zombie;
	}
	return (zombie_leader);
}
