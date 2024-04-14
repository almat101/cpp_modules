#ifndef ScalarConverter_hpp
#define ScalarConverter_hpp

#include <iostream>
#include <sstream>
#include <iomanip>
#include <limits>
#include <cmath>

struct ConvertedValues
{
	char c;
	int i;
	float f;
	double d;
	bool isChar;
	bool isInt;
	bool isFloat;
	bool isDouble;
	bool isNotDisplayable;
	bool isStringLike;
};

class ScalarConverter
{
	private:
		ScalarConverter();

	public:
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
		ScalarConverter & operator=(const ScalarConverter & rhs);
		static ConvertedValues convert(const std::string& str);
		static void print(const ConvertedValues& values);
};

bool isNumber(const std::string& str);

#endif
