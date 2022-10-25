#pragma once

#include <vector>
#include <cmath>

using namespace std;

double absolute_difference(vector<double> list1, vector<double> list2)
{
    double difference = 0;
    for (unsigned int i = 0; i < values.size(); i++)
    {
        difference += abs(list1[i] - list2[i]);
    }
    return difference;
}
