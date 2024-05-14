#include "Array.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>


int main(void)
{

	// static int array[5]; // try to remove static and use valgrind to see the difference

	// for(int i = 0; i < 5; i++)
	// {
	// 	std::cout << array[i] << std::endl;
	// }


	Array<unsigned int> intArray(5);
	try
	{
		intArray[1] = 42;
		for (int i = 0; i < intArray.getSize(); i++) {
			std::cout << intArray[i] << " ";
		}
		std::cout << std::endl;

	} catch (const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try {
		unsigned int value = intArray[10];
		std::cout << "Value at index 10: " << value << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	Array<double> doubleArray(5);

	doubleArray[0] = 3.14;
	doubleArray[2] = 2.7;
	doubleArray[4] = 42.42;

	for (int i = 0; i < doubleArray.getSize(); i++) {
		std::cout << doubleArray[i] << " ";
	}
	std::cout << std::endl;

	Array<char> charArray(3);

	// charArray[0] = 'A';
	charArray[1] = 'B'; //now works other char are initialized to 0
	// charArray[2] = 'C';
	for (int i = 0; i < charArray.getSize(); i++) {
		std::cout << charArray[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}



// #define MAX_VAL 750
// int main(int, char**)
// {
// 	Array<int> numbers(MAX_VAL);
// 	int* mirror = new int[MAX_VAL];
// 	srand(time(NULL));
// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		const int value = rand();
// 		numbers[i] = value;
// 		mirror[i] = value;
// 	}
// 	//SCOPE
// 	{
// 		Array<int> tmp = numbers;
// 		Array<int> test(tmp);
// 	}

// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		if (mirror[i] != numbers[i])
// 		{
// 			std::cerr << "didn't save the same value!!" << std::endl;
// 			return 1;
// 		}
// 	}
// 	try
// 	{
// 		numbers[-2] = 0;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
// 	try
// 	{
// 		numbers[MAX_VAL] = 0;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}

// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		numbers[i] = rand();
// 	}
// 	delete [] mirror;//
// 	return 0;
// }

