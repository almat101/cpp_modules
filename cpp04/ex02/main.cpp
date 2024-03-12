#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main(void)
{

	//Animal animal; // this doesnt work because Animal now is an abstract class, his use is to be a blueprint for the derived class
	//animal.getType();

	// copy constructor and assignment operator test for deep copy
	Dog *dog1 = new Dog();
	Cat *cat1 = new Cat();

	Dog *dog2 = new Dog(*dog1);
	Cat *cat2 = new Cat(*cat1);
	Dog *dog3 = new Dog();
	Cat *cat3 = new Cat();
	*dog3 = *dog1;
	*cat3 = *cat1;

	dog1->makeSound();
	cat1->makeSound();
	dog2->makeSound();
	cat2->makeSound();
	dog3->makeSound();
	cat3->makeSound();

	delete dog1;
	delete cat1;
	delete dog2;
	delete cat2;
	delete dog3;
	delete cat3;

	return 0;
}
