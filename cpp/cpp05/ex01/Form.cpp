#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form(void): _name("default"), _sign_grade(150), _exec_grade(150) {
	this->_signed = false;
}

Form::Form(std::string name, int sign_grade, int exec_grade): _name(name), _sign_grade(sign_grade), _exec_grade(exec_grade) {
	this->_signed = false;
}

Form::Form(const Form& object): _name(object.getName()), _sign_grade(object.getSignGrade()), _exec_grade(object.getExecGrade()) {
	(void)object;
	this->_signed = false;
}

Form& Form::operator = (const Form& object) {
	(void)object;
	this->_signed = false;
	return *this;
}

Form::~Form() {}

std::string Form::getName(void) const {
	return this->_name;
}

bool Form::getSigned(void) const {
	return this->_signed;
}

int Form::getSignGrade(void) const {
	return this->_sign_grade;
}

int Form::getExecGrade(void) const {
	return this->_exec_grade;
}

void Form::beSigned(Bureaucrat& signer) {
	if (signer.getGrade() > this->getSignGrade())
		throw GradeTooLowException();
	else
		this->_signed = true;
}

std::ostream& operator << (std::ostream& out, const Form& object) {
	out << object.getName() << ", status: " << (object.getSigned() ? "signed" : "not signed") << ", required grade to sign: " << object.getSignGrade() << " required grade to execute: " << object.getExecGrade() << ".";
	return out;
}
