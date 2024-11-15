#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
	std::stringstream ss;

	for (int i = 1; i < argc; ++i) {
		ss << argv[i];
		if (i != argc - 1)
			ss << " ";
	}
	try {
		PmergeMe::mSortQue(ss.str());
	} catch (PmergeMe::InvalidInputException& iie) {
		std::cerr << "The input should be a sequence of positive integer" << std::endl;
		return 1;
	}
	return 0;
}
