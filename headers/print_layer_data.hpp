#pragma once

#include <vector>

#include "Layer.hpp"
#include "print_vector.hpp"
#include "print_matrix.hpp"

using namespace std;

void print_layer_data(Layer &layer)
{
    // cout << "================================\n";
    cout << '\t' << layer.name << " Neurons:" << '\n';
    print_vector(layer.neurons); // print neuron values

    if (layer.weights[0].size() > 0) // only print weights if there are any
    {
        cout << '\t' << layer.name << " Weights:" << '\n';
        print_matrix(layer.weights);
    }
    else
    {
        cout << '\t' << layer.name << " Weights: None" << '\n';
    }
}