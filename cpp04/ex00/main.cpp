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

	const Animal *copy = new Animal(*a); // const in copy constructor made this copy possible, if there isn't const in copy costructor this cant't copy (with const is possible to copy const and non const object)

	// this is not ok because the reverse order is untrue
	// Cat* err = new Animal();
	std::cout << std::endl;
	std::cout << a->getType() << " is an animal" << std::endl;
	a->makeSound();
	std::cout << std::endl;
	std::cout << copy->getType() << " is an animal copied" << std::endl;
	copy->makeSound();
	std::cout << std::endl;
	std::cout << m->getType() << " is a cat" << std::endl;
	m->makeSound();
	std::cout << std::endl;
	std::cout << d->getType() << " is a dog" << std::endl;
	d->makeSound();
	std::cout << std::endl;
	std::cout << wrong->getType() << " is a wrongAnimal" << std::endl;
	wrong->makeSound();
	std::cout << std::endl;
	std::cout << catwrong->getType() << " is a wrongCat" << std::endl;
	catwrong->makeSound();

	std::cout << std::endl;
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

// int main(void)
// {
// 	const Animal* meta = new Animal();
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();
// 	std::cout << j->getType() << " " << std::endl;
// 	std::cout << i->getType() << " " << std::endl;
// 	i->makeSound(); //will output the cat sound!
// 	j->makeSound();
// 	meta->makeSound();

// 	delete meta;
// 	delete j;
// 	delete i;

// return 0;
// }
