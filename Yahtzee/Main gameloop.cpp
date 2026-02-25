
using namespace std;
#include "UIElements.h"
#include "FunctionDeclarations.h"
#include "PlayerClass.h"
//@TODO What the hell is a bonus yahtzee
//@TODO if player inputs something other than 0 but not a score place, it just passes to the placement
//@TODO extend to multiple players by wrapping the game in a class and making a vector of players -- would need to print player at start of each turn

int main()
{
	cout << UI_TITLE_CARD << "\n";
	//cout << "Press enter to contiue...";
	//string dummyString = ""; //to wait for input
	//getline(cin, dummyString);

	//a vector that holds all the players
	std::vector<Player> listOfPlayers;

	int playerCount = getPlayerCount();
	createPlayers(playerCount, listOfPlayers);

	int currentPlayerID = 0; //start from first player

	while (!areAllScoreCardsFull(playerCount, listOfPlayers))
	{
		bool handPlaced = false; //flag set when hand placed. if we run out of rerolls without placing, force placement.

		listOfPlayers[currentPlayerID].FullNewHand(); //Roll a whole new hand
		int rerollsRemaining = 2; //start a new turn
		
		clearScreen();
		cout << "A new round has begun\n";

		//it feels a lot better if you press a key for the first hand
		cout << "Press enter to roll the first set of dice\n";
		cin.get(); //waits for the user to press enter and returns nothing


		while (rerollsRemaining > 0)
		{

			rerollsRemaining--; //advance number of rolls per turn
			
			//print hand
			clearScreen();
			listOfPlayers[currentPlayerID].printCurrentHand();
			listOfPlayers[currentPlayerID].printScoreCard();
			cout << "Rolls Left: " << rerollsRemaining +1 << "\n"; //1 index vs 0 index
			
			cout << "\nCurrent turn: " << listOfPlayers[currentPlayerID].PLAYER_NAME_STRING << "\n";
			cout << "Enter \"0\" to reroll part of the hand.\nOtherwise, enter the corresponding key on the score card.\n";
			string userInput = "";
			getline(cin, userInput);
			StoUpper(userInput);

			//if the player input 0, reroll part of the hand
			if (userInput == "0")
			{
				clearScreen();
				listOfPlayers[currentPlayerID].printCurrentHand();
				listOfPlayers[currentPlayerID].printScoreCard();

				listOfPlayers[currentPlayerID].removeAndRefill();
			}
			
			//if the player input anything else, go on to score placement logic
			else 
			{
				listOfPlayers[currentPlayerID].placeHandInScorecard(userInput);
				handPlaced = true;
				break; //after succeeding in placing the new score, end this turn
			}



		}

		//if we reach the end of 3 rolls without saving the score, force to place in scoreDataVector
		if (!handPlaced)
		{
			clearScreen();
			listOfPlayers[currentPlayerID].printCurrentHand();
			listOfPlayers[currentPlayerID].printScoreCard();

			cout << "You have run out of rerolls.\n";

			listOfPlayers[currentPlayerID].placeHandInScorecard("\0"); //call score placement logic with null intial value
		}


		if (areAllScoreCardsFull(playerCount, listOfPlayers))
		{
			//theoretically this will break the while loop before its condition check ever does
			//end the game if all players' scorecards are full
			break;
		}
		else
		{
			//increment current player and loop to the first one if we were on the last player
			//if the next player's scorecard is full, continue looping
			do
			{
				currentPlayerID = (currentPlayerID + 1) % playerCount;
			} while (listOfPlayers[currentPlayerID].isScoreCardFull() == true);
		}

	} 
	

	cout << "The game has ended! Final scores:\n";
	for (int currentPlayerID = 0; currentPlayerID < playerCount; currentPlayerID++)
	{
		listOfPlayers[currentPlayerID].printScoreCard();
	}

	return 0;
}

