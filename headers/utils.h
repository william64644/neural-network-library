#pragma once
#include <vector>
using namespace std;

void print_vector(vector<string> vec); // print a vector

void print_data(vector<double> vec); // print a vector of doubles

vector<string> split(string str, char delimiter); // split a string into a vector of words

vector<double> multiply_vector_by_matrix(vector<double> vec, vector<vector<double>> matrix); // multiply vector by matrix

vector<vector<double>> matrix_transponser(vector<vector<double>> matrix);

void print_matrix(vector<vector<double>> matrix);

vector<double> multiply_scalar_by_vector(vector<double> vec, double scalar);

double average(vector<double> vec);

#include "../tool_box/utils.cpp"