#include <vector>
#include <sstream>
#include <chrono>
#include "../headers/data_types.h"

using namespace std;

void matrix_randomizer(vector<vector<double>> &data)
{
    srand(std::chrono::system_clock::now().time_since_epoch().count());
    for (long unsigned int i = 0; i < data.size(); i++)
    {
        for (long unsigned int j = 0; j < data[i].size(); j++)
        {
            data[i][j] = (rand() % 100) / 100.0;
        }
    }
}

void reset_matrix(vector<vector<double>> &matrix)
{
    for (unsigned int i = 0; i < matrix.size(); i++)
    {
        for (unsigned int j = 0; j < matrix[i].size(); j++)
        {
            matrix[i][j] = 0;
        }
    }
}

void reset_vector(vector<double> &vec)
{
    for (unsigned int i = 0; i < vec.size(); i++)
    {
        vec[i] = 0;
    }
}

void layer_parser(Layer &A_layer, Layer &B_layer)
{
    reset_vector(B_layer.neurons);
    for (unsigned int i = 0; i < A_layer.neurons.size(); i++)
    {
        for (unsigned int j = 0; j < A_layer.weights[0].size(); j++)
        {
            B_layer.neurons[j] += A_layer.neurons[i] * A_layer.weights[i][j];
        }
    }
}
