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

	std::cout << std::endl;
	std::cout << "Animal[0]: " << ani[0]->getType() << std::endl;
	for (int i = 0; i < animalSize / 2; i++)
	{
		for (int j = 0; j < brainSize; j++)
			std::cout << dynamic_cast<Dog *>(ani[i])->getDogIdea(j) << std::endl;
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << "Animal[9]: " << ani[9]->getType() << std::endl;
	for (int i = animalSize / 2; i < animalSize; i++)
	{
		for (int j = 0; j < brainSize; j++)
			std::cout << dynamic_cast<Cat *>(ani[i])->getCatIdea(j) << std::endl;
		std::cout << std::endl;
	}
	for (int i = 0; i < animalSize; i++)
	{
		delete ani[i];
	}
	std::cout << std::endl;



	////copy constructor and assignment operator test for deep copy
	// Dog *dog1 = new Dog();
	// Cat *cat1 = new Cat();


	// dog1->setDogIdea(99,"bau bau");
	// Dog *dog2 = new Dog(*dog1);
	// Cat *cat2 = new Cat(*cat1);
	// Dog *dog3 = new Dog();
	// Cat *cat3 = new Cat();
	// *dog3 = *dog1;
	// *cat3 = *cat1;
	
	// std::cout << std::endl;
	// std::cout << " dog 1 idea:" << std::endl;
	// for (int i = 0; i < 100; i++)
	// {
	// 	std::cout << dog1->getDogIdea(i) << std::endl;
	// }
		
	
	// std::cout << std::endl;
	// std::cout << " dog 2 idea:" << std::endl;
	// for (int i = 0; i < 100; i++)
	// {
	// 	std::cout << dog2->getDogIdea(i) << std::endl;
	// }

	// std::cout << std::endl;
	// std::cout << " dog 3 idea:" << std::endl;
	// for (int i = 0; i < 100; i++)
	// {
	// 	std::cout << dog3->getDogIdea(i) << std::endl;
	// }
	// std::cout << std::endl;

	// delete dog1;
	// delete cat1;
	// delete dog2;
	// delete cat2;
	// delete dog3;
	// delete cat3;

	return 0;
}
