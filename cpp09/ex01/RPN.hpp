#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <list>
#include <sstream>
#include <cstdlib>

class RPN
{
	private:
		std::stack<int, std::list<int>> _myStack;

	public :
		RPN();
		~RPN();
		RPN(const RPN& src);
		RPN& operator=(const RPN& rhs);
		void rpn_calculator(char **argv);
};

#endif
