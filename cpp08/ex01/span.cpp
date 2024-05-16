#include "span.hpp"

Span::Span() : _size(0) {}

Span::Span(unsigned int size)
{
	if (static_cast<int>(size) < 0)
		throw Span::SpanException();
	if (size == 0 || size == 1)
		throw Span::SpanException();
	_size = size;
}

Span::~Span(){}


Span::Span(Span const &src)
{
	*this = src;
}

Span& Span::operator=(Span const &rhs)
{
	if (this != &rhs)
	{
		_size = rhs._size;
		_vector = rhs._vector;
	}
	return *this;
}

void Span::addNumber(int value) {
	if (_size == 0 || _vector.size() >= _size)
		throw Span::SpanException();
	_vector.push_back(value);
}

void Span::printSpan()
{
 for (long unsigned int i = 0; i < _vector.size(); ++i) {
    std::cout << _vector[i] << " ";
  }
  std::cout << std::endl;
}

const char *Span::SpanException::what() const throw()
{
	return "span exception";
}

int Span::longestSpan()
{
	if (_vector.empty() || _vector.size() == 1)
		throw Span::SpanException();
	int max_value = *std::max_element(_vector.begin(), _vector.end());
	int min_value = *std::min_element(_vector.begin(), _vector.end());
	return (max_value - min_value);
}

int Span::shortestSpan()
{
	if (_vector.empty() || _vector.size() == 1)
		throw Span::SpanException();
	std::sort(_vector.begin(),_vector.end());
	std::vector<int> differences(_vector.size());
	std::adjacent_difference(_vector.begin(),_vector.end(),differences.begin());
	differences.erase(differences.begin());
	int shortest = *std::min_element(differences.begin(), differences.end());
	return (shortest);
}


void printVector(std::vector<int> vector)
{
	//std::sort(vector.begin(), vector.end());
	for (long unsigned int i = 0; i < vector.size(); ++i) {
	std::cout << vector[i] << " ";
}
std::cout << std::endl;
}

void Span::addNumberImproved(std::vector<int>::iterator it1, std::vector<int>::iterator it2)
{
	if (_vector.size() + std::distance(it1, it2) > _size)
		throw Span::SpanException();
	_vector.insert(_vector.end(), it1, it2);
}
