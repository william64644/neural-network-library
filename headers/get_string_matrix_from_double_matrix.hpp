#pragma once

#include <vector>
#include <string>

using namespace std;

vector<vector<string>> get_string_matrix_from_double_matrix(vector<vector<double>> &double_matrix)
{
    vector<vector<string>> string_matrix(double_matrix.size(), vector<string>(double_matrix[0].size()));

    for (int i = 0; i < double_matrix.size(); i++)
    {
        for (int j = 0; j < double_matrix[i].size(); j++)
        {
            string_matrix[i][j] = to_string(double_matrix[i][j]);
        }
    }
    return string_matrix;
}