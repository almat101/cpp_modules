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
		std::string str = argv[1];
		ConvertedValues values = ScalarConverter::convert(str);
		ScalarConverter::print(values);
	}
}
