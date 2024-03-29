#pragma once

#include <vector>
#include <sstream>
#include <chrono>
#include <cmath>

#include "random_bool.hpp"

using namespace std;

double variate(double &num, double &max_variation, bool allow_negative = false)
{
	srand(std::chrono::system_clock::now().time_since_epoch().count());
	double variation = (float(rand())/float((RAND_MAX)) * max_variation);

	variation = variation / 10;

	if (random_bool() && allow_negative)
	{
		
		return (num - variation);
	}
	else
	{
		return (num + variation);
	}
}
