#pragma once

/*
bool in(char input, string dataset)
{
	for (unsigned int i = 0; i < dataset.length(); i++)
	{
		if (input == dataset[i])
		{
			return true;
		}
		return false;
	}
}
*/

bool in(string input, vector<string> dataset)
{
	for (unsigned int i = 0; i < dataset.size(); i++)
	{
		if (input == dataset[i])
		{
			return true;
		}
	}
    return false;
}