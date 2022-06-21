#pragma once

#include <cmath>

#include "Layer.h"
#include "reset_vector.h"

using namespace std;

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
    for (unsigned int k = 0; k < B_layer.neurons.size(); k++)
    {
        B_layer.neurons[k] = tanh(B_layer.neurons[k]);
    }
}