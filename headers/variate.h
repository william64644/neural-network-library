#pragma once

#include <vector>
#include <sstream>
#include <chrono>
#include <cmath>

#include "random_bool.h"

using namespace std;

double variate(double num, int max_variation = 10)
{
	srand(std::chrono::system_clock::now().time_since_epoch().count());
	double absolute_variation = rand() % max_variation;

	absolute_variation = absolute_variation / 100;

	if (random_bool())
	{
		return tanh(num + num * absolute_variation);
	}
	else
	{
		return tanh(num - num * absolute_variation);
	}
}
