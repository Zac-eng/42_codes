#pragma once
#ifndef PMERGE_HPP
# define PMERGE_HPP

# include <deque>
# include <list>
# include <iostream>
# include <string>
# include <exception>
# include <ctime>
# include <sstream>

class PmergeMe {

private:
	PmergeMe(void);
	~PmergeMe();
	PmergeMe(const PmergeMe& obj);
	PmergeMe& operator = (const PmergeMe& obj);

	enum Container {
		DEQUE,
		LIST,
	};

	static void createDeQue(const std::string& i_sequence, std::deque<int>& to_push);
	static void createLst(const std::string& i_sequence, std::list<int>& to_push);
	static void mergeDeQue(std::deque<std::deque<int> >& grand);
	static void mergeLst(std::list<std::list<int> >& grand);
	static void devideDeQue(const std::deque<int>& original, std::deque<std::deque<int> >& to_push);
	static void devideLst(const std::list<int>& original, std::list<std::list<int> >& to_push);
	static void printDeQue(const std::deque<int>& to_print);
	static void printLst(const std::list<int>& to_print);
	static void printTimeSpent(const std::size_t& element_num, const Container& which, const std::clock_t& time);

public:
	class InvalidInputException: std::exception {};
	static void mSortDeQue(const std::string& i_sequence);
	static void mSortLst(const std::string& i_sequence);

};

#endif
