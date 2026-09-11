#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <iostream>
#include <string>
#include <fstream>

class  BitcoinExchange
{
	private:
		std::map<std::string,float> _data;
		bool validate_date(const std::string &date);
		bool validate_date_calendar(const std::string &date);
		bool validate_format(const std::string &line);
		float look_map(const std::string &date);
	public:
		BitcoinExchange();
		~ BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);

		void LoadDatabase(const std::string &dbPath);
		void ProcessInput(const std::string &inputPath);

		class OutfileException : public std::exception {
			public:
				virtual const char * what() const throw()
				{
					return "Error: could not open database file";
				}
		};
};


#endif