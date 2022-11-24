#pragma once

#include <vector>
#include <iostream>

#include "Layer.hpp"
#include "print_layer_data.hpp"
#include "layer_runner.hpp"
#include "vector_numeric_difference.hpp"

using namespace std;

struct Network
{
    double error;
    double default_error = 0;
    vector<Layer> layers;
    vector<vector<vector<double>>> learning_samples;

    Network() = default;
    Network(vector<Layer> layers, vector<vector<vector<double>>>learning_samples = {})
    {
        this->layers = layers;
        this->learning_samples = learning_samples;
        this->error = layers.back().neurons.size() * learning_samples.size();
        this->default_error = this->error;
    }


    void print_network()
    {
        cout << "================================\n";
        for (unsigned int i = 0; i < layers.size(); i++)
        {
            print_layer_data(this->layers[i]);
        }
        //cout << "Error: " << error << '\n';
        cout << "================================\n";
    }

    void run_network()
    {
        //running each layer
        for (unsigned int i = 0; i < layers.size() - 1; i++)
        {
            layer_runner(this->layers[i], this->layers[i + 1]);
        }
    }

    void run_test()
    {
        this->error = 0;
        for (int learning_sample = 0; learning_sample < learning_samples.size(); learning_sample++)
        {
            this->layers[0].neurons = learning_samples[learning_sample][0];
            run_network();
            this->error += vector_numeric_difference(this->layers.back().neurons, learning_samples[learning_sample][1]);
        }
        //cout << error << '\n';
    }

    bool is_formed()
    {
        // Detecting wether this network has it's layers defined
        // or if it is still just a default empty constructor
        // based on wether default_error was defined or not
        if (this->default_error != 0)
        {
            return true;
        } else {
            return false;
        }
    }

    void printed_test()
    {
        for (int i = 0; i < this->learning_samples.size(); i++)
        {
            this->layers[0].neurons = this->learning_samples[i][0];
            this->run_network();
            this->print_network();
        }
    }
        
};
