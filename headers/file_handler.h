#pragma once

using namespace std;

vector<string> read_file(string file_name); // read file and return vector of strings

void write_file(vector<string> data, string file_name); // write vector to file

vector<vector<double>> dpkg(string data_file_path); // read file and return vector of vectors of doubles

void repack(vector<vector<double>> data, string output_file); // write matrix to file

void vector_packager(vector<double> data, string file_name); // write vector to file

#include "../tool_box/file_handler.cpp"