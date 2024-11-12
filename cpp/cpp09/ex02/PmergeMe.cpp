#include "PmergeMe.hpp"

void PmergeMe::mSortQue(std::string i_sequence) {
	std::queue grand;

	try {
		createQue(i_sequence, grand);
	} catch () {}
}
void PmergeMe::mSortLst(std::string i_sequence) {
	std::list grand;

	try {
		createLst(i_sequence, grand);
	}
}

void PmergeMe::createQue(std::string& i_sequence, std::queue<std::queue<int>>& to_push) {
	std::stringstream ss(i_sequence);
	
	int tmp;

	while (true) {
		ss >> tmp;
		if (ss.fail()) {
			std::cerr << "Input array invalid" << std::endl;
			throw InvalidInputException();
		}
		if (ss.eof())
			break ;
		if (tmp < 0)
			throw NegativeValueException();

	}

}
void PmergeMe::createLst(std::string& i_sequence, std::list<std::list<int>>& to_push);
