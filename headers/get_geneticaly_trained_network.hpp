#include "Network.hpp"
#include "randomly_variate_network_weights.hpp"

using namespace std;

Network get_geneticaly_trained_network(Network network, int generarions, int iterations, double training_rate)
{
    Network cache = network;
    Network best = network;

    for (int generarion = 0; generarion < generarions; generarion++)
    {
        for (int iteration = 0; iteration < iterations; iteration++)
        {
            randomly_variate_network_weights(cache, training_rate);
        }
    }
}
