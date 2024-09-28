#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>

template <typename T>
void iter(T* array, std::size_t length, void (* func_ptr)(T&)) {
  for (std::size_t i = 0; i < length; i++) {
    func_ptr(array[i]);
  }
}

#endif
