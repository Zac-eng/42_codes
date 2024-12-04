#include "PmergeMe.hpp"

int main(int argc, char* argv[]) {
	PmergeMe pm;
	std::stringstream ss;

	for (int i = 1; i < argc; ++i) {
		ss << argv[i];
		if (i != argc - 1)
			ss << " ";
	}
	if (pm.readInput(ss.str()) != 0) {
		std::cerr << "Error" << std::endl;
		return 1;
	}
	// PmergeMe::mSortDeQue(ss.str());
	pm.pMergeVec();
	return 0;
}
