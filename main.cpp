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
	Layer input(2, 8, "Input", {"Temperature", "Pressure"});
	Layer hidden1(8, 1, "Hidden1");
	Layer hidden2(8, 1, "Hidden2");
	Layer output(1, 0, "Output", {"Solid", "Liquid", "Gas"});

	Network network({input, hidden1, hidden2, output});

	matrix_randomizer(network.layers[0].weights);
	matrix_randomizer(network.layers[1].weights);
	
	vector<vector<vector<double>>> labeled_in_out = {
			{{0.1,0.1},{0.50}},
			{{1,0.1},{0.1}},
			{{0.1,1},{1}},
			{{1,1},{0.50}}
		};

	network.run_network();

	// Train
	const double TRAINING_RATE = 0.01;
	const double TRAIN_ITERATIONS = 1;

	// Train
	Network trained_network = get_funneled_trained_network(network, labeled_in_out, 30, 30000);
		
	while (true)
	{
		vector<double> game_input = ask_network_input_from_user(2);
		trained_network.layers[0].neurons = game_input;
		trained_network.run_network();
		trained_network.print_network();
	}
	return 0;
}
// ssssssssssssssssssssssss