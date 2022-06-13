#pragma once

#include <vector>
#include <sstream>
#include <chrono>
#include <math.h>

using namespace std;

struct Layer; // give it the size of the layer and the size of the next layer (0 for the output layer)

void matrix_randomizer(vector<vector<double>> &data);

void reset_matrix(vector<vector<double>> &matrix);

void reset_vector(vector<double> &vec);

void layer_parser(Layer &A_layer, Layer &B_layer);

#include "src/core_neural.cpp"