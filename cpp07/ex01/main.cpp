#include "iter.hpp"
#include <iostream>

int main(void)
{
	size_t len = 6;
	int arr[] = {42,9,0,21,13,39};
	iter(arr , len , print);

	float arr3[] = {42.3f,9.4f,0.3f,21.1f,13.2f,39.04f};
	iter(arr3 , len , print);

	char arr1[] = {'C','I','A','o','n','e'};
	iter(arr1, len, print);


	std::string arr2[] = {"Hello","lol","asd","HELL","kek","kkk"};
	iter(arr2, len, print);

	std::cout << std::endl;
	std::cout << "Other operation on arrays: " << std::endl;
	iter(arr , len , increment);
	for (size_t i = 0; i < len; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;

	iter(arr1, len, reverseCase);
	for (size_t i = 0; i < len; i++)
		std::cout << arr1[i] << " ";
	std::cout << std::endl;

	try
	{
		std::string arr4[] = {"eeee" , " " , "" ,"lol","mma","|||"};
		iter(arr4, len, appendString);

	}
	catch(const std::invalid_argument& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::string arr5[] = {"ggg", "iii", "ooo", "vvv" ,"aaa" , "nna"};
		iter(arr5, len, appendString);
		for (size_t i = 0; i < len; i++)
			std::cout << arr5[i] << " ";
		std::cout << std::endl;
	}
	catch(const std::invalid_argument& e)
	{
		std::cerr << e.what() << '\n';
	}






	return 0;
}
