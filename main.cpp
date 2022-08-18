#include <iostream>
#include <vector>
#include <stdlib.h>
//#include <SFML/Graphics.hpp>
#include <cmath>
#include "headers/global.h"
#include "headers/repack_network.h"
#include "headers/print_matrix.h"
#include "headers/print_vector.h"
#include "headers/repack_pgm.h"
#include "headers/dpkg.h"

// ssssssssssssssssssssss
// output.shrink_to_fit();

using namespace std;

int main()
{
/*
	// Create network
	Layer input(3, 3, "Input", {"Rock", "Paper", "Scissor"});
	Layer output(3, 0, "Output", {"Rock", "Paper", "Scissor"});

	Network network({input, output});

	matrix_randomizer(network.layers[0].weights);

	vector<vector<vector<double>>> labeled_in_out = {{{1,0,0},{0,1,0}},{{0,1,0},{0,0,1}},{{0,0,1},{1,0,0}}};

	repack_network(network, "networks/untrained_");
//
	//print_vector(labeled_in_out[0][0]);
	// Train
	
	//network.run_network();s
	
	Network trained_network = get_funneled_trained_network(network, labeled_in_out, 20, 40000);
	
	repack_network(trained_network, "networks/trained_");
	
	trained_network.run_network();
	trained_network.print_network();
	
	// Looping through labeled in/outs
	for (int labeled_in_out_indice = 0; labeled_in_out_indice < labeled_in_out.size(); labeled_in_out_indice ++)
	{
		trained_network.expected_output = labeled_in_out[labeled_in_out_indice][1];
		
		vector<double> game_input = ask_network_input_from_user(3);
		trained_network.layers[0].neurons = game_input;
		trained_network.run_network();
		trained_network.print_network();
	}

	// Runtimes
*/	

	vector<vector<double>> double_matrix = dpkg("networks/trained_Input_weights.txt");
	
	repack_pgm(double_matrix, "img.pgm");
	
	return 0;
}
// sssssssssssssssssssssssssssss
