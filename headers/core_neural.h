#pragma once
#include <vector>

using namespace std;

struct Layer;

void layer_parser(Layer &A_layer, Layer &B_layer); // forward propagation

void matrix_randomizer(vector<vector<double>> &data); // randomize a matrix

void reset_matrix(vector<vector<double>> &matrix); // reset a matrix

void reset_vector(vector<double> &vec); // reset vector of doubles

#include "../tool_box/core_neural.cpp"