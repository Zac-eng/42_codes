# include "easyfind.hpp"

template <typename T>
typename T::const_iterator easyfind(const T& container, int target) {
	typename T::const_iterator iter;

	for (iter = container.begin(); iter != container.end(); ++iter) {
		if (*iter == target)
			return iter;
	}
	throw std::exception();
}
