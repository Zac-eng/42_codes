#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main() {
  Serializer serializer;
  Data sample("sample data");
  uintptr_t casted_ptr;
  Data *casted_data;

  std::cout << sample.readContent() << std::endl;
  casted_ptr = serializer.serialize(&sample);
  std::cout << "0x" <<std::hex << casted_ptr << std::endl;
  std::cout << &sample << std::endl;
  casted_data = serializer.deserialize(casted_ptr);
  std::cout << casted_data->readContent() << std::endl;
  return 0;
}