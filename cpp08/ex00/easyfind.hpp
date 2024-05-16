#ifndef easyfind_hpp
#define easyfind_hpp

#include <iostream>
#include <algorithm>

template<typename T>
bool easyfind(T& container, int target)
{
	return std::find(container.begin(), container.end(), target) != container.end();
}

#endif

