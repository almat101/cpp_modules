#include <fstream>
#include <iostream>
#include <string>

std::string ft_replace(const std::string &str, const std::string &oldStr, const std::string &newStr,int &count)
{
	std::string result = str;
	size_t pos = 0;
	count = 0;
	while ((pos = result.find(oldStr, pos)) != std::string::npos)
	{
		result.erase(pos, oldStr.length());
		result.insert(pos, newStr);
		pos += newStr.length();
		count++;
	}
	return result;
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Error! Wrongs args!" << '\n';
		std::cerr << "argv[1] file path\nargv[2] line to be replaced\nargv[3] line that replace\n";
		return 1;
	}
	else
	{
		std::string inputFilePath = argv[1];
		std::string s1 = argv[2];
		std::string s2 = argv[3];
		std::string outputFilePath = inputFilePath + ".replace";

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
		int totalReplacements = 0;
		int replacements = 0;
		while (getline(inputFile, line))
		{
			outputFile << ft_replace(line, s1, s2, replacements) << '\n';
			totalReplacements += replacements;
		}

		inputFile.close();
		outputFile.close();

		if (totalReplacements == 0)
		{
			std::cerr << "No replacements were made!" << '\n';
			return 1;
		}
		else
			std::cout << "File copied with "<< totalReplacements << " replacements!\n";
	}
	return 0;
}
