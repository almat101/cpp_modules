#include "ScalarConverter.hpp"

void init_bool_value(ConvertedValues& values)
{
	values.isChar = true;
	values.isInt = true;
	values.isFloat = true;
	values.isDouble = true;
	values.isNotDisplayable = false;
	values.isStringLike = false;
	values.isNan = false;
	values.isInf = false;
	values.isInff = false;
	values.hasDecimalPoint = false;
	values.has2DecimalPoint = false;
	values.c = '\0';
	values.i = 0;
	values.f = 0.0f;
	values.d = 0.0;
}

bool init_special_values(ConvertedValues& values, const std::string& str)
{
	if (str == "+inf" || str == "-inf" || str == "inf")
	{
		values.isInf = true;
		values.f = std::numeric_limits<float>::infinity();
		values.d = std::numeric_limits<double>::infinity();
		return true;
	}
	else if (str == "+inff" || str == "-inff" || str == "inff")
	{
		values.isInff = true;
		values.f = std::numeric_limits<float>::infinity();
		values.d = std::numeric_limits<double>::infinity();
		return true;
	}
	else if (str == "nan" || str == "nanf")
	{
		values.isNan = true;
		values.f = std::numeric_limits<float>::quiet_NaN();
		values.d = std::numeric_limits<double>::quiet_NaN();
		return true;
	}
	return false;
}

bool str_has_2_decimal_point(const std::string &str, ConvertedValues &values)
{
	for (size_t i = 0; i < str.length(); ++i)
	{
		if (str[i] == '.')
		{
			if (values.hasDecimalPoint) // More than one decimal point means it's not a valid number
			{
				//std::cout << "str has more than one decimal point" << std::endl;
				values.has2DecimalPoint = true;
				values.c = '\0';
				values.i = -2147483648;
				values.f = std::numeric_limits<float>::quiet_NaN();
				values.d = std::numeric_limits<double>::quiet_NaN();
				return true;
			}
			values.hasDecimalPoint = true;
		}
	}
	return false;
}

bool str_is_int_float_double(std::string& str, ConvertedValues& values)
{
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
		return true;
	}
	return false;
}

bool str_is_float(std::string& str, ConvertedValues& values)
{
	if (values.hasDecimalPoint)
	{
		//std::cout << str  << " str is a float" << std::endl;
		std::istringstream iss(str);
		iss >> values.d;

		if (iss.fail())
		{
			values.isDouble = false;
			values.isInt = false;
			values.isNotDisplayable = true;
			values.i = 0;
			values.f = std::numeric_limits<float>::infinity();
			values.d = std::numeric_limits<double>::infinity();
			values.c = '\0';
			std::cerr << "Error: double overflow or underflow" << std::endl;
			return true;
		}

		iss.clear();
		iss.seekg(0);
		iss >> values.f;
		if (iss.fail())
		{
			values.isFloat = false;
			values.isInt = false;
			values.isNotDisplayable = true;
			values.f = std::numeric_limits<float>::infinity();
			values.i = 0;
			values.c = '\0';
			std::cerr << "Error: float overflow or underflow" << std::endl;
			return true;
		}

		values.isFloat = true;

		iss.clear();
		iss.seekg(0);
		double temp;
		iss >> temp;
		if (iss.fail() || temp < -2147483648 || temp > 2147483647)
		{;
			values.isInt = false;
			values.isNotDisplayable = true;
			values.i = 0;
			values.c = '\0';
			std::cerr << "Error: int overflow or underflow" << std::endl;
			return true;
		}
		values.i = static_cast<int>(temp);

		if (values.i >= 32 && values.i <= 126)
		{
			values.c = static_cast<char>(values.i);
			values.isNotDisplayable = false;
		}
		else
		{
			values.c = '\0';
			values.isNotDisplayable = true;
		}
		return true;
	}
	return false;
}


bool str_is_int(std::string& str, ConvertedValues& values)
{
	//std::cout << str  << " str is an int" << std::endl;
	//The string is an int
	if(str.length() == 1 && str[0] >= '0' && str[0] <= '9')
	{
		//std::cout << "str is a number between 0 - 9" << std::endl;
		values.c = '\0';
		values.isNotDisplayable = true;
		values.i = str[0] - '0';
		values.f = str[0] - '0';
		values.d = str[0] - '0';
		return true;
	}
	else if(str.length() == 1)
	{
		//std::cout << "str is a char" << std::endl;
		values.c = str[0];
		values.i = str[0];
		values.f = str[0];
		values.d = str[0];
		values.isNotDisplayable = (values.i < 32 || values.i > 126);
		return true;
	}
	else if(str.length() > 1)
	{
		std::istringstream iss(str);
		double asciiValue;
		iss >> asciiValue;
		if (iss.fail())
		{
			values.isDouble = false;
			values.isInt = false;
			values.isNotDisplayable = true;
			values.i = 0;
			values.f = std::numeric_limits<float>::infinity();
			values.d = std::numeric_limits<double>::infinity();
			values.c = '\0';
			std::cerr << "Error: double overflow or underflow" << std::endl;
			return true;
		}
		values.d = asciiValue;

		iss.clear();
		iss.str(str);
		int iValue;
		iss >> iValue;
		if (iss.fail() || iValue > std::numeric_limits<int>::max() || iValue < std::numeric_limits<int>::min())
		{
			values.isInt = false;
			values.isNotDisplayable = true;
			values.i = 0;
			values.isInt = false;
			std::cout << "Error: int overflow or underflow" << std::endl;
		}
		else
		{
			values.i = iValue;
		}
		values.i = static_cast<int>(asciiValue);
		if(asciiValue >= 0 && asciiValue <= 127 )
		{
			if (asciiValue > std::numeric_limits<char>::max() || asciiValue < std::numeric_limits<char>::min())
			{
				std::cerr << "Error: char overflow or underflow" << std::endl;
			}
			else
			{
				values.c = static_cast<char>(asciiValue);
			}
		}

		iss.clear();
		iss.str(str);
		float fValue;
		iss >> fValue;
		if (iss.fail() || fValue > std::numeric_limits<float>::max() || fValue < -std::numeric_limits<float>::max())
		{
			values.isFloat = false;
			values.isNotDisplayable = true;
			values.f = std::numeric_limits<float>::infinity();
			values.i = -2147483648;
			std::cerr << "Error: float overflow or underflow" << std::endl;
		}
		else
		{
			values.isFloat = true;
			values.f = fValue;
		}
		values.isNotDisplayable = (values.i < 32 || values.i > 126);
		return true;
	}
	return false;
}

std::string isValidScientificNotation(std::string& str)
{
	std::string modifiedStr = str;

	if (!modifiedStr.empty() && (modifiedStr.at(modifiedStr.size() - 1) == 'e' || modifiedStr.at(modifiedStr.size() - 1) == 'E'))
	{
		modifiedStr += '0'; // Add a zero to the end of the string to make it a valid number
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
		else if (*it == 'f' || *it == 'F')
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
