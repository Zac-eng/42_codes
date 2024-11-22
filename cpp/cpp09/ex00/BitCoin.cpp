#include "BitCoin.hpp"

BitCoin::BitCoin(const std::string& database_path): _database_path(database_path) {}

BitCoin::~BitCoin() {}

BitCoin::BitCoin(const BitCoin& object) {
	*this = object;
}

BitCoin& BitCoin::operator = (const BitCoin& object) {
	_database_path = object._database_path;
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

int BitCoin::readDataBase(void) {
	std::ifstream csv_stream(_database_path.c_str());
	std::string line;
	std::string::size_type comma_pos;
	Date date;
	double value;

	if (!csv_stream) {
		std::cerr << "Error: Could not open csv file for database: " << _database_path << std::endl;
		return 1;
	}
	getline(csv_stream, line);
	if (csv_stream.fail()) {
		std::cerr << "Error: Failed to read from csv file" << std::endl;
		return 1;
	}
	else if (line != "date,exchange_rate") {
		std::cerr << "Error: Invalid firstline in database, it should be 'date,exchange_rate'" << std::endl;
		return 1;
	}
	while (!csv_stream.eof()) {
		getline(csv_stream, line);
		if (line.empty())
			continue ;
		else if (csv_stream.fail()) {
			std::cerr << "Error: Failed to read from csv file" << std::endl;
			return 1;
		}
		comma_pos = line.find(',');
		if (csv_stream.fail() || comma_pos == std::string::npos) {
			std::cerr << "Error: Invalid data format, it should be 'date,exchange rate'" << std::endl;
			return 1;
		}
		if (parseDate(line.substr(0, comma_pos), date) != 0) {
			std::cerr << "Error: Invalid date in the database" << std::endl;
			return 1;
		}
		if (parseValue(line.substr(comma_pos + 1, line.length()), value) != 0) {
			std::cerr << "Error: Invalid value in the database" << std::endl;
			return 1;
		}
		if (_database.size() > 0 && !(_database.rbegin()->first < date)) {
			std::cerr << "Error: Database does not follow the timeline" << std::endl;
			return 1;
		}
		_database.insert(std::make_pair(date, value));
	}
	return 0;
}

int BitCoin::parseDate(const std::string& date_string, Date& date_struct) {
	std::stringstream ss(trim(date_string));
	char removed;

	ss >> date_struct.year;
	if (ss.fail() || ss.eof())
		return 1;
	ss.get(removed);
	if (removed != '-' || ss.fail() || ss.eof())
		return 1;
	ss >> date_struct.month;
	if (ss.fail() || ss.eof())
		return 1;
	ss.get(removed);
	if (removed != '-' || ss.fail() || ss.eof())
		return 1;
	ss >> date_struct.day;
	if (ss.fail() || !ss.eof())
		return 1;
	if (!isValidDate(date_struct))
		return 1;
	return 0;
}

int BitCoin::parseValue(const std::string& value_string, double& value_double) {
	std::stringstream ss(trim(value_string));

	ss >> value_double;
	if (ss.fail() || !ss.eof())
		return 1;
	if (value_double < 0)
		return 1;
	return 0;
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
		std::cerr << "Error: Could not open file: " << date_n_value << std::endl;
		return ;
	}
	getline(ifs, line);
	pipe_pos = line.find('|');
	if (trim(line.substr(0, pipe_pos)) != "date" || trim(line.substr(pipe_pos + 1, line.length())) != "value") {
		std::cerr << "Error: The first line of the input file should be 'date | value'" << std::endl;
		return ;
	}
	while (!ifs.eof()) {
		getline(ifs, line);
		if (line.empty())
			continue ;
		else if (ifs.fail()) {
			std::cerr << "Error: Failed to read from input file" << std::endl;
			return ;
		}
		pipe_pos = line.find('|');
		if (pipe_pos == std::string::npos) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue ;
		}
		if (parseDate(trim(line.substr(0, pipe_pos)), date) != 0) {
			std::cerr << "Error: the date is invalid." << std::endl;
			continue ;
		}
		if (parseValue(trim(line.substr(pipe_pos + 1, line.length())), value) != 0) {
			std::cerr << "Error: not a positive number." << std::endl;
			continue ;
		}
		else if (value > 1000) {
			std::cerr << "Error: too large a number." << std::endl;
			continue ;
		}
		try {
			ex_rate = findExchangeRate(date);
			std::cout << date << " => " << value << " = " << (ex_rate * value) << std::endl;
		} catch (TooEarlyException& tee) {
			std::cerr << "Error: the date is too early." << std::endl;
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
	os << object.year << "-" << std::setfill('0') << std::setw(2) << object.month << "-" << std::setfill('0') << std::setw(2) << object.day;
	return os;
}
