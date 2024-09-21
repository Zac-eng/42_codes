#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie {

	public:
		Zombie(std::string name);
		~Zombie(void);
		void	announce(void) const;
		Zombie*	get_next(void) const;
		void	set_next(Zombie *next_zombie);

	private:
		std::string	_name;
		Zombie		*_next;
};

Zombie* zombieHorde(int N, std::string name);

#endif