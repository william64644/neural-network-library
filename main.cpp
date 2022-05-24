#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "headers/file_handler.h"
#include "headers/utils.h"

using namespace std;

vector<float> calculate_layer(vector<float> A, vector<float> B, vector<vector<float>> AB_weights)
{
	vector<float> result;
	for (int i = 0; i < A.size(); i++)
	{
		float sum = 0;
		for (int j = 0; j < A.size(); j++)
		{
			sum += A[j] * AB_weights[j][i];
		}
		result.push_back(sum);
	}
	return result;
}

int main()
{
	vector<vector<float>> AB = dpkg("data/weights/AB");
	vector<vector<float>> A = dpkg("data/neurons/A");
	vector<vector<float>> B = dpkg("data/neurons/B");

	vector<float> result = calculate_layer(A[0], B[0], AB);

	print_data(result);

	return 0;
} //