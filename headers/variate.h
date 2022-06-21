#pragma once

#include <vector>
#include <sstream>
#include <chrono>

using namespace std;

void variate(vector<vector<double>> &data, int max_variation = 100)
{
    srand(std::chrono::system_clock::now().time_since_epoch().count());
    for (long unsigned int i = 0; i < data.size(); i++)
    {
        for (long unsigned int j = 0; j < data[i].size(); j++)
        {
            data[i][j] += (rand() % (max_variation * 2 + 1)) + max_variation;
            if (data[i][j] < 0) data[i][j] = 0;
        }
    }
}
