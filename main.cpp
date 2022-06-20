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

struct Network
{
	vector<Layer> layers;

	Network(vector<Layer> layers)
	{
		this->layers = layers;
	}

	void print_network()
	{
		cout << "================================\n";
		for (unsigned int i = 0; i < layers.size(); i++)
		{
			print_layer_data(layers[i]);
		}
		cout << "================================\n";
	}

	void parse_network()
	{
		for (unsigned int i = 0; i < layers.size() - 1; i++)
		{
			layer_parser(layers[i], layers[i + 1]);
		}
	}
};

int main()
{

	double test_set[3][3] = {{0.0, 1.0, 0.0}, {0.0, 0.0, 1.0}, {1.0, 0.0, 0.0}};

	Layer input(3, 3, "Input");
	Layer output(3, 0, "Output");

	Network network({input, output});

	/* Test set
		1 0 0
		0 1 0

		0 1 0
		0 0 1

		0 0 1
		1 0 0
	*/

	matrix_randomizer(network.layers[0].weights);

	// rock paper scissors

	network.layers[0].neurons = {1.0, 0.0, 0.0};
	network.parse_network();
	network.print_network();

	cout << "\n\n\n\n";

	network.layers[0].neurons = {0.0, 1.0, 0.0};
	network.parse_network();
	network.print_network();

	cout << "\n\n\n\n";

	network.layers[0].neurons = {0.0, 0.0, 1.0};
	network.parse_network();
	network.print_network();

	//////////////////////////////////////
	// 		   	    Graphics			//
	//////////////////////////////////////
	/*
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
	*/
	return 0;
}
// sssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss