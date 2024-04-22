#ifndef Serializer_hpp
#define Serializer_hpp

#include <iostream>
#include <string>
#include "Data.hpp"
#include <stdint.h>

class Serializer {
	private:
		Serializer();
	public:
		Serializer(Serializer const &src);
		~Serializer();
		Serializer &operator=(Serializer const &src);
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
