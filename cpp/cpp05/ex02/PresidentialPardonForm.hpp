#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

# include "AForm.hpp"

# define PRESIDENTIAL_SIGN_GRADE 25
# define PRESIDENTIAL_EXEC_GRADE 5

class PresidentialPardonForm: public AForm {

public:
	PresidentialPardonForm(void);
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm& object);
	~PresidentialPardonForm();
	PresidentialPardonForm& operator = (const PresidentialPardonForm& object);
	void execute(Bureaucrat const & executor) const;

};

#endif
