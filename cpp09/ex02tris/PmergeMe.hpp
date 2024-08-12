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
#include <cmath>
#include <iterator>
#include <deque>


class PmergeMe {
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);

		std::vector<int>& getUnorderedVector();
		std::deque<int>& getUnorderedDeque();

		void validationVector(char **argv);
		void validationDeque(char **argv);

		std::vector<std::pair<int, int> >  first_step(std::vector<int>& vector );
		std::deque<std::pair<int, int> >  first_step_deque(std::deque<int>& input_deque);

		std::vector<int> recursion(std::vector<std::pair<int, int> >& pairs, int &level);
		std::deque<int> recursion_deque(std::deque<std::pair<int, int> >& pairs, int &i);

		std::vector<int> create_jacob_order(int n);
		std::deque<int> create_jacob_order_deque(int n);

		int jacobsthal(int n);
		int jacobsthal_deque(int n);

		void printVectorOdd();
		void printDequeOdd();

		std::vector<int> insert(const std::vector<int>& coll, int n, int i);
		std::deque<int> insert_deque(const std::deque<int>& coll, int n, int i);

		int binary_search_insertion_point(const std::vector<int>& coll, int n);
		int binary_search_insertion_point_deque(const std::deque<int>& coll, int n);

		void printVector( std::vector<int>& vec);
		void printDeque(std::deque<int>& vec);

		void printVectorOfPairs(std::vector<std::pair<int, int> > & vec);
		void printDequeOfPairs(std::vector< std::pair<int, int > > & deque);


		void processPairs();

		void merge_items(std::vector<int>& pend, std::vector<int>& jacob_sequence,std::vector<int>& main);

		void insert_odd_element(std::vector<int>& main_chain, int rest);

		std::vector<int> generateJacobSequence(std::vector<int>& array);

		// std::vector<int> binary_insert(const std::vector<int>& coll, int n);
		std::vector<int> merge_insertion_sort(const std::vector<int>& coll);

		std::vector<std::pair<int, int> > sort_pairs(const std::vector<std::pair<int, int> >& sorted_pairs);

		void insertFirstPend();







		void printPair();



		// Custom exceptions
		class NegativeNumberException : public std::exception {
			public:
				const char* what() const throw() {
					return "Error\nNegative number encountered";
				}
		};

		class DuplicatedNumberException : public std::exception {
			public:
				const char* what() const throw() {
					return "Error\nDuplicated number encountered";
				}
		};

		class NotIntegerException : public std::exception {
			public:
				const char* what() const throw() {
					return "Error\nNot an integer encountered";
				}
		};

	public:
		std::vector<int> _vector;
		std::deque<int> _deque;
		int _odd;
		int _odd_deque;
};

		bool compare_pairs(const std::pair<int, int>& a, const std::pair<int, int>& b);
#endif
