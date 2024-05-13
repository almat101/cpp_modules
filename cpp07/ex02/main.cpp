#include "Array.hpp"

int main(void)
{

    Array<unsigned int> intArray(10);

    
    try
    {
        intArray[1] = 42;
        unsigned int value = intArray[1];
        std::cout << "Value at index 1: " << value << std::endl;

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

    for (int i = 0; i < doubleArray.getSize(); i++) {
        std::cout << doubleArray[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}