#pragma once

#include <vector>

#include "write_file.h"

using namespace std;

int get_biggest_in_matrix(vector<vector<int>> data)
{
	int biggest = 0;
	
	for (unsigned int row = 0; row < data.size(); row++)
	{
        	for (unsigned int column = 0; column < data[row].size(); column++)
        	{
            		if (data[row][column] > biggest)
            		{
            			biggest = data[row][column];
            		}
		}
    	}
    	
    	return biggest;
	
}

void write_pgm(vector<vector<int>> data, string output_file)
{
    vector<string> output(data.size());
    for (unsigned int row = 0; row < data.size(); row++)
    {
        for (unsigned int column = 0; column < data[row].size(); column++)
        {
            output[row] = output[row] + to_string(data[row][column]) + ' ';
        }
    }
    
    int brightest_color = get_biggest_in_matrix(data);

    string header = "P2\n" + to_string(data.size()) + " " + to_string(data[0].size()) + "\n" + to_string(brightest_color) + "\n";

    output.insert(output.begin(), header);

    write_file(output, output_file);
}
