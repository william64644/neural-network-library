#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "headers/file_handler.h"
#include "headers/utils.h"

// use stoi() to convert string to int
// use stof() to convert string to floatt

using namespace std;

int main()
{
	vector<vector<float>> nums = dpkg("data/neurons/A");
	print_data(nums[0]);
	repack(nums, "data/neurons/A_repack");
	return 0;
}
