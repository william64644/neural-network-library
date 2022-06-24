#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include <sys/stat.h>
#include <cmath>

#include "headers/Layer.h"
#include "headers/print_layer_data.h"
#include "headers/layer_parser.h"
#include "headers/matrix_randomizer.h"
#include "headers/Network.h"
#include "headers/vector_packager.h"
#include "headers/absolute_difference.h"
#include "headers/double_packager.h"
#include "headers/repack_network.h"
#include "headers/read_file.h"
#include "headers/variate.h"
#include "headers/variate_matrix.h"
#include "headers/print_matrix.h"
#include "headers/print_data.h"
#include "headers/split.h"
// ssssssssssss
using namespace std;

double test_network(Network network, vector<vector<vector<double>>> &in_out_settings)
{
	double total_error;
	for (unsigned int test_set = 0; test_set < in_out_settings.size(); test_set++)
	{
		network.layers[0].neurons = in_out_settings[test_set][0];
		network.expected_output = in_out_settings[test_set][1];

		network.parse_network();

		total_error += network.error;
	}
	return total_error;
}

void variate_network(Network &network, int variation)
{
	for (unsigned int layer = 0; layer < network.layers.size(); layer++)
	{
		variate_matrix(network.layers[layer].weights, variation);
	}
}

Network train(Network &network, int variation, vector<vector<vector<double>>> in_out_settings, int iterations = 1000)
{
	Network best_network = network;
	Network cache_network = network;

	double best_error;

	if (network.error == 0)
	{
		best_error = network.layers.back().neurons.size() + network.layers[0].neurons.size();
	}
	else
	{
		best_error = network.error;
	}

	double current_error = best_error;

	for (unsigned int iteration = 0; iteration < iterations; iteration++)
	{
		variate_network(cache_network, variation);
		cache_network.parse_network();
		current_error = test_network(cache_network, in_out_settings);

		if (current_error < best_error)
		{
			best_error = current_error;
			best_network = cache_network;
		}
		else
		{
			cache_network = best_network;
		}
	}
	best_network.error = best_error;
	return best_network;
}

vector<double> get_input(int numbers_ammount)
{
	vector<double> nums;
	cout << "Type " << numbers_ammount << " numbers" << '\n';
	for (unsigned int i = 0; i < numbers_ammount; i++)
	{
		cout << "Number " << i << ": ";
		string num;
		cin >> num;
		nums.push_back(stod(num));
	}
	return nums;
}

// change this to get_variation_scope()
double get_range(int input)
{
	// this equation was optimized for 20 divisions
	return 15 * pow(input, 3);
}

Network funneled_train(Network &network, vector<vector<vector<double>>> &in_out_settings, int divisions = 20)
{
	Network funneled_network = network;
	
	cout << "traingn network ..." << '\n';
	
	for (unsigned int i = 0; i < divisions; i++)
	{
	cout << "phase " << i + 1 << " - ";
	funneled_network = train(funneled_network, get_range(divisions - i), in_out_settings);
	cout << "Error: " << funneled_network.error << '\n';
	}
	
	return funneled_network;
}



int main()
{
	vector<vector<vector<double>>> in_out_settings = {{{1, 0, 0}, {0, 1, 0}}, {{0, 1, 0}, {0, 0, 1}}, {{0, 0, 1}, {1, 0, 0}}};

	// setup
	Layer input(3, 4, "Input");
	Layer hidden1(4, 4, "Hidden1");
	Layer hidden2(4, 3, "Hidden2");
	Layer output(3, 0, "Output");

	Network network({input, hidden1, hidden2, output});

	// configure
	matrix_randomizer(network.layers[0].weights);
	matrix_randomizer(network.layers[1].weights);
	matrix_randomizer(network.layers[2].weights);
	network.parse_network();
	
	// train
	Network trained_network = funneled_train(network, in_out_settings);

	// runtime
	cout << "Training phase complete, the network error is "
		 << test_network(trained_network, in_out_settings) << '\n'
		 << '\n';

	repack_network(trained_network, "data/trained_");
	while (true)
	{
		vector<double> game_input = get_input(3);

		trained_network.layers[0].neurons = game_input;

		trained_network.parse_network();

		trained_network.print_network();
	}

	return 0;
}
// sssssssssssssssssssssssssssssss
