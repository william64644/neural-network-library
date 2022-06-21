#pragma once

#include <vector>
#include <sstream>
#include <chrono>

#include "variate.h"

using namespace std;

void variate_matrix(vector<vector<double>> &data, int max_variation = 10)
{
    srand(std::chrono::system_clock::now().time_since_epoch().count());
    for (unsigned int i = 0; i < data.size(); i++)
    {
        for (unsigned int j = 0; j < data[i].size(); j++)
        {
		data[i][j] = variate(data[i][j], max_variation);
        }
    }
}
