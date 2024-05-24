#include "RPN.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Program use: ./RPN [reverse polish notation valid operation]\n";
		std::cerr << "https://en.wikipedia.org/wiki/Reverse_Polish_notation\n";
		std::cerr << "https://www.rpn-calc.com/\n";
		return 1;
	}
	else
	{
		RPN rpn;
		rpn.rpn_calculator(argv);
	}
	return 0;
}
