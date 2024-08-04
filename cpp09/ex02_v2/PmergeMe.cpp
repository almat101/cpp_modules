#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}


PmergeMe::~PmergeMe(){}


PmergeMe::PmergeMe(const PmergeMe& src){
	*this = src;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs){
	if (this != &rhs){
		_unordered_vector = rhs._unordered_vector;
	}
	return *this;
}

std::vector<int>& PmergeMe::getUnorderedVector(){
	return _unordered_vector;
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


// Function to generate the nth Jacobsthal number
int PmergeMe::jacobsthal(int n) {
    return static_cast<int>(round((pow(2, n) + pow(-1, n - 1)) / 3));
}

/**
 * @brief Creates the Jacobsthal order for a given number.
 *
 * This function generates a sequence of indices based on Jacobsthal numbers up to the given number `n`.
 * The Jacobsthal numbers are used to determine the order in which elements are processed.
 * The function performs the following steps:
 * - Generates Jacobsthal numbers until the number exceeds `n`.
 * - Adds `n` to the list of Jacobsthal numbers.
 * - Creates the order based on the Jacobsthal numbers.
 *
 * The generated order is used in the Ford-Johnson sorting algorithm to determine the sequence of element processing.
 *
 * @param n The number up to which Jacobsthal numbers are generated.
 * @return A vector of integers representing the order based on Jacobsthal numbers.
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
 * @brief Finds the insertion point for a given number in a sorted vector using binary search.
 *
 * This function performs a binary search on a sorted vector to find the appropriate insertion point for the given number `n`.
 * If the number is found in the vector, its index is returned. If the number is not found, the function returns the index
 * where the number should be inserted to maintain the sorted order.
 *
 * @param coll The sorted vector in which to search for the insertion point.
 * @param n The number for which to find the insertion point.
 * @return The index at which the number should be inserted.
 */
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

// // Function to perform binary insertion
// std::vector<int> PmergeMe::binary_insert(const std::vector<int>& coll, int n) {
//     int insert_index = binary_search_insertion_point(coll, n);
//     return insert(coll, n, insert_index);
// }

// Comparison function for std::pair<int, int>
bool compare_pairs(const std::pair<int, int>& a, const std::pair<int, int>& b) {
	return a.first < b.first;
}

/**
 * @brief Sorts a vector of pairs using insertion sort with binary search.
 *
 * This function sorts a vector of pairs using an insertion sort algorithm combined with binary search.
 * It iterates through each pair in the input vector `sorted_pairs` and inserts it into the correct position
 * in the `sorted_pairs_sorted` vector using binary search to find the insertion point.
 *
 * @param sorted_pairs The input vector of pairs to be sorted.
 * @return A new vector of pairs sorted in ascending order.
 */
std::vector<std::pair<int, int> > PmergeMe::sort_pairs(const std::vector<std::pair<int, int> >& sorted_pairs) {
	std::vector<std::pair<int, int> > sorted_pairs_sorted;
	for (size_t i = 0; i < sorted_pairs.size(); ++i) {
		std::vector<std::pair<int, int> >::iterator it = std::lower_bound(
			sorted_pairs_sorted.begin(), sorted_pairs_sorted.end(), sorted_pairs[i], compare_pairs);
		sorted_pairs_sorted.insert(it, sorted_pairs[i]);
	}
	return sorted_pairs_sorted;
}


/**
 * @brief Sorts a vector using a merge-insertion sort algorithm.
 *
 * This function sorts the input vector `coll` using a merge-insertion sort algorithm.
 * It performs the following steps:
 * - If the input vector has fewer than 2 elements, it returns the input vector as it is already sorted.
 * - Pairs adjacent elements and sorts each pair.
 * - Sorts the pairs using the `sort_pairs` function.
 * - Separates the sorted pairs into a main chain and pending elements.
 * - If the input vector has an odd number of elements, the last element is added to the pending elements.
 * - Creates a Jacobsthal order for the pending elements.
 * - Inserts each pending element into the main chain using binary search to find the insertion point.
 *
 * @param coll The input vector to be sorted.
 * @return A new vector sorted in ascending order.
 */
std::vector<int> PmergeMe::merge_insertion_sort(const std::vector<int>& coll) {
	if (coll.size() < 2) return coll;

	std::vector<std::pair<int, int> > first_pairs_sort;
	for (size_t i = 0; i + 1 < coll.size(); i += 2) {
		if (coll[i] < coll[i + 1]) {
			first_pairs_sort.push_back(std::make_pair(coll[i], coll[i + 1]));
		} else {
			first_pairs_sort.push_back(std::make_pair(coll[i + 1], coll[i]));
		}
	}
	std::vector<std::pair<int, int> > sorted_pairs = sort_pairs(first_pairs_sort);

	std::vector<int> main_chain;
	std::vector<int> pending_elements;
	for (size_t i = 0; i < sorted_pairs.size(); ++i) {
		main_chain.push_back(sorted_pairs[i].first);
		pending_elements.push_back(sorted_pairs[i].second);
	}
	if (coll.size() % 2 != 0) {
		pending_elements.push_back(coll.back());
	}
	std::vector<int> a_positions(main_chain.size());
	for (size_t i = 0; i < a_positions.size(); ++i) {
		a_positions[i] = i;
	}
	std::vector<int> result = main_chain;
	std::vector<int> order = create_jacob_order(pending_elements.size());
	for (size_t i = 0; i < order.size(); ++i) {
		int b_index = order[i];
		int item = pending_elements[b_index];
		int insert_index = binary_search_insertion_point(result, item);
		result = insert(result, item, insert_index);
	}
	return result;
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

