#include "BitCoin.hpp"

BitCoin::BitCoin(const std::string& csv_path) {
	std::ifstream csv_stream(csv_path.c_str());
	std::string line;
	std::string::size_type comma_pos;
	Date date;
	double value;

	if (!csv_stream) {
		std::cerr << "No such csv file for database" << std::endl;
		throw FileException();
	}
	getline(csv_stream, line);
	while (!csv_stream.eof()) {
		getline(csv_stream, line);
		if (line.empty())
			continue ;
		comma_pos = line.find(',');
		if (csv_stream.fail() || comma_pos == std::string::npos) {
			std::cerr << "Invalid date format, it should be 'date,exchange rate'" << std::endl;
			throw FileException();
		}
		parseDate(line.substr(0, comma_pos), date);
		parseValue(line.substr(comma_pos + 1, line.length()), value);
		_database.insert(std::make_pair(date, value));
	}
}
BitCoin::~BitCoin() {}

BitCoin::BitCoin(const BitCoin& object) {
	*this = object;
}

BitCoin& BitCoin::operator = (const BitCoin& object) {
	_database = object._database;
	return *this;
}

bool Date::operator < (const Date& object) const {
	if (year != object.year)
		return year < object.year;
	else if (month != object.month)
		return month < object.month;
	else
		return day < object.day;
}

void BitCoin::parseDate(const std::string& date_string, Date& date_struct) {
	std::stringstream ss(trim(date_string));
	char removed;

	ss >> date_struct.year;
	if (ss.fail() || ss.eof())
		throw std::exception();
	ss.get(removed);
	if (removed != '-' || ss.fail() || ss.eof())
		throw std::exception();
	ss >> date_struct.month;
	if (ss.fail() || ss.eof())
		throw std::exception();
	ss.get(removed);
	if (removed != '-' || ss.fail() || ss.eof())
		throw std::exception();
	ss >> date_struct.day;
	if (ss.fail())
		throw std::exception();
}

void BitCoin::parseValue(const std::string& value_string, double& value_double) {
	std::stringstream ss(trim(value_string));

	ss >> value_double;
	if (ss.fail())
		throw std::exception();
	if (value_double < 0)
		throw NegativeValueException();
}

double BitCoin::findExchangeRate(Date& date) const {
	std::map<Date, double>::const_iterator ret_elem = this->_database.upper_bound(date);
	ret_elem--;
	return ret_elem->second;
}

std::string BitCoin::trim(const std::string& str_to_trim) {
	std::size_t start = 0;
	std::size_t end = str_to_trim.length();

	while (start < end && std::isspace(str_to_trim[start])) {
        ++start;
    }
    while (end > start && std::isspace(str_to_trim[end - 1])) {
        --end;
    }
    return str_to_trim.substr(start, end - start);
}

void BitCoin::printPrice(const std::string& date_n_value) {
	std::ifstream ifs(date_n_value.c_str());
	std::string line;
	std::string::size_type pipe_pos;
	Date date;
	double value;

	if (!ifs) {
		std::cerr << "No such file or directory: " << date_n_value << std::endl;
		return ;
	}
	getline(ifs, line);
	pipe_pos = line.find('|');
	if (trim(line.substr(0, pipe_pos)) != "date" || trim(line.substr(pipe_pos + 1, line.length())) != "value") {
		std::cerr << "The first line of input file should be 'date | value'" << std::endl;
		return ;
	}
	while (!ifs.eof()) {
		getline(ifs, line);
		if (line.empty())
			continue ;
		pipe_pos = line.find('|');
		try {
			parseDate(trim(line.substr(0, pipe_pos)), date);
			parseValue(trim(line.substr(pipe_pos + 1, line.length())), value);
			if (value > 1000)
				throw LargeValueException();
			std::cout << date << " => " << value << " = " << (findExchangeRate(date) * value) << std::endl;
		} catch (NegativeValueException& nve) {
			std::cerr << "Error: not a positive number." << std::endl;
		} catch (LargeValueException& lve) {
			std::cerr << "Error: too large a number." << std::endl;
		} catch (std::exception& e) {
			std::cerr << "Error: bad input => 2001-42-42" << std::endl;
		}
	}
}

std::ostream& operator << (std::ostream& os, const Date& object) {
	os << object.year << "-" << object.month << "-" << object.day;
	return os;
}
