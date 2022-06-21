#pragma once

#include <vector>
#include <SFML/Graphics.hpp>

#include "Graphic_Neuron.h"

using namespace std;

void draw_graphic_neurons(sf::RenderWindow &window, vector<Graphic_Neuron> &layer)
{
    for (long unsigned int i = 0; i < layer.size(); i++)
    {
        window.draw(layer[i].shape);
        window.draw(layer[i].text);
    }
}