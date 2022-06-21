#pragma once

#include <vector>
#include <sstream>
#include <chrono>

using namespace std;

void matrix_randomizer(vector<vector<double>> &data)
{
    srand(std::chrono::system_clock::now().time_since_epoch().count());
    for (long unsigned int i = 0; i < data.size(); i++)
    {
        for (long unsigned int j = 0; j < data[i].size(); j++)
        {
            data[i][j] = (rand() % 100) / 100.0;
        }
    }
}