#ifndef Base_hpp
#define Base_hpp

#include <iostream>
#include <cstdlib> //library for rand() function

class Base
{
	public:
		virtual ~Base();
};

// it is often considered a good practise to explicity declare the destructor as virtual
// in any derived class as well, to make it clear to anyone reading the code that the destructor is intented to be virtual.
class A : public Base
{
	public:

		virtual ~A();
};

class B : public Base
{
	public:

		virtual ~B();
};

class C : public Base
{
	public:

		virtual ~C();

};

//class D that not exist (in it not returned by generate function)
class D : public Base
{
	public:

		virtual ~D();

};
Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif
