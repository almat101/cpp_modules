#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}


ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	(void)src;
}

ScalarConverter & ScalarConverter::operator=(const ScalarConverter &rhs)
{
	(void)rhs;
	return *this;
}

ConvertedValues ScalarConverter::convert(const std::string& str)
{
	ConvertedValues values;
	values.isChar = true;
	values.isInt = true;
	values.isFloat = true;
	values.isDouble = true;
	values.isNotDisplayable = false;
	values.isStringLike = false;


	if (str == "+inf" || str == "-inf" || str == "inf")
	{
		values.isChar = false;
		values.isInt= false;
		values.f = std::numeric_limits<float>::infinity();
		values.d = std::numeric_limits<double>::infinity();
		return values;
	}
	if (str == "nan" || str == "nanf")
	{
		values.isChar = false;
		values.isInt= false;
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
				values.c = '\0'; // or any other special value
				values.isNotDisplayable = true;
				values.isInt = false;
				values.f = std::numeric_limits<float>::quiet_NaN(); // or any other special value
				values.d = std::numeric_limits<double>::quiet_NaN(); // or any other special value
				return values;
			}
			hasDecimalPoint = true;
		}
	}


	if (str.size() > 1 && !isNumber(str))
	{
		std::cout << str  << " str is not a valid number" << std::endl;
		values.isStringLike = true;
		values.isNotDisplayable = true;
		values.isChar = false;
		values.isInt = false;
		values.isFloat = false;
		values.isDouble = false;
		values.c = '\0'; // or any other special value
		values.i = 0; // or any other special value
		values.f = 0.0f; // or any other special value
		values.d = 0.0; // or any other special value
		return values;
	}


	if (hasDecimalPoint)// && str[str.size() - 1] == 'f')
	{
		std::cout << str  << " str is a float" << std::endl;
		std::istringstream iss(str);
		iss >> values.f;
		values.i = static_cast<int>(values.f);
		values.d = static_cast<double>(values.f);
		if (values.i >= 32 && values.i <= 126)
		{
			values.c = static_cast<char>(values.i);
			values.isNotDisplayable = false;
		}
		else
		{
			values.c = '\0'; // or any other special value
			values.isNotDisplayable = true;
		}
		return values;
	}
	// else if (hasDecimalPoint)
	// {
	// 	std::cout << str  << " str has decimal point" << std::endl;
	// 	std::istringstream iss(str);
	// 	iss >> values.d;
	// 	values.i = static_cast<int>(values.d);
	// 	values.f = static_cast<float>(values.d);
	// 	if (values.i >= 32 && values.i <= 126)
	// 	{
	// 		values.c = static_cast<char>(values.i);
	// 		values.isNotDisplayable = false;
	// 	}
	// 	else
	// 	{
	// 		values.c = '\0'; // or any other special value
	// 		values.isNotDisplayable = true;
	// 	}
	// 	return values;
	// }
	else
	{
		std::cout << str  << " str has no decimal point" << std::endl;
		// The string is an int
		// Add code to handle this case
		if(str.length() == 1 && str[0] >= '0' && str[0] <= '9')
		{
			std::cout << "str is a number between 0 - 9" << std::endl;
			values.c = '\0'; // or any other special value
			values.isNotDisplayable = true;
			values.i = static_cast<int>(str[0] - 48);
			values.f = static_cast<float>(str[0] - 48);
			values.d = static_cast<double>(str[0] - 48);
			return values;
		}
		else if(str.length() == 1)
		{
			std::cout << "str is a char" << std::endl;
			values.c = str[0];
			values.i = static_cast<int>(str[0]);
			values.f = static_cast<float>(str[0]);
			values.d = static_cast<double>(str[0]);
			values.isNotDisplayable = (values.i < 32 || values.i > 126);
			return values;
		}
		else if(str.length() > 1)
		{
			std::cout << "str is a number" << std::endl;
			const char* cstr = str.c_str();
			int asciiValue = atoi(cstr);
			if(asciiValue >= 0 && asciiValue <= 127 )
			{
				values.c = static_cast<char>(asciiValue);
				values.i = asciiValue;
				values.f = static_cast<float>(asciiValue);
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


	std::stringstream ss2(str);
	ss2 >> values.i;

	std::stringstream ss3(str);
	ss3 >> values.f;

	std::stringstream ss4(str);
	ss4 >> values.d;

	return values;
}

void ScalarConverter::print(const ConvertedValues& values)
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
	//for nan and inf
	if (values.isChar == false && values.isInt == false )//&& values.isFloat == false && values.isDouble == false)
	{
		std::cout << "char: " << "impossible" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << values.f << std::endl;
		std::cout << "double: " << values.d << std::endl;
		return ;
	}
	// for float like 3..14f
	if (values.isInt == false && values.isNotDisplayable == true)
	{
		std::cout << "char: " << "Not displayable" << std::endl;
		std::cout << "int: " << "impossible" << std::endl;
		std::cout << "float: " << "impossible"<< std::endl;
		std::cout << "double: " << "impossible" << std::endl;
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
	std::cout << "char like a" << std::endl;
	std::cout << "char: " << "'" << values.c << "'" << std::endl;
	std::cout << "int: " << values.i << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << values.f << "f" << std::endl;
	std::cout << "double: " << values.d << std::endl;
}

bool isNumber(const std::string& str)
{
	bool hasDecimalPoint = false;
	bool hasF = false;
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
		else if (!std::isdigit(*it))
			return false;
	}
	return true;
}
