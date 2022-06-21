#pragma once

#include <vector>
#include <sstream>

using namespace std;

vector<string> split(string str, char delimiter = ' ')
{
    vector<string> words;
    stringstream ss(str); // Turn the string into a stream.
    string tok;

    while (getline(ss, tok, delimiter))
    {
        words.push_back(tok);
    }
    return words;
}