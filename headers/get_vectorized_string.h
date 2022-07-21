#pragma once

#include <vector>
#include <string>

std::vector<double> get_vectorized_string(std::vector<std::string> tokens, std::vector<std::string> input)
{
	std::vector<double> output(tokens.size());
	
	for (unsigned int i = 0; i < tokens.size(); i++)
	{
		for (unsigned int j = 0; j < input.size(); j++)
		{
			if (input[j] == tokens[i])
			{
				output[i] ++;
			}
		}
	}
	return output;
}