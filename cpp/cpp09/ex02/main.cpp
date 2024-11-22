#include "PmergeMe.hpp"

int main(int argc, char* argv[]) {
	std::stringstream ss;

	for (int i = 1; i < argc; ++i) {
		ss << argv[i];
		if (i != argc - 1)
			ss << " ";
	}
	try {
		PmergeMe::mSortQue(ss.str());
		PmergeMe::mSortLst(ss.str());
	} catch (PmergeMe::InvalidInputException& iie) {
		std::cerr << "Error" << std::endl;
		return 1;
	}
	return 0;
}
