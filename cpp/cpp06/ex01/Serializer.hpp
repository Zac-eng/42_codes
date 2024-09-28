#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include "Data.hpp"

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
