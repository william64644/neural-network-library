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

	const string phrase1 = "we carried the cargo one by one";
	const string phrase2 = "we carry cargo from time to time";

	string full_pharese = get_merged_strings({phrase1, phrase2});
	cout << full_pharese;

	vector<string> phrase_vector = split(full_pharese);

	vector<string> tokens = get_tokenized_strings(full_pharese);

	print_vector(get_vectorized_string(tokens, phrase_vector));



	Layer input(tokens.size(), 4, "Input");
	Layer dummy_output(4, 0, "Dummy Output");

	input.neurons = get_vectorized_string(tokens, phrase_vector);

	Network net({input, dummy_output});
	matrix_randomizer(net.layers[0].weights);

	net.parse_network();

	net.print_network();

	return 0;
}
// ssssssssssss