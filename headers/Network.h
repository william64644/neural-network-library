#pragma once

#include <vector>
#include <iostream>

#include "Layer.h"
#include "print_layer_data.h"
#include "layer_runner.h"
#include "absolute_difference.h"

using namespace std;

struct Network
{
    double error;
    vector<Layer> layers;
    vector<double> expected_output;

    Network(vector<Layer> layers, vector<double> expected_output = {})
    {
        this->layers = layers;
        this->expected_output = expected_output;
        error = layers.back().neurons.size() + layers[0].neurons.size();
    }

    void print_network()
    {
        cout << "================================\n";
        for (unsigned int i = 0; i < layers.size(); i++)
        {
            print_layer_data(layers[i]);
        }
        cout << "Cache Error: " << error << '\n';
        cout << "================================\n";
    }

    void run_network()
    {
        error = 404;
        for (unsigned int i = 0; i < layers.size() - 1; i++)
        {
            layer_runner(layers[i], layers[i + 1]);
        }
        
        error = absolute_difference(layers.back().neurons, expected_output);
    }
};
