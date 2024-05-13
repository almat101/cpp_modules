#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array {
    private:
        T* data;  // Pointer to the dynamically allocated array
        unsigned int size;  // Size of the array

    public:
        // Construction with no parameter: Creates an empty array.
        Array();
        // Constructor (allocate memory)
        // Construction with an unsigned int n as a parameter: Creates an array of n elements initialized by default.
        Array(unsigned int capacity);

        // Destructor (deallocate memory)
        ~Array();

        // Access element at index (bounds checking)
        T& operator[](int index);

        // Get the size of the array
        int getSize() const { return size; }

        class array_out_of_range : public std::exception
		{
			// this function has to be virtual because override the method what() of the base class std::exception that is already virtual
			// this is the declaration of what() in std::exception in c++98
			virtual const char *what() const throw();
		};
};


template <typename T>
Array<T>::Array()
{
    data = NULL;
    size = 0;
}

template <typename T>
Array<T>::Array(unsigned int capacity)
{
    data = new T[capacity];
    size = capacity;   
}

template <typename T>
Array<T>::~Array()
{
    if (data != NULL)
        delete[] data;
}

template <typename T>
T& Array<T>::operator[]( int index)
{
    if (index < 0 || index >= static_cast<int>(size))
    {
        throw Array<T>::array_out_of_range();
    }
    return data[index];
}

template <typename T>
const char* Array<T>::array_out_of_range::what() const throw()
{
	return "index is out of bound";
}


#endif