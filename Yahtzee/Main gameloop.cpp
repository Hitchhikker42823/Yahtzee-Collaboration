
#include "Functions.h"
#include <iostream>
#include <vector>
#include <string>
#include <random>
using namespace std;



int main()
{
	vector<int> currentHand = roll5Dice();


	printCurrentHand(currentHand);

	vector<int> numbersToBeRemoved = askForNumbersToRemove();
	
	currentHand = removeFromHand(currentHand, numbersToBeRemoved);

	printCurrentHand(currentHand);


	return 0;
}

