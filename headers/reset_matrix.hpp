#pragma once

#include <vector>

using namespace std;

void reset_matrix(vector<vector<double>> &matrix)
{
    for (unsigned int i = 0; i < matrix.size(); i++)
    {
        for (unsigned int j = 0; j < matrix[i].size(); j++)
        {
            matrix[i][j] = 0;
        }
    }
}