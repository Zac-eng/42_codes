#pragma once
#ifndef RPN_HPP
# define RPN_HPP

# include <stack>

class RPN: public std::stack<double> {

public:
	RPN(void);
	~RPN();
	void operator + (void);

};

#endif
