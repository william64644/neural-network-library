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
//#include "tests/unit/test_activators.hpp"

// ssssssssssssss

using namespace std;

int main()
{

	// Create network
	Layer input(2, 5, "Input");
	Layer hidden1(5, 4, "Hidden 1");
	Layer hidden2(4, 5, "Hidden 2");
	Layer hidden3(5, 1, "Hidden 3");
	Layer output(1, 0, "Output");

	vector<vector<vector<double>>> labeled_in_out;
	
	vector<vector<double>> outer_spots = dpkg("circle_data_outer.txt");
	vector<vector<double>> inner_spots = dpkg("circle_data_inner.txt");
	
	for (int i = 0; i < outer_spots.size(); i++)
	{
		labeled_in_out.push_back({outer_spots[i], {0.0}});
		labeled_in_out.push_back({inner_spots[i], {1.0}});
	}
	

	Network network({input, hidden1, hidden2, hidden3, output}, labeled_in_out);

	Population pop(network, 100);

	pop.do_genetic_train(100, 5, 10);

	Network trained_net = pop.best_net;
	
	randomly_variate_network_weights(trained_net, 5);

	trained_net.printed_test();


	return 0;
}




// sssssssssssssssssssssssss

// TODO: Functions refactor
// Revise the name of all functions
// Revise the implementation of all functions

// TODO: Update README.md

// TODO: Use Cmake instead of a custom bash script

// TODO: selectable activation function using a map of string to function pointer, ref at: https://stackoverflow.com/questions/1952175/how-can-i-call-a-function-using-a-function-pointer
