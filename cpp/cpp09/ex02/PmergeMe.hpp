#pragma once
#ifndef PMERGE_HPP
# define PMERGE_HPP

# include <vector>
# include <deque>
# include <iostream>
# include <string>
# include <ctime>
# include <cmath>
# include <sstream>

typedef std::vector<int> vec;
typedef std::vector<std::vector<int> > vec_vec;
typedef std::deque<int> deq;
typedef std::deque<std::deque<int> > deq_deq;

class PmergeMe {

private:
	vec _i_seq;

	enum Container {
		DEQ,
		VEC,
	};
	int genJacobSthal(int index);

	void SortVec(vec_vec& input);
	// void SortDeq(deq_deq& input);
	void mSortVec(vec_vec& input, vec& left);
	// void mSortDeq(deq_deq& input);
	void iSortVec(vec_vec& input, vec& left);
	// void iSortDeq(deq_deq& input);

	vec_vec::iterator bSearchVec(vec_vec& grand, vec& inserted, int range);
	vec_vec createVecVec(void) const;
	deq_deq createDeqDeq(void) const;
	int printDeqDeq(const deq_deq& to_print);
	int printVecVec(const vec_vec& to_print);
	void printTimeSpent(const std::size_t& element_num, const Container& which, const std::clock_t& time);

public:
	PmergeMe(void);
	~PmergeMe();
	PmergeMe(const PmergeMe& obj);
	PmergeMe& operator = (const PmergeMe& obj);

	int readInput(const std::string& i_sequence);
	// int pMergeDeq(void);
	int pMergeVec(void);

};

#endif
