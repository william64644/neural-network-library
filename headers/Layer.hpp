#pragma once

#include <vector>

using namespace std;

struct Layer // give it the size of the layer and the size of the next layer (0 for the output layer)
{
    vector<double> neurons;
    vector<double> biases;
    vector<vector<double>> weights;
    string name;
    vector<string> parameter_names;
    
    Layer(unsigned int size, unsigned int next_layer_size, string name = "Layer", vector<string> parameter_names = {})
    {
        neurons = vector<double>(size);
        weights = vector<vector<double>>(size, vector<double>(next_layer_size));
        biases = vector<double>(size);
        this->name = name;
        this->parameter_names = parameter_names;
    }
};
