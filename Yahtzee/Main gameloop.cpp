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
	int roundsRemaining = 13;

	while (roundsRemaining > 0)
	{
		roundsRemaining--;

		player0.FullNewHand(); //when the user is done with their hand, roll a whole new one
		int rerollsRemaining = 3;

		while (rerollsRemaining > 0)
		{
			cout << "\n\n\n" << rerollsRemaining << "\n\n\n"; //@DEBUG
			rerollsRemaining--;

			//print hand
			player0.printCurrentHand();

			//logic to break the while loop if the user wants to keep their hand
			cout << promptToKeep;

			string userInput = "";
			while (userInput != "1" || userInput != "2")
			{
				userInput = "";
				getline(cin, userInput);
				StoUpper(userInput);
				if (userInput == "1")
				{
					cout << scoreCardSelectionUI;
					char cardPlaceSelected = '\0';	
					cin >> cardPlaceSelected;
					cardPlaceSelected = toupper(cardPlaceSelected);
					
					int ScoreAssignmentSucceeded = 1;
					while (ScoreAssignmentSucceeded != 0)
					{
						int inputAsInt = cardPlaceSelected - '0'; //ASCII math
						switch (cardPlaceSelected) {
						case '1': case '2': case '3':
						case '4': case '5': case '6':
							ScoreAssignmentSucceeded = player0.setUpperSection(inputAsInt);
							break;
						case 'Q':
							ScoreAssignmentSucceeded = player0.set3oaK();
							break;
						case 'W':
							ScoreAssignmentSucceeded = player0.set4oaK();
							break;
						case 'E':
							ScoreAssignmentSucceeded = player0.setFullHouse();
							break;
						case 'R':
							ScoreAssignmentSucceeded = player0.setSmallStraight();
							break;
						case 'T':
							ScoreAssignmentSucceeded = player0.setLargeStraight();
							break;
						case 'Y':
							ScoreAssignmentSucceeded = player0.setYahtzee();
							break;
						case 'U':
							ScoreAssignmentSucceeded = player0.setChance();
							break;
						}
					}
					break; //get a new hand

				}
				else if (userInput == "2")
				{
					player0.removeAndRefill();
					break;
				}
			}

		}


	}
	


	return 0;
}

