#pragma once

#include <chrono>

using namespace std;

bool random_bool()
{
	srand(std::chrono::system_clock::now().time_since_epoch().count());
	
	float num = rand() % 10;
	
	if (num > 5)
	{
		return true;
	} else {
		return false;
	}
}
