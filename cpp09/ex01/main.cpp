#include <iostream>
#include <stack>
#include <list>
#include <sstream>
#include <cstdlib>

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		std::cout << "program use ./RPN [reverse polish notation operation]\n";
		std::cout << "https://en.wikipedia.org/wiki/Reverse_Polish_notation\n";
		return 1;
	}
	else
	{
		std::stack<int, std::list<int>> myStack;
		std::stringstream ss(argv[1]);
		char ch;
		int counterOp = 0;
		int pushed = 0;

		while (ss.get(ch))
		{
			if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
			{
				counterOp++;
			}
			if (!isdigit(ch) && ch != '+' && ch != '-' && ch != '*' && ch != '/' && isspace(ch) == 0)
			{
				std::cout << "Invalid character: " << ch << std::endl;
				return 1;
			}

			if (isdigit(ch))
			{
				myStack.push(ch - '0');  // Convert from char to int
				pushed++;
				std::cout << "Pushed: " << ch << std::endl;
			}
			else if (ch == '+' && myStack.size() >= 2)
			{
				int num2 = myStack.top();
				std::cout << "num2: " << num2 << std::endl;
				myStack.pop();

				int num1 = myStack.top();
				std::cout << "num1: " << num1 << std::endl;
				myStack.pop();

				int result = num1 + num2;
				std::cout << "+ result: " << result << std::endl;
				myStack.push(result);
			}
			else if (ch == '-' && myStack.size() >= 2)
			{
				int num2 = myStack.top();
				std::cout << "num2: " << num2 << std::endl;
				myStack.pop();

				int num1 = myStack.top();
				std::cout << "num1: " << num1 << std::endl;
				myStack.pop();

				int result = num1 - num2;
				std::cout << "- result: " << result << std::endl;
				myStack.push(result);
			}
			else if (ch == '*' && myStack.size() >= 2)
			{
				int num2 = myStack.top();
				std::cout << "num2: " << num2 << std::endl;
				myStack.pop();

				int num1 = myStack.top();
				std::cout << "num1: " << num1 << std::endl;
				myStack.pop();

				int result = num1 * num2;
				std::cout << " * result: " << result << std::endl;
				myStack.push(result);
			}
			else if (ch == '/' && myStack.size() >= 2)
			{
				int num2 = myStack.top();
				std::cout << "num2: " << num2 << std::endl;
				myStack.pop();

				int num1 = myStack.top();
				std::cout << "num1: " << num1 << std::endl;
				myStack.pop();

				int result = num1 / num2;
				std::cout << "/ result: " << result << std::endl;
				myStack.push(result);
			}
		}
		if (myStack.size() == 1 && counterOp < pushed)
		{
			std::cout << myStack.top() << std::endl;
		}
		else
		{
			std::cerr << "Stack error" << std::endl;
			while (myStack.top())
			{
				std::cerr << "Stack is composed by '" << myStack.top() << "' " << std::endl;
				myStack.pop();
			}

			std::cerr << "last ch is " << ch << std::endl;
			std::cerr << "counterOp of op is " << counterOp << std::endl;
			std::cerr << "pushed in the stack are " << pushed << std::endl;
			return 1;
		}
	}
	return 0;
}
