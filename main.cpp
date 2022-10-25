#include <iostream>
#include <vector>
#include <stdlib.h>
//#include <SFML/Graphics.hpppp>
#include <cmath>
#include "headers/global.hpp"
#include "headers/repack_network.hpp"
#include "headers/print_matrix.hpp"
#include "headers/print_vector.hpp"
#include "headers/repack_pgm.hpp"
#include "headers/dpkg.hpp"
#include "headers/Population.hpp"
#include "headers/vector_packager.hpp"


// ssssssssssssssssssssssss
// output.shrink_to_fit();

using namespace std;

int main()
{

	// Create network
	Layer input(3, 3, "Input", {"Rock", "Paper", "Scissor"});
	Layer hidden1(3, 3);
	Layer hidden2(3, 3);
	Layer output(3, 0, "Output", {"Rock", "Paper", "Scissor"});

	vector<vector<vector<double>>> labeled_in_out = {{{1,0,0},{0,1,0}},{{0,1,0},{0,0,1}},{{0,0,1},{1,0,0}}};

	Network network({input, output}, labeled_in_out);

	Population pop(network, 100);


	pop.multi_run(10000, 5, 20);

	pop.best.print_network();

	vector_packager(pop.error_history, "error_history.txt");

	return 0;
}
// sssssssssssssssssss

// TODO: Functions refactor
	// Revise the name of all functions
	// Revise the implementation of all functions

// TODO: Update README.md

// TODO: Use Cmake intead of a custom bash script
