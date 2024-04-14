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
		ConvertedValues values = ScalarConverter::convert(argv[1]);
		ScalarConverter::print(values);
	}
}
