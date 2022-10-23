#pragma once

#include "Network.hpp"
#include "vector_packager.hpp"
#include "double_packager.hpp"

using namespace std;

void repack_network(Network &network, string folder)
{
    // loop through all layers in the network
    for (unsigned int i = 0; i < network.layers.size(); i++)
    {
        // write neurons of the current layer
        vector_packager(network.layers[i].neurons, folder + network.layers[i].name + ".txt");

        // write weights of the current layer
        repack(network.layers[i].weights, folder + network.layers[i].name + "_weights.txt");
    }
    // write error of the network
    double_packager(network.error, folder + "network_error.txt");
}