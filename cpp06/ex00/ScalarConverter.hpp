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
	bool isNan;
	bool isInf;
	bool isInff;
	bool hasDecimalPoint;
	bool has2DecimalPoint;
};

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

std::string isValidScientificNotation(std::string& str);
bool isNumber(std::string& str);

#endif
