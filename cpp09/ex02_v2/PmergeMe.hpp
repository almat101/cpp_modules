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


class PmergeMe {
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe& other);
		PmergeMe& operator=(const PmergeMe& other);

		std::vector<int>& getUnorderedVector();

		void validation(char **argv);
		// void create_pair();
		// void create_vectors();
		void processPairs();
		void merge_items(std::vector<int>& pend, std::vector<int>& jacob_sequence,std::vector<int>& main);
		void insert_odd_element(std::vector<int>& main_chain, int rest);
		std::vector<int> generateJacobSequence(std::vector<int>& array);
		// std::vector<int> binary_insert(const std::vector<int>& coll, int n);
		std::vector<int> merge_insertion_sort(const std::vector<int>& coll);
		std::vector<std::pair<int, int> > sort_pairs(const std::vector<std::pair<int, int> >& sorted_pairs);
		void insertFirstPend();
		int jacobsthal(int n);
		std::vector<int> create_jacob_order(int n);
		int binary_search_insertion_point(const std::vector<int>& coll, int n);
		std::vector<int> insert(const std::vector<int>& coll, int n, int i);

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
};

		bool compare_pairs(const std::pair<int, int>& a, const std::pair<int, int>& b);
#endif
