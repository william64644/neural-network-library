#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include <chrono>

using namespace std;

sf::Color random_color()
{
    srand(std::chrono::system_clock::now().time_since_epoch().count());
    return sf::Color(rand() % 255, rand() % 255, rand() % 255);
}