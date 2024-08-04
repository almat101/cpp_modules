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

// Function to get the pending element order
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

// Function to find the binary search insertion point
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

// Function to insert an element into a vector at a specific index
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
// Function to sort pairs using lower_bound without lambda expressions
std::vector<std::pair<int, int> > PmergeMe::sort_pairs(const std::vector<std::pair<int, int> >& sorted_pairs) {
	std::vector<std::pair<int, int> > sorted_pairs_sorted;
	for (size_t i = 0; i < sorted_pairs.size(); ++i) {
		std::vector<std::pair<int, int> >::iterator it = std::lower_bound(
			sorted_pairs_sorted.begin(), sorted_pairs_sorted.end(), sorted_pairs[i], compare_pairs);
		sorted_pairs_sorted.insert(it, sorted_pairs[i]);
	}
	return sorted_pairs_sorted;
}

// Example usage in the merge_insertion_sort function
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

	// Use the sort_pairs function to sort the pairs
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

