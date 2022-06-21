#pragma once

#include <vector>

#include "repack.h"

using namespace std;

void double_packager(double data, string file_name)
{
    vector<vector<double>> matrix(1, vector<double>(1, data));
    repack(matrix, file_name);
}