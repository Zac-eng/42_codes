#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void) {
	Bureaucrat				crew("crew", 120);
	Bureaucrat				elite("elite", 5);
	ShrubberyCreationForm	tree("home");
	ShrubberyCreationForm	tree_form = tree;
	RobotomyRequestForm robo_form("robby");
	PresidentialPardonForm presidential_form("pressy");

	crew.executeForm(tree_form);
	crew.signForm(tree_form);
	crew.executeForm(tree_form);
	crew.signForm(robo_form);
	elite.signForm(robo_form);
	crew.executeForm(robo_form);
	elite.executeForm(robo_form);
	crew.signForm(presidential_form);
	elite.signForm(presidential_form);
	elite.executeForm(presidential_form);
	return 0;
}
