#pragma once

#include "Network.hpp"
#include "variate_matrix.hpp"

void randomly_variate_network_weights(Network &network, double variation, int mutation_chance = 100)
{
	for (unsigned int layer = 0; layer < network.layers.size(); layer++)
	{
		variate_matrix(network.layers[layer].weights, variation, mutation_chance);
	}
}