#include "PmergeMe.hpp"

void PmergeMe::mSortQue(const std::string& i_sequence) {
	std::queue<int> input;
	std::queue<std::queue<int> > grand;
	std::clock_t start;
	std::clock_t end;

	start = std::clock();
	createQue(i_sequence, input);
	devideQue(input, grand);
	while (grand.size() > 1)
		mergeQue(grand);
	end = std::clock();
	std::cout << "Before:\t";
	printQue(input);
	std::cout << std::endl;
	std::cout << "After:\t";
	printQue(grand.front());
	std::cout << std::endl;
	printTimeSpent(input.size(), QUEUE, end - start);
}

void PmergeMe::mSortLst(const std::string& i_sequence) {
	std::list<int> input;
	std::list<std::list<int> > grand;
	std::clock_t start;
	std::clock_t end;

	start = std::clock();
	createLst(i_sequence, input);
	devideLst(input, grand);
	while (grand.size() > 1)
		mergeLst(grand);
	end = std::clock();
	printTimeSpent(input.size(), LIST, end - start);
}

void PmergeMe::createQue(const std::string& i_sequence, std::queue<int>& to_push) {
	std::stringstream ss(i_sequence);
	int tmp;
	char next;

	while (!ss.eof()) {
		std::queue<int> tmp_que;

		ss >> tmp;
		if (ss.fail())
			throw InvalidInputException();
		if (tmp < 0)
			throw InvalidInputException();
		to_push.push(tmp);
		next = ss.peek();
		while (std::isspace(next)) {
			ss.get(next);
			next = ss.peek();
		}
	}
}

void PmergeMe::createLst(const std::string& i_sequence, std::list<int>& to_push) {
	std::stringstream ss(i_sequence);
	int tmp;
	char next;

	while (!ss.eof()) {
		std::list<int> tmp_lst;

		ss >> tmp;
		if (ss.fail())
			throw InvalidInputException();
		if (tmp < 0)
			throw InvalidInputException();
		to_push.push_back(tmp);
		next = ss.peek();
		while (std::isspace(next)) {
			ss.get(next);
			next = ss.peek();
		}
	}
}


void PmergeMe::devideQue(const std::queue<int>& original, std::queue<std::queue<int> >& to_push) {
	std::queue<int> que_copy = original;

	while (!que_copy.empty()) {
		std::queue<int> tmp_que;

		tmp_que.push(que_copy.front());
		que_copy.pop();
		to_push.push(tmp_que);
	}
}

void PmergeMe::devideLst(const std::list<int>& original, std::list<std::list<int> >& to_push) {
	std::list<int> list_copy = original;

	while (!list_copy.empty()) {
		std::list<int> tmp_lst;

		tmp_lst.push_back(list_copy.front());
		list_copy.pop_front();
		to_push.push_back(tmp_lst);
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

void PmergeMe::mergeLst(std::list<std::list<int> >& grand) {
	std::list<int> tmp_que;
	std::list<int> first = grand.front();
	grand.pop_front();
	std::list<int> second = grand.front();
	grand.pop_front();

	while (!first.empty() || !second.empty()) {
		if (second.empty()) {
			tmp_que.push_back(first.front());
			first.pop_front();
		} else if (first.empty() || first.front() > second.front()) {
			tmp_que.push_back(second.front());
			second.pop_front();
		} else {
			tmp_que.push_back(first.front());
			first.pop_front();
		}
	}
	grand.push_back(tmp_que);
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

void PmergeMe::printLst(const std::list<int>& to_print) {
	std::list<int> copy = to_print;

	while (!copy.empty()) {
		std::cout << copy.front();
		copy.pop_front();
		if (!copy.empty())
			std::cout << ' ';
	}
}

void PmergeMe::printTimeSpent(const std::size_t& element_num, const Container& which, const std::clock_t& time) {
	std::cout << "Time to process a range of " << element_num << " elements with std::" << (which == QUEUE ? "queue" : "list") << " : ";
	std::cout << ((static_cast<double>(time) / CLOCKS_PER_SEC * 1e6)) << " us" << std::endl;
}
