#pragma once

#include <vector>
#include <iostream>

using namespace std;

void print_vector(vector<string> vec)
{
    for (unsigned int i1 = 0; i1 < vec.size(); i1++)
    {
        cout << vec[i1] << '\n';
    }
    cout << '\n';
}