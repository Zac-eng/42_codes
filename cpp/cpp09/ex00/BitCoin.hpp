#ifndef BIT_COIN_HPP
# define BIT_COIN_HPP

# include <map>
# include <string>
# include <fstream>
# include <sstream>
# include <iostream>
# include <iomanip>
# include <exception>

struct Date {
	unsigned int year;
	unsigned int month;
	unsigned int day;
	bool operator < (const struct Date& object) const;
};

std::ostream& operator << (std::ostream& os, const Date& object);

class BitCoin {

private:
	std::map<Date, double> _database;
	std::string _database_path;

	BitCoin(void);
	double findExchangeRate(Date& date) const;
	int parseDate(const std::string& date_string, Date& date_struct);
	int parseValue(const std::string& value_string, double& value_double);
	bool isValidDate(const Date& date) const;
	std::string trim(const std::string& str_to_trim);

public:
	BitCoin(const std::string& database_path);
	~BitCoin();
	BitCoin(const BitCoin& object);
	BitCoin& operator = (const BitCoin& object);
	int readDataBase(void);
	void printPrice(const std::string& date_n_value);
	class FileException: public std::exception {};
	class TooEarlyException: public std::exception {};
	class InvalidDateException: public std::exception {};
	class InvalidValueException: public std::exception {};
	class LargeValueException: public std::exception {};

};

#endif
