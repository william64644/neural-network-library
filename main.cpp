#include <iostream>
#include <vector>
#include <stdlib.h>
//#include <SFML/Graphics.hpp>
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
#include "headers/dpkg.h"

// ssssssssssss

using namespace std;

double get_network_total_error(Network network, vector<vector<vector<double>>> &in_out_settings)
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

void ramdomly_variate_network_weights(Network &network, int variation)
{
	for (unsigned int layer = 0; layer < network.layers.size(); layer++)
	{
		variate_matrix(network.layers[layer].weights, variation);
	}
}

void train_network(Network &network, int max_variation, vector<vector<vector<double>>> in_out_settings, int iterations = 20000)
{
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
		ramdomly_variate_network_weights(cache_network, max_variation);
		cache_network.parse_network();
		current_error = get_network_total_error(cache_network, in_out_settings);

		if (current_error < best_error)
		{
			best_error = current_error;
			network = cache_network;
		}
		else
		{
			cache_network = network;
		}
	}

	network.error = best_error;
}

vector<double> ask_network_input_from_user(int numbers_ammount)
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

double get_variation_scope(int current_training_phase)
{
	// this equation was optimized for 20 training phases
	return 15 * pow(current_training_phase, 3);
}

Network get_funneled_trained_network(Network &network, vector<vector<vector<double>>> &in_out_settings, int phases = 20)
{
	cout << "traingn network ..." << '\n';

	for (unsigned int i = 0; i < phases; i++)
	{
		cout << "phase " << i + 1 << " - ";
		train_network(network, get_variation_scope(phases - i), in_out_settings);
		cout << "Error: " << network.error << '\n';
	}

	return network;
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
	Network trained_network = get_funneled_trained_network(network, in_out_settings);

	// runtime
	cout << "Training phase complete, the network error is "
		 << get_network_total_error(trained_network, in_out_settings) << '\n'
		 << '\n';

	repack_network(trained_network, "data/trained_");
	while (true)
	{
		vector<double> game_input = ask_network_input_from_user(3);

		trained_network.layers[0].neurons = game_input;

		trained_network.parse_network();

		trained_network.print_network();
	}

	return 0;
}
// ssssssss
