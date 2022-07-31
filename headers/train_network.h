#pragma once

#include "Network.h"
#include "ramdomly_variate_network_weights.h"
#include "get_network_total_error.h"

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
		cache_network.run_network();
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