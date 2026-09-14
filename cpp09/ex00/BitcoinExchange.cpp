#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	_data = other._data;
}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if(this != &other)
		_data = other._data;
	return *this;
}

bool BitcoinExchange::validate_date_calendar(const std::string &date)
{
	int year = std::atoi(date.substr(0,4).c_str());
	int month = std::atoi(date.substr(5,2).c_str());
	int day = std::atoi(date.substr(8,2).c_str());

	if (month < 1 || month > 12)
		return false;
	bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	int daysinMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if(month == 2 && isLeap)
		daysinMonth[2] = 29;
	if( day < 1 || day > daysinMonth[month])
		return false;
	return true;
}

bool BitcoinExchange::validate_date(const std::string &date)
{
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	if(!validate_date_calendar(date))
		return false;
	return true;
}
bool BitcoinExchange::validate_value(const std::string &valueStr, float &value)
{
	char *endPtr = NULL;
	double val = std::strtod(valueStr.c_str(),&endPtr);
	
	if(endPtr == valueStr.c_str() || *endPtr != '\0')
	{
		std::cout << "Error: bad input => "<< valueStr << std::endl;
		return false;
	}
	if(val < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return false;
	}
	if(val > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return false;
	}
	value = static_cast<float>(val);
	return true;
}
float BitcoinExchange::look_map(const std::string &date)
{
	std::map<std::string, float>::const_iterator it = this->_data.find(date);
	if(it != this->_data.end())
		return it->second;
	it = this->_data.upper_bound(date);

	if(it  == _data.begin())
		return it->second;
	--it;
	return it->second;
}


void BitcoinExchange::LoadDatabase(const std::string &dbPath)
{
	std::ifstream file(dbPath.c_str()); // abrir archivo
	if(!file.is_open())
		throw BitcoinExchange::OutfileException();
	std::string line;

	std::getline(file,line);

	while(std::getline(file,line))
	{
		size_t index = line.find(',');
		if(index == std::string::npos)
			continue;
		std::string date = line.substr(0,index);
		std::string rate = line.substr(index + 1);
		this->_data[date] = std::atof(rate.c_str());
	}
	file.close();
}

void BitcoinExchange::ProcessInput(const std::string &inputPath)
{
	std::ifstream file(inputPath.c_str());
	if(!file.is_open())
		throw BitcoinExchange::OutfileException();
	std::string line;
	std::getline(file,line);
	while(std::getline(file,line))
	{
		size_t sep = line.find(" | ");
		if(sep == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		std::string date = line.substr(0,sep);
		if(!validate_date(date))
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		std::string valueStr = line.substr(sep + 3);
		float value = 0.0f;
		if(!validate_value(valueStr, value))
		{
			continue;
		}
		float rate = look_map(date);
		std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
	}
	file.close();
}