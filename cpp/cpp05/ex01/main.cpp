#include "Bureaucrat.hpp"

int	main(void) {
	Bureaucrat bureaucrat;
	Bureaucrat abc("ABC", 120);
	Bureaucrat elite("elite", 1);
	Form form_one("1", 100, 10);
	Form not_important("not_important", 150, 150);
	Form confidential("confidential", 1, 1);

	std::cout << form_one << std::endl;
	bureaucrat.signForm(form_one);
	std::cout << form_one << std::endl;
	std::cout << not_important << std::endl;
	bureaucrat.signForm(not_important);
	std::cout << not_important << std::endl;
	std::cout << elite << std::endl;
	elite.decrementGrade();
	elite.signForm(confidential);
	std::cout << elite << std::endl;
	std::cout << confidential << std::endl;
	elite.incrementGrade();
	elite.signForm(confidential);
	std::cout << elite << std::endl;
	std::cout << confidential << std::endl;
	return 0;
}
