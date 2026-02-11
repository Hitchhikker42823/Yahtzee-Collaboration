
using namespace std;
#include "UIElements.h"
#include "FunctionDeclarations.h"
#include "PlayerClass.h"
//@TODO Back Button from Score Card Entry
//@TODO Fix total math
//@TODO fix stringstream on score placement selection
//@TODO fix softlock if scorecard fills in < 13 rounds
//@TODO comment way more
//@TODO fix text stating "press any key" when actually you need enter
//@TODO all caps name the constants
//@TODO enum the scorecard locations
//@TODO have scorecard search for a string to make it more resilient

int main()
{
	cout << UI_TITLE_CARD << "\n";
	cout << "Press any key to contiue...";
	string dummyString = ""; //to wait for input
	getline(cin, dummyString);


	Player player0;
	int roundsRemaining = 13; //start a new game

	while (roundsRemaining > 0)
	{
		roundsRemaining--; //advance turn count


		player0.FullNewHand(); //Roll a whole new hand
		int rerollsRemaining = 2; //start a new turn
		
		clearScreen();
		cout << "A new round has begun\n";
		cout << "Rounds remaining: " << roundsRemaining +1 << "\n"; //1 index vs 0 index

		//it feels a lot better if you press a key for the first hand
		cout << "Press any key to roll the first set of dice\n";
		string dummyString = ""; //to wait for input
		getline(cin, dummyString);

		while (rerollsRemaining > 0)
		{

			rerollsRemaining--; //advance number of rolls per turn
			
			//print hand
			clearScreen();
			player0.printCurrentHand();
			cout << "Rolls Left: " << rerollsRemaining +1 << "\n"; //1 index vs 0 index
			
			//logic to break the while loop if the user wants to keep their hand
			cout << UI_PROMPT_TO_KEEP;
			string userInput = "";
			while (userInput != "1" && userInput != "2")
			{
				userInput = "";
				getline(cin, userInput);
				StoUpper(userInput);
			}

			//if user selected to keep their hand, do the logic to verify and 
			if (userInput == "1")
			{
				player0.printScoreCard();
				player0.placeHandInScorecard();
				break; //after succeeding in placing the new score, 

			}

			//if the player does not want to keep this hand,
			//remove the selected dice and reroll
			else if (userInput == "2")
			{
				player0.removeAndRefill();
			}

		}

		//if we reach the end of 3 rolls, force to place in scorecard
		if (rerollsRemaining == 0)
		{
			clearScreen();
			player0.printCurrentHand();
			player0.printScoreCard();
			cout << "You have run out of rerolls. Please choose something to place this hand in.\n";
			player0.placeHandInScorecard();
		}



	}
	


	return 0;
}

