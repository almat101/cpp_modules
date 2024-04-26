#ifndef iter_hpp
#define iter_hpp

#include <iostream>

template<typename T>
void print(T & element)
{
	std::cout << element << std::endl;
}

template<typename T>
void iter(T *arr, size_t len, void(*func)(T&))
{
	for (size_t i = 0; i < len; i++)
		func(arr[i]);
}

template<typename T>
void increment(T & i)
{
	++i;
}

void reverseCase(char& c)
{
	if (isupper(c))
		c = static_cast<char>(tolower(c));
	else
		c = static_cast<char>(toupper(c));
}

void appendString(std::string& s)
{
	if (s.empty())
		throw std::invalid_argument("Empty string");
	else
		s += "O<_>O";
}


#endif
