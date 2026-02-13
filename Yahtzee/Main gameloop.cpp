
using namespace std;
#include "UIElements.h"
#include "FunctionDeclarations.h"
#include "PlayerClass.h"
//@TODO fix softlock if scoreDataVector fills in < 13 rounds (bonus yahtzee or glitch)
//@TODO What the hell is a bonus yahtzee
//@TODO if player inputs something other than 0 but not a score place, it just passes to the placement

int main()
{
	cout << UI_TITLE_CARD << "\n";
	cout << "Press enter to contiue...";
	string dummyString = ""; //to wait for input
	getline(cin, dummyString);


	Player player0;
	int roundsRemaining = 13; //start a new game, 13 rounds in a game

	while (roundsRemaining > 0)
	{
		bool handPlaced = false; //flag set when hand placed. if we run out of rerolls without placing, force placement.

		player0.FullNewHand(); //Roll a whole new hand
		int rerollsRemaining = 2; //start a new turn
		
		clearScreen();
		cout << "A new round has begun\n";
		cout << "Rounds remaining: " << roundsRemaining-- << "\n"; //1 index vs 0 index

		//it feels a lot better if you press a key for the first hand
		cout << "Press enter to roll the first set of dice\n";
		cin.get(); //waits for the user to press enter and returns nothing


		while (rerollsRemaining > 0)
		{

			rerollsRemaining--; //advance number of rolls per turn
			
			//print hand
			clearScreen();
			player0.printCurrentHand();
			player0.printScoreCard();
			cout << "Rolls Left: " << rerollsRemaining +1 << "\n"; //1 index vs 0 index
			

			cout << "\nEnter \"0\" to reroll part of the hand.\nOtherwise, enter the corresponding key on the score card.\n";
			string userInput = "";
			getline(cin, userInput);
			StoUpper(userInput);

			//if the player input 0, reroll part of the hand
			if (userInput == "0")
			{
				clearScreen();
				player0.printCurrentHand();
				player0.printScoreCard();

				player0.removeAndRefill();
			}

			//if the player input anything else, go on to score playcement logic
			else
			{
				player0.placeHandInScorecard(userInput);
				handPlaced = true;
				break; //after succeeding in placing the new score, 
			}



		}

		//if we reach the end of 3 rolls without saving the score, force to place in scoreDataVector
		if (!handPlaced)
		{
			clearScreen();
			player0.printCurrentHand();
			player0.printScoreCard();

			cout << "You have run out of rerolls.\n";

			player0.placeHandInScorecard("\0"); //call score placement logic with null intial value
		}



	}
	


	return 0;
}

