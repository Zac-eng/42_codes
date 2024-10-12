#ifndef EASY_FIND_HPP
# define EASY_FIND_HPP

# include <exception>

template <typename T>
typename T::const_iterator easyfind(const T& container, int target);

# include "easyfind.tpp"

#endif
