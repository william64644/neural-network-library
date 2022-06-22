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
#include "headers/read_file.h"
#include "headers/variate.h"
#include "headers/variate_matrix.h"
#include "headers/print_matrix.h"
#include "headers/print_data.h"
//ssssssss
using namespace std;

void write_samples()
{
	vector<vector<vector<double>>> in_out_settings = {{{1, 0, 0}, {0, 1, 0}}, {{0, 1, 0}, {0, 0, 1}}, {{0, 0, 1}, {1, 0, 0}}};

	const string input_options[3] = {"Rock", "Paper", "Scissors"};

	// setup
	Layer input(3, 4, "Input", {"Input_Rock", "Input_Paper", "Input_Scissors"});
	Layer hidden(4, 3, "Hidden", {"Hidden_Rock", "Hidden_Paper", "Hidden_Scissors"});
	Layer output(3, 0, "Output", {"Output_Rock", "Output_Paper", "Output_Scissors"});
	Network network({input, hidden, output});

	for (unsigned int i = 0; i < 100; i++)
	{
		string parent_path = "./networks/" + to_string(i) + "/";
		mkdir(parent_path.c_str(), 0777);
		matrix_randomizer(network.layers[0].weights);
		matrix_randomizer(network.layers[1].weights);
		for (unsigned int current_option = 0; current_option < 3; current_option++)
		{
			// config
			network.layers[0].neurons = in_out_settings[current_option][0];
			network.expected_output = in_out_settings[current_option][1];

			// calculate
			network.parse_network();

			// write
			string current_path = parent_path + input_options[current_option] + "/";
			mkdir(current_path.c_str(), 0777);
			repack_network(network, current_path);
		}
	}
}

void test_error()
{
	double total_network_error = 0;
	const string input_options[3] = {"Rock", "Paper", "Scissors"};
	double best_network_error = 100;
	string best_network_path = "";
	double value_being_tested;
	for (unsigned int folder = 0; folder < 100; folder++)
	{
		string parent_path = "./networks/" + to_string(folder) + "/";
		for (unsigned int option = 0; option < 3; option++)
		{
			string current_path = parent_path + input_options[option] + "/";

			value_being_tested += stod(read_file(current_path + "network_error.txt")[0]);
		}
		if (value_being_tested < best_network_error)
		{
			best_network_error = value_being_tested;
			best_network_path = parent_path;
		}
		value_being_tested = 0;

	}

	cout << "Best network error: " << best_network_error << endl;
	cout << "Best network path: " << best_network_path << endl;
}

void test_network(Network &network, vector<vector<vector<double>>> in_out_settings)
{

}

int main()
{
	vector<vector<vector<double>>> in_out_settings = {{{1, 0, 0}, {0, 1, 0}}, {{0, 1, 0}, {0, 0, 1}}, {{0, 0, 1}, {1, 0, 0}}};

	const string input_names[3] = {"Rock", "Paper", "Scissors"};

	// setup
	Layer input(3, 3, "Input", {"Input_Rock", "Input_Paper", "Input_Scissors"});
	Layer output(3, 0, "Output", {"Output_Rock", "Output_Paper", "Output_Scissors"});
	
	Network network({input, output});
	
	// configuration
	network.layers[0].neurons = in_out_settings[0][0];
	network.expected_output = in_out_settings[0][1];
	
	vector<vector<double>> best_weights;
	
	// run
	int smallest_error = 3;
	
	for (unsigned int i = 0; i < 100; i++)
	{
		matrix_randomizer(network.layers[0].weights);
		network.parse_network();
		
		if (network.error < smallest_error)
		{
			smallest_error = network.error;
			best_weights = network.layers[0].weights;
		}
	}

	print_matrix(best_weights);


	return 0;
}
