#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	// this is ok Animal is an Animal
	const Animal *a = new Animal();
	// this is ok Cat is an Animal
	const Animal *m = new Cat();
	// this is ok Dog is an Animal
	const Animal *d = new Dog();
	const WrongAnimal *wrong = new WrongCat();
	const WrongCat *catwrong = new WrongCat();

	const Animal *copy = new Animal(*a);

	// this is not ok because the reverse order is untrue
	// Cat* err = new Animal();
	std::cout << std::endl;
	std::cout << a->getType() << " is an animal" << std::endl;
	std::cout << copy->getType() << " is an animal copied" << std::endl;
	std::cout << m->getType() << " is a cat" << std::endl;
	std::cout << d->getType() << " is a dog" << std::endl;
	std::cout << wrong->getType() << " is a wrongAnimal" << std::endl;
	std::cout << catwrong->getType() << " is a wrongCat" << std::endl;

	std::cout << std::endl;
	a->makeSound();
	copy->makeSound();
	m->makeSound();
	d->makeSound();
	
	std::cout << std::endl;
	// wrong cat without virtual makesound in wrongAnimal use the generic wrongAnimal makeSound
	wrong->makeSound();
	catwrong->makeSound();

	// without virtual in animal makeAnoterSound they all use the animal makeAnotherSound
	a->makeAnotherSound();
	copy->makeAnotherSound();
	m->makeAnotherSound();
	d->makeAnotherSound();

	std::cout << std::endl;

	delete a;
	delete m;
	delete d;
	delete wrong;
	delete catwrong;
	delete copy;

	return 0;
}
