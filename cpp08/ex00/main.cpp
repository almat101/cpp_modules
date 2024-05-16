#include <list>
#include "easyfind.hpp"
#include <iostream>

int main (void)
{
	std::list<int> integer;

	integer.push_back(1);
	integer.push_back(42);
	integer.push_back(3);
	integer.reverse();
	integer.push_front(17);


	for(std::list<int>::iterator it = integer.begin(); it != integer.end(); it++)
		std::cout << *it << " ";

	std::cout << std::endl;
	if (easyfind(integer, 42))
		std::cout << "42 is in the list" << std::endl;
	else
		std::cout << "42 is not in the list" << std::endl;
	if (easyfind(integer, 43))
		std::cout << "43 is in the list" << std::endl;
	else
		std::cout << "43 is not in the list" << std::endl;
	return 0;
}
