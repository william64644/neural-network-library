#pragma once

#include <vector>

#include "/home/night/Documents/GitHub/neural-network-framework/headers/activators.hpp"
#include "/home/night/Documents/GitHub/neural-network-framework/headers/size.hpp"

using namespace std;

bool test_relu()
{
    double inputs[7] = {-1.5, -1.0, -0.5, 0.0, 0.5, 1.0, 1.5};
    double expecteds[7] = {0.0, 0.0, 0.0, 0.0, 0.5, 1.0, 1.5};

    for (int i = 0; i < size(inputs); i++)
    {
        if (relu(inputs[i]) != expecteds[i])
        {
            return false;
        }
    }
    return true;
}

bool test_perceptron()
{
    double inputs[7] = {-1.5, -1.0, -0.5, 0.0, 0.5, 1.0, 1.5};
    double expecteds[7] = {0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0};

    for (int i = 0; i < size(inputs); i++)
    {
        if (perceptron(inputs[i]) != expecteds[i])
        {
            return false;
        }
    }
    return true;
}

bool test_hyperbolic_tangent()
{
    double inputs[7] = {-1.5, -1.0, -0.5, 0.0, 0.5, 1.0, 1.5};
    double expecteds[7] = {-0.905148, -0.761594, -0.462117, 0.0, 0.462117, 0.761594, 0.905148};

    for (int i = 0; i < size(inputs); i++)
    {
        if (hyperbolic_tangent(inputs[i]) != expecteds[i])
        {
            return false;
        }
    }
    return true;
}

bool test_sigmoid()
{
    double inputs[7] = {-1.5, -1.0, -0.5, 0.0, 0.5, 1.0, 1.5};
    double expecteds[7] = {0.182426, 0.268941, 0.377541, 0.5, 0.622459, 0.731059, 0.817574};

    for (int i = 0; i < size(inputs); i++)
    {
        if (sigmoid(inputs[i]) != expecteds[i])
        {
            return false;
        }
    }
    return true;
}

bool test_leaky_relu()
{
    double inputs[7] = {-1.5, -1.0, -0.5, 0.0, 0.5, 1.0, 1.5};
    double expecteds[7] = {-0.15, -0.1, -0.05, 0.0, 0.5, 1.0, 1.5};

    for (int i = 0; i < size(inputs); i++)
    {
        if (leaky_relu(inputs[i]) != expecteds[i])
        {
            return false;
        }
    }
    return true;
}