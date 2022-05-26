#pragma once
#include <vector>

using namespace std;

struct Layer;

void layer_parser(Layer &A_layer, Layer &B_layer); // forward propagation

void matrix_randomizer(vector<vector<float>> &data); // randomize a matrix

void reset_matrix(vector<vector<float>> &matrix); // reset a matrix

void data_randomizer(vector<vector<float>> &data); // randomize vector of vectors of floats

void reset_vector(vector<float> &vec); // reset vector of floats

#include "../tool_box/core_neural.cpp"