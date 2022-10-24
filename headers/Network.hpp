#pragma once

#include <vector>
#include <iostream>

#include "Layer.hpp"
#include "print_layer_data.hpp"
#include "layer_runner.hpp"
#include "absolute_difference.hpp"

using namespace std;

struct Network
{
    double error;
    double default_error;
    vector<Layer> layers;
    vector<vector<vector<double>>> learning_samples;

    //Network() = default;
    Network(vector<Layer> layers, vector<vector<vector<double>>>learning_samples = {})
    {
        this->layers = layers;
        this->learning_samples = learning_samples;
        this->error = layers.back().neurons.size();
        this->default_error = this->error;
    }
    

    void print_network()
    {
        cout << "================================\n";
        for (unsigned int i = 0; i < layers.size(); i++)
        {
            print_layer_data(layers[i]);
        }
        cout << "Error: " << error << '\n';
        cout << "================================\n";
    }

    void run_network()
    {
        //running each layer
        for (unsigned int i = 0; i < layers.size() - 1; i++)
        {
            layer_runner(layers[i], layers[i + 1]);
        }
    }

    void run_test()
    {
        this->error = 0;
        for (int learning_sample = 0; learning_sample < learning_samples.size(); learning_sample++)
        {
            this->layers[0].neurons = learning_samples[learning_sample][0];
            run_network();
            this->error += absolute_difference(this->layers.back().neurons, learning_samples[learning_sample][1]);
        }
        //cout << error << '\n';
    }
        
};
