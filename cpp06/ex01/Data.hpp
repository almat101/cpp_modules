#ifndef Data_hpp
#define Data_hpp

#include <iostream>
#include <string>

class Data
{
	private :
		std::string s1;
		std::string s2;
		int n;
		
	public:
		Data();
		Data(Data const &src);
		~Data();
		Data(std::string s1, std::string s2, int n);
		Data &operator=(Data const &src);

		std::string getS1() const;
		std::string getS2() const;
		int getN() const;

		void setS1(std::string s1);
		void setS2(std::string s2);
		void setN(int n);

};

#endif
