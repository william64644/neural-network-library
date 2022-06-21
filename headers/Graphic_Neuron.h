#pragma once

#include <vector>

#include "random_dark_color.h"

using namespace std;

struct Graphic_Neuron
{
    sf::CircleShape shape;
    sf::Text text;
    double value;

    Graphic_Neuron(sf::Font &font, double x = 0, double y = 0, double radius = 0, double value = 0)
    {

        shape.setPosition(x, y);
        shape.setRadius(radius);
        shape.setFillColor(random_dark_color());

        text.setFont(font);

        text.setFillColor(sf::Color::White);
        text.setCharacterSize(radius);
        text.setString(to_string(value));
        text.setPosition(x + radius, y);
        this->value = value;
    }
};