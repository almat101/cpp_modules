#include "ScalarConverter.hpp"



int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: Invalid number of arguments" << std::endl;
		return 1;
	}
	else
	{
		try
		{
			std::string str = argv[1];
			ConvertedValues values = ScalarConverter::convert(str);
			ScalarConverter::print(values);
		}
		catch (std::exception &e)
		{
			std::cerr << "Error: Invalid argument" << std::endl;
			return 1;
		}
	}
}
