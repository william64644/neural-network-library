#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "headers/file_handler.h"
#include "headers/utils.h"
#include "headers/core_neural.h"

using namespace std;

int main()
{
	vector<vector<float>> AB = dpkg("data/weights/AB");
	vector<vector<float>> BC = dpkg("data/weights/BC");
	vector<vector<float>> A = dpkg("data/neurons/A");
	vector<vector<float>> B = dpkg("data/neurons/B");
	vector<vector<float>> C = dpkg("data/neurons/C");

	Layer A_layer;
	A_layer.neurons = A[0];
	A_layer.weights = AB;

	Layer B_layer;
	B_layer.neurons = B[0];
	B_layer.weights = BC;

	Layer C_layer;
	C_layer.neurons = C[0];

	cout << '\n';

	layer_parser(A_layer, B_layer);
	layer_parser(B_layer, C_layer);
	print_data(B_layer.neurons);
	print_data(C_layer.neurons);

	return 0;
} // assssssssssssssssss