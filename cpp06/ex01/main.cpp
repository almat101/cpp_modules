#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main()
{
	Data data("Hello", "World", 42);

	std::cout << "Data: " << data.getS1() << " " << data.getS2() << " " << data.getN() << std::endl;

	uintptr_t serialized = Serializer::serialize(&data);

	std::cout << "Serialized decimal: " << serialized << std::endl;
	std::cout << "Serialized hexa: 0x" << std::hex << serialized << std::endl;
	std::cout << std::dec;
	Data *deserialized = Serializer::deserialize(serialized);

	std::cout << "Deserialized: " << deserialized << std::endl;
	std::cout << "Data: " << deserialized->getS1() << " " << deserialized->getS2() << " " << deserialized->getN() << std::endl;

	return 0;
}
