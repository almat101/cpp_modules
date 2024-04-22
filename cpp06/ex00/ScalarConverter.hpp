#ifndef ScalarConverter_hpp
#define ScalarConverter_hpp

#include <iostream>
#include <sstream>
#include <iomanip>
#include <limits>
#include <cmath>
#include "Utils.hpp"

class ScalarConverter
{
	private:
		ScalarConverter();

	public:
		~ScalarConverter();
		ScalarConverter(ScalarConverter &src);
		ScalarConverter & operator=(ScalarConverter & rhs);
		static ConvertedValues convert(std::string& str);
		static void print(ConvertedValues& values);
};

#endif
