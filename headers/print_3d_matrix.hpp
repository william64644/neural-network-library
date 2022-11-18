#pragma once

#include <vector>
#include <iostream>
#include "print_matrix.hpp"

using namespace std;

void print_3d_matrix(vector<vector<vector<double>>> &matrix3d)
{
    for (int i = 0; i < matrix3d.size(); i++)
    {
        print_matrix(matrix3d[i]);
    }

    cout << "\n\n";
}