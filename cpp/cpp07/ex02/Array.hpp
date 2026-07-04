#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <string>
# include <iostream>
# include <cstdlib>
# include <exception>

template <typename T>
class Array {

private:
  T* _elements;
  std::size_t _size;

public:
  Array(void);
  Array(unsigned int n);
  Array(const Array& object);
  ~Array();
  Array& operator = (const Array& object);
  T& operator [] (int index);
  T operator [] (int index) const;
  std::size_t size(void) const;

};

# include "Array.tpp"

#endif
