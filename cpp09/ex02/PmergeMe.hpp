#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <cstdlib> // For std::strtol
#include <cerrno>  // For errno
#include <limits>
#include <cctype>
#include <sstream>
#include <algorithm>
#include <vector>
#include <exception>
#include <ctime> // For clock

class PmergeMe {
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);

		std::vector<int>& getUnorderedVector();
		std::vector<std::pair<int, int> >& getFirstPair();
		std::vector<int>& getMainChainVector();
		std::vector<int>& getPendChainVector();

		void validation(char **argv);
		void create_pair();
		void processPairs();
		void merge_items(std::vector<int>& pend, std::vector<int>& jacob_sequence,std::vector<int>& main);
		void insert_odd_element(std::vector<int>& main_chain, int rest);
		std::vector<int> generateJacobSequence(std::vector<int>& array);
		int jacobsthal(int n);
		void insertFirstPend();



		void printVectorOdd();
		void printVector( std::vector<int>& vec);
		void printPair();
		void printVectorOfPairs(std::vector<std::pair<int, int> > & vec);

		// Custom exceptions
		class NegativeNumberException : public std::exception {
			public:
				const char* what() const throw() {
					return "Negative number encountered";
				}
		};

		class DuplicatedNumberException : public std::exception {
			public:
				const char* what() const throw() {
					return "Duplicated number encountered";
				}
		};

		class NotIntegerException : public std::exception {
			public:
				const char* what() const throw() {
					return "Not an integer encountered";
				}
		};

	private:
		std::vector<int> _unordered_vector;
		std::vector<std::pair<int, int> > _first_pair;
		std::vector<int> _main_chain_vector;
		std::vector<int> _pend_chain_vector;
		int _vector_odd;
};

#endif
