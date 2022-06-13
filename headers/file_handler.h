#pragma once

#include <fstream>
#include <vector>
#include "../headers/utils.h"

using namespace std;

vector<string> read_file(string file_name);

void write_file(vector<string> data, string file_name);

vector<vector<double>> dpkg(string data_file_path);

void repack(vector<vector<double>> data, string output_file);

void vector_packager(vector<double> data, string file_name);

#include "src/file_handler.cpp"