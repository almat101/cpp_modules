#include "Base.hpp"

int main()
{

		Base *g = NULL;
		Base *d = new D();
		Base *x = generate();
		identify(x);
		identify(*x);
		
		std::cout << std::endl;
		std::cout << "Class D that not exist" << std::endl;
		identify(d);
		identify(*d);

		std::cout << std::endl;
		std::cout << "Class == NULL" << std::endl;
		identify(g);
		identify(*g);
		delete x;
		delete d;
}
