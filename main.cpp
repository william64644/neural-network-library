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
	data_randomizer(A);
	B[0] = multiply_vector_by_matrix(A[0], AB);

	print_data(B[0]);

	repack(B, "data/neurons/B");
	repack(A, "data/neurons/A");
	repack(AB, "data/weights/AB");
	return 0;
}