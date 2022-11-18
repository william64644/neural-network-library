#pragma once

#include <vector>
#include <cmath>

using namespace std;

double vector_numeric_difference(vector<double> &list1, vector<double> &list2)
{
    const int LISTS_LENGHT = list1.size();
    double difference = 0;
    for (int i = 0; i < LISTS_LENGHT; i++)
    {
        difference += abs(list1[i] - list2[i]);
    }
    return difference;
}
