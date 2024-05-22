#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{

	if (ac != 2)
	{
		std::cout << "Usage: ./bitcoin [input.txt]" << std::endl;
		return 1;
	}
	else
	{
		std::string input_file = av[1];
		BitcoinExchange btc;
		//read data.csv
		btc.readValues();
		//read input_file
		btc.readInputValues(input_file);
		//compute the values
		btc.computeValues();
	}

	return 0;
}
