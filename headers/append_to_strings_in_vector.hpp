#pragma once

#include <vector>
#include <string>

using namespace std;

void append_to_strings_in_vector(vector<string> &vector, string appending_text = ",")
{
    for (int i = 0; i < vector.size(); i++)
    {
        vector[i].append(appending_text);
    }
}