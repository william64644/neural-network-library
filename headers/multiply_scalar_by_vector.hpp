#pragma once

#include <vector>

using namespace std;

vector<double> multiply_scalar_by_vector(vector<double> vec, double scalar)
{
    vector<double> result;
    for (unsigned int i = 0; i < vec.size(); i++)
    {
        result.push_back(vec[i] * scalar);
    }
    return result;
}