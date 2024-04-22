#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}


ScalarConverter::ScalarConverter(ScalarConverter &src)
{
	(void)src;
}

ScalarConverter & ScalarConverter::operator=(ScalarConverter &rhs)
{
	(void)rhs;
	return *this;
}

ConvertedValues ScalarConverter::convert(std::string& str)
{
	ConvertedValues values;

	//init bool values
	init_bool_value(values);
	if (init_special_values(values, str))
		return values;
	if (str_has_2_decimal_point(str, values))
		return values;
	// Check if the string is a valid scientific notation
	str = isValidScientificNotation(str);
	// Check if the string is a valid number (it can be a float or an int)
	if (str_is_int_float_double(str, values))
		return values;
	if (str_is_float(str, values))
		return values;
	if (str_is_int(str, values))
		return values;
	return values;
}

void ScalarConverter::print(ConvertedValues& values)
{
	//for string like hello
	if (values.isStringLike)
	{
		std::cout << "Error: impossible conversion" << std::endl;
		return ;
	}
	//for 2 decimal point error
	if (values.has2DecimalPoint)
	{
		std::cout << "Error: impossible conversion" << std::endl;
		return ;
	}

	//for inf
	if (values.isInf)
	{
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << values.f << "f" << std::endl;
		std::cout << "double: " << values.d << std::endl;
		return ;
	}
	//for inff
	if (values.isInff)
		{
			std::cout << "char: " << "impossible" << std::endl;
			std::cout << "int: " << "impossible" << std::endl;
			std::cout << "float: inff" << std::endl;
			std::cout << "double: " << values.d << std::endl;
			return ;
		}
	//for nan
	if (values.isNan)
	{
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << values.f << std::endl;
		std::cout << "double: " << values.d << std::endl;
		return ;
	}
	//for int float double and overflow
	if (values.isNotDisplayable)
	{
		std::cout << "char: " << "Not Displayable" << std::endl;
		if (values.isInt == false || values.i == -2147483648)
			std::cout << "int: " << "overflow" << std::endl;
		else
			std::cout << "int: " << values.i << std::endl;

		if (std::isinf(values.f))
			std::cout << "float: overflow" << std::endl;
		else
		{
			std::cout << std::scientific << std::setprecision(1);
			std::cout << "float: " << values.f << "f" << std::endl;
		}
		if (std::isinf(values.d))
				std::cout << "double: overflow" << std::endl;
		else
			std::cout << "double: " << values.d << std::endl;
		return ;
	}
	// for char
	std::cout << "char: " << "'" << values.c << "'" << std::endl;
	std::cout << "int: " << values.i << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << values.f << "f" << std::endl;
	std::cout << "double: " << values.d << std::endl;
}
