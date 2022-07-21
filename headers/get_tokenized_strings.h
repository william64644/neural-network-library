#pragma once

#include <vector>
#include <string>

#include "in.h"
#include "split.h"

std::vector<std::string> get_tokenized_strings(std::string input)
{
	std::vector<std::string> words = split(input);
	
	std::vector<std::string> output;
	
	for (unsigned int i = 0; i < words.size(); i++)
	{
		if (! in(words[i], output))
		{
			output.push_back(words[i]);
		}
	}
	return output;
}