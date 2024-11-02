#include "BitCoin.hpp"

BitCoin::BitCoin(const std::string& csv_path) {
	readDataBase(csv_path);
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

void BitCoin::readDataBase(const std::string& db_path) {
	std::ifstream csv_stream(db_path.c_str());
	std::string line;
	std::string::size_type comma_pos;
	Date date;
	double value;

	if (!csv_stream) {
		std::cerr << "No such csv file for database" << std::endl;
		throw FileException();
	}
	getline(csv_stream, line);
	if (csv_stream.fail()) {
		std::cerr << "Failed to read from csv file" << std::endl;
		throw FileException();
	}
	while (!csv_stream.eof()) {
		getline(csv_stream, line);
		if (line.empty())
			continue ;
		else if (csv_stream.fail()) {
			std::cerr << "Failed to read from csv file" << std::endl;
			throw FileException();
		}
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

void BitCoin::parseDate(const std::string& date_string, Date& date_struct) {
	std::stringstream ss(trim(date_string));
	char removed;

	ss >> date_struct.year;
	if (ss.fail() || ss.eof())
		throw InvalidDateException();
	ss.get(removed);
	if (removed != '-' || ss.fail() || ss.eof())
		throw InvalidDateException();
	ss >> date_struct.month;
	if (ss.fail() || ss.eof())
		throw InvalidDateException();
	ss.get(removed);
	if (removed != '-' || ss.fail() || ss.eof())
		throw InvalidDateException();
	ss >> date_struct.day;
	if (ss.fail())
		throw InvalidDateException();
	if (!isValidDate(date_struct))
		throw InvalidDateException();
}

void BitCoin::parseValue(const std::string& value_string, double& value_double) {
	std::stringstream ss(trim(value_string));

	ss >> value_double;
	if (ss.fail())
		throw FileException();
	if (value_double < 0)
		throw NegativeValueException();
}

double BitCoin::findExchangeRate(Date& date) const {
	std::map<Date, double>::const_iterator ret_elem = this->_database.upper_bound(date);
	if (ret_elem == this->_database.begin())
		throw TooEarlyException();
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
	double ex_rate;
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
		else if (ifs.fail()) {
			std::cerr << "Failed to read from input file" << std::endl;
			return ;
		}
		pipe_pos = line.find('|');
		if (pipe_pos == std::string::npos) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue ;
		}
		try {
			parseDate(trim(line.substr(0, pipe_pos)), date);
			parseValue(trim(line.substr(pipe_pos + 1, line.length())), value);
			if (value > 1000)
				throw LargeValueException();
			ex_rate = findExchangeRate(date);
			std::cout << date << " => " << value << " = " << (ex_rate * value) << std::endl;
		} catch (FileException& fe) {
			std::cerr << "Error: error occurred readling from file" << std::endl;
		} catch (TooEarlyException& tee) {
			std::cerr << "Error: the date is too early." << std::endl;
		} catch (InvalidDateException& ide) {
			std::cerr << "Error: the date is invalid." << std::endl;
		} catch (NegativeValueException& nve) {
			std::cerr << "Error: not a positive number." << std::endl;
		} catch (LargeValueException& lve) {
			std::cerr << "Error: too large a number." << std::endl;
		}
	}
}

bool BitCoin::isValidDate(const Date& date) const {
	bool is_leap_year = !(date.year % 4);
	int month = date.month;

	if (date.year < 0 || 2024 < date.year)
		return false;
	if (month == 2)
		return (1 <= date.day && date.day <= (is_leap_year ? 29 : 28));
	if (month ==  4 || month == 6 || month == 9 || month == 11)
		return (1 <= date.day && date.day <= 30);
	else
		return (1 <= date.day && date.day <= 31);
}

std::ostream& operator << (std::ostream& os, const Date& object) {
	os << object.year << "-" << object.month << "-" << object.day;
	return os;
}
