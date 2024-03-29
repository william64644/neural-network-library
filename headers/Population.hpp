#pragma once

#include <vector>
#include <thread>

#include "Network.hpp"
#include "randomly_variate_network_weights.hpp"
#include "chance.hpp"
#include "join_thread_vector.hpp"

struct Population
{
    unsigned int population_size;
    vector<Network> networks;
    Network best_net;
    Network original_net;
    vector<double> error_history;
    double best_error;

    Population(Network &original_network, int size)
    {
        this->population_size = size;
        this->original_net = original_network;
        this->best_error = original_network.default_error;
        //this->best = &original_network;
        networks.resize(sizeof(original_network)*size);
        for (int i = 0; i < size; i++)
        {
            networks[i] = (original_network);
        }

        networks[0].run_test();
        this->best_error = networks[0].error;
    }

    void mutate(double variation, int mutation_chance = 100)
    {
        //vector<thread> threads;
        for (int i = 0; i < population_size; i++)
        {
            //threads.push_back(thread(randomly_variate_network_weights, ref(networks[i]), variation, mutation_chance));
            randomly_variate_network_weights(networks[i], variation, mutation_chance, true);
        }

        //join_thread_vector(threads);
    }

    void test_population()
    {

        int best_layer_i = 0;

        

        for (int i = 1; i < population_size; i++)
        {
    
            //cout << networks[i].default_error << '\n';
            //cout << networks[i].error << '\n';
            networks[i].run_test();
            if (networks[i].error < this->best_error)
            {
                best_layer_i = i;
                cout << networks[best_layer_i].error << '\n';
                best_error = networks[i].error;
                this->best_net = networks[best_layer_i];
                //error_history.push_back(this->best_net.error);
            }
            //error_history.push_back(this->best.error);

        }

        if (! this->best_net.is_formed())
        {
            this->best_net = original_net;
        }
    }

    void renew()
    {
        for (int i = 0; i < population_size; i++)
        {
            networks[i].layers = best_net.layers;
        }
    }

    void do_genetic_train(int rounds, double variation, int mutation_chance = 100)
    {
        // TODO: doing this check is breaking 2 clean code rules
        if (! this->best_net.is_formed())
        {
            this->best_net = original_net;
        }

        for (double i = 0; i < rounds; i++)
        {
            this->mutate(variation, mutation_chance);
            this->test_population();
            this->renew();
            cout << (i+1) / rounds * 100.0 << "%\n";
        }
    }
};
