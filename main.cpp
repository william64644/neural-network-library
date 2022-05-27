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
	vector<vector<float>> CD = dpkg("data/weights/CD");
	vector<vector<float>> A = dpkg("data/neurons/A");
	vector<vector<float>> B = dpkg("data/neurons/B");
	vector<vector<float>> C = dpkg("data/neurons/C");
	vector<vector<float>> D = dpkg("data/neurons/D");

	Layer A_layer;
	A_layer.neurons = A[0];
	A_layer.weights = AB;

	Layer B_layer;
	B_layer.neurons = B[0];
	B_layer.weights = BC;

	Layer C_layer;
	C_layer.neurons = C[0];
	C_layer.weights = CD;

	Layer D_layer;
	D_layer.neurons = D[0];

	layer_parser(A_layer, B_layer);
	layer_parser(B_layer, C_layer);
	layer_parser(C_layer, D_layer);

	matrix_randomizer(A_layer.weights);
	matrix_randomizer(B_layer.weights);
	matrix_randomizer(C_layer.weights);

	print_data(A_layer.neurons);
	print_data(B_layer.neurons);
	print_data(C_layer.neurons);
	print_data(D_layer.neurons);

	repack(A_layer.weights, "data/weights/AB");
	repack(B_layer.weights, "data/weights/BC");
	repack(C_layer.weights, "data/weights/CD");
	vector_packager(A_layer.neurons, "data/neurons/A");
	vector_packager(B_layer.neurons, "data/neurons/B");
	vector_packager(C_layer.neurons, "data/neurons/C");
	vector_packager(D_layer.neurons, "data/neurons/D");

	return 0;
} // assssssssssssssssssss