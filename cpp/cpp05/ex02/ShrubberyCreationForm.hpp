#ifndef SHRUBBERY_CREATION_FORM_HPP
# define SHRUBBERY_CREATION_FORM_HPP

# include "AForm.hpp"
# include <fstream>

# define SHRUBBERY_SIGN_GRADE 145
# define SHRUBBERY_EXEC_GRADE 137

class ShrubberyCreationForm: public AForm {

public:
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm& object);
	~ShrubberyCreationForm();
	ShrubberyCreationForm& operator = (const ShrubberyCreationForm& object);
	bool execute(Bureaucrat const & executor) const;

};

#endif
