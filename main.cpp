#include <iostream>
#include <vector>
#include <stdlib.h>
#include <cmath>

#include "headers/repack_network.hpp"
#include "headers/print_matrix.hpp"
#include "headers/print_vector.hpp"
#include "headers/repack_pgm.hpp"
#include "headers/dpkg.hpp"
#include "headers/Population.hpp"
#include "headers/vector_packager.hpp"
#include "headers/write_csv.hpp"
#include "headers/print_3d_matrix.hpp"
//#include "tests/unit/test_activators.hpp"

// ssssssssssssssssss

using namespace std;

int main()
{
	
	// Create network
	Layer input(2, 16, "Input");
	Layer hidden1(16, 16, "Hidden 1");
	Layer hidden2(16, 16, "Hidden 2");
	Layer hidden3(16, 16, "Hidden 3");
	Layer hidden4(16, 1, "Hidden 4");
	Layer output(1, 0, "Output");
	
	vector<vector<vector<double>>> labeled_in_out;
	vector<vector<vector<double>>> labeled_in_out2 = {{{1,0,0},{0,1,0}},{{0,1,0},{0,0,1}},{{0,0,1},{1,0,0}}};
	
	vector<vector<double>> outer_spots = dpkg("triangle_data_up.txt");
	vector<vector<double>> inner_spots = dpkg("triangle_data_down.txt");
	
	for (int i = 0; i < outer_spots.size(); i++)
	{
		labeled_in_out.push_back({outer_spots[i], {1.0}});
		labeled_in_out.push_back({inner_spots[i], {0.0}});
	}
	

	Network network({input, hidden1, hidden2, hidden3, hidden4, output}, labeled_in_out);

	Population pop(network, 100);

	pop.do_genetic_train(200, 2, 90);

	Network trained_net = pop.best_net;
	
	randomly_variate_network_weights(trained_net, 10, 10);

	trained_net.printed_test();

	vector<vector<double>> image(500, vector<double>(500, 0.0));

	
	for (double i = 0; i < 500; i++)
	{
		for (double j = 0; j < 500; j++)
		{
			trained_net.layers[0].neurons = {i / 500.0, j / 500.0};
			trained_net.run_network();
			image[i][j] = trained_net.layers.back().neurons[0] * 100;
		}
	}

	repack_pgm(image, "image.pgm");


	return 0;
}




// ssssssssssssssssssssssssssssss

// TODO: pass by refference whenever possible

// TODO: Functions refactor
// Revise the name of all functions
// Revise the implementation of all functions

// TODO: Update README.md

// TODO: Use Cmake instead of a custom bash script

// TODO: selectable activation function using a map of string to function pointer, ref at: https://stackoverflow.com/questions/1952175/how-can-i-call-a-function-using-a-function-pointer
