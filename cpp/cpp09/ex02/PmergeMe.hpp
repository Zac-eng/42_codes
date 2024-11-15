#pragma once
#ifndef PMERGE_HPP
# define PMERGE_HPP

# include <queue>
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
		QUEUE,
		LIST,
	};

	static void createQue(const std::string& i_sequence, std::queue<int>& to_push);
	static void createLst(const std::string& i_sequence, std::list<int>& to_push);
	static void mergeQue(std::queue<std::queue<int> >& grand);
	static void mergeLst(std::list<std::list<int> >& grand);
	static void devideQue(std::queue<int>& original, std::queue<std::queue<int> >& to_push);
	static void devideLst(std::list<int>& original, std::list<std::list<int> >& to_push);
	static void printQue(const std::queue<int>& to_print);
	static void printLst(const std::list<int>& to_print);
	static void printTimeSpent(const std::size_t& element_num, const Container& which, const std::clock_t& time);

public:
	class InvalidInputException: std::exception {};
	static void mSortQue(const std::string& i_sequence);
	static void mSortLst(const std::string& i_sequence);

};

#endif
