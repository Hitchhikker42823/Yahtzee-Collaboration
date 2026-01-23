
#include "Functions.h"
#include <iostream>
#include <vector>
#include <string>
#include <random>
using namespace std;



int main()
{
	while (true)
	{
		vector<int> currentHand = roll5Dice(); //when the user is done with their hand, roll a whole new one

		while (true)
		{
			//print hand, prompt for removal, refill, print again
			printCurrentHand(currentHand);
			currentHand = removeAndRefill(currentHand);
			printCurrentHand(currentHand);

			//logig to break the while loop if the user wants to keep their hand
			cout << "KeepHand?\n"; //@DEBUG
			string userInput = "";
			getline(cin, userInput);
			if (userInput == "KeepHand")
			{
				cout << "Hand Kept! Restarting game.\n";
				break;
			}
		}
	}
	


	return 0;
}

