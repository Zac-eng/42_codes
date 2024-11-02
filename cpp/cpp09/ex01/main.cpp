#include "RPN.hpp"
#include <string>
#include <iostream>
#include <sstream>
# include <cctype>

int main(int argc, char* argv[]) {
	RPN rpn;
	std::stringstream ss;
	char got;

	if (argc != 2) {
		std::cout << "Please pass an 'inverted Polish mathematical expression' as an argument" << std::endl;
		return 1;
	}
	ss.str(argv[1]);
	while (!ss.eof()) {
		ss.get(got);
		if (std::isspace(got) || ss.eof())
			continue ;
		if (!ss.eof() && ss.fail()) {
			std::cerr << "Error occurred reading string stream" << std::endl;
			return 1;
		}
		try {
			if (isdigit(got))
				rpn.push(got - '0');
			else if (got == '+')
				rpn.add();
			else if (got == '-')
				rpn.sub();
			else if (got == '*')
				rpn.mul();
			else if (got == '/')
				rpn.div();
			else {
				std::cout << "Error" << std::endl;
				return 1;
			}
		} catch (RPN::FewElementException& fee) {
			std::cerr << "Input expression invalid" << std::endl;
			return 1;
		}
	}
	if (rpn.size() != 1) {
		std::cerr << "Input expression invalid" << std::endl;
		return 1;
	}
	std::cout << rpn.top() << std::endl;
	return 0;
}
