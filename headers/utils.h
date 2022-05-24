#pragma once

using namespace std;

void print_vector(vector<string> vec); // print a vector

void print_data(vector<float> vec); // print a vector of floats

vector<string> split(string str, char delimiter); // split a string into a vector of words

void data_randomizer(vector<vector<float>> &data); // randomize vector of vectors of floats

#include "../tool_box/utils.cpp"