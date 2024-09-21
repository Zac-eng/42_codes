#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon {

	public:
		Weapon(std::string type);
		const std::string&	getType(void);
		void				setType(std::string new_type);

	private:
		std::string	type;

};

#endif
