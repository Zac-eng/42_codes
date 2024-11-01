#ifndef BIT_COIN_HPP
# define BIT_COIN_HPP

# include <string>
# include <fstream>
# include <exception>
# include <map>

typedef struct date {
	unsigned int year;
	unsigned int month;
	unsigned int day;
} t_date;

class BitCoin {

private:
	BitCoin(void);
	static std::map<t_date, double> _database;
	void readDataBase(const std::string& db_path);
	t_date parseDate(const std::string& date);
	double parseValue(const std::string& value);
	class FileException: public std::exception;
	class NegativeValueException: public std::exception;
	class LargeValueException: public std::exception;

public:
	BitCoin(const std::string& csv_path);
	~BitCoin();
	BitCoin(const BitCoin& object);
	BitCoin& operator = (const BitCoin& object);
	void printPrice(const std::string& date_n_value);

};

#endif
