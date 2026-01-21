
#include "Functions.cpp"
#include <iostream>
#include <vector>
#include <string>
using namespace std;



int main()
{




	vector<int> currentHand = roll5Dice();
	
	printCurrentHand(currentHand);


	return 0;
}

