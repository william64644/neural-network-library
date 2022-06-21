#pragma once

#include <vector>
#include <iostream>

using namespace std;

void print_matrix(vector<vector<double>> matrix)
{
    for (unsigned int i = 0; i < matrix.size(); i++)
    {
        for (unsigned int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}