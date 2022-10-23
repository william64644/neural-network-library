#pragma once

#include <vector>

using namespace std;

void reset_vector(vector<double> &vec)
{
    fill(vec.begin(), vec.end(), 0);
}