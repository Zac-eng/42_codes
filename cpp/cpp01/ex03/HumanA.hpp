#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {

	public:
		HumanA(std::string init_name, Weapon &init_weapon);
		void	attack(void);

	private:
		std::string	name;
		Weapon		&weapon;

};

#endif
