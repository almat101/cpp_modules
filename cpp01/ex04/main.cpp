#include <fstream>
#include <iostream>
#include <string>

std::string ft_replace(const std::string &str, const std::string &oldStr, const std::string &newStr, int &numReplacements)
{
	std::string result = str;
	size_t pos = 0;
	while ((pos = result.find(oldStr, pos)) != std::string::npos)
	{
		result.erase(pos, oldStr.length());
		result.insert(pos, newStr);
		pos += newStr.length();
		numReplacements++;
	}
	return result;
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Error! Wrongs args!" << '\n';
		std::cerr << "Usage:\nargv[1] file path\nargv[2] line to be replaced\nargv[3] line that replace\n";
		return 1;
	}
	else
	{
		std::string inputFilePath = argv[1];
		std::string s1 = argv[2];
		std::string s2 = argv[3];
		std::string outputFilePath = inputFilePath + ".replace";

		if (s1.empty() || s2.empty())
		{
			std::cerr << "Ehehehe don't type empty string" << '\n';
			return 1;
		}
		std::ifstream inputFile(inputFilePath.c_str());

		if (!inputFile)
		{
			std::cerr << "Error on file input" << '\n';
			return 1;
		}

		std::ofstream outputFile(outputFilePath.c_str());

		if (!outputFile)
		{
			std::cerr << "Error on file output" << '\n';
			return 1;
		}

		std::string line;
		int replacements = 0;
		while (getline(inputFile, line))
		{
			outputFile << ft_replace(line, s1, s2, replacements) << '\n';
		}
		inputFile.close();
		outputFile.close();

		if (replacements == 0)
		{
			std::cerr << "No replacements were made!" << '\n';
			return 1;
		}
		else
			std::cout << "File copied in " << outputFilePath << " with " << replacements << " replacements!\n";
	}
	return 0;
}
