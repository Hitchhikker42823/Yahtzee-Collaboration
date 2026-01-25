#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <random>

#include "PlayerClass.cpp"
#include "UIElements.cpp"
using namespace std;



int main()
{
	cout << UITitleCard; //@DEBUG
	Player player0;

	while (true)
	{
		player0.FullNewHand(); //when the user is done with their hand, roll a whole new one

		while (true)
		{
			//print hand, prompt for removal, refill, print again
			player0.printCurrentHand();
			player0.removeAndRefill();
			player0.printCurrentHand();

			//logic to break the while loop if the user wants to keep their hand
			cout << "\nDo you want to keep your hand? (Yes/Y)\n"; //@DEBUG
			clearScreen();
			string userInput = "";
			getline(cin, userInput);
			StoUpper(userInput);
			if (userInput == "YES" || userInput == "Y")
			{
				cout << "\nHand Kept! Restarting game.\n";
				break;
			}
		}
	}
	


	return 0;
}

