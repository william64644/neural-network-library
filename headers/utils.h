#pragma once

#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include "core_graphics.h"

using namespace std;

void print_vector(vector<string> vec);

vector<string> split(string str, char delimiter);

vector<double> multiply_scalar_by_vector(vector<double> vec, double scalar);

void print_matrix(vector<vector<double>> matrix);

vector<vector<double>> matrix_transponser(vector<vector<double>> matrix);

double average(vector<double> vec);

double absolute_difference(double test_set[], vector<double> values);

bool is_largest(vector<double> vec, unsigned int indice);

void print_data(vector<double> vec);

#include "src/utils.cpp"