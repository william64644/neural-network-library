#pragma once

#include <vector>

using namespace std;

vector<vector<int>> get_int_matrix_from_double_matrix(vector<vector<double>> double_matrix)
{

	vector<vector<int>> int_matrix(double_matrix.size(), vector<int>(double_matrix[0].size()));
	
	for (int y = 0; y < double_matrix.size(); y ++)
	{
		for (int x = 0; x < double_matrix[y].size(); x ++)
		{
			double_matrix[x][y] = double_matrix[x][y] * 1000; // scale up matrix data
			int_matrix[x][y] = static_cast<int> (double_matrix[x][y]);
		}
	}
	
	return int_matrix;
}
