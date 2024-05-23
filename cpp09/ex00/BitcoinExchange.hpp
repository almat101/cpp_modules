#ifndef BitcoinExchange_hpp
#define BitcoinExchange_hpp

#include <iostream>
#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
class BitcoinExchange
{
	private:
		std::multimap<std::string, float> _btc_values; // first multimap that contain the values of the data.csv
		std::multimap<std::string, float> _input_value; // second multimap that contain the values of the input.txt


	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);
		BitcoinExchange & operator=(const BitcoinExchange &rhs);
		void readInputValues(std::string input_file);
		void readValues();
		void computeValues();
		void printmultimaps();

};

#endif
