#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <SFML/Graphics.hpp>
#include "headers/file_handler.h"
#include "headers/utils.h"
#include "headers/core_neural.h"
#include "headers/data_types.h"

using namespace std;

sf::Color random_color()
{
	srand(std::chrono::system_clock::now().time_since_epoch().count());
	return sf::Color(rand() % 255, rand() % 255, rand() % 255);
}

sf::Color random_dark_color()
{
	srand(std::chrono::system_clock::now().time_since_epoch().count());
	return sf::Color(rand() % 100 + 100, rand() % 100 + 100, rand() % 100 + 100);
}

struct Graphic_Neuron
{
	sf::CircleShape shape;
	sf::Text text;
	sf::Font font;

	Graphic_Neuron(double x, double y, double radius, double value)
	{
		shape.setPosition(x, y);
		shape.setRadius(radius);
		shape.setFillColor(random_dark_color());

		font.loadFromFile("/usr/share/fonts/truetype/freefont/FreeSans.ttf");
		text.setFont(font);

		text.setFillColor(sf::Color::White);
		text.setCharacterSize(radius);
		text.setString(to_string(value));
		text.setPosition(x + radius, y);
	}

	void update(double value)
	{
		text.setString(to_string(value));
	}
};

// get a graphicable neuron from a Layer
Graphic_Neuron get_graphic_neuron(Layer &layer, unsigned int index, double x = 0, double y_spacing = 70, double radius = 30)
{
	double y = index * y_spacing;
	return Graphic_Neuron(x, y, radius, layer.neurons[index]);
}

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

	Graphic_Neuron input_neuron1 = get_graphic_neuron(input, 0, 0);
	Graphic_Neuron input_neuron2 = get_graphic_neuron(input, 1, 0);
	Graphic_Neuron input_neuron3 = get_graphic_neuron(input, 2, 0);

	Graphic_Neuron output_neuron1 = get_graphic_neuron(output, 0, 200);
	Graphic_Neuron output_neuron2 = get_graphic_neuron(output, 1, 200);
	Graphic_Neuron output_neuron3 = get_graphic_neuron(output, 2, 200);

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
		window.draw(input_neuron1.shape);
		window.draw(input_neuron2.shape);
		window.draw(input_neuron3.shape);

		window.draw(output_neuron1.shape);
		window.draw(output_neuron2.shape);
		window.draw(output_neuron3.shape);

		window.draw(input_neuron1.text);
		window.draw(input_neuron2.text);
		window.draw(input_neuron3.text);

		window.draw(output_neuron1.text);
		window.draw(output_neuron2.text);
		window.draw(output_neuron3.text);

		window.display();
	}

	return 0;
}
// ssssssssssssssssssssssssssssssss