#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}


PmergeMe::~PmergeMe(){}


PmergeMe::PmergeMe(const PmergeMe& src){
	*this = src;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs){
	if (this != &rhs){
		_unordered_vector = rhs._unordered_vector;
		_first_pair = rhs._first_pair;
		_main_chain = rhs._main_chain;
		_pend_chain = rhs._pend_chain;
		_main_chain_vector = rhs._main_chain_vector;
		_pend_chain_vector = rhs._pend_chain_vector;
		_vector_odd = rhs._vector_odd;
	}
	return *this;
}

std::vector<int>& PmergeMe::getUnorderedVector(){
	return _unordered_vector;
}

std::vector<std::pair<int, int> >& PmergeMe::getFirstPair(){
	return _first_pair;
}

std::vector<std::pair<int, int> >& PmergeMe::getMainChain(){
	return _main_chain;
}

std::vector<std::pair<int, int> >& PmergeMe::getPendChain(){
	return _pend_chain;
}

std::vector<int>& PmergeMe::getMainChainVector(){
	return _main_chain_vector;
}

std::vector<int>& PmergeMe::getPendChainVector(){
	return _pend_chain_vector;
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
void PmergeMe::validation(char **argv) {
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
		if (std::find(_unordered_vector.begin(), _unordered_vector.end(), number) != _unordered_vector.end()) {
			throw DuplicatedNumberException();
		}

		_unordered_vector.push_back(static_cast<int>(number));
	}
}

/**
 * @brief Creates pairs from the _unordered_vector and stores them in _first_pair.
 *
 * This function iterates over the _unordered_vector and creates pairs of integers.
 * - If the vector has an odd number of elements, the last element is stored in _vector_odd.
 * - Each pair is stored in _first_pair with the smaller number first.
 *
 * @throws None
 */
void PmergeMe::create_pair()
{
	// Initialize _vector_odd to -1 to indicate no odd element initially
	_vector_odd = -1;
	// Iterate over the _unordered_vector in steps of 2
	for (std::size_t i = 0; i < _unordered_vector.size(); i += 2)
	{
		int first = _unordered_vector[i];
		int second;

		// Check if there is a second element to pair with
		if (i + 1 < _unordered_vector.size()) {
			second = _unordered_vector[i + 1];
		} else {
			// If no second element, store the odd element and break the loop
			_vector_odd = first;
			break;
		}
		// Store the pair in _first_pair with the smaller number first
		if (first > second) {
			_first_pair.push_back(std::make_pair(second, first));
		} else {
			_first_pair.push_back(std::make_pair(first, second));
		}
	}
}

/**
 * @brief Processes pairs from _first_pair and distributes elements to _main_chain_vector and _pend_chain_vector.
 *
 * This function iterates over the _first_pair vector and processes each pair by:
 * - Finding the pair with the lowest second element.
 * - Adding the second element of the pair to _main_chain_vector.
 * - Adding the first element of the pair to _pend_chain_vector.
 * - Removing the processed pair from _first_pair.
 *
 * @throws None
 */
void PmergeMe::processPairs() {
	while (!_first_pair.empty()) {
		// Find the pair with the lowest second element
		std::vector<std::pair<int, int> >::iterator minIt = _first_pair.begin();
		for (std::vector<std::pair<int, int> >::iterator it = _first_pair.begin(); it != _first_pair.end(); ++it) {
			if (it->second < minIt->second) {
				minIt = it;
			}
		}

		// Push the second element of the pair to _main_chain
		_main_chain_vector.push_back(minIt->second);
		// _main_chain.push_back(std::make_pair(minIt->second, 0));

		// Push the first element of the pair to _pend_chain
		_pend_chain_vector.push_back(minIt->first);
		// _pend_chain.push_back(std::make_pair(minIt->first, 0));

		// Erase the processed pair from _first_pair
		_first_pair.erase(minIt);
	}
}

/**
 * @brief Generates a Jacobsthal sequence of length n.
 *
 * This function generates a Jacobsthal sequence, which is a sequence of integers defined by the recurrence relation:
 * - J(0) = 0
 * - J(1) = 1
 * - J(n) = J(n-1) + 2 * J(n-2) for n >= 2
 *
 * The generated sequence is stored in a vector and returned.
 *
 * @param n The length of the Jacobsthal sequence to generate.
 * @return std::vector<int> The generated Jacobsthal sequence.
 */
std::vector<int> PmergeMe::generateJacobSequence(int n) {
	std::vector<int> jacobSequence;
	if (n >= 1) jacobSequence.push_back(0);
	if (n >= 2) jacobSequence.push_back(1);

	for (int i = 2; i < n; ++i) {
		int next = jacobSequence[i - 1] + 2 * jacobSequence[i - 2];
		jacobSequence.push_back(next);
	}
	return jacobSequence;
}


/**
 * @brief Merges items from the pending vector into the main vector using a Jacobsthal insertion sequence.
 *
 * This function merges elements from the `pend` vector into the `main` vector. It uses a Jacobsthal insertion sequence
 * to determine the positions of elements to be inserted. The function also handles an odd element if it exists.
 *
 * @param pend The vector containing elements to be merged.
 * @param jacob_insertion_sequence The Jacobsthal insertion sequence used for determining insertion positions.
 * @param main The main vector where elements are merged into.
 */
void PmergeMe::merge_items(std::vector<int>& pend, std::vector<int>& jacob_insertion_sequence, std::vector<int>& main) {
	// Insert the first element of pend into the beginning of main
	main.insert(main.begin(), pend[0]);

	// Initialize the index sequence with the first index
	std::vector<int> indexSequence;
	indexSequence.push_back(1);

	size_t iterator = 1; // iterator is 1 because we already inserted the first element

	// Iterate over the pend vector to merge elements into main
	while (iterator <= pend.size())
	{

		int item;
		// Check if the Jacobsthal insertion sequence is not empty
		if (!jacob_insertion_sequence.empty()) {
			// Use the Jacobsthal sequence to determine the next item to insert
			indexSequence.push_back(jacob_insertion_sequence[0]);
			item = pend[jacob_insertion_sequence[0] - 1];
			jacob_insertion_sequence.erase(jacob_insertion_sequence.begin());
		} else {
			// If the current iterator is already in the index sequence, skip it
			if (std::find(indexSequence.begin(), indexSequence.end(), iterator) != indexSequence.end()) {
				iterator++;
				continue;
			}
			// Otherwise, use the current iterator to determine the next item to insert
			item = pend[iterator - 1];
			indexSequence.push_back(iterator);
		}

		// Find the insertion point using binary search and insert the item into main
		std::vector<int>::iterator binary_insertion_point = std::lower_bound(main.begin(), main.end(), item);
		main.insert(binary_insertion_point, item);

		iterator++;
	}

	// If there is an odd element, insert it into the main vector
	if (_vector_odd != -1) {
		insert_odd_element(main, _vector_odd);
	}
}


/**
 * @brief Inserts an odd element into the main vector in sorted order.
 *
 * This function checks if the odd element is valid (not equal to -1) and inserts it into the main vector
 * at the appropriate position to maintain sorted order. The insertion point is determined using binary search.
 *
 * @param main The main vector where the odd element is to be inserted.
 * @param odd The odd element to be inserted.
 */
void PmergeMe::insert_odd_element(std::vector<int>& main, int odd) {
	if (odd != -1) {
		std::vector<int>::iterator insertion_point = std::lower_bound(main.begin(), main.end(), odd);
		main.insert(insertion_point, odd);
	}
}


void PmergeMe::printVector(std::vector<int>& vec){
	for (size_t i = 0; i < vec.size(); ++i) {
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::printPair(){
	for (std::vector<std::pair<int, int> >::const_iterator it = _first_pair.begin(); it != _first_pair.end(); ++it) {
		std::cout << "(" << it->first << ", " << it->second << ") ";
	}
	std::cout << std::endl;
}

void PmergeMe::printVectorOfPairs(std::vector< std::pair<int, int > > & vec){
	for (std::vector<std::pair<int, int> > ::const_iterator it = vec.begin(); it != vec.end(); ++it) {
		std::cout << "(" << it->first << ", " << it->second << ") ";
	}
	std::cout << std::endl;
}

void PmergeMe::printVectorOdd(){
	if (_vector_odd != -1)
		std::cout << _vector_odd << std::endl;
}
