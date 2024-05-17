#ifndef mutantstack_hpp
#define mutantstack_hpp

#include <iostream>
#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	//define iterator type
	typedef typename std::deque<T>::iterator iterator;

	MutantStack() : std::stack<T>()
	{
		// std::cout << "Default constructor\n";
	}

	MutantStack(const MutantStack<T>& src) : std::stack<T>(src)
	{
		// std::cout << "Copy constructor\n";
	}

	MutantStack& operator=(const MutantStack<T>& rhs) {
		if (this != &rhs)
		{
			// std::cout << "Assignment operator\n";
			std::stack<T>::operator=(rhs);
		}
		return *this;
	}

	~MutantStack()
	{
		// std::cout << "Destructor\n";
	}


	iterator begin() {
		return this->c.begin();
	}

	iterator end() {
		return this->c.end();
	}
};

#endif


// #ifndef mutantstack_hpp
// #define mutantstack_hpp

// #include <iostream>
// #include <stack>
// #include <deque>

// template <typename T>
// class MutantStack
// {
// public:
// 	typedef typename std::deque<T>::iterator iterator;

// 	MutantStack()
// 	{
// 		std::cout << "Default constructor\n";
// 	}

// 	MutantStack(const MutantStack<T>& src) : deque_(src.deque_)
// 	{
// 		std::cout << "Copy constructor\n";
// 	}

// 	// Assignment operator
// 	MutantStack& operator=(const MutantStack<T>& rhs) {
// 		if (this != &rhs)
// 		{
// 			std::cout << "Assignment operator\n";
// 			deque_ = rhs.deque_;
// 		}
// 		return *this;
// 	}

// 	~MutantStack()
// 	{
// 		std::cout << "Destructor\n";
// 	}

// 	//deque iterator methods
// 	iterator begin() {
// 		return deque_.begin();
// 	}

// 	iterator end() {
// 		return deque_.end();
// 	}

// 	//stack default methods implemented using deque methods
// 	void push(T value) {
// 		deque_.push_back(value);
// 	}

// 	void pop() {
// 		deque_.pop_back();
// 	}

// 	T& top() {
// 		return deque_.back();
// 	}

// 	const T& top() const {
// 		return deque_.back();
// 	}

// 	bool empty() {
// 		return deque_.empty();
// 	}

// 	size_t size() {
// 		return deque_.size();
// 	}


// 	private:
// 		std::deque<T> deque_;
// };

// #endif
