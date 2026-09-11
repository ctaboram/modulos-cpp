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

const char* BitcoinExchange::OutfileException::what() const throw ()
{
	return "Error open file";
}

void LoadDatabase(const std::string &dbPath)
{
	std::ifstream file(dbPath.c_str()); // abrir archivo
	if(!file.is_open())
		throw BitcoinExchange::OutfileException();
	std::string line;

	std::getline(file,line);

	while(std::getline(file,line))
	{
		
	}
	file.close();
}

