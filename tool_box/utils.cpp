#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

void print_vector(vector<string> vec)
{
    for (unsigned int i1 = 0; i1 < vec.size(); i1++)
    {
        cout << vec[i1] << '\n';
    }
}

void print_data(vector<float> vec)
{
    for (unsigned int i1 = 0; i1 < vec.size(); i1++)
    {
        cout << vec[i1] << ' ';
    }
}

vector<string> split(string str, char delimiter = ' ')
{
    vector<string> words;
    stringstream ss(str); // Turn the string into a stream.
    string tok;

    while (getline(ss, tok, delimiter))
    {
        words.push_back(tok);
    }
    return words;
}

void data_randomizer(vector<vector<float>> &data)
{
    srand(time(NULL));
    for (int i = 0; i < data.size(); i++)
    {
        for (int j = 0; j < data[i].size(); j++)
        {
            data[i][j] = (rand() % 100) / 100.0;
        }
    }
}