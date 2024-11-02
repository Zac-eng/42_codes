#include "RPN.hpp"

RPN::RPN(void) {}

RPN::~RPN() {}

void RPN::operator + (void) {
	double lhs;
	double rhs;

	if (size() <= 1)
		return ;
	lhs = top();
	pop();
	rhs = top();
	pop();
	push(lhs + rhs);
}
