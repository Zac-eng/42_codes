#include "RPN.hpp"

RPN::RPN(void) {}

RPN::~RPN() {}

void RPN::add(void) {
	double lhs;
	double rhs;

	if (size() <= 1)
		throw FewElementException();
	rhs = top();
	pop();
	lhs = top();
	pop();
	push(lhs + rhs);
}

void RPN::sub(void) {
	double lhs;
	double rhs;

	if (size() <= 1)
		throw FewElementException();
	rhs = top();
	pop();
	lhs = top();
	pop();
	push(lhs - rhs);
}

void RPN::mul(void) {
	double lhs;
	double rhs;

	if (size() <= 1)
		throw FewElementException();
	rhs = top();
	pop();
	lhs = top();
	pop();
	push(lhs * rhs);
}

void RPN::div(void) {
	double lhs;
	double rhs;

	if (size() <= 1)
		throw FewElementException();
	rhs = top();
	pop();
	lhs = top();
	pop();
	push(lhs / rhs);
}
