#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

# include <stack>

template <typename T>
class MutantStack: public std::stack<T> {

public:
  MutantStack(void);
  MutantStack(const MutantStack& object);
  ~MutantStack();

};

# include "MutantStack.tpp"

#endif
