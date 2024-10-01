#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void) {
	{
		Bureaucrat	robo_executor("robo", 45);
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		if (rrf == NULL)
			return 1;
		robo_executor.executeForm(*rrf);
		robo_executor.signForm(*rrf);
		robo_executor.executeForm(*rrf);
		delete rrf;
	}
	{
		Bureaucrat	pp_executor("elite", 5);
		Intern someRandomIntern;
		AForm* ppf;
		ppf = someRandomIntern.makeForm("presidentialpardon", "speaker");
		if (ppf == NULL) {
			std::cout << "wrong form name detected appropriately!" << std::endl;
		}
		ppf = someRandomIntern.makeForm("presidential pardon", "speaker");
		if (ppf == NULL)
			return 1;
		pp_executor.executeForm(*ppf);
		pp_executor.signForm(*ppf);
		pp_executor.executeForm(*ppf);
		delete ppf;
	}
	return 0;
}
