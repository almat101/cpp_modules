#include "Data.hpp"

Data::Data()
{}

Data::Data(Data const &src)
{
	*this = src;
}

Data::~Data()
{}

Data &Data::operator=(Data const &src)
{
	if (this != &src)
	{
		s1 = src.s1;
		s2 = src.s2;
		n = src.n;
	}
	return *this;
}

Data::Data(std::string s1, std::string s2, int n) : s1(s1), s2(s2), n(n)
{}

std::string Data::getS1() const
{
	return s1;
}

std::string Data::getS2() const
{
	return s2;
}

int Data::getN() const
{
	return n;
}

void Data::setS1(std::string s1)
{
	this->s1 = s1;
}

void Data::setS2(std::string s2)
{
	this->s2 = s2;
}

void Data::setN(int n)
{
	this->n = n;
}


