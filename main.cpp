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
	return 15 * pow(input, 3);
}

Network funneled_train(Network &network, vector<vector<vector<double>>> &in_out_settings)
{
	Network funneled_network = network;
	
	cout << "traingn network ..." << '\n';
	cout << "phase 1 - ";
	funneled_network = train(funneled_network, get_range(20), in_out_settings);
	cout << "error: " << funneled_network.error << '\n';
	cout << "phase 2 - ";
	funneled_network = train(funneled_network, get_range(19), in_out_settings);
	cout << "error: " << funneled_network.error << '\n';
	cout << "phase 3 - ";
	funneled_network = train(funneled_network, get_range(18), in_out_settings);
	cout << "error: " << funneled_network.error << '\n';
	cout << "phase 4 - ";
	funneled_network = train(funneled_network, get_range(17), in_out_settings);
	cout << "error: " << funneled_network.error << '\n';
	cout << "phase 5 - ";
	funneled_network = train(funneled_network, get_range(16), in_out_settings);
	cout << "error: " << funneled_network.error << '\n';
	cout << "phase 6 - ";
	funneled_network = train(funneled_network, get_range(15), in_out_settings);
	cout << "error: " << funneled_network.error << '\n';
	cout << "phase 7 - ";
	funneled_network = train(funneled_network, get_range(14), in_out_settings);
	cout << "error: " << funneled_network.error << '\n';
	cout << "phase 8 - ";
	funneled_network = train(funneled_network, get_range(13), in_out_settings);
	cout << "error: " << funneled_network.error << '\n';
	cout << "phase 9 - ";
	funneled_network = train(funneled_network, get_range(12), in_out_settings);
	cout << "error: " << funneled_network.error << '\n';
	cout << "phase 5 - ";
	funneled_network = train(funneled_network, get_range(11), in_out_settings);
	cout << "error: " << funneled_network.error << '\n';
	cout << "phase 11 - ";
	funneled_network = train(funneled_network, get_range(10), in_out_settings);
	cout << "error: " << funneled_network.error << '\n';
	cout << "phase 12 - ";
	funneled_network = train(funneled_network, get_range(9), in_out_settings);
	cout << "error: " << funneled_network.error << '\n';
	cout << "phase 13 - ";
	funneled_network = train(funneled_network, get_range(8), in_out_settings);
	cout << "error: " << funneled_network.error << '\n';
	cout << "phase 14 - ";
	funneled_network = train(funneled_network, get_range(7), in_out_settings);
	cout << "error: " << funneled_network.error << '\n';
	cout << "phase 15 - ";
	funneled_network = train(funneled_network, get_range(6), in_out_settings);
	cout << "error: " << funneled_network.error << '\n';
	cout << "phase 16 - ";
	funneled_network = train(funneled_network, get_range(5), in_out_settings);
	cout << "error: " << funneled_network.error << '\n';
	cout << "phase 17 - ";
	funneled_network = train(funneled_network, get_range(4), in_out_settings);
	cout << "error: " << funneled_network.error << '\n';
	cout << "phase 18 - ";
	funneled_network = train(funneled_network, get_range(3), in_out_settings);
	cout << "error: " << funneled_network.error << '\n';
	cout << "phase 19 - ";
	funneled_network = train(funneled_network, get_range(2), in_out_settings);
	cout << "error: " << funneled_network.error << '\n';
	cout << "phase 20 - ";
	funneled_network = train(funneled_network, get_range(1), in_out_settings);
	cout << "error: " << funneled_network.error << '\n';
	
	return funneled_network;
}



int main()
{
	vector<vector<vector<double>>> in_out_settings = {{{1, 0, 0}, {0, 1, 0}}, {{0, 1, 0}, {0, 0, 1}}, {{0, 0, 1}, {1, 0, 0}}};

	// setup
	Layer input(3, 3, "Input");
	Layer output(3, 0, "Output");

	Network network({input, output});

	// configure
	matrix_randomizer(network.layers[0].weights);
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
