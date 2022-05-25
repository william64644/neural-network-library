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
	vector<vector<float>> BC = dpkg("data/weights/BC");
	vector<vector<float>> A = dpkg("data/neurons/A");
	vector<vector<float>> B = dpkg("data/neurons/B");
	vector<vector<float>> C = dpkg("data/neurons/C");
	data_randomizer(C);
	print_data(A[0]);
	cout << '\n';
	B[0] = multiply_vector_by_matrix(A[0], AB);
	C[0] = multiply_vector_by_matrix(B[0], BC);

	print_data(B[0]);
	cout << '\n';
	print_data(C[0]);

	repack(A, "data/neurons/A");
	repack(B, "data/neurons/B");
	repack(C, "data/neurons/C");
	repack(AB, "data/weights/AB");
	return 0;
} //