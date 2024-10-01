#ifndef A_FORM_HPP
# define A_FORM_HPP

# include <string>
# include <iostream>
# include <exception>

class Bureaucrat;

class AForm {

private:
	const std::string	_name;
	bool				_signed;
	const int			_sign_grade;
	const int			_exec_grade;

public:
	AForm(void);
	AForm(std::string name, int sign_grade, int exec_grade);
	AForm(const AForm& object);
	AForm& operator = (const AForm& object);
	virtual ~AForm();
	class GradeTooHighException: public std::exception {};
	class GradeTooLowException: public std::exception {};
	class NotSignedException: public std::exception {};
	std::string		getName(void) const;
	bool			getSigned(void) const;
	int				getSignGrade(void) const;
	int				getExecGrade(void) const;
	void			beSigned(Bureaucrat& signer);
	void			checkExecutable(Bureaucrat const & executor) const;
	virtual void	execute(Bureaucrat const & executor) const = 0;

};

std::ostream& operator << (std::ostream& out, const AForm& object);

#endif
