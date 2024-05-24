#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	// std::cout << "Default constuctor\n";
}

BitcoinExchange::~BitcoinExchange()
{
	// std::cout << "Default destuctor\n";
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	*this = src;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
	if (this != &rhs)
	{
		this->_btc_values = rhs._btc_values;
		this->_input_values = rhs._input_values;
	}
	return *this;
}


	void BitcoinExchange::readValues()
	{
		std::ifstream file("data.csv");
		std::string line;

		//skip the first line
		std::getline(file, line);

		while (std::getline(file, line))
		{
			std::istringstream iss(line);
			std::string key;
			float value;

			std::getline(iss, key, ',');
			iss >> value;

			//insert the values in the multimap _btc_values
			_btc_values.insert(std::make_pair(key, value));
		}
	}

void BitcoinExchange::readInputValues(std::string input_file)
{
	std::ifstream file(input_file.c_str());
	std::string line;

	if (!file.is_open())
	{
    	std::cerr << "Failed to open file" << std::endl;
    	return;
	}
	if (file.peek() == std::ifstream::traits_type::eof())
	{
		std::cerr << "The file is empty" << std::endl;

	}
	//skip the first line
	std::getline(file, line);

	while (std::getline(file, line))
	{
		std::istringstream iss(line);
		std::string key;
		float value;

		std::getline(iss, key, '|');
		if (key.empty())
		{
			std::cerr << "Error: empty key." << std::endl;
			continue ;
		}

		 // Date validation starts here
		std::string year_str, month_str, day_str;
		std::istringstream date_iss(key);
		std::getline(date_iss, year_str, '-');
		std::getline(date_iss, month_str, '-');
		std::getline(date_iss, day_str, '-');

		if (year_str.empty() || month_str.empty() || day_str.empty() || date_iss.get() != EOF) {
			std::cerr << "Error: date is not in the correct format." << std::endl;
			continue;
		}

		std::istringstream year_iss(year_str), month_iss(month_str), day_iss(day_str);
		int year, month, day;
		if (!(year_iss >> year) || !(month_iss >> month) || !(day_iss >> day)) {
			std::cerr << "Error: date is not a valid number. =>" << year << month << day << std::endl;
			continue;
		}

		if (year < 1900 || year > 2100 || month < 1 || month > 12 || day < 1 || day > 31) {
			std::cerr << "Error: bad input => " << year << "-" << month << "-" << day << std::endl;
			continue;
		}
		// Date validation ends here

		// No '|' was found in the line
		if (iss.eof())
		{
			std::cerr << "Error: no value found." << std::endl;
			continue ;
		}
		else
			iss >> value;
		//check for invalid values like possible strings in the value field
		if (iss.fail() || iss.peek() != EOF)
		{
			std::cerr << "Error: not a valid number." << std::endl;
			continue;
		}
		if (value < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue ;
		}
		if (value >= 1000 )
		{
			std::cerr << "Error: too large number." << std::endl;
			continue ;
		}

		//insert the values in the multimap _input_values
		_input_values.insert(std::make_pair(key, value));
	}


}

std::string trim(const std::string& str)
{
	size_t first = str.find_first_not_of(' ');
	if (std::string::npos == first)
	{
		return str;
	}
	size_t last = str.find_last_not_of(' ');
	return str.substr(first, (last - first + 1));
}
void BitcoinExchange::computeValues()
{
	for (std::multimap<std::string, float>::reverse_iterator it = _input_values.rbegin(); it != _input_values.rend(); ++it)
	{
		std::string key1 = trim(it->first);

		for (std::multimap<std::string, float>::reverse_iterator it2 = _btc_values.rbegin(); it2 != _btc_values.rend(); ++it2)
		{
			std::string key2 = trim(it2->first);

			if (key1.empty() || key2.empty())
				continue ;

			if (key1.compare(key2) >= 0)
			{
				float result = it->second * it2->second;
				std::cout << key1 << " => " << result << std::endl;
				break;
			}

		}
	}
}

void BitcoinExchange::printmultimaps()
{
	std::cout << "Printing _btc_values" << std::endl;
	for (std::multimap<std::string, float>::iterator it = _btc_values.begin(); it != _btc_values.end(); ++it)
	{
		std::cout << it->first << " " << it->second << std::endl;
	}

	std::cout << "Printing _input_values" << std::endl;
	for (std::multimap<std::string, float>::iterator it = _input_values.begin(); it != _input_values.end(); ++it)
	{
		std::cout << it->first << " " << it->second << std::endl;
	}
}
