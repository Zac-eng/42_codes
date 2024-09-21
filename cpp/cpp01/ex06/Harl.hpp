#ifndef HARL_HPP
# define HARL_HPP

# include <string>
# include <iostream>
# include <cctype>
# include <map>

typedef enum {
  DEBUG = 0,
  INFO = 1,
  WARNING = 2,
  ERROR = 3,
  OTHERS = 4
} HarlLevel;

class Harl
{

private:
  void debug(void);
  void info(void);
  void warning(void);
  void error(void);
public:
  void complain(HarlLevel level);

};

#endif
