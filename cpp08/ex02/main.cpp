#include "MutantStack.hpp"
#include <deque>
#include <stdlib.h>
#include <vector>
#include <list>

int main()
{
	MutantStack<int> mstack;

	std::cout << "now MutantStack\n" << std::endl;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::stack<int> s(mstack);

	std::cout << "\nnow std::vector\n" << std::endl;

	std::vector<int> mstack2;

	mstack2.push_back(5);
	mstack2.push_back(17);
	std::cout << mstack2.back() << std::endl;
	mstack2.pop_back();
	std::cout << mstack2.size() << std::endl;

	mstack2.push_back(3);
	mstack2.push_back(5);
	mstack2.push_back(737);
	mstack2.push_back(0);

	std::vector<int>::iterator it2 = mstack2.begin();
	std::vector<int>::iterator ite2 = mstack2.end();

	++it2;
	--it2;
	while (it2 != ite2)
	{
		std::cout << *it2 << std::endl;
		++it2;
	}

	std::vector<int> s2(mstack2);
	return 0;
}

// int main()
// {
//     MutantStack<int, std::list<int> > mstack_list;

//     std::cout << "now MutantStack<int,std::list<int> >\n" << std::endl;
//     mstack_list.push(5);
//     mstack_list.push(17);
//     std::cout << mstack_list.top() << std::endl;
//     mstack_list.pop();
//     std::cout << mstack_list.size() << std::endl;

//     mstack_list.push(3);
//     mstack_list.push(5);
//     mstack_list.push(737);
//     mstack_list.push(0);

//     MutantStack<int, std::list<int> >::iterator it = mstack_list.begin();
//     MutantStack<int, std::list<int> >::iterator ite = mstack_list.end();

//     ++it;
//     --it;

//     while (it != ite)
//     {
//         std::cout << *it << std::endl;
//         ++it;
//     }

// 	std::stack<int,std::list<int> > s;
// 	std::cout << "now Stack with std::list\n" << std::endl;
//     s.push(5);
//     s.push(17);
//     std::cout << s.top() << std::endl;
//     s.pop();
//     std::cout << s.size() << std::endl;

//     s.push(3);
//     s.push(5);
//     s.push(737);
//     s.push(0);
// 	//stack is lifo and has no iterator
// 	std::stack<int, std::list<int> > s_copy = s;
// 	while (!s_copy.empty())
// 	{

// 		std::cout << s_copy.top() << std::endl;
// 		s_copy.pop();
// 	}

//     // std::stack<int, std::list<int> >::iterator it = s.begin();
//     // std::stack<int, std::list<int> >::iterator ite = s.end();

//     // ++it;
//     // --it;

//     // while (it != ite)
//     // {
//     //     std::cout << *it << std::endl;
//     //     ++it;
//     // }

//     return 0;
// }

// int main() {

// 	MutantStack<int> stack1;
// 	std::deque<int> d;


// 	stack1.push(10);
// 	stack1.push(-20);
// 	stack1.push(30);
// 	stack1.push(42);
// 	stack1.push(5);

// 	MutantStack<int> stack2(stack1);

// 	std::cout << "\nstack 2:\n";
// 	for (MutantStack<int>::iterator it = stack2.begin(); it != stack2.end(); ++it)
// 	{
// 		std::cout << *it << " ";
// 	}

// 	std::cout << "\nstack 1:\n";
// 	for (MutantStack<int>::iterator it = stack1.begin(); it != stack1.end(); ++it) {
// 		std::cout << *it << " ";
// 	}
// 	std::cout << std::endl;


// 	d.push_back(10);
// 	d.push_back(-20);
// 	d.push_back(30);
// 	d.push_back(42);
// 	d.push_back(5);

// 	std::cout << "\ndeque d:\n";
// 	for (std::deque<int>::iterator it = d.begin(); it != d.end(); ++it) {
// 		std::cout  << *it << " ";
// 	}
// 	std::cout << std::endl;
// 	return 0;
// }

// int main (void)
// {
// 	 MutantStack<int> myStack;

// 	myStack.push(10);
// 	myStack.push(20);
// 	myStack.push(30);


// 	for (MutantStack<int>::iterator it = myStack.begin(); it != myStack.end(); ++it) {
// 	    std::cout << *it << " ";
// 	}

// 	MutantStack<int> stack1,stack2;

// 	stack1.push(10);
// 	stack1.push(-20);
// 	stack1.push(30);
// 	stack1.push(42);
// 	stack1.push(5);

// 	stack2 = stack1;

// 	std::cout << "\nstack 1:\n";
// 	for (MutantStack<int>::iterator it = stack1.begin(); it != stack1.end(); ++it) {
// 	    std::cout << *it << " ";
// 	}

// 	std::cout << "\nstack 2:\n";
// 	for (MutantStack<int>::iterator it = stack2.begin(); it != stack2.end(); ++it) {
// 	    std::cout << *it << " ";
// 	}
// 	return 0;
// }


// int main (void)
// {
// 	std::stack<int> myStack;

// 	MutantStack<int> mutant;

// 	// Push elements onto the stack
// 	myStack.push(10);
// 	myStack.push(20);
// 	myStack.push(30);

// 	mutant.push(42);
// 	mutant.push(20);
// 	mutant.push(10);
// 	mutant.push(-23);

// 	// Get the size of the stack
// 	std::cout << "Size of the std::stack: " << myStack.size() << std::endl;
// 	std::cout << "Size of the mutant stack: " << mutant.size() << std::endl;

// 	// Access the top element without removing it
// 	std::cout << "Top element of std::stack: " << myStack.top() << std::endl;
// 	std::cout << "Top element of mutant stack: " << mutant.top() << std::endl;

// 	// Remove the top element
// 	myStack.pop();
// 	mutant.pop();

// 	// Access the new top element
// 	std::cout << "New top element of std::stack: " << myStack.top() << std::endl;
// 	std::cout << "New top element of mutant stack: " << mutant.top() << std::endl;


// 	// Check if the stack is empty
// 	if (myStack.empty())
// 		std::cout << "The stack is empty." << std::endl;
// 	else
// 		std::cout << "The stack is not empty." << std::endl;

// 	if (mutant.empty())
// 		std::cout << "The stack is empty." << std::endl;
// 	else
// 		std::cout << "The stack is not empty." << std::endl;

// 	return 0;
// }
