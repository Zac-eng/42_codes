#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"


int	main(void) {
	Bureaucrat				crew("crew", 120);
	Bureaucrat				elite("elite", 1);
	ShrubberyCreationForm	tree_form;

	tree_form = ShrubberyCreationForm("home");
	crew.executeForm(tree_form);
	crew.signForm(tree_form);
	crew.executeForm(tree_form);
	return 0;
}
