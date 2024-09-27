#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(void): AForm("default", ROBOTOMY_SIGN_GRADE, ROBOTOMY_EXEC_GRADE) {}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm(target, ROBOTOMY_SIGN_GRADE, ROBOTOMY_EXEC_GRADE) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& object): AForm(object) {
	*this = object;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm& RobotomyRequestForm::operator = (const RobotomyRequestForm& object) {
  (void)object;
  return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
  if (this->getSigned() == false)
    throw NotSignedException();
  else if (executor.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
  std::cout << "Drrrrrrrr......" << std::endl; 
  srand(static_cast<unsigned int>(time(0)));
  bool robotomizable = rand() % 2;
  if (robotomizable)
    std::cout << this->getName() << " has robotomized!!!" << std::endl;
  else
    std::cout << "robotomization failed......" << std::endl;
}
