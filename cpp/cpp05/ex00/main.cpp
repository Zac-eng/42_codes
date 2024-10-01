#include "Bureaucrat.hpp"

int	main(void) {
	Bureaucrat bureaucrat;
	Bureaucrat abc("ABC", 120);
	Bureaucrat elite("elite", 1);

	{
		try {
			std::cout << bureaucrat << std::endl;
			bureaucrat.incrementGrade();
			std::cout << bureaucrat << std::endl;
			bureaucrat.decrementGrade();
			std::cout << bureaucrat << std::endl;
			bureaucrat.decrementGrade();
		} catch (Bureaucrat::GradeTooHighException& e) {
			std::cout << "too high exception" << std::endl;
		} catch (Bureaucrat::GradeTooLowException& e) {
			std::cout << "too low exception" << std::endl;
		}
	}
	{
		try {
			Bureaucrat abc_copy = abc;
			std::cout << abc_copy << std::endl;
			abc_copy.incrementGrade();
			std::cout << abc_copy << std::endl;
			abc_copy.decrementGrade();
			std::cout << abc_copy << std::endl;
			std::cout << elite << std::endl;
			elite.incrementGrade();
			std::cout << elite << std::endl;
		} catch (Bureaucrat::GradeTooHighException& e) {
			std::cout << "too high exception" << std::endl;
		} catch (Bureaucrat::GradeTooLowException& e) {
			std::cout << "too low exception" << std::endl;
		}
	}
	return 0;
}
