#include "easyfind.hpp"
#include <vector>
#include <iostream>

int main(void) {
	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(8);
	vec.push_back(5);
	vec.push_back(6);
	vec.push_back(7);

	std::cout << *(easyfind(vec, 5)) << std::endl;
	std::cout << *(easyfind(vec, 1)) << std::endl;
	return 0;
}
