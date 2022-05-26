#pragma once
#include <vector>
using namespace std;

void print_vector(vector<string> vec); // print a vector

void print_data(vector<float> vec); // print a vector of floats

vector<string> split(string str, char delimiter); // split a string into a vector of words

vector<float> multiply_vector_by_matrix(vector<float> vec, vector<vector<float>> matrix); // multiply vector by matrix

vector<vector<float>> matrix_transponser(vector<vector<float>> matrix);

void print_matrix(vector<vector<float>> matrix);

vector<float> multiply_scalar_by_vector(vector<float> vec, float scalar);

#include "../tool_box/utils.cpp"