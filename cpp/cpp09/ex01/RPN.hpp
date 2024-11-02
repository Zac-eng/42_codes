#pragma once
#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <exception>

class RPN: public std::stack<int> {

public:
	RPN(void);
	~RPN();
	class FewElementException: public std::exception {};
	void add(void);
	void sub(void);
	void mul(void);
	void div(void);

};

#endif
