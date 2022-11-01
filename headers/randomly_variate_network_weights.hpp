#pragma once

#include "Network.hpp"
#include "mutate_matrix.hpp"

void randomly_variate_network_weights(Network &network, double variation, int mutation_chance = 100, bool allow_negative = false)
{
	for (unsigned int layer = 0; layer < network.layers.size(); layer++)
	{
		mutate_matrix(network.layers[layer].weights, variation, mutation_chance, allow_negative);
	}
}