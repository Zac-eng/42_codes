#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"

class Intern {

public:
  Intern(void);
  Intern(const Intern& object);
  ~Intern();
  Intern& operator = (const Intern& object);
  AForm* makeForm(std::string form_name, std::string target_name);

};

#endif
