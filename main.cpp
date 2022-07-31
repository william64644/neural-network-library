#include <iostream>
#include <vector>
#include <stdlib.h>
//#include <SFML/Graphics.hpp>
#include <cmath>

#include "headers/global.h"

// ssssssssssssssssssssss
// output.shrink_to_fit();

using namespace std;

int main()
{
	// Create network
	Layer input(3, 3, "Input", {"Rock", "Paper", "Scisors"});
	Layer output(3, 0, "Output", {"Rock", "Paper", "Scisors"});

	Network network({input, output});

	matrix_randomizer(network.layers[0].weights);
	
	vector<vector<vector<double>>> labeled_in_out = {{{0,0,1},{1,0,0}},{{0,1,0},{0,0,1}},{{1,0,0},{0,1,0}}};

	// Train
	const double TRAINING_RATE = 0.01;
	const double TRAIN_ITERATIONS = 100;
	for (int train_iteration = 0; train_iteration < TRAIN_ITERATIONS; train_iteration ++)
	{
		// Loops through labeled examples from labeled_in_out
		for (int training_example = 0; training_example < labeled_in_out.size(); training_example ++)
		{
			// Set network inputs outputs
			network.layers[0].neurons = labeled_in_out[training_example][0];
			network.expected_output = labeled_in_out[training_example][1];

			// Calculate
			network.run_network();

			// Print
			network.print_network();
		}
	}

	return 0;
}
// ssssssssssssssss