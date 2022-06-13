
#include <fstream>
#include <vector>
#include "../utils.h"

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

void write_file(vector<string> data, string file_name)
{
    fstream file;
    file.open(file_name, ios::out);
    for (unsigned int i1 = 0; i1 < data.size(); i1++)
    {
        file << static_cast<string>(data[i1]) << '\n';
    }
    file.close();
}

vector<vector<double>> dpkg(string data_file_path)
{
    vector<string> data_lines = read_file(data_file_path);                               // get string lines from file
    vector<vector<double>> output(data_lines.size(), vector<double>(data_lines.size())); // double vectors output
    vector<vector<string>> double_strings(data_lines.size());                            // vectors of words
    for (unsigned short i = 0; i < data_lines.size(); i++)                               // split lines into words
    {
        double_strings[i] = split(data_lines[i]);
    }
    for (unsigned short i1 = 0; i1 < double_strings.size(); i1++)
    {
        for (unsigned short i2 = 0; i2 < double_strings[i1].size(); i2++)
        {
            double num = stod(double_strings[i1][i2]);
            output[i1][i2] = num;
        }
        output[i1].erase(output[i1].begin() + static_cast<long int>(double_strings[i1].size()), output[i1].end()); // delete unsused spaces
    }
    return output;
}

void repack(vector<vector<double>> data, string output_file)
{
    vector<string> output(data.size());
    for (unsigned int i1 = 0; i1 < data.size(); i1++)
    {
        for (unsigned int i2 = 0; i2 < data[i1].size(); i2++)
        {
            output[i1] = output[i1] + to_string(data[i1][i2]) + ' ';
        }
    }
    write_file(output, output_file);
}

void vector_packager(vector<double> data, string file_name)
{
    vector<vector<double>> matrix(1);
    matrix[0] = data;
    repack(matrix, file_name);
}