#pragma once

#include <vector>
#include <string>

using namespace std;

bool is_there(string looking_for, vector<string> analyzing_data)
{
	for (unsigned int current_data_i = 0; current_data_i < analyzing_data.size(); current_data_i++)
	{
		if (looking_for == analyzing_data[current_data_i])
		{
			return true;
		}
	}
    return false;
}

bool is_there(int looking_for, vector<int> analyzing_data)
{
	for (unsigned int current_data_i = 0; current_data_i < analyzing_data.size(); current_data_i++)
	{
		if (looking_for == analyzing_data[current_data_i])
		{
			return true;
		}
	}
    return false;
}

bool is_there(double looking_for, vector<double> analyzing_data)
{
	for (unsigned int current_data_i = 0; current_data_i < analyzing_data.size(); current_data_i++)
	{
		if (looking_for == analyzing_data[current_data_i])
		{
			return true;
		}
	}
    return false;
}