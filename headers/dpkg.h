#pragma once

#include <vector>

#include "read_file.h"
#include "split.h"

using namespace std;

vector<vector<double>> dpkg(string data_file_path)
{
    vector<string> data_lines = read_file(data_file_path);                               // get string lines from file
    vector<vector<double>> output(data_lines.size(), vector<double>(data_lines.size())); // double vectors output
    vector<vector<string>> double_strings(data_lines.size());                            // vectors of words
    for (unsigned short i = 0; i < data_lines.size(); i++)                               // split lines into words
    {
        double_strings[i] = split(data_lines[i]);
    }
    for (unsigned short i1 = 0; i1 < double_strings.size(); i1++)
    {
        for (unsigned short i2 = 0; i2 < double_strings[i1].size(); i2++)
        {
            double num = stod(double_strings[i1][i2]);
            output[i1][i2] = num;
        }
        output[i1].erase(output[i1].begin() + static_cast<long int>(double_strings[i1].size()), output[i1].end()); // delete unsused spaces
    }
    return output;
}