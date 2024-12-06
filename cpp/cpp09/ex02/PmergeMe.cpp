#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& object) {
	*this = object;
}

PmergeMe& PmergeMe::operator = (const PmergeMe& object) {
	this->_i_seq = object._i_seq;
	return *this;
}

int PmergeMe::readInput(const std::string& i_sequence) {
	std::stringstream ss(i_sequence);
	int tmp;
	char next;

	while (!ss.eof()) {
		ss >> tmp;
		if (ss.fail())
			return 1;
		if (tmp < 0)
			return 1;
		_i_seq.push_back(tmp);
		next = ss.peek();
		while (std::isspace(next)) {
			ss.get(next);
			next = ss.peek();
		}
	}
	return 0;
}

void PmergeMe::SortVec(vec_vec& input) {
	vec left;

	if (input.size() == 1)
		return ;
	mSortVec(input, left);
	SortVec(input);
	iSortVec(input, left);
}

void PmergeMe::SortDeq(deq_deq& input) {
	deq left;

	if (input.size() == 1)
		return ;
	mSortDeq(input, left);
	SortDeq(input);
	iSortDeq(input, left);
}

void PmergeMe::mSortVec(vec_vec& input, vec& left) {
	vec_vec merged;
	vec first;
	vec second;

	while (input.size() > 1) {
		first = input.front();
		input.erase(input.begin());
		second = input.front();
		input.erase(input.begin());
		if (first[0] < second[0]) {
			second.insert(second.end(), first.begin(), first.end());
			merged.push_back(second);
		} else {
			first.insert(first.end(), second.begin(), second.end());
			merged.push_back(first);
		}
	}
	if (input.size() == 1)
		left = input.front();
	input = merged;
}

void PmergeMe::mSortDeq(deq_deq& input, deq& left) {
	deq_deq merged;
	deq first;
	deq second;

	while (input.size() > 1) {
		first = input.front();
		input.erase(input.begin());
		second = input.front();
		input.erase(input.begin());
		if (first[0] < second[0]) {
			second.insert(second.end(), first.begin(), first.end());
			merged.push_back(second);
		} else {
			first.insert(first.end(), second.begin(), second.end());
			merged.push_back(first);
		}
	}
	if (input.size() == 1)
		left = input.front();
	input = merged;
}

void PmergeMe::iSortVec(vec_vec& input, vec& left) {
	int input_len = input.size();
	int vec_len = input[0].size();
	int index = 2;
	int insert_count = 0;
	int prior_jacob = 0;

	while (true) {
		vec_vec insert_waitlist;
		int jacob = genJacobSthal(index);
		for (int i=prior_jacob+1; i <= jacob; ++i) {
			if (i > input_len) {
				if (left.size() != 0)
					insert_waitlist.push_back(left);
				break ;
			} else {
				vec& target = input[i+insert_count-1];
				insert_waitlist.push_back(vec(target.begin() + vec_len / 2, target.end()));
				target.resize(vec_len/2);
			}
		}
		for (vec_vec::iterator it = insert_waitlist.begin(); it != insert_waitlist.end(); ++it) {
			vec_vec::iterator insert_index = bSearchVec(input, *it, std::min(jacob, input_len)+insert_count);
			input.insert(insert_index, *it);
			++insert_count;
		}
		if (jacob > input_len)
			break ;
		prior_jacob = jacob;
		++index;
	}
}

void PmergeMe::iSortDeq(deq_deq& input, deq& left) {
	int input_len = input.size();
	int deq_len = input[0].size();
	int index = 2;
	int insert_count = 0;
	int prior_jacob = 0;

	while (true) {
		deq_deq insert_waitlist;
		int jacob = genJacobSthal(index);
		for (int i=prior_jacob+1; i <= jacob; ++i) {
			if (i > input_len) {
				if (left.size() != 0)
					insert_waitlist.push_back(left);
				break ;
			} else {
				deq& target = input[i+insert_count-1];
				insert_waitlist.push_back(deq(target.begin() + deq_len / 2, target.end()));
				target.resize(deq_len/2);
			}
		}
		for (deq_deq::iterator it = insert_waitlist.begin(); it != insert_waitlist.end(); ++it) {
			deq_deq::iterator insert_index = bSearchDeq(input, *it, std::min(jacob, input_len)+insert_count);
			input.insert(insert_index, *it);
			++insert_count;
		}
		if (jacob > input_len)
			break ;
		prior_jacob = jacob;
		++index;
	}
}

int PmergeMe::pMergeVec(void) {
	const vec_vec input = createVecVec();
	vec_vec grand = input;
	std::clock_t start;
	std::clock_t end;

	start = std::clock();
	SortVec(grand);
	end = std::clock();
	std::cout << "Before:\t";
	printVecVec(input);
	std::cout << std::endl;
	std::cout << "After:\t";
	if (printVecVec(grand) != 0)
		return 1;
	std::cout << std::endl;
	printTimeSpent(input.size(), VEC, end - start);
	return 0;
}

int PmergeMe::pMergeDeq(void) {
	const deq_deq input = createDeqDeq();
	deq_deq grand = input;
	std::clock_t start;
	std::clock_t end;

	start = std::clock();
	SortDeq(grand);
	end = std::clock();
	std::cout << "Before:\t";
	printDeqDeq(input);
	std::cout << std::endl;
	std::cout << "After:\t";
	if (printDeqDeq(grand) != 0)
		return 1;
	std::cout << std::endl;
	printTimeSpent(input.size(), DEQ, end - start);
	return 0;
}

vec_vec PmergeMe::createVecVec(void) const {
	vec_vec grand;
	std::size_t len = _i_seq.size();

	for (std::size_t i = 0; i < len; ++i) {
		vec tmp;
		tmp.push_back(_i_seq[i]);
		grand.push_back(tmp);
	}
	return grand;
}

deq_deq PmergeMe::createDeqDeq(void) const {
	deq_deq grand;
	std::size_t len = _i_seq.size();

	for (std::size_t i = 0; i < len; ++i) {
		deq tmp;
		tmp.push_back(_i_seq[i]);
		grand.push_back(tmp);
	}
	return grand;
}


int PmergeMe::printDeqDeq(const deq_deq& to_print) {
	std::size_t len = to_print.size();

	for (std::size_t i = 0; i < len; ++i) {
		if (to_print[i].size() == 0)
			return 1;
		std::cout << to_print[i].front();
		if (i != len)
			std::cout << ' ';
	}
	return 0;
}

int PmergeMe::printVecVec(const vec_vec& to_print) {
	std::size_t len = to_print.size();

	for (std::size_t i = 0; i < len; ++i) {
		if (to_print[i].size() == 0)
			return 1;
		std::cout << to_print[i].front();
		if (i != len)
			std::cout << ' ';
	}
	return 0;
}

int PmergeMe::genJacobSthal(int index) {
	return (std::pow(2, index) - std::pow(-1, index)) / 3;
}

vec_vec::iterator PmergeMe::bSearchVec(vec_vec& grand, vec& inserted, int range) {
	vec_vec::iterator left = grand.begin();

	while (true) {
		range /= 2;
		if (range == 0) {
			if (inserted[0] > (*left)[0])
				++left;
			return left;
		}
		vec_vec::iterator access = left + range;
		if (inserted[0] > (*access)[0])
			left += range;
	}
}

deq_deq::iterator PmergeMe::bSearchDeq(deq_deq& grand, deq& inserted, int range) {
	deq_deq::iterator left = grand.begin();

	while (true) {
		range /= 2;
		if (range == 0) {
			if (inserted[0] > (*left)[0])
				++left;
			return left;
		}
		deq_deq::iterator access = left + range;
		if (inserted[0] > (*access)[0])
			left += range;
	}
}

void PmergeMe::printTimeSpent(const std::size_t& element_num, const Container& which, const std::clock_t& time) {
	std::cout << "Time to process a range of " << element_num << " elements with std::" << (which == DEQ ? "deque" : "vector") << " : ";
	std::cout << ((static_cast<double>(time) / CLOCKS_PER_SEC * 1e6)) << " us" << std::endl;
}
