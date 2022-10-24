#pragma once

#include <thread>
#include <vector>

using namespace std;

void join_thread_vector(vector<thread> &threads)
{
    for(int i = 0; i < threads.size(); i++)
    {
        threads[i].join();
    }
}
