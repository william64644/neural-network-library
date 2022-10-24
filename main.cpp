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


// ssssssssssssssssssssss
// output.shrink_to_fit();

using namespace std;

int main()
{

	// Create network
	Layer input(3, 3, "Input", {"Rock", "Paper", "Scissor"});
	Layer output(3, 0, "Output", {"Rock", "Paper", "Scissor"});

	vector<vector<vector<double>>> labeled_in_out = {{{1,0,0},{0,1,0}},{{0,1,0},{0,0,1}},{{0,0,1},{1,0,0}}};

	Network network({input, output}, labeled_in_out);
	
	Population pop(network, 1000);

	pop.multi_run(1, 0.5);

	pop.best->print_network();
	
	return 0;
}
// ssssssssssssssssssssssssssssssssssssssssssssssssssssssss