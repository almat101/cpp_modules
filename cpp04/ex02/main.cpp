#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main(void)
{

	//AAnimal animal; // this doesnt work because Animal now is an abstract class, his use is to be a blueprint for the derived class
	//animal.getType();

	// copy constructor and assignment operator test for deep copy
	Dog *dog1 = new Dog();
	Cat *cat1 = new Cat();

	Dog *dog2 = new Dog(*dog1);
	Cat *cat2 = new Cat(*cat1);

	dog1->makeSound();
	cat1->makeSound();
	dog2->makeSound();
	cat2->makeSound();

	delete dog1;
	delete cat1;
	delete dog2;
	delete cat2;

	return 0;
}
