#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include <sys/stat.h>

#include "headers/Layer.h"
#include "headers/print_layer_data.h"
#include "headers/layer_parser.h"
#include "headers/matrix_randomizer.h"
#include "headers/Network.h"
#include "headers/vector_packager.h"
#include "headers/absolute_difference.h"
#include "headers/double_packager.h"
#include "headers/repack_network.h"

using namespace std;
// sss

int main()
{
	const double in_out_settings[3][2][3] = {{{1, 0, 0}, {0, 1, 0}}, {{0, 1, 0}, {0, 0, 1}}, {{0, 0, 1}, {1, 0, 0}}};

	const string input_options[3] = {"Rock", "Paper", "Scissors"};

	// setup
	Layer input(3, 3, "Input", {"Input_Rock", "Input_Paper", "Input_Scissors"});
	Layer output(3, 0, "Output", {"Output_Rock", "Output_Paper", "Output_Scissors"});
	Network network({input, output});

	// config
	network.layers[0].neurons = {1, 0, 0};
	network.expected_output = {0, 1, 0};

	// calculate
	matrix_randomizer(network.layers[0].weights);
	network.parse_network();

	// write
	repack_network(network, "./networks/");

	return 0;
}
// sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss
