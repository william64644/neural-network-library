#pragma once

#include <vector>
#include <iostream>

using namespace std;

void print_matrix(vector<vector<double>> matrix)
{
    for (unsigned int i = 0; i < matrix.size(); i++)
    {
        print_vector(matrix[i]);
    }
    cout << '\n';
}
