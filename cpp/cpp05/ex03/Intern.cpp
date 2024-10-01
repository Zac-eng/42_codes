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
  int form_len = static_cast<int>(sizeof(form_names) / sizeof(form_names[0]));
  AForm* form_ptrs[] = {new ShrubberyCreationForm(target_name), new RobotomyRequestForm(target_name), new PresidentialPardonForm(target_name)};
  AForm* return_ptr = NULL;

  for (int i = 0; i < form_len; i++) {
    if (form_name == form_names[i])
      return_ptr = form_ptrs[i];
    else
      delete form_ptrs[i];
  }
  if (return_ptr == NULL)
    std::cout << "the form name, " << form_name << " does not exist" << std::endl;
  return return_ptr;
}
