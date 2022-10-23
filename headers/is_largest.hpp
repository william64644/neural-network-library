#pragma once

#include <vector>

using namespace std;

bool is_largest(vector<double> vec, unsigned int indice)
{
    if (vec[indice] == *max_element(vec.begin(), vec.end()))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool is_largest(vector<int> vec, unsigned int indice)
{
    if (vec[indice] == *max_element(vec.begin(), vec.end()))
    {
        return true;
    }
    else
    {
        return false;
    }
}