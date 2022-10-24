#pragma once

#include "Network.hpp"
#include "variate_matrix.hpp"

void randomly_variate_network_weights(Network &network, double variation)
{
	for (unsigned int layer = 0; layer < network.layers.size(); layer++)
	{
		variate_matrix(network.layers[layer].weights, variation);
	}
}

void randomly_variate_network_weights(Network* network, double variation)
{
	for (unsigned int layer = 0; layer < network->layers.size(); layer++)
	{
		variate_matrix(network->layers[layer].weights, variation);
	}
}