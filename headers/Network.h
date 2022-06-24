#pragma once

#include <vector>
#include <iostream>

#include "Layer.h"
#include "print_layer_data.h"
#include "layer_parser.h"
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
        // error = 9999999; // expected_output.size();
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

    void parse_network()
    {
        error = 0;
        for (unsigned int i = 0; i < layers.size() - 1; i++)
        {
            layer_parser(layers[i], layers[i + 1]);
        }
        if (expected_output.size() > 0) // calculates the error if the expected output is defined
        {
            error = absolute_difference(layers.back().neurons, expected_output);
        }
    }
};
