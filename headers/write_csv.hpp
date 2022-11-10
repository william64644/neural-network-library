#pragma once

#include <vector>
#include <string>

#include "get_string_matrix_from_double_matrix.hpp"
#include "append_to_strings_in_vector.hpp"
#include "append_to_strings_in_matrix.hpp"
#include "repack.hpp"

using namespace std;

void write_csv(vector<vector<double>> double_matrix, vector<string> csv_header, string file_name, string separator = ",")
{
    vector<vector<string>> text_matrix = get_string_matrix_from_double_matrix(double_matrix);
    text_matrix.reserve(text_matrix.size() + 1);

    append_to_strings_in_vector(csv_header, separator);
    append_to_strings_in_matrix(text_matrix, separator);

    text_matrix.insert(text_matrix.begin(), csv_header);

    repack(text_matrix, file_name);
}