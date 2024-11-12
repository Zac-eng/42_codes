#pragma once
#ifndef PMERGE_HPP
# define PMERGE_HPP

# include <queue>
# include <list>
# include <string>
# include <sstream>

class PmergeMe {

private:
	void createQue(std::string& i_sequence, std::queue<std::queue<int>>& to_push);
	void createLst(std::string& i_sequence, std::list<std::list<int>>& to_push);

public:
	void mSortQue(std::string i_sequence);
	void mSortLst(std::string i_sequence);

};

#endif
