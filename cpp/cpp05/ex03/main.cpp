#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main(void) {
	Bureaucrat				crew("crew", 120);
	Bureaucrat				elite("elite", 1);
	ShrubberyCreationForm	tree_form("home");
	RobotomyRequestForm robo_form("robby");

	tree_form = ShrubberyCreationForm("home");
	crew.executeForm(tree_form);
	crew.signForm(tree_form);
	crew.executeForm(tree_form);
	crew.signForm(robo_form);
	elite.signForm(robo_form);
	elite.executeForm(robo_form);
	return 0;
}
