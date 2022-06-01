#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "headers/file_handler.h"
#include "headers/utils.h"
#include "headers/core_neural.h"
#include "headers/data_types.h"

using namespace std;

int main()
{

	const char alphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

	Layer input(3, 4);
	Layer hidden1(4, 4);
	Layer hidden2(4, 4);
	Layer hidden3(4, 3);
	Layer output(3, 0);

	// rock paper scissors
	input.neurons = {3, 0, 0};

	vector<vector<double>> results;

	for (unsigned int i = 0; i < 100000; i++)
	{

		matrix_randomizer(input.weights);
		matrix_randomizer(hidden1.weights);
		matrix_randomizer(hidden2.weights);
		matrix_randomizer(hidden3.weights);
		matrix_randomizer(output.weights);

		layer_parser(input, hidden1);
		layer_parser(hidden1, hidden2);
		layer_parser(hidden2, hidden3);
		layer_parser(hidden3, output);

		results.push_back(output.neurons);
	}
	results = matrix_transponser(results);

	cout << '\n'
		 << average(results[0]);
	cout << '\n'
		 << average(results[1]);
	cout << '\n'
		 << average(results[2]);
	return 0;
}
// sssssssssssssssssss