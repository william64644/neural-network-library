#pragma once

#include <vector>

using namespace std;

double average(vector<double> vec)
{
    double sum = 0;
    for (unsigned int i = 0; i < vec.size(); i++)
    {
        sum += vec[i];
    }
    return sum / vec.size();
}
