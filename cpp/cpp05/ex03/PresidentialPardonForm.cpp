#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): AForm("default", PRESIDENTIAL_SIGN_GRADE, PRESIDENTIAL_EXEC_GRADE) {}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm(target, PRESIDENTIAL_SIGN_GRADE, PRESIDENTIAL_EXEC_GRADE) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& object): AForm(object) {
	*this = object;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm& PresidentialPardonForm::operator = (const PresidentialPardonForm& object) {
  (void)object;
  return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
  if (this->getSigned() == false)
    throw NotSignedException();
  else if (executor.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
  std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
