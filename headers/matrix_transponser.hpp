#pragma once

#include <vector>

using namespace std;

vector<vector<double>> matrix_transponser(vector<vector<double>> matrix)
{
    vector<vector<double>> transposed_matrix;
    for (unsigned int i = 0; i < matrix[0].size(); i++)
    {
        vector<double> row;
        for (unsigned int j = 0; j < matrix.size(); j++)
        {
            row.push_back(matrix[j][i]);
        }
        transposed_matrix.push_back(row);
    }
    return transposed_matrix;
}