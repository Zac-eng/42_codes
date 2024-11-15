#include "PmergeMe.hpp"

void PmergeMe::mSortQue(const std::string& i_sequence) {
	std::queue<int> input;
	std::queue<std::queue<int> > grand;

	createQue(i_sequence, input);
	std::cout << "Before\t";
	printQue(input);
	std::cout << std::endl;
	devideQue(input, grand);
	while (grand.size() > 1)
		mergeQue(grand);
	std::cout << "After:\t";
	printQue(grand.front());
	std::cout << std::endl;
}

// void PmergeMe::mSortLst(std::string i_sequence) {
// 	std::list grand;

// 	try {
// 		createLst(i_sequence, grand);
// 	}
// }

void PmergeMe::createQue(const std::string& i_sequence, std::queue<int>& to_push) {
	std::stringstream ss(i_sequence);
	int tmp;

	while (!ss.eof()) {
		std::queue<int> tmp_que;

		ss >> tmp;
		if (ss.fail())
			throw InvalidInputException();
		if (tmp < 0)
			throw InvalidInputException();
		to_push.push(tmp);
	}
}

void PmergeMe::devideQue(std::queue<int>& original, std::queue<std::queue<int> >& to_push) {
	while (!original.empty()) {
		std::queue<int> tmp_que;

		tmp_que.push(original.front());
		original.pop();
		to_push.push(tmp_que);
	}
}

void PmergeMe::mergeQue(std::queue<std::queue<int> >& grand) {
	std::queue<int> tmp_que;
	std::queue<int> first = grand.front();
	grand.pop();
	std::queue<int> second = grand.front();
	grand.pop();

	while (!first.empty() || !second.empty()) {
		if (second.empty()) {
			tmp_que.push(first.front());
			first.pop();
		} else if (first.empty() || first.front() > second.front()) {
			tmp_que.push(second.front());
			second.pop();
		} else {
			tmp_que.push(first.front());
			first.pop();
		}
	}
	grand.push(tmp_que);
}

void PmergeMe::printQue(const std::queue<int>& to_print) {
	std::queue<int> copy = to_print;

	while (!copy.empty()) {
		std::cout << copy.front();
		copy.pop();
		if (!copy.empty())
			std::cout << ' ';
	}
}

// void PmergeMe::createLst(std::string& i_sequence, std::list<std::list<int>>& to_push);
