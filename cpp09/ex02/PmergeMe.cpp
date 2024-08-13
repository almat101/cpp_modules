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

void PmergeMe::validationDeque(char **argv) {
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
		if (std::find(_deque.begin(), _deque.end(), number) != _deque.end()) {
			throw DuplicatedNumberException();
		}

		_deque.push_back(static_cast<int>(number));
	}
}


/**
 * @brief Extracts pairs from the input vector and returns them as a vector of pairs.
 *
 * This function takes an input vector and extracts pairs of elements from it. If the size of the input vector is odd, the last element is considered as an odd element and is stored separately. The extracted pairs are then stored in a vector of pairs and returned.
 *
 * @param input_vector The input vector from which pairs are to be extracted.
 * @return std::vector<std::pair<int, int>> The vector of pairs extracted from the input vector.
 */
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
	return pairs;
}


std::deque<std::pair<int, int> >  PmergeMe::first_step_deque(std::deque<int>& input_deque)
{
	// int i = 1;
	// Extract odd element
	_odd_deque = -1;
	if (input_deque.size() % 2 != 0)
	{
		_odd_deque = input_deque.back();
		input_deque.pop_back();
	}

	//create the pair deque
	std::deque<std::pair<int, int> > pairs;
	// Extract pairs
	for (size_t i = 0; i < input_deque.size(); i += 2)
	{
		pairs.push_back(std::make_pair(input_deque[i], input_deque[i + 1]));
	}
	// printdequeOfPairs(pairs);
	return pairs;
}

/**
 * @brief Performs a recursive operation on a vector of pairs.
 *
 * This function takes a vector of pairs and performs a recursive operation on it.
 * It sorts the pairs and extracts the largest value. If the size of the vector is 1, it returns the sorted pairs.
 * Otherwise, it creates new pairs for the next recursion and makes a recursive call with the new pairs.
 * Finally, it inserts the elements from the pend_chain vector into the main_chain vector in a specific order.
 *
 * @param pairs A vector of pairs to perform the recursive operation on.
 * @param i A reference to an integer representing the recursion level.
 * @return A vector of integers representing the result of the recursive operation.
 */
std::vector<int> PmergeMe::merge_recursion(std::vector<std::pair<int, int> >& pairs, int &i)
{
	// std::cout << "recursion level " << i << std::endl;
	i++;

   	std::vector<int> main_chain;
	std::vector<int> pend_chain;
	//exit recursion when pair size is 1
    if (pairs.size() == 1)
    {
		for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
		{
			std::pair<int, int>& pair = *it;
			if (pair.first > pair.second)
			{
				std::swap(pair.first, pair.second);
			}
			main_chain.push_back(pair.first);
			main_chain.push_back(pair.second);
		}
		// printVector(main_chain);
		if (_odd != -1)
		{
			std::vector<int>::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), _odd);
			main_chain.insert(pos, _odd);
		}
		// printVector(main_chain);
        return main_chain;
    }

    // Sort the pairs and extract the largest value
	for (std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
	{
		std::pair<int, int>& pair = *it;
		if (pair.first > pair.second)
		{
			std::swap(pair.first, pair.second);
		}
		pend_chain.push_back(pair.first);
		// std::cout << "now pend is ";
		// printVector(pend_chain);
    }

    // Create new pairs for the next recursion
	// std::cout << " create new pair for the next recursion " << std::endl;
    std::vector<std::pair<int, int> > new_pairs;

    for (size_t i = 0; i < pairs.size(); i += 2)
    {

        if (i + 1 < pairs.size())
        {
            new_pairs.push_back(std::make_pair(pairs[i].second, pairs[i + 1].second));
        }
        else
        {
			// main_chain.push_back(pairs[i].first);// this is not needed
			pend_chain.push_back(pairs[i].second);
        }
	}
    // Recursive call
	// std::cout << "recursive call " << std::endl;
    main_chain = merge_recursion(new_pairs, i);

	//insert pend_chain in main_chain using jacobstable order + binary search (lower bound)
	std::vector<int> order = create_jacob_order(pend_chain.size());
	for (size_t i = 0; i < order.size(); ++i) {
		int b_index = order[i];
		int item = pend_chain[b_index];
		std::vector<int>::iterator it = std::lower_bound(main_chain.begin(), main_chain.end(), item);
		main_chain.insert(it, item);
	}

	return main_chain;
}


//recursion for deque
/**
 * @brief Recursively merges pairs of integers in a deque.
 *
 * This function takes a deque of pairs of integers and recursively merges them into a single deque.
 * The merging process involves sorting the pairs and extracting the largest value from each pair.
 * The function continues to merge the remaining pairs until only one pair is left.
 *
 * @param pairs The deque of pairs of integers to be merged.
 * @param i A reference to an integer representing the recursion level.
 * @return A deque of integers containing the merged pairs.
 */
std::deque<int> PmergeMe::merge_recursion_deque(std::deque<std::pair<int, int> >& pairs, int &i)
{
	// std::cout << "recursion level " << i << std::endl;
	i++;
   	std::deque<int> main_chain;
	std::deque<int> pend_chain;
    if (pairs.size() == 1)
    {
		// printVectorOfPairs(pairs);
		for (std::deque<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
		{
			std::pair<int, int>& pair = *it;
			if (pair.first > pair.second)
			{

				std::swap(pair.first, pair.second);
			}
			main_chain.push_back(pair.first);
			main_chain.push_back(pair.second);
		}
		// printVector(main_chain);
		if (_odd != -1)
		{
			std::deque<int>::iterator pos = std::lower_bound(main_chain.begin(), main_chain.end(), _odd);
			main_chain.insert(pos, _odd);
		}
		// std::cout << "ritorno main chain che e' " << std::endl;
		// printVector(main_chain);
        return main_chain;
    }

    // Sort the pairs and extract the largest value
	for (std::deque<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
	{
		std::pair<int, int>& pair = *it;
		if (pair.first > pair.second)
		{
			std::swap(pair.first, pair.second);

		}
		pend_chain.push_back(pair.first);
		// std::cout << "now pend is ";
		// printVector(pend_chain);
    }

    // Create new pairs for the next recursion
    std::deque<std::pair<int, int> > new_pairs;
    for (size_t i = 0; i < pairs.size(); i += 2)
    {

        if (i + 1 < pairs.size())
        {
            new_pairs.push_back(std::make_pair(pairs[i].second, pairs[i + 1].second));
        }
        else
        {
			// main_chain.push_back(pairs[i].first); not necessary
			pend_chain.push_back(pairs[i].second);
        }
	}

    // Recursive call
	// std::cout << "recursive call " << std::endl;
    main_chain = merge_recursion_deque(new_pairs, i);

	//insert pend_chain in main_chain using jacobstable order + binary search (lower bound)
	std::deque<int> order = create_jacob_order_deque(pend_chain.size());
	for (size_t i = 0; i < order.size(); ++i) {
		int b_index = order[i];
		int item = pend_chain[b_index];
		std::deque<int>::iterator it = std::lower_bound(main_chain.begin(), main_chain.end(), item);
		main_chain.insert(it, item);
	}

	return main_chain;
}

/**
 * @brief Creates a Jacobsthal order for a given number.
 *
 * This function generates a Jacobsthal order for a given number 'n'.
 * The Jacobsthal order is a sequence of numbers that are less than or equal to 'n'
 * and are generated based on the Jacobsthal sequence.
 *
 * @param n The number for which the Jacobsthal order is to be created.
 * @return A vector containing the Jacobsthal order.
 */
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

/**
 * @brief Creates a Jacob Order deque.
 *
 * This function generates a deque of integers in Jacob Order up to a given number 'n'.
 * Jacob Order is a sequence of numbers defined by the Jacobsthal function.
 * The Jacobsthal function calculates the nth Jacobsthal number, which is defined recursively as follows:
 * - Jacobsthal(0) = 0
 * - Jacobsthal(1) = 1
 * - Jacobsthal(n) = Jacobsthal(n-1) + 2 * Jacobsthal(n-2)
 *
 * The function iterates through the Jacobsthal numbers until it reaches a number greater than 'n'.
 * It then adds 'n' to the list of Jacobsthal numbers.
 * Finally, it generates the Jacob Order deque by iterating through the Jacobsthal numbers and adding the difference between consecutive numbers to the deque.
 *
 * @param n The maximum number up to which the Jacob Order deque should be generated.
 * @return A deque of integers in Jacob Order.
 */
std::deque<int> PmergeMe::create_jacob_order_deque(int n) {
	std::deque<int> jacobsthal_numbers;
	for (int i = 0; ; ++i) {
		int j = jacobsthal_deque(i);
		if (j > n) break;
		jacobsthal_numbers.push_back(j);
	}
	jacobsthal_numbers.push_back(n);
	std::deque<int> order;
	for (size_t i = 1; i < jacobsthal_numbers.size(); ++i) {
		for (int j = jacobsthal_numbers[i]; j > jacobsthal_numbers[i - 1]; --j) {
			order.push_back(j - 1);
		}
	}
	return order;
}



int PmergeMe::jacobsthal(int n) {
    return static_cast<int>(round((pow(2, n) + pow(-1, n - 1)) / 3));
}

int PmergeMe::jacobsthal_deque(int n) {
    return static_cast<int>(round((pow(2, n) + pow(-1, n - 1)) / 3));
}


void PmergeMe::printVectorOdd() {
	if (_odd != -1)
		std::cout << _odd << std::endl;
}

void PmergeMe::printDequeOdd() {
	if (_odd_deque != -1)
		std::cout << _odd_deque << std::endl;
}


void PmergeMe::printVector(std::vector<int>& vec) {
	for (size_t i = 0; i < vec.size(); ++i) {
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::printDeque(std::deque<int>& vec) {
	for (size_t i = 0; i < vec.size(); ++i) {
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
}


void PmergeMe::printVectorOfPairs(std::vector< std::pair<int, int > > & vec) {
	for (std::vector<std::pair<int, int> > ::const_iterator it = vec.begin(); it != vec.end(); ++it) {
		std::cout << "(" << it->first << ", " << it->second << ") ";
	}
	std::cout << std::endl;
}

void PmergeMe::printDequeOfPairs(std::deque< std::pair<int, int > > & deque) {
	for (std::deque<std::pair<int, int> > ::const_iterator it = deque.begin(); it != deque.end(); ++it) {
		std::cout << "(" << it->first << ", " << it->second << ") ";
	}
	std::cout << std::endl;
}


