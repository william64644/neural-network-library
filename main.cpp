#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "headers/file_handler.h"
#include "headers/utils.h"

using namespace std;

int main()
{
	vector<vector<float>> AB = dpkg("data/weights/AB");
	vector<vector<float>> A = dpkg("data/neurons/A");
	vector<vector<float>> B = dpkg("data/neurons/B");

	vector<float> result = calculate_layer(A[0], &B[0], AB);

	print_data(result);

	repack(B, "data/neurons/B");
	repack(A, "data/neurons/A");
	repack(AB, "data/weights/AB");

	return 0;
}