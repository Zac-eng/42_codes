#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): _name("default") {
	this->_grade = 150;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name) {
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& object): _name(object.getName()) {
	this->_grade = object.getGrade();
}

Bureaucrat& Bureaucrat::operator = (const Bureaucrat& object) {
	this->_grade = object.getGrade();
	if (this->getGrade() < 1)
		throw GradeTooHighException();
	else if (this->getGrade() > 150)
		throw GradeTooLowException();
	return *this;
}

Bureaucrat::~Bureaucrat() {}

std::string	Bureaucrat::getName(void) const {
	return this->_name;
}

int	Bureaucrat::getGrade(void) const {
	return this->_grade;
}

void	Bureaucrat::incrementGrade(void) {
	if (this->_grade <= 1)
		throw GradeTooHighException();
	else
		this->_grade -= 1;
}

void	Bureaucrat::decrementGrade(void) {
	if (this->_grade >= 150)
		throw GradeTooLowException();
	else
		this->_grade += 1;
}

void	Bureaucrat::signForm(AForm& form_to_sign) {
	try {
		form_to_sign.beSigned(*this);
		std::cout << this->getName() << " signed " << form_to_sign.getName() << std::endl;
	} catch (AForm::GradeTooHighException& error) {
		std::cout << this->getName() << " couldn't sign " << form_to_sign.getName() << " because the grade was too high." << std::endl;
	} catch (AForm::GradeTooLowException& error) {
		std::cout << this->getName() << " couldn't sign " << form_to_sign.getName() << " because the grade was too low." << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const & form) {
	try {
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	} catch (AForm::NotSignedException& error) {
		std::cout << this->getName() << " couldn't execute " << form.getName() << " because the form is not signed." << std::endl;
	} catch (AForm::GradeTooHighException& error) {
		std::cout << this->getName() << " couldn't execute " << form.getName() << " because the grade was too high." << std::endl;
	} catch (AForm::GradeTooLowException& error) {
		std::cout << this->getName() << " couldn't execute " << form.getName() << " because the grade was too low." << std::endl;
	}
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& object) {
	out << object.getName() << ", bureaucrat grade " << object.getGrade() << ".";
	return out;
}
