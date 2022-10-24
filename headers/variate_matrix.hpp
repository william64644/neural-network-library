#pragma once

#include <vector>
#include <sstream>
#include <chrono>

#include "variate.hpp"

using namespace std;

void variate_matrix(vector<vector<double>> &data, double max_variation)
{
    //srand(std::chrono::system_clock::now().time_since_epoch().count());
    for (unsigned int i = 0; i < data.size(); i++)
    {
        for (unsigned int j = 0; j < data[i].size(); j++)
        {
            data[i][j] = variate(data[i][j], max_variation);

            if (data[i][j] < 0)
            {
                data[i][j] = 0;
            }
        }
    }
}

