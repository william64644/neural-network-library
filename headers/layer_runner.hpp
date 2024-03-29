#pragma once

#include <cmath>

#include "Layer.hpp"
#include "reset_vector.hpp"
#include "activators.hpp"
#include "activate_vector.hpp"

using namespace std;

void layer_runner(Layer &A_layer, Layer &B_layer)
{
    reset_vector(B_layer.neurons);
    // Looping through A-neurons
    for (unsigned int neuron_i = 0; neuron_i < A_layer.neurons.size(); neuron_i++)
    {
        // Looping through A-weights
        for (unsigned int weight_i = 0; weight_i < A_layer.weights[0].size(); weight_i++)
        {
            // Multiply and sum
            //B_layer.neurons[weight_i] += A_layer.neurons[neuron_i] * A_layer.weights[neuron_i][weight_i] + B_layer.biases[weight_i];

            B_layer.neurons[weight_i] += A_layer.neurons[neuron_i] * A_layer.weights[neuron_i][weight_i];
        }
    }

    // Activation function over all neurons
    activate_vector(B_layer.neurons);
}
