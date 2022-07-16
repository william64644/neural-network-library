#pragma once

#include "Network.h"

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