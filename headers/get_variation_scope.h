#pragma once

#include <cmath>

double get_variation_scope(int current_training_phase)
{
	// this equation was optimized for 20 training phases
	return 15 * pow(current_training_phase, 3);
}