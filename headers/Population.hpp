#pragma once

#include <vector>

#include "Network.hpp"
#include "randomly_variate_network_weights.hpp"

struct Population
{
    int size;
    vector<Network> networks;
    Network *best;
    Network *worst;
    

    Population(Network original_network, int size)
    {
        this->size = size;
        //this->best = &original_network;
        //networks.resize(sizeof(original_network)*size);
        for (int i = 0; i < size; i++)
        {
            networks.push_back(original_network);
        }
    }

    void mutate(double variation)
    {
        for (int i = 0; i < size; i++)
        {
            randomly_variate_network_weights(networks[i], variation);
            //networks[i].print_network();
        }
    }

    void test()
    {
        double best_error = 10; //best->default_error;
        double worst_error = 0;

        int best_layer_i = 0;
        int worst_layer_i = 0;
        for (int i = 0; i < size; i++)
        {
            networks[i].run_test();
            if (networks[i].error < best_error)
            {
                best_layer_i = i;
            }

            if (networks[i].error > worst_layer_i)
            {
                worst_layer_i = i;
            }
        }
        this->best = &networks[best_layer_i];
        this->worst = &networks[worst_layer_i];
    }

    void renew()
    {
        for (int i = 0; i < size; i++)
        {
            networks[i].layers = (*best).layers;
        }
    }

    void multi_run(int rounds, double variation)
    {
        for (int i = 0; i < rounds; i++)
        {
            this->mutate(variation);
            this->test();
            this->renew();
        }
    }
};
