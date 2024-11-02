#include "RPN.hpp"
#include <iostream>

int main(void) {
	RPN rpn;

	rpn.push(1.0);
	rpn.push(20.0);
	//check copy copy assignment operator works;
	RPN copy = rpn;
	rpn.operator+();
	std::cout << rpn.top() << std::endl;
	std::cout << copy.top() << std::endl;
	return 0;
}
