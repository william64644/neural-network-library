#pragma once

#include <iostream>
#include <vector>

using namespace std;

vector<double> ask_network_input_from_user(int &numbers_ammount)
{
	vector<double> nums;
	cout << "Type " << numbers_ammount << " numbers" << '\n';
	for (unsigned int i = 0; i < numbers_ammount; i++)
	{
		cout << "Number " << i << ": ";
		string num;
		cin >> num;
		nums.push_back(stod(num));
	}
	return nums;
}