#include "RPN.hpp"

RPN::RPN(void) {}

RPN::~RPN() {}

void RPN::add(void) {
	int lhs;
	int rhs;

	if (size() <= 1)
		throw FewElementException();
	rhs = top();
	pop();
	lhs = top();
	pop();
	push(lhs + rhs);
}

void RPN::sub(void) {
	int lhs;
	int rhs;

	if (size() <= 1)
		throw FewElementException();
	rhs = top();
	pop();
	lhs = top();
	pop();
	push(lhs - rhs);
}

void RPN::mul(void) {
	int lhs;
	int rhs;

	if (size() <= 1)
		throw FewElementException();
	rhs = top();
	pop();
	lhs = top();
	pop();
	push(lhs * rhs);
}

void RPN::div(void) {
	int lhs;
	int rhs;

	if (size() <= 1)
		throw FewElementException();
	rhs = top();
	pop();
	lhs = top();
	pop();
	push(lhs / rhs);
}
