#include "PmergeMe.hpp"

int main(int argc, char **argv) {

	PmergeMe pmm;

	if (argc < 2) {
		std::cerr << "Usage: ./pmm some positive integers" << std::endl;
		return 1;
	}
	try {
		int i = 1;
		pmm.validationVector(argv);
		std::cout << "Before: ";
		pmm.printVector(pmm.getUnorderedVector());
		clock_t start = clock();
		if(pmm.getUnorderedVector().size() == 1)
		{
			std::cout << "After: ";
			std::cout << pmm.getUnorderedVector()[0] << std::endl;
			clock_t end = clock();
			double elapsed_time =   60.0 * (end - start) / CLOCKS_PER_SEC;
			std::cout << "Time to process a range of "<< argc  - 1 << " elements with std::[vector] : " << elapsed_time << " us" << std::endl;
			return 0;
		}
		std::vector<std::pair<int, int> > pairs = pmm.first_step(pmm.getUnorderedVector());
		std::vector<int> sorted = pmm.recursion(pairs, i);
		clock_t end = clock();
		std::cout << "After: ";
		pmm.printVector(sorted);
		double elapsed_time =  60.0 * (end - start) / CLOCKS_PER_SEC;
		std::cout << "Time to process a range of "<< sorted.size() << " elements with std::[vector] : " << elapsed_time << " us" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}

	try {
		int i = 1;
		pmm.validationDeque(argv);
		// std::cout << "Before: ";
		// pmm.printDeque(pmm.getUnorderedDeque());
		clock_t start = clock();
		if(pmm.getUnorderedDeque().size() == 1)
		{
			// std::cout << "After: ";
			// std::cout << pmm.getUnorderedDeque()[0] << std::endl;
			clock_t end = clock();
			double elapsed_time =   60.0 * (end - start) / CLOCKS_PER_SEC;
			std::cout << "Time to process a range of "<< argc  - 1 << " elements with std::[deque] : " << elapsed_time << " us" << std::endl;
			return 0;
		}
		std::deque<std::pair<int, int> > pairs = pmm.first_step_deque(pmm.getUnorderedDeque());
		std::deque<int> sorted_deque = pmm.recursion_deque(pairs, i);
		clock_t end = clock();
		// std::cout << std::endl;
		// std::cout << "After: ";
		// pmm.printDeque(sorted_deque);
		double elapsed_time = 60.0 * (end - start) / CLOCKS_PER_SEC;
		std::cout << "Time to process a range of "<< sorted_deque.size() << " elements with std::[deque] : " << elapsed_time << " us" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}
	return 0;
}
