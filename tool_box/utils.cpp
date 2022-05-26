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
    cout << '\n';
}

void print_data(vector<float> vec)
{
    for (unsigned int i1 = 0; i1 < vec.size(); i1++)
    {
        cout << vec[i1] << ' ';
    }
    cout << '\n';
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

vector<float> multiply_vector_by_matrix(vector<float> vec, vector<vector<float>> matrix)
{
    if (vec.size() != matrix[0].size())
    {
        cout << "Error: vector size does not match matrix size\n";
        return vec;
    }
    vector<float> result;
    for (unsigned int i = 0; i < matrix.size(); i++)
    {
        float sum = 0;
        for (unsigned int j = 0; j < vec.size(); j++)
        {
            sum += vec[j] * matrix[i][j];
        }
        result.push_back(sum);
    }
    return result;
}

vector<float> multiply_scalar_by_vector(vector<float> vec, float scalar)
{
    vector<float> result;
    for (unsigned int i = 0; i < vec.size(); i++)
    {
        result.push_back(vec[i] * scalar);
    }
    return result;
}

void print_matrix(vector<vector<float>> matrix)
{
    for (unsigned int i = 0; i < matrix.size(); i++)
    {
        for (unsigned int j = 0; j < matrix[i].size(); j++)
        {
            cout << matrix[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

vector<vector<float>> matrix_transponser(vector<vector<float>> matrix)
{
    vector<vector<float>> transposed_matrix;
    for (unsigned int i = 0; i < matrix[0].size(); i++)
    {
        vector<float> row;
        for (unsigned int j = 0; j < matrix.size(); j++)
        {
            row.push_back(matrix[j][i]);
        }
        transposed_matrix.push_back(row);
    }
    return transposed_matrix;
}
