#pragma once

#include <cmath>
#include <algorithm>

using namespace std;

double relu(double input)
{
    return max(0.0, input);
}

double perceptron(double input)
{
    if (input > 0)
    {
        return 1;
    }
    return 0;
}

double hyperbolic_tangent(double input)
{
    return tanh(input);
}

// TODO: Find out why this sigmoid not working
double sigmoid(double input)
{
    return (1 / 1 + exp(input * -1));
}

double leaky_relu(double input)
{
    if (input < 0)
    {
        return 0.1 * input;
    }
    return input;
}

double elu(double input)
{
    return exp(input) -1;
}

double soft_plus(double input)
{
    return log(1 + exp(input));
}

double stepper(double input)
{
    return round(input*10)/10;
}

double bounded_square(double input)
{
    if (input < 0.0)
    {
        return 0.0;
    } else if (input > 1.0)
    {
        return 1.0;
    } else {
        return input * input;
    }
}

// Refference at:
// https://www.researchgate.net/profile/Aaron-Stebner-2/publication/341310767/figure/fig7/AS:890211844255749@1589254451431/Common-activation-functions-in-artificial-neural-networks-NNs-that-introduce.ppm