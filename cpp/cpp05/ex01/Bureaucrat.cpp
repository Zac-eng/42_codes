#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): _name("default"), _grade(LOWEST_GRADE) {}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name) {
	checkGrade(grade);
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& object): _name(object.getName()) {
	*this = object;
}

Bureaucrat& Bureaucrat::operator = (const Bureaucrat& object) {
	checkGrade(object.getGrade());
	this->_grade = object.getGrade();
	return *this;
}

Bureaucrat::~Bureaucrat() {}

void Bureaucrat::checkGrade(int grade_to_be) const {
	if (grade_to_be > LOWEST_GRADE)
		throw GradeTooLowException();
	else if (grade_to_be < HIGHEST_GRADE)
		throw GradeTooHighException();
}

std::string	Bureaucrat::getName(void) const {
	return this->_name;
}

int	Bureaucrat::getGrade(void) const {
	return this->_grade;
}

void	Bureaucrat::incrementGrade(void) {
	checkGrade(this->_grade - 1);
	this->_grade -= 1;
}

void	Bureaucrat::decrementGrade(void) {
	checkGrade(this->_grade + 1);
	this->_grade += 1;
}

void	Bureaucrat::signForm(Form& form_to_sign) {
	try {
		form_to_sign.beSigned(*this);
		std::cout << this->getName() << " signed " << form_to_sign.getName() << std::endl;
	} catch (Form::GradeTooHighException& error) {
		std::cout << this->getName() << " couldn't sign " << form_to_sign.getName() << " because the grade was too high." << std::endl;
	} catch (Form::GradeTooLowException& error) {
		std::cout << this->getName() << " couldn't sign " << form_to_sign.getName() << " because the grade was too low." << std::endl;
	}
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& object) {
	out << object.getName() << ", bureaucrat grade " << object.getGrade() << ".";
	return out;
}
