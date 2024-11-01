#include "BitCoin.hpp"

BitCoin::BitCoin(const std::string& csv_path) {
	std::ifstream csv_stream(csv_path);
	std::string line;
	t_date date;
	double value;

	if (!csv_stream) {
		std::cerr << "No such csv file for database" << std::endl;
		throw FileException();
	}
	while (!csv_stream.eof()) {
		line = getline(csv_stream, line);
		if 
	}
	date = parseDate()
	value = parseValue()
}
BitCoin::~BitCoin() {}

BitCoin::BitCoin(const BitCoin& object) {
	*this = object;
}

BitCoin& BitCoin::operator = (const BitCoin& object) {
	this->_database = object._database;
	return *this;
}

t_date BitCoin::parseDate(const std::string& date) {
	
}

double BitCoin::parseValue(const std::string& value);

void BitCoin::printPrice(const std::string& date_n_value);
