#pragma once

#include <vector>
#include <SFML/Graphics.hpp>
#include <chrono>

using namespace std;

sf::Color random_dark_color()
{
    srand(std::chrono::system_clock::now().time_since_epoch().count());
    return sf::Color(rand() % 100 + 100, rand() % 100 + 100, rand() % 100 + 100);
}