#ifndef span_hpp
#define span_hpp

#include "algorithm"
#include "iostream"
#include "vector"
#include "numeric"
#include "climits"

class Span
{
	private:
		std::vector<int>	_vector;
		unsigned int		_size;

	public:
		Span();
		Span(Span const &src);
		Span &operator=(Span const &rhs);
		Span(unsigned int size);
		~Span();

		void addNumber(int);
		void addNumberImproved(std::vector<int>::iterator it1, std::vector<int>::iterator it2);
		void printSpan();
		int longestSpan();
		int shortestSpan();

		class SpanException : public std::exception
		{
			virtual const char *what() const throw();
		};

};

void printVector(std::vector<int>);


#endif
