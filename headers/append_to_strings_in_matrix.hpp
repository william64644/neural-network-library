#pragma once

#include <vector>
#include <string>

using namespace std;

void append_to_strings_in_matrix(vector<vector<string>> &matrix, string appending_text)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            matrix[i][j].append(appending_text);
        }
    }
}