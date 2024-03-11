#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int main(void)
{
	int animalSize = 10;
	Animal *ani[animalSize];
	int brainSize = 100;

	for (int i = 0; i < animalSize / 2; i++)
		ani[i] = new Dog();

	for (int i = animalSize / 2; i < animalSize; i++)
		ani[i] = new Cat();

	dynamic_cast<Dog *>(ani[0])->setDogIdea(0, "424242");
	dynamic_cast<Cat *>(ani[9])->setCatIdea(99, "424242");

	for (int i = 0; i < animalSize / 2; i++)
	{
		for (int j = 0; j < brainSize; j++)
			std::cout << dynamic_cast<Dog *>(ani[i])->getDogIdea(j) << std::endl;
	}

	for (int i = animalSize / 2; i < animalSize; i++)
	{
		for (int j = 0; j < brainSize; j++)
			std::cout << dynamic_cast<Cat *>(ani[i])->getCatIdea(j) << std::endl;
	}
	for (int i = 0; i < animalSize; i++)
	{
		delete ani[i];
	}



	// copy constructor and assignment operator test for deep copy
	// Dog *dog1 = new Dog();
	// Cat *cat1 = new Cat();

	// Dog *dog2 = new Dog(*dog1);
	// Cat *cat2 = new Cat(*cat1);
	// Dog *dog3 = new Dog();
	// Cat *cat3 = new Cat();
	// *dog3 = *dog1;
	// *cat3 = *cat1;

	// dog1->makeSound();
	// cat1->makeSound();
	// dog2->makeSound();
	// cat2->makeSound();
	// dog3->makeSound();
	// cat3->makeSound();

	// delete dog1;
	// delete cat1;
	// delete dog2;
	// delete cat2;
	// delete dog3;
	// delete cat3;

	return 0;
}
