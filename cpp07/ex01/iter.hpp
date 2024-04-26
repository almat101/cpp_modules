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

void upperCase(char& i)
{
	i = toupper(i);
}

void appendString(std::string& s)
{
	s += " world!";
}


#endif
