#include <vector>

using namespace std;

struct Layer
{
    vector<float> neurons;
    vector<vector<float>> weights;
};

struct Vector2
{
    float x;
    float y;
};

struct Vector3
{
    float x;
    float y;
    float z;
};