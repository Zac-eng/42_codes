#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>

# define HIGHEST_GRADE 1
# define LOWEST_GRADE 150

class	Bureaucrat {

private:
	const std::string	_name;
	int								_grade;
	void							checkGrade(int grade_to_be) const;

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

};

std::ostream& operator << (std::ostream& out, const Bureaucrat& object);

#endif
