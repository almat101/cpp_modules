#include "RPN.hpp"

RPN::RPN(){}

RPN::~RPN(){}

RPN::RPN(const RPN& src)
{
	*this = src;
}

RPN& RPN::operator=(const RPN& rhs)
{
	if (this != &rhs)
	{
		this->_myStack = rhs._myStack;
	}
	return *this;
}

void RPN::rpn_calculator(char **argv)
{
		std::stringstream ss(argv[1]);
		char ch;
		int counterOp = 0;
		int pushed = 0;

		while (ss.get(ch))
		{
			if (isspace(ch))
			{
				continue;
			}
			if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
			{
				counterOp++;
			}
			if (!isdigit(ch) && ch != '+' && ch != '-' && ch != '*' && ch != '/')
			{
				std::cout << "Error: Invalid character: " << ch << std::endl;
				return ;
			}

			if (isdigit(ch))
			{
				_myStack.push(ch - '0');  // Convert from char to int
				pushed++;
			}
			else if (ch == '+' && _myStack.size() >= 2)
			{
				int num2 = _myStack.top();
				_myStack.pop();

				int num1 = _myStack.top();
				_myStack.pop();

				int result = num1 + num2;
				_myStack.push(result);
			}
			else if (ch == '-' && _myStack.size() >= 2)
			{
				int num2 = _myStack.top();
				_myStack.pop();

				int num1 = _myStack.top();
				_myStack.pop();

				int result = num1 - num2;
				_myStack.push(result);
			}
			else if (ch == '*' && _myStack.size() >= 2)
			{
				int num2 = _myStack.top();
				_myStack.pop();

				int num1 = _myStack.top();
				_myStack.pop();

				int result = num1 * num2;
				_myStack.push(result);
			}
			else if (ch == '/' && _myStack.size() >= 2)
			{
				int num2 = _myStack.top();
				_myStack.pop();

				if(num2 == 0)
				{
					std::cerr << "Error: Division by zero" << std::endl;
					return ;
				}

				int num1 = _myStack.top();
				_myStack.pop();

				int result = num1 / num2;
				_myStack.push(result);
			}
		}
		if (_myStack.size() == 1 && counterOp < pushed)
		{
			std::cout << _myStack.top() << std::endl;
		}
		else
		{
			std::cerr << "Error" << std::endl;
			// while (_myStack.top())
			// {
			// 	std::cerr << "Stack is composed by '" << _myStack.top() << "' " << std::endl;
			// 	_myStack.pop();
			// }
			return ;
		}
}
