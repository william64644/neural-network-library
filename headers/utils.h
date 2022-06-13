#pragma once

#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include "core_graphics.h"

using namespace std;

void print_vector(vector<string> vec)
{
    for (unsigned int i1 = 0; i1 < vec.size(); i1++)
    {
        cout << vec[i1] << '\n';
    }
    cout << '\n';
}

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

vector<double> multiply_scalar_by_vector(vector<double> vec, double scalar)
{
    vector<double> result;
    for (unsigned int i = 0; i < vec.size(); i++)
    {
        result.push_back(vec[i] * scalar);
    }
    return result;
}

void print_matrix(vector<vector<double>> matrix)
{
    for (unsigned int i = 0; i < matrix.size(); i++)
    {
        for (unsigned int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

vector<vector<double>> matrix_transponser(vector<vector<double>> matrix)
{
    vector<vector<double>> transposed_matrix;
    for (unsigned int i = 0; i < matrix[0].size(); i++)
    {
        vector<double> row;
        for (unsigned int j = 0; j < matrix.size(); j++)
        {
            row.push_back(matrix[j][i]);
        }
        transposed_matrix.push_back(row);
    }
    return transposed_matrix;
}

double average(vector<double> vec)
{
    double sum = 0;
    for (unsigned int i = 0; i < vec.size(); i++)
    {
        sum += vec[i];
    }
    return sum / vec.size();
}

double absolute_difference(double test_set[], vector<double> values)
{
    double difference = 0;
    for (unsigned int i = 0; i < values.size(); i++)
    {
        difference += abs(test_set[i] - values[i]);
    }
    return difference;
}

bool is_largest(vector<double> vec, unsigned int indice)
{
    if (vec[indice] == *max_element(vec.begin(), vec.end()))
    {
        return true;
    }
    else
    {
        return false;
    }
}

void print_data(vector<double> vec)
{
    for (unsigned int i = 0; i < vec.size(); i++)
    {
        if (is_largest(vec, i))
        {
            cout << BLUE;
        }
        cout << vec[i] << ' ';
        cout << RESET;
    }
    cout << '\n';
}
