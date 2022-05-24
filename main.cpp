#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "headers/file_handler.h"
#include "headers/utils.h"

using namespace std;

int main()
{
	vector<vector<float>> nums = dpkg("data/weights/AB");
	data_randomizer(nums);
	repack(nums, "data/weights/AB");

	return 0;
}
