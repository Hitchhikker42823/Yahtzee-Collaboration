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
			cout << promptToKeep;
			clearScreen();
			string userInput = "";
			getline(cin, userInput);
			StoUpper(userInput);
			if (userInput == "1")
			{
				cout << "\nHand Kept! Restarting game.\n";
				break;
			}
			else if (userInput == "2")
			{
				//@TODO: REROLL
			}
		}
	}
	


	return 0;
}

