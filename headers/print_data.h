#pragma once

#include <vector>

#include "is_largest.h"
#include "colors.h"

using namespace std;

void print_data(vector<double> vec)
{
    for (unsigned int i = 0; i < vec.size(); i++)
    {
        if (is_largest(vec, i))
        {
            cout << BLUE;
        }
        cout << vec[i] << ' ';
        cout << RESET;
    }
    cout << '\n';
}