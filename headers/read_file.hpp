#pragma once

#include <vector>
#include <fstream>
using namespace std;

vector<string> read_file(string file_name)
{
    vector<string> lines;
    fstream data;
    data.open(file_name, ios::in);
    string line;
    while (getline(data, line))
    {
        lines.push_back(line);
    }
    data.close();
    return lines;
}