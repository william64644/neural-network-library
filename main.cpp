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

// ssssssssssssssss

using namespace std;

int main()
{

	// Create network
	Layer input(3, 3, "Input", {"Rock", "Paper", "Scissor"});
	Layer hidden1(4, 4, "Hidden 1");
	Layer hidden2(4, 3, "Hidden 2");
	Layer output(3, 0, "Output", {"Rock", "Paper", "Scissor"});

	vector<vector<vector<double>>> labeled_in_out = {{{1,0,0},{0,1,0}},{{0,1,0},{0,0,1}},{{0,0,1},{1,0,0}}};

	Network network({input, hidden1, hidden2, output}, labeled_in_out);

	Population pop(network, 100);

	pop.do_genetic_train(1000, 5, 50);

	Network trained_net = pop.best_net;

	trained_net.printed_test();

	//vector_packager(pop.error_history, "mutations_experiment/10.txt", true);

	return 0;
}
// sssssssssssssssss

// TODO: Functions refactor
	// Revise the name of all functions
	// Revise the implementation of all functions

// TODO: Update README.md

// TODO: Use Cmake intead of a custom bash script

// TODO: selectable activation function using a map of string to function pointer, reff at: https://stackoverflow.com/questions/1952175/how-can-i-call-a-function-using-a-function-pointer
