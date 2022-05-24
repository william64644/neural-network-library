#pragma once

using namespace std;

vector<string> read_file(string file_name); // read file and return vector of strings

void write_file(vector<string> data, string file_name); // write vector to file

vector<vector<float>> dpkg(string data_file_path);

void repack(vector<vector<float>> data, string output_file);

#include "../tool_box/file_handler.cpp"