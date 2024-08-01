#include "PmergeMe.hpp"

int main(int argc, char **argv) {

	PmergeMe pmm;

	if (argc < 2) {
		std::cerr << "Usage: ./pmm some positive integers" << std::endl;
		return 1;
	}
	try {

		pmm.validation(argv);
		std::cout << "Before: ";
		pmm.printVector(pmm.getUnorderedVector());

		clock_t start = clock();
		pmm.create_pair();
		pmm.processPairs();
		std::vector<int> jacob = pmm.generateJacobSequence(pmm.getPendChainVector());
		pmm.merge_items(pmm.getPendChainVector(), jacob ,pmm.getMainChainVector());

		std::cout << std::endl << "after: ";
		pmm.printVector(pmm.getMainChainVector());

		clock_t end = clock();
		double elapsed_time =  1000.0 * (end - start) / CLOCKS_PER_SEC;
		std::cout << std::endl << "Time to process a range of "<< pmm.getMainChainVector().size() << " elements with std::[vector] : " << elapsed_time << " us" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}


	return 0;
}

