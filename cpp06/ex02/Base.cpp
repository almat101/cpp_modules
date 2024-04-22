#include "Base.hpp"


Base::~Base()
{}

//The `Base` class does have a virtual destructor, which is important when you're dealing with inheritance.
// This ensures that the correct destructor is called when an object of a derived class is deleted through a pointer to the base class, which prevents resource leaks.


A::~A()
{}

B::~B()
{}

C::~C()
{}

//class D that not exist (in it not returned by generate function)

D::~D()
{}

Base * generate(void)
{
	srand(time(NULL));
	int random = rand() % 3;
	if (random == 0)
		return new A();
	else if (random == 1)
		return new B();
	else
		return new C();
}
//It prints the actual type of the object pointed to by p: "A", "B" or "C".
void identify(Base* p)
{
	if (p == NULL)
		std::cout << "the base pointer is NULL" << std::endl;
	else
	{
		if (dynamic_cast<A*>(p) != NULL)
			std::cout << "the base pointer is type A" << std::endl;
		else if (dynamic_cast<B*>(p) != NULL)
			std::cout << "the base pointer is type B" << std::endl;
		else if (dynamic_cast<C*>(p) != NULL)
			std::cout << "the base pointer is type C" << std::endl;
		else
			std::cout << "the base pointer is not type A, B or C" << std::endl;
	}
}

//It prints the actual type of the object pointed to by p: "A", "B" or "C". Using a pointer
//inside this function is forbidden.

//in this function we cant use std::bad_cast for exception because it is not allowed to use typeinfo library
void identify(Base& p)
{
	try
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "the base reference is type A" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "the base reference is type B" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "the base reference is type C" << std::endl;
		return ;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
