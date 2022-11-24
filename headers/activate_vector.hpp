#pragma once

#include <vector>

#include "activators.hpp"

void  activate_vector(vector<double> &vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		vec[i] = sigmoid(vec[i]);
	}
}