#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>
# include "AForm.hpp"

class	Bureaucrat {

private:
	const std::string	_name;
	int					_grade;

public:
	Bureaucrat(void);
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat& object);
	Bureaucrat& operator = (const Bureaucrat& object);
	~Bureaucrat();
	class GradeTooHighException: public std::exception {};
	class GradeTooLowException: public std::exception {};
	std::string	getName(void) const;
	int			getGrade(void) const;
	void		incrementGrade(void);
	void		decrementGrade(void);
	void		signForm(AForm& form_to_sign);
	void		executeForm(AForm const & form);

};

std::ostream& operator << (std::ostream& out, const Bureaucrat& object);

#endif
