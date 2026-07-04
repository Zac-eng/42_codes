#include "Serializer.hpp"

Serializer::Serializer(void) {}

Serializer::Serializer(const Serializer& object) {
  *this = object;
}

Serializer& Serializer::operator = (const Serializer& object) {
  (void)object;
  return *this;
}

Serializer::~Serializer() {}

uintptr_t Serializer::serialize(Data* ptr) {
  return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
  return reinterpret_cast<Data *>(raw);
}