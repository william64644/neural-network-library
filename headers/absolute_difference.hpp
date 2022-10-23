#pragma once

#include <vector>
#include <cmath>

using namespace std;

double absolute_difference(vector<double> test_set, vector<double> values)
{
    double difference = 0;
    for (unsigned int i = 0; i < values.size(); i++)
    {
        difference += abs(test_set[i] - values[i]);
    }
    return difference;
}