#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

# include "AForm.hpp"
# include <cstdlib>
# include <ctime>

# define ROBOTOMY_SIGN_GRADE 72
# define ROBOTOMY_EXEC_GRADE 45

class RobotomyRequestForm: public AForm {

public:
	RobotomyRequestForm(void);
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm& object);
	~RobotomyRequestForm();
	RobotomyRequestForm& operator = (const RobotomyRequestForm& object);
	void execute(Bureaucrat const & executor) const;

};

#endif
