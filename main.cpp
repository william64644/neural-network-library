#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include "headers/file_handler.h"
#include "headers/utils.h"
#include "headers/core_neural.h"
#include "headers/core_graphics.h"

using namespace std;

double absolute_difference(double test_set[], vector<double> values)
{
	double difference = 0;
	for (unsigned int i = 0; i < values.size(); i++)
	{
		difference += abs(test_set[i] - values[i]);
	}
	return difference;
}

int main()
{

	double test_set[3][3] = {{0.0, 1.0, 0.0}, {0.0, 0.0, 1.0}, {1.0, 0.0, 0.0}};

	Layer input(3, 3);
	Layer output(3, 0);

	/*
		1 0 0
		0 1 0

		0 1 0
		0 0 1

		0 0 1
		1 0 0
	*/

	matrix_randomizer(input.weights);

	// rock paper scissors
	input.neurons = {1, 0, 0};

	layer_parser(input, output);

	cout << '\n';

	cout << "input: " << input.neurons[0] << " " << input.neurons[1] << " " << input.neurons[2] << '\n';
	cout << "output: " << output.neurons[0] << " " << output.neurons[1] << " " << output.neurons[2] << '\n';
	cout << "error: " << absolute_difference(test_set[0], output.neurons) << '\n';

	input.neurons = {0, 1, 0};
	layer_parser(input, output);

	cout << '\n';

	cout << "input: " << input.neurons[0] << " " << input.neurons[1] << " " << input.neurons[2] << '\n';
	cout << "output: " << output.neurons[0] << " " << output.neurons[1] << " " << output.neurons[2] << '\n';
	cout << "error: " << absolute_difference(test_set[1], output.neurons) << '\n';

	input.neurons = {0, 0, 1};
	layer_parser(input, output);

	cout << '\n';

	cout << "input: " << input.neurons[0] << " " << input.neurons[1] << " " << input.neurons[2] << '\n';
	cout << "output: " << output.neurons[0] << " " << output.neurons[1] << " " << output.neurons[2] << '\n';
	cout << "error: " << absolute_difference(test_set[2], output.neurons) << '\n';

	cout << '\n'
		 << "total error: "
		 << absolute_difference(test_set[0], output.neurons) + absolute_difference(test_set[1], output.neurons) + absolute_difference(test_set[2], output.neurons)
		 << '\n';

	//////////////////////////////////////
	// 		   	    Graphics			//
	//////////////////////////////////////

	sf::RenderWindow window(sf::VideoMode(900, 500), "My window");
	window.setFramerateLimit(60);

	// run the program as long as the window is open
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loopp
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::Black);

		// draw everything here...

		window.display();
	}

	return 0;
}
// sssssssssssssssssssssssssssssssss