#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename >
class Array {

private:

public:
  Array(void);
  Array(unsigned int n);
  ~Array();
  Array& operator = (const Array& object);
  std::size_t size(void) const ;


};

#endif
