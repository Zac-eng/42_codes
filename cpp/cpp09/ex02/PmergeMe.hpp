#pragma once
#ifndef PMERGE_HPP
# define PMERGE_HPP

# include <iostream>
# include <queue>
# include <list>
# include <string>
# include <sstream>
# include <exception>

class PmergeMe {

private:
	PmergeMe(void);
	~PmergeMe();
	PmergeMe(const PmergeMe& obj);
	PmergeMe& operator = (const PmergeMe& obj);
	static void createQue(const std::string& i_sequence, std::queue<int>& to_push);
	static void createLst(const std::string& i_sequence, std::list<std::list<int> >& to_push);
	static void mergeQue(std::queue<std::queue<int> >& grand);
	static void mergeList(std::list<std::list<int> >& grand);
	static void devideQue(std::queue<int>& original, std::queue<std::queue<int> >& to_push);
	static void printQue(const std::queue<int>& to_print);

public:
	class InvalidInputException: std::exception {};
	static void mSortQue(const std::string& i_sequence);
	// static void mSortLst(const std::string& i_sequence);

};

#endif
