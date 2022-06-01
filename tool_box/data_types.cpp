#include <vector>

using namespace std;

struct Layer // give it the size of the layer and the size of the next layer (0 for the output layer)
{
    vector<double> neurons;
    vector<vector<double>> weights;
    Layer(unsigned int size, unsigned int next_layer_size)
    {
        neurons = vector<double>(size);
        weights = vector<vector<double>>(size, vector<double>(next_layer_size));
    }
};

struct Vector2
{
    double x;
    double y;
};

struct Vector3
{
    double x;
    double y;
    double z;
};