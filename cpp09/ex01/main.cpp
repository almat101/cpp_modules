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

		while (ss.get(ch))
		{
			if (!isdigit(ch) && ch != '+' && ch != '-' && ch != '*' && ch != '/' && isspace(ch) == 0)
			{
				std::cout << "Invalid character: " << ch << std::endl;
				return 1;
			}
			if (isdigit(ch))// && myStack.size() <= 2)
			{
				myStack.push(ch - '0');  // Convert from char to int
				//std::cout << "Pushed: " << ch << std::endl;
			}
			// else if (myStack.size() > 2 )
			// {
			// 	std::cout << "Error \n";
			// 	return 1;
			// }
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
			// else
			// {
			// 	std::cout << "char is" << ch << std::endl;
			// 	std::cout << "Invalid character: " << ch << std::endl;
			// 	return 1;
			// }
			// Add more else if blocks here for other operators
		}
		if (!myStack.empty() && myStack.size() == 1)
		{
			std::cout << "Result: " << myStack.top() << std::endl;
		}
		else
		{
			std::cout << "Stack error" << std::endl;
			return 1;
		}
	}
	return 0;
}
