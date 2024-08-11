#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}


PmergeMe::~PmergeMe(){}


PmergeMe::PmergeMe(const PmergeMe& src){
	*this = src;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs){
	if (this != &rhs){
		_vector = rhs._vector;
		_deque = rhs._deque;
	}
	return *this;
}

std::vector<int>& PmergeMe::getUnorderedVector(){
	return _vector;
}

std::deque<int>& PmergeMe::getUnorderedDeque(){
	return _deque;
}


/**
 * @brief Validates and processes command-line arguments.
 *
 * This function iterates over the command-line arguments, checks if each argument is a valid integer,
 * converts it to a long integer, and performs several validations:
 * - Ensures the argument is an integer.
 * - Checks for conversion errors and ensures the number is within the int range.
 * - Ensures the number is not negative.
 * - Checks for duplicate numbers.
 *
 * If any validation fails, an appropriate exception is thrown.
 * Validated numbers are added to the _unordered_vector.
 *
 * @param argv Array of command-line arguments.
 * @throws NotIntegerException if an argument is not a valid integer.
 * @throws std::out_of_range if the number is out of the int range or invalid input.
 * @throws NegativeNumberException if the number is negative.
 * @throws DuplicatedNumberException if the number is a duplicate.
 */
void PmergeMe::validationVector(char **argv) {
	for (int i = 1; argv[i] != NULL; ++i) {
		std::string arg = argv[i];

		// Check if the argument is an integer
		for (size_t j = 0; j < arg.length(); ++j) {
			if (!isdigit(arg[j]) && !(j == 0 && arg[j] == '-')) {
				throw NotIntegerException();
			}
		}
		std::stringstream ss(arg);
		long number;
		ss >> number;

		// Check for conversion errors
		if (ss.fail() || !ss.eof() || number > std::numeric_limits<int>::max() || number < std::numeric_limits<int>::min()) {
			throw std::out_of_range("Number out of range or invalid input");
		}

		// Check for negative numbers
		if (number < 0) {
			throw NegativeNumberException();
		}

		// Check for duplicated numbers
		if (std::find(_vector.begin(), _vector.end(), number) != _vector.end()) {
			throw DuplicatedNumberException();
		}

		_vector.push_back(static_cast<int>(number));
	}
}

std::vector<std::pair<int, int> >  PmergeMe::first_step(std::vector<int>& input_vector)
{
	// int i = 1;
	// Extract odd element
	_odd = -1;
	if (input_vector.size() % 2 != 0)
	{
		_odd = input_vector.back();
		input_vector.pop_back();
	}

	//create the pair vector
	std::vector<std::pair<int, int> > pairs;
	// Extract pairs
	for (size_t i = 0; i < input_vector.size(); i += 2)
	{
		pairs.push_back(std::make_pair(input_vector[i], input_vector[i + 1]));
	}
	printVectorOfPairs(pairs);
	// recursion(pairs,i);
	return pairs;
}

std::vector<int> PmergeMe::recursion(std::vector<std::pair<int, int> >& pairs, int &i)
{
	std::cout << "recursion level " << i << std::endl;
	i++;
	std::cout << "before recursion pair is" << std::endl;
	printVectorOfPairs(pairs);
	// main chain is the sorted pair from last recursion
   	std::vector<int> main_chain;
	//pend chain go back to precedent recursion step and insert the element that are not in main_chain
	std::vector<int> pend_chain;
    if (pairs.size() == 1)
    {
		printVectorOfPairs(pairs);
		for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
		{
			std::pair<int, int>& pair = *it;
			if (pair.first > pair.second)
			{
				std::cout << pair.first << " e " << pair.second << std::endl;
				std::swap(pair.first, pair.second); // Ensure pair.first <= pair.second
				std::cout << pair.first << " e " << pair.second << std::endl;
			}
			std::cout << "main chain is now and im in last recursion level: " << std::endl;
			main_chain.push_back(pair.first);
			main_chain.push_back(pair.second);
			std::cout << std::endl;
		}
		// printVector(main_chain);
		// printVectorOfPairs(pairs);
		if (_odd != -1)
		{
			std::cout << "insert odd if present" << std::endl;
			std::vector<int>::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), _odd);
			main_chain.insert(pos, _odd);
		}
        // int largest = std::max(pairs[0].first, pairs[0].second);
        // std::cout << "Largest value: " << largest << std::endl;
		std::cout << "ritorno main chain che e' " << std::endl;
		printVector(main_chain);
        return main_chain;
    }

    // Sort the pairs and extract the largest value
    // std::vector<int> pre_chain;
	std::cout << "sort pair " <<std:: endl;
	for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
	{
		std::pair<int, int>& pair = *it;
		if (pair.first > pair.second)
		{
			std::cout << pair.first << " e " << pair.second << std::endl;
			std::swap(pair.first, pair.second); // Ensure pair.first <= pair.second
			// std::cout << "first element is " << pair.first << " and  " << pair.second << std::endl;
			// pend_chain.push_back(pair.first);
		}
		std::cout <<std::endl;
		std::cout << " first el of pair is " << pair.first << std::endl;
		// if (std::find(pend_chain.begin(), pend_chain.end(), pair.first) == pend_chain.end())
		// {
			std::cout << "pushing first to pend chain " << std::endl;
			pend_chain.push_back(pair.first);
			std::cout << "now pend is ";
			printVector(pend_chain);
		// 	std::cout << std::endl;
		// }
		// else
		// {
		// 	std::cout << "first element is already in pend chain " << std::endl;
		// }

		// pend_chain.push_back(pair.first);
		// std::cout << " main chain ? " << std::endl;
		// printVector(main_chain);
    }

    //Print the sorted pairs
    // Create new pairs for the next recursion
	std::cout << " create new pair for the next recursion " << std::endl;

    std::vector<std::pair<int, int> > new_pairs;

    for (size_t i = 0; i < pairs.size(); i += 2)
    {

        if (i + 1 < pairs.size())
        {
			std::cout << "ramo if " << std::endl;
            new_pairs.push_back(std::make_pair(pairs[i].second, pairs[i + 1].second));
        }
        else
        {
			std::cout << "ramo else " << std::endl;
            // new_pairs.push_back(pairs[i]);
			main_chain.push_back(pairs[i].first);
			pend_chain.push_back(pairs[i].second);
        }
	}
    printVectorOfPairs(new_pairs);

    // Recursive call
	std::cout << "recursive call " << std::endl;
    main_chain = recursion(new_pairs, i);
	std::cout << "after all recursion i am here this is main chain " << std::endl;
	printVector(main_chain);
	std::cout << "pend chain is " << std::endl;
	printVector(pend_chain);



	// for (std::vector<int>::const_iterator it = pend_chain.begin(); it != pend_chain.end(); ++it)
	// {
	// 	int elem = *it;
	// 	std::vector<int>::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), elem);
	// 	main_chain.insert(pos, elem);
	// }

	std::vector<int> order = create_jacob_order(pend_chain.size());
	for (size_t i = 0; i < order.size(); ++i) {
		int b_index = order[i];
		int item = pend_chain[b_index];
		int insert_index = binary_search_insertion_point(main_chain, item);
		main_chain = insert(main_chain, item, insert_index);
	}

	std::cout << "main chain after all insert" << std::endl;
	printVector(main_chain);

	std::cout << "pend chain after all recursion: " << std::endl;
	printVector(pend_chain);
	// printVectorOfPairs(pairs);

	// printVectorOdd();
	return main_chain;
}

void PmergeMe::printVectorOdd(){
	if (_odd != -1)
		std::cout << _odd << std::endl;
}

int PmergeMe::jacobsthal(int n) {
    return static_cast<int>(round((pow(2, n) + pow(-1, n - 1)) / 3));
}


std::vector<int> PmergeMe::create_jacob_order(int n) {
	std::vector<int> jacobsthal_numbers;
	for (int i = 0; ; ++i) {
		int j = jacobsthal(i);
		if (j > n) break;
		jacobsthal_numbers.push_back(j);
	}
	jacobsthal_numbers.push_back(n);
	std::vector<int> order;
	for (size_t i = 1; i < jacobsthal_numbers.size(); ++i) {
		for (int j = jacobsthal_numbers[i]; j > jacobsthal_numbers[i - 1]; --j) {
			order.push_back(j - 1);
		}
	}
	return order;
}

// int PmergeMe::jacobsthal(int n) {
//     if (n == 0) return 0;
//     if (n == 1) return 1;
//     int a = 0, b = 1, c;
//     for (int i = 2; i <= n; ++i) {
//         c = b + 2 * a;
//         a = b;
//         b = c;
//     }
//     return b;
// }


/**
 * @brief Inserts a number into a specified position in a vector.
 *
 * This function creates a new vector by inserting the given number `n` at the specified index `i` in the input vector `coll`.
 * The function performs the following steps:
 * - Reserves space in the result vector to accommodate the new element.
 * - Copies elements from the beginning of the input vector up to the insertion point.
 * - Inserts the new element at the specified position.
 * - Copies the remaining elements from the input vector after the insertion point.
 *
 * @param coll The input vector in which to insert the number.
 * @param n The number to be inserted.
 * @param i The index at which to insert the number.
 * @return A new vector with the number inserted at the specified position.
 */
std::vector<int> PmergeMe::insert(const std::vector<int>& coll, int n, int i) {
	std::vector<int> result;
	result.reserve(coll.size() + 1);
	result.insert(result.end(), coll.begin(), coll.begin() + i);
	result.push_back(n);
	result.insert(result.end(), coll.begin() + i, coll.end());
	return result;
}

std::vector<int> PmergeMe::generateJacobSequence(std::vector<int>& array) {
		std::cout << " size of array pend is " << array.size() << std::endl;
		int len = array.size();
		std::vector<int> sequence;
		int jacob_index = 1;

		// Loop through and create the sequence
		while (jacobsthal(jacob_index) < len - 1) {
			sequence.push_back(jacobsthal(jacob_index));
			jacob_index += 1;
		}
		return sequence;
}

// // Function to generate the nth Jacobsthal number
// int PmergeMe::jacobsthal(int n) {
//     return static_cast<int>(round((pow(2, n) + pow(-1, n - 1)) / 3));
// }

// /**
//  * @brief Creates the Jacobsthal order for a given number.
//  *
//  * This function generates a sequence of indices based on Jacobsthal numbers up to the given number `n`.
//  * The Jacobsthal numbers are used to determine the order in which elements are processed.
//  * The function performs the following steps:
//  * - Generates Jacobsthal numbers until the number exceeds `n`.
//  * - Adds `n` to the list of Jacobsthal numbers.
//  * - Creates the order based on the Jacobsthal numbers.
//  *
//  * The generated order is used in the Ford-Johnson sorting algorithm to determine the sequence of element processing.
//  *
//  * @param n The number up to which Jacobsthal numbers are generated.
//  * @return A vector of integers representing the order based on Jacobsthal numbers.
//  */
// std::vector<int> PmergeMe::create_jacob_order(int n) {
// 	std::vector<int> jacobsthal_numbers;
// 	for (int i = 0; ; ++i) {
// 		int j = jacobsthal(i);
// 		if (j > n) break;
// 		jacobsthal_numbers.push_back(j);
// 	}
// 	jacobsthal_numbers.push_back(n);
// 	std::vector<int> order;
// 	for (size_t i = 1; i < jacobsthal_numbers.size(); ++i) {
// 		for (int j = jacobsthal_numbers[i]; j > jacobsthal_numbers[i - 1]; --j) {
// 			order.push_back(j - 1);
// 		}
// 	}
// 	return order;
// }

// /**
//  * @brief Finds the insertion point for a given number in a sorted vector using binary search.
//  *
//  * This function performs a binary search on a sorted vector to find the appropriate insertion point for the given number `n`.
//  * If the number is found in the vector, its index is returned. If the number is not found, the function returns the index
//  * where the number should be inserted to maintain the sorted order.
//  *
//  * @param coll The sorted vector in which to search for the insertion point.
//  * @param n The number for which to find the insertion point.
//  * @return The index at which the number should be inserted.
//  */
int PmergeMe::binary_search_insertion_point(const std::vector<int>& coll, int n) {
	int lower_bound = 0;
	int upper_bound = coll.size() - 1;

	while (lower_bound <= upper_bound) {
		int mid_index = (lower_bound + upper_bound) / 2;
		if (coll[mid_index] < n) {
			lower_bound = mid_index + 1;
		} else if (coll[mid_index] > n) {
			upper_bound = mid_index - 1;
		} else {
			return mid_index;
		}
	}
	return lower_bound;
}



void PmergeMe::printVector(std::vector<int>& vec){
	for (size_t i = 0; i < vec.size(); ++i) {
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
}


void PmergeMe::printVectorOfPairs(std::vector< std::pair<int, int > > & vec){
	for (std::vector<std::pair<int, int> > ::const_iterator it = vec.begin(); it != vec.end(); ++it) {
		std::cout << "(" << it->first << ", " << it->second << ") ";
	}
	std::cout << std::endl;
}
