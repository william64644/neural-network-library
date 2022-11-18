#pragma once

#include <chrono>

using namespace std;

bool chance(int &percentage)
{
	srand(std::chrono::system_clock::now().time_since_epoch().count());

	float num = rand() % 100;
	
	if (num <= percentage)
	{
		return true;
	} else {
		return false;
	}
}
