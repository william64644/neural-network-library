#pragma once

#include <vector>
#include <fstream>

using namespace std;

void write_file(vector<string> &data, string &file_name, bool append_mode = false)
{
    fstream file;

    if (append_mode)
    {
        file.open(file_name, ios::app);
    } else {
        file.open(file_name, ios::out);
    }

    for (unsigned int i1 = 0; i1 < data.size(); i1++)
    {
        file << static_cast<string>(data[i1]) << '\n';
    }
    file.close();
}