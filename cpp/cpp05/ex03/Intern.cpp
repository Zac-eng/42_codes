#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void) {}

Intern::Intern(const Intern& object) {
  *this = object;
}

Intern::~Intern() {}

Intern& Intern::operator = (const Intern& object) {
  (void)object;
  return *this;
}

AForm* Intern::makeForm(std::string form_name, std::string target_name) {
  std::string form_names[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
  AForm* form_ptrs[] = {new ShrubberyCreationForm(target_name), new RobotomyRequestForm(target_name), new PresidentialPardonForm(target_name)};
  AForm* return_ptr;

  for (int i = 0; i < static_cast<int>(form_names->length()); i++) {
    if (form_name == form_names[i])
      return_ptr = form_ptrs[i];
    else
      delete form_ptrs[i];
  }
  return return_ptr;
}
