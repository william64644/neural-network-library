#pragma once

#include <vector>

#include "repack.h"

using namespace std;

void vector_packager(vector<double> data, string file_name)
{
    vector<vector<double>> matrix(1);
    matrix[0] = data;
    repack(matrix, file_name);
}