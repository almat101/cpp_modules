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

const char* ScalarConverter::ImpossibleConversionException::what() const throw()
{
	return "Error: impossible conversion";
}
ConvertedValues ScalarConverter::convert(std::string& str)
{
	ConvertedValues values;

	//init bool values
	values.isChar = true;
	values.isInt = true;
	values.isFloat = true;
	values.isDouble = true;
	values.isNotDisplayable = false;
	values.isStringLike = false;
	values.isNan = false;
	values.isInf = false;

	if (str == "+inf" || str == "-inf" || str == "inf")
	{
		// values.isChar = false;
		// values.isInt= false;
		values.isInf = true;
		values.f = std::numeric_limits<float>::infinity();
		values.d = std::numeric_limits<double>::infinity();
		return values;
	}
	if (str == "nan" || str == "nanf")
	{
		values.isNan =	true;
		values.f = std::numeric_limits<float>::quiet_NaN();
		values.d = std::numeric_limits<double>::quiet_NaN();
		return values;
	}
	bool hasDecimalPoint = false;
	for (size_t i = 0; i < str.length(); ++i)
	{
		if (str[i] == '.')
		{
			if (hasDecimalPoint) // More than one decimal point means it's not a valid number
			{
				std::cout << "str has more than one decimal point" << std::endl;
				values.c = '\0';
				values.isNotDisplayable = true;
				values.isInt = false;
				values.f = std::numeric_limits<float>::quiet_NaN();
				values.d = std::numeric_limits<double>::quiet_NaN();
				return values;
			}
			hasDecimalPoint = true;
		}
	}
	// Check if the string is a valid scientific notation
	str = isValidScientificNotation(str);
	// Check if the string is a valid number (it can be a float or an int)
	if (str.size() > 1 && !isNumber(str))
	{
		//std::cout << str  << " str is not a valid number" << std::endl;
		values.isStringLike = true;
		values.isNotDisplayable = true;
		values.isChar = false;
		values.isInt = false;
		values.isFloat = false;
		values.isDouble = false;
		values.c = '\0';
		values.i = 0;
		values.f = 0.0f;
		values.d = 0.0;
		return values;
	}
	// Check if the string is a float
	if (hasDecimalPoint)
	{
		//std::cout << str  << " str is a float" << std::endl;
		double val;
		std::istringstream iss(str);
		iss >> val;

		if (iss.fail())
		{
			std::cerr << "Error: double overflow or underflow" << std::endl;
			throw ImpossibleConversionException();
		}
		else
		{
			values.d = val;
			values.f = static_cast<float>(val);

			//  check for overflow or underflow of float if u want to throw exception when float is - or + inf or not

			// if (values.f == std::numeric_limits<float>::infinity() || values.f == -std::numeric_limits<float>::infinity())
			// {
			// 	std::cerr << "Error: float overflow or underflow" << std::endl;
			// 	throw ImpossibleConversionException();
			// }
			// else
			// {
				float rounded = round(values.f);

				// check int overflow or underflow
				if (rounded < std::numeric_limits<int>::min() || rounded >std::numeric_limits<int>::max())
				{
					std::cerr << "Error: int overflow or underflow" << std::endl;
					throw ImpossibleConversionException();
				}
				//std::cout << "rounded: " << rounded << std::endl;
				int roundedInt = static_cast<int>(rounded);
				values.i = roundedInt;
				if (rounded >= 32 && rounded <= 126)
				{
					values.c = static_cast<char>(rounded);
					values.isNotDisplayable = false;
				}
				else
				{
					values.c = '\0'; // or any other special value
					values.isNotDisplayable = true;
				}
			// }
		}
		return values;
	}
	else
	{
		//std::cout << str  << " str has no decimal point" << std::endl;
		//The string is an int
		if(str.length() == 1 && str[0] >= '0' && str[0] <= '9')
		{
			//std::cout << "str is a number between 0 - 9" << std::endl;
			values.c = '\0'; // or any other special value
			values.isNotDisplayable = true;
			values.i = str[0] - '0';
			values.f = str[0] - '0';
			values.d = str[0] - '0';
			return values;
		}
		else if(str.length() == 1)
		{
			//std::cout << "str is a char" << std::endl;
			values.c = str[0];
			values.i = str[0];
			values.f = str[0];
			values.d = str[0];
			values.isNotDisplayable = (values.i < 32 || values.i > 126);
			return values;
		}
		else if(str.length() > 1)
		{
			//std::cout << "str is a number" << std::endl;
			std::istringstream iss(str);
			double asciiValue;
			iss >> asciiValue;
			if (asciiValue > std::numeric_limits<int>::max() || asciiValue < std::numeric_limits<int>::min())
			{
				std::cerr << "Error: int overflow or underflow" << std::endl;
				throw ImpossibleConversionException();
			}
			//std::cout << "asciiValue: " << asciiValue << std::endl;
			values.i = static_cast<int>(asciiValue);
			if(asciiValue >= 0 && asciiValue <= 127 )
			{
				if (asciiValue > std::numeric_limits<char>::max() || asciiValue < std::numeric_limits<char>::min())
				{
					std::cerr << "Error: char overflow or underflow" << std::endl;
					throw ImpossibleConversionException();
				}
				else
				{
					values.c = static_cast<char>(asciiValue);
				}
				if (asciiValue > std::numeric_limits<float>::max() || asciiValue < std::numeric_limits<float>::min())
				{
					std::cerr << "Error: float overflow or underflow" << std::endl;
					throw ImpossibleConversionException();
				}
				else
				{
					values.f = static_cast<float>(asciiValue);
				}
				//std::cout << "asciiValue.d: " << asciiValue << std::endl;
				values.d = static_cast<double>(asciiValue);
				values.isNotDisplayable = (asciiValue < 32 || asciiValue > 126);
				return values;
			}
			else
			{
				//std::cout << "not displayable" << std::endl;
				values.isNotDisplayable = true;
			}
		}
	}
	std::stringstream ss1(str);
	ss1 >> values.c;


	// std::stringstream ss2(str);
	// ss2 >> values.i;

	std::stringstream ss3(str);
	ss3 >> values.f;

	std::stringstream ss4(str);
	ss4 >> values.d;

	return values;
}

void ScalarConverter::print(ConvertedValues& values)
{
	//for string like hello
	if (values.isStringLike)
	{
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << "impossible" << std::endl;
		std::cout << "double: " << "impossible"<< std::endl;
		return ;
	}
	//for inf
	if (values.isInf)
	{
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << values.f << std::endl;
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
	// for int float and double
	if (values.isNotDisplayable)
	{
		std::cout << "char: " << "Not Displayable" << std::endl;
		std::cout << "int: " << values.i << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: " << values.f << "f" << std::endl;
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

std::string isValidScientificNotation(std::string& str)
{
	std::string modifiedStr = str;

	if (!modifiedStr.empty() && (modifiedStr.at(modifiedStr.size() - 1) == 'e' || modifiedStr.at(modifiedStr.size() - 1) == 'E'))
	{
		throw std::invalid_argument("Error: Invalid argument");
		//modifiedStr += '0'; // this could be ok but is better to throw an exception because in c++ a number like 1.8e is not a valid scientific notation number
	}

	return modifiedStr;
}

bool isNumber(std::string& str)
{
	bool hasDecimalPoint = false;
	bool hasF = false;
	bool hasE = false;
	bool hasSign = false;
	for (std::string::const_iterator it = str.begin(); it != str.end(); ++it)
	{
		if (it == str.begin() && (*it == '+' || *it == '-'))
			continue;
		if (*it == '.')
		{
			if (hasDecimalPoint)
				return false;
			hasDecimalPoint = true;
		}
		else if (*it == 'f')
		{
			if (hasF)
				return false;
			hasF = true;
		}
		else if (*it == 'e' || *it == 'E')
		{
			if (hasE)
				return false;
			hasE = true;
		}
		else if (*it == '+' || *it == '-')
		{
			if (hasSign)
				return false;
			hasSign = true;
		}
		else if (!std::isdigit(*it))
			return false;
	}
	return true;
}
