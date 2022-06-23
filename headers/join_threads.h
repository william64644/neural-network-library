#pragma once

#include <vector>
#include <thread>

using namespace std;

void join_threads(vector<thread> &threads)
{
    for (unsigned int i = 0; i < threads.size(); i++)
    {
        threads[i].join();
    }
}