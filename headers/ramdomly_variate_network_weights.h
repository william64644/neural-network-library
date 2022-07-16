#pragma once

#include "Network.h"
#include "variate_matrix.h"

void ramdomly_variate_network_weights(Network &network, int variation)
{
	for (unsigned int layer = 0; layer < network.layers.size(); layer++)
	{
		variate_matrix(network.layers[layer].weights, variation);
	}
}