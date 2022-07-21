#pragma once

#include <vector>
#include <algorithm>

#include "is_largest.h"
#include "colors.h"

using namespace std;

void print_vector(vector<double> vec)
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

void print_vector(vector<int> vec)
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

void print_vector(vector<string> vec)
{
    for (unsigned int i1 = 0; i1 < vec.size(); i1++)
    {
        if (vec[i1] != ""){
            cout << vec[i1] << '\n';
        }
        
    }
    cout << '\n';
}