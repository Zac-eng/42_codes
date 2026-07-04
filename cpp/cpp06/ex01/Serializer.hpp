#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include "Data.hpp"
//necessary to use uintptr_t since <cstdint> is available on C++11
# include <stdint.h>

class Serializer {

public:
  Serializer(void);
  Serializer(const Serializer& object);
  Serializer& operator = (const Serializer& object);
  ~Serializer();
  static uintptr_t serialize(Data* ptr);
  static Data* deserialize(uintptr_t raw);

};

#endif
