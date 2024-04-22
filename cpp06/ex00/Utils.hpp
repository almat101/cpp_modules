#ifndef UTILS_HPP
#define UTILS_HPP

#include "ScalarConverter.hpp"

// moved from ScalarConverter.cpp to Utils.cpp to avoid compiler error
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

void init_bool_value(ConvertedValues& values);
bool init_special_values(ConvertedValues& values, const std::string& str);
bool str_has_2_decimal_point(const std::string &str, ConvertedValues &values);
bool str_is_int_float_double(std::string &str, ConvertedValues &values);
bool str_is_float(std::string &str, ConvertedValues &values);
bool str_is_int(std::string &str, ConvertedValues &values);
std::string isValidScientificNotation(std::string& str);
bool isNumber(std::string& str);


#endif
