#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "headers/file_handler.h"
#include "headers/utils.h"
#include "headers/core_neural.h"
#include "headers/data_types.h"

using namespace std;

vector<vector<float>> matrix_creator(unsigned int x_size, unsigned int y_size)
{
	return vector<vector<float>>(y_size, vector<float>(x_size));
}

void create_weights()
{
}

void create_neurons(vector<float> neurons_sizes, string neurons_folder)
{
}

void network_architect(vector<int> neurons_sizes, string weights_foler, string neurons_folder)
{
	const int layers_ammount = neurons_sizes.size();
	const char neurons_names[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
	const string weights_names[9] = {"AB", "BC", "CD", "DE", "EF", "FG", "GH", "HI", "IJ"};

	for (unsigned int i = 0; i < layers_ammount; i++)
	{
		unsigned int ammount_of_weights_vectors = neurons_sizes[i];
	}
}

int main()
{

	// vector<Layer> network = network_architect({3, 4, 3});

	return 0;
} // assssssssssssssssssss

/*

neurons = {3, 4, 3}
neurons_ammount = neurons.size()

create A neurons file with 3 floats

create AB weights file with 3 lines and 4 values each

create B weights file with 4 floats

create BC weights file with 4 lines and 3 values each

create C neurons file with 3 floats



create <neurons_ammount> neurons files A B C...
looping <neurons_ammount>
	A neurons file has <neurons[0]> floats
	B neurons file has <neurons[1]> floats
	B neurons file has <neurons[2]> floats



*/