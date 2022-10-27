#pragma once

#include <vector>
#include <sstream>
#include <chrono>

#include "variate.hpp"
#include "chance.hpp"

using namespace std;

void mutate_matrix(vector<vector<double>> &matrix, double max_variation, int mutation_chance = 100)
{
    //srand(std::chrono::system_clock::now().time_since_epoch().count());
    for (unsigned int i = 0; i < matrix.size(); i++)
    {
        for (unsigned int j = 0; j < matrix[i].size(); j++)
        {
            if (chance(mutation_chance))
            {
                matrix[i][j] = variate(matrix[i][j], max_variation);
            }
            

            //if (matrix[i][j] < 0)
            //{
            //    matrix[i][j] = 0;
            //}
        }
    }
}

