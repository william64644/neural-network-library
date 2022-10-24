#pragma once

#include <vector>
#include <thread>

#include "Network.hpp"
#include "randomly_variate_network_weights.hpp"
#include "chance.hpp"
#include "join_thread_vector.hpp"

struct Population
{
    int size;
    vector<Network> networks;
    Network best;
    vector<double> error_history;
    double best_error;

    Population(Network original_network, int size)
    {
        this->size = size;
        //this->best = &original_network;
        //networks.resize(sizeof(original_network)*size);
        for (int i = 0; i < size; i++)
        {
            networks.push_back(original_network);
            best_error = original_network.default_error;
        }
    }

    void mutate(double variation, int mutation_chance = 100)
    {
        //vector<thread> threads;
        for (int i = 0; i < size; i++)
        {
            //threads.push_back(thread(randomly_variate_network_weights, ref(networks[i]), variation, mutation_chance));
            randomly_variate_network_weights(networks[i], variation, mutation_chance);
            
        }
        //join_thread_vector(threads);
    }

    void test()
    {

        int best_layer_i = 0;
        int worst_layer_i = 0;
        for (int i = 0; i < size; i++)
        {
            networks[i].run_test();
            if (networks[i].error < best_error)
            {
                best_layer_i = i;
                cout << networks[best_layer_i].error << '\n';
                best_error = networks[i].error;
                this->best = networks[best_layer_i];
                error_history.push_back(this->best.error);
            }
        }
    }

    void renew()
    {
        for (int i = 0; i < size; i++)
        {
            networks[i].layers = networks[i].layers; //(*best).layers;
        }
    }

    void multi_run(int rounds, double variation, int mutation_chance = 100)
    {
        for (int i = 0; i < rounds; i++)
        {
            this->mutate(variation, mutation_chance);
            this->test();
            this->renew();
        }
    }
};
