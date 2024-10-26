#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

# include <stack>
# include <iterator>
# include <iostream>

template <typename T>
class MutantStack: public std::stack<T> {

public:
  class iterator;
  MutantStack(void);
  MutantStack(const MutantStack& object);
  ~MutantStack() {}
  MutantStack& operator = (const MutantStack& object);
  iterator begin();
  iterator end();

};

# include "MutantStack.tpp"

#endif
