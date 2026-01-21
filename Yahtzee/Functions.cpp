
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

inline int rollOne()
{
	return rand() % 7;
}


void printCurrentHand(vector<int> currentHand)
{
	for (int i = 0; i < 5; i++)
	{
		cout << currentHand[i] << " \n";
	}
}

vector<int> roll5Dice()
{
	vector<int> currentHand = {};

	for (int i = 0; i < 5; i++)
	{
		currentHand.push_back(rand() % 7);
	}

	return currentHand;
}