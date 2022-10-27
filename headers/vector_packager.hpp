#pragma once

#include <vector>

#include "repack.hpp"

using namespace std;

void vector_packager(vector<double> data, string file_name, bool append_mode = false)
{
    vector<vector<double>> matrix(1);
    matrix[0] = data;
    repack(matrix, file_name, append_mode);
}