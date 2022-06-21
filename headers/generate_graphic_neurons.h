#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

#include "Graphic_Neuron.h"
#include "Layer.h"

using namespace std;

vector<Graphic_Neuron> generate_graphic_neurons(Layer &layer, sf::Font &font, double x = 0, double y = 0, double radius = 0)
{
    vector<Graphic_Neuron> graphic_neurons;
    for (long unsigned int i = 0; i < layer.neurons.size(); i++)
    {
        graphic_neurons.push_back(Graphic_Neuron(font, x, y, radius, layer.neurons[i]));
        y += radius * 2;
    }
    return graphic_neurons;
}