#pragma once

#include <vector>
#include <string>

std::string get_merged_strings(std::vector<std::string> &strings)
{
	std::string output;

	for (unsigned int i = 0; i < strings.size(); i++)
	{
		output += strings[i];
		output += ' ';
	}
	output.resize(output.size() -1);
	return output;
}