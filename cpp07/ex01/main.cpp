#include "iter.hpp"
#include <iostream>

int main(void)
{
	size_t len = 6;
	int arr[] = {42,9,0,21,13,39};
	iter(arr , len , print<int>);

	float arr3[] = {42.3f,9.4f,0.3f,21.1f,13.2f,39.04f};
	iter(arr3 , len , print<float>);

	char arr1[] = {'c','i','a','o','n','e'};
	iter(arr1, len, print<char>);

	std::string arr2[] = {"Hello","lol","lmao","HELL","kek","kkk"};
	iter(arr2, len, print<std::string>);

	std::cout << std::endl;
	std::cout << "Other operation on arrays: " << std::endl;
	iter(arr , len , increment);
	for (size_t i = 0; i < len; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;

	iter(arr1, len, upperCase);
	for (size_t i = 0; i < len; i++)
		std::cout << arr1[i] << " ";
	std::cout << std::endl;

	iter(arr2, len, appendString);
	for (size_t i = 0; i < len; i++)
		std::cout << arr2[i] << " ";
	std::cout << std::endl;




	return 0;
}
