/*------------------------------------------------------------------------------------------------------/
/ @Author:          Aidan Bernardo
/
/ @Date Modified:   3/24/26
/
/ @Description:     Contains a few definitions for functions that should not be member methods of the 
/					player class. Used mostly in the main gameloop.
/------------------------------------------------------------------------------------------------------*/


#include <vector>

using namespace std;
#include "UIElements.h"
#include "FunctionDeclarations.h"
#include "PlayerClass.h"


//A function to convert a string to all uppercase
//note that unlike stoi() and similar, this is pass by reference and modifies the original string
void StoUpper(std::string& inputString)
{
	for (char& c : inputString) {
		c = std::toupper(c);
	}

	return;
}

//--------------------------------------------------------------------------------------//

//iterates to check if all score cards are full
bool areAllScoreCardsFull(int playerCount, vector<Player>& listOfPlayers)
{
	for (int i = 0; i < playerCount; i++)
	{
		//if any are not full, we can immediately quit
		if (listOfPlayers[i].isScoreCardFull() == false)
		{
			return false;
		}

	}

	return true;
}

//--------------------------------------------------------------------------------------//

int getPlayerCount()
{
	//get user input until they correctly input a positive int-eger
	cout << "\n\nHow many players should be added?: ";
	int playerCount = 0;
	while (playerCount <= 0)
	{
		try
		{
			string playerCountInput = "";
			getline(cin, playerCountInput);
			playerCount = stoi(playerCountInput);

		}
		catch (...) {  /*do nothing and cin again*/ }
	}

	return playerCount;
}

//--------------------------------------------------------------------------------------//

//creates specified number of players
void createPlayers(int playerCount, vector<Player>& listOfPlayers)
{
	//creates requested number of players
	//prompts for a name string for human names
	for (int i = 1; i <= playerCount; i++)
	{
		cout << "Please enter a name for player " << i << ": ";

		string enteredPlayerName = "";
		getline(cin, enteredPlayerName);

		
		//instantiates class and passes (PLAYER_ID, MAX_HAND_SIZE, PLAYER_NAME) to the constructor
		listOfPlayers.emplace_back(enteredPlayerName);
	}
}