#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <algorithm>
# include <exception>
# include <cmath>

class Span {

private:
  std::vector<int> _contents;
  std::vector<int> _spans;
  unsigned int _capacity;
  Span(void);

public:
  Span(unsigned int n);
  ~Span();
  Span(const Span& object);
  Span& operator = (const Span& object);
  void addNumber(int to_add);
  int shortestSpan(void);
  int longestSpan(void);

};

#endif
