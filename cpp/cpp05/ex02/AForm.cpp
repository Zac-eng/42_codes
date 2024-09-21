#include "Bureaucrat.hpp"
#include "AForm.hpp"

AForm::AForm(void): _name("default"), _sign_grade(150), _exec_grade(150) {
	this->_signed = false;
}

AForm::AForm(std::string name, int sign_grade, int exec_grade): _name(name), _sign_grade(sign_grade), _exec_grade(exec_grade) {
	this->_signed = false;
}

AForm::AForm(const AForm& object): _name(object.getName()), _sign_grade(object.getSignGrade()), _exec_grade(object.getExecGrade()) {
	(void)object;
	this->_signed = false;
}

AForm& AForm::operator = (const AForm& object) {
	(void)object;
	this->_signed = false;
	return *this;
}

AForm::~AForm() {}

std::string AForm::getName(void) const {
	return this->_name;
}

bool AForm::getSigned(void) const {
	return this->_signed;
}

int AForm::getSignGrade(void) const {
	return this->_sign_grade;
}

int AForm::getExecGrade(void) const {
	return this->_exec_grade;
}

void AForm::beSigned(Bureaucrat& signer) {
	if (signer.getGrade() > this->getSignGrade())
		throw GradeTooLowException();
	else
		this->_signed = true;
}

std::ostream& operator << (std::ostream& out, const AForm& object) {
	out << object.getName() << ", status: " << (object.getSigned() ? "signed" : "not signed") << ", required grade to sign: " << object.getSignGrade() << " required grade to execute: " << object.getExecGrade() << ".";
	return out;
}
