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
	pm.pMergeVec();
	pm.pMergeDeq();
	return 0;
}

//command for testing:
// ./PmergeMe $(python3 -c "import random; n=1000; print(' '.join(str(random.randint(1, 100000)) for _ in range(n)))")
