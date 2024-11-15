#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
	std::stringstream ss;

	for (int i = 1; i < argc; ++i) {
		ss << argv[i];
		if (i != argc - 1)
			ss << " ";
	}
	PmergeMe::mSortQue(ss.str());
	return 0;
}
