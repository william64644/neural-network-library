#pragma once

#include <vector>

#include "get_int_matrix_from_double_matrix.h"
#include "write_pgm.h"

using namespace std;

void repack_pgm(vector<vector<double>> double_matrix, string file_name)
{
	vector<vector<int>> int_matrix = get_int_matrix_from_double_matrix(double_matrix);
	
	write_pgm(int_matrix, file_name);
}
