#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include <exception>

class Bureaucrat;

class Form {

private:
	const std::string	_name;
	bool				_signed;
	const int			_sign_grade;
	const int			_exec_grade;

public:
	Form(void);
	Form(std::string name, int sign_grade, int exec_grade);
	Form(const Form& object);
	Form& operator = (const Form& object);
	~Form();
	class GradeTooHighException: public std::exception {};
	class GradeTooLowException: public std::exception {};
	std::string		getName(void) const;
	bool			getSigned(void) const;
	int				getSignGrade(void) const;
	int				getExecGrade(void) const;
	void			beSigned(Bureaucrat& signer);

};

std::ostream& operator << (std::ostream& out, const Form& object);

#endif
