#pragma once

#include <vector>

#include "write_file.h"

using namespace std;

void repack(vector<vector<double>> data, string output_file)
{
    vector<string> output(data.size());
    for (unsigned int i1 = 0; i1 < data.size(); i1++)
    {
        for (unsigned int i2 = 0; i2 < data[i1].size(); i2++)
        {
            output[i1] = output[i1] + to_string(data[i1][i2]) + ' ';
        }
    }
    write_file(output, output_file);
}