
//these are included elsewhere and so aren't technically needed
//but I am leaving them here because they are used in this file
#include <vector>
#include <cstdlib>
#include <string>
#include <algorithm>

#include <random>
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;
#include "UIElements.h"
#include "FunctionDeclarations.h"
#include "PlayerClass.h"




//--------------------------------------------------------------------------------------//
//									Public Methods										//
//--------------------------------------------------------------------------------------//

Player::Player(int playerID, int MAX_HAND_SIZE)
	: playerID(playerID), MAX_HAND_SIZE(MAX_HAND_SIZE) //initializes constants
	//theoretically we can have hand size other than 5, but then scoring becomes hard
{
	//blank constructor body for now
}

//--------------------------------------------------------------------------------------//

//takes the current hand and iterates
void Player::printCurrentHand()
{

	cout << "\n"; //for formatting
	
	//print lines sequentially from UI_DICE_MATRIX
	//dice are 5 lines tall
	for (int j = 0; j < 5; j++) 
	{
		//in a given line, print one line for each value in the hand
		//if repeated for all lines, prints the dice next to eachother
		for (int i = 0; i < currentHand.size(); i++)
		{
			switch (currentHand[i])
			{
			case 1:
				//in j'th row of matrix, pull graphic for one line of a die
				//the die we need is at currentHand[i] -1 (0 index vector vs 1-6 dice)
				cout << UI_DICE_MATRIX[currentHand[i] -1][j];
				break;
			case 2:
				cout << UI_DICE_MATRIX[currentHand[i] -1][j];
				break;
			case 3:
				cout << UI_DICE_MATRIX[currentHand[i] - 1][j];
				break;
			case 4:
				cout << UI_DICE_MATRIX[currentHand[i] - 1][j];
				break;
			case 5:
				cout << UI_DICE_MATRIX[currentHand[i] - 1][j];
				break;
			case 6:
				cout << UI_DICE_MATRIX[currentHand[i] - 1][j];
				break;
			default:
				cout << "\nInvalid die value in this hand location\n";
			}

			cout << "  "; //space in between the dice
		}
		cout << "\n"; //go to next line of the graphic
	}

	return;
}

//--------------------------------------------------------------------------------------//

void Player::printScoreCard()
{
	//top section sum
	int upperSum = 0;
	int lowerSum = 0;
	int totalSum = 0;
	
	//create a copy of the scoreDataVector with nulls replaced with "-"
	vector<string>scoreCardCopy(scoreDataVector.size());
	for (int j = 0; j < scoreDataVector.size(); j++)
	{
		if (scoreDataVector[j] == Null)
		{ 
			scoreCardCopy[j] = "-";
		}
		else
		{
			scoreCardCopy[j] = to_string(scoreDataVector[j]);
		}
	}

	for (int j = 0; j < 6; j++) //upper sum
	{

		if (scoreDataVector[j] != Null)
		{
			upperSum += scoreDataVector[j];
		}
	}

	for (int j = 6; j < 14; j++) //lower sum
	{
		if (scoreDataVector[j] != Null)
		{
			lowerSum += scoreDataVector[j];
		}
	}

	//get total sum with bonus
	totalSum = upperSum + lowerSum;
	if (upperSum >= 63) { totalSum += 35; } //the upper bonus


	int j = 0; //for stepping through <int>scoreDataVector
	for (int i = 0; i < UI_SCORECARD_ART.size(); i++)
	{

		if (UI_SCORECARD_ART[i].size() == 26) //non score rows are 26 char long
		{
			cout << UI_SCORECARD_ART[i];
		}
		else //score row
		{
			if (i == 13) //upper section bonus in UI_SCORECARD_ART
			{
				cout << UI_SCORECARD_ART[i];
				cout << setw(3) << ((upperSum >= 63) ? "35" : "0"); //35 if we got the bonus, 0 otherwise
				cout << UI_SCORECARD_ART[++i]; //increment and print next
			}
			else if (i == 33) //upper total in UI_SCORECARD_ART
			{
				cout << UI_SCORECARD_ART[i];
				cout << setw(3) << upperSum;
				cout << UI_SCORECARD_ART[++i];
			}
			else if (i == 35) //lower total in UI_SCORECARD_ART
			{
				cout << UI_SCORECARD_ART[i];
				cout << setw(3) << lowerSum;
				cout << UI_SCORECARD_ART[++i];
			}
			else if (i == 37) //full total in UI_SCORECARD_ART
			{
				cout << UI_SCORECARD_ART[i];
				cout << setw(3) << totalSum;
				cout << UI_SCORECARD_ART[++i];
			}
			else //all other normal score
			{

				cout << UI_SCORECARD_ART[i];
				cout << setw(3) << scoreCardCopy[j];
				j++; //iterate through <int>scoreDataVector
				cout << UI_SCORECARD_ART[++i]; //increment and print next
			}

		}

		cout << "\n";
	}
}

//--------------------------------------------------------------------------------------//

void Player::FullNewHand()
{
	//throw away the old hand
	currentHand = {};

	//roll until hand is full
	for (int i = 0; i < MAX_HAND_SIZE; i++)
	{

		currentHand.push_back(rollOne());
	}

	return;
}

//--------------------------------------------------------------------------------------//


vector<int> Player::askForNumbersToRemove()
{
	vector<int> numbersToRemove = {};
	string input = "";
	int singularValue;

	cout << "\nPlease enter numbers to remove (as integers with spaces between them):\n";
	getline(cin, input);

	stringstream ss(input); //turns the input into a stream like cin
	while (ss >> singularValue) //keep going until we fail to store a valid value
	{
		numbersToRemove.push_back(singularValue);
	}


	return numbersToRemove;
}

//--------------------------------------------------------------------------------------//

//Just rolls and adds numbers until the hand has 5 dice in it
void Player::fillHand()
{
	while (currentHand.size() < MAX_HAND_SIZE)
	{
		currentHand.push_back(rollOne());
	}

	return;
}

//--------------------------------------------------------------------------------------//

//a combination function that prompts for numbers to remove, 
//removes them, and then returns the refilled hand
void Player::removeAndRefill()
{
	vector<int> numbersToRemove = askForNumbersToRemove();
	removeFromHand(numbersToRemove);
	fillHand();

	return;
}

//--------------------------------------------------------------------------------------//

//takes user input for where to place the current hand in the scoreDataVector and then does that
void Player::placeHandInScorecard(string initialInput)
{
	int ScorePlacedExitCode = 1;
	char cardPlaceSelected = initialInput[0];
	while (ScorePlacedExitCode != 0)
	{
		//first try to execute the function with the given input
		//if that fails, cin at bottom of while loop
		cardPlaceSelected = toupper(cardPlaceSelected); //caps insensitve

		int inputAsInt = cardPlaceSelected - '0'; //ASCII math
		switch (cardPlaceSelected) {
		case '1': case '2': case '3':
		case '4': case '5': case '6':
			ScorePlacedExitCode = setUpperSection(inputAsInt); break;
		case 'Q':  ScorePlacedExitCode = set3oaK();            break;
		case 'W':  ScorePlacedExitCode = set4oaK();            break;
		case 'E':  ScorePlacedExitCode = setFullHouse();       break;
		case 'R':  ScorePlacedExitCode = setSmallStraight();   break;
		case 'T':  ScorePlacedExitCode = setLargeStraight();   break;
		case 'Y':  ScorePlacedExitCode = setYahtzee();         break;
		case 'U':  ScorePlacedExitCode = setChance();          break;
		default:
			//if the user inputs anything other than 0, that value will be passed to this
			//this will do nothing and let the loop continue until a valid place is selected
			break;
		}

		//don't prompt for input if we succeeded above
		if (ScorePlacedExitCode != 0)
		{
			//if we got an invalid value, get a new input
			cout << "Please enter a score card position.\n";
			cin >> cardPlaceSelected;
		}


	}

	return;
}

//--------------------------------------------------------------------------------------//
//									Private Methods										//
//--------------------------------------------------------------------------------------//

//rolls a die
//all other rolling functions reference this, 
// so use this to alter the dice fundamentally
int Player::rollOne()
{
	//random number generation but *fancy* 
	//(will only call this block the first time)
	static random_device rd; //gets a seed from entropy
	static mt19937 engine(rd()); //puts it in a fancy engine
	static uniform_int_distribution<int> dist(1, 6); //defines the range of values

	return dist(engine); //actually roll and return the value
}

//--------------------------------------------------------------------------------------//

void Player::removeFromHand(vector<int> numbersToRemove)
{
	while (numbersToRemove.size() > 0)
	{

		for (int i = 0; i < currentHand.size(); i++)
		{
			//check against the last element of vector to remove
			if (currentHand[i] == numbersToRemove[numbersToRemove.size() - 1])
			{
				currentHand.erase(currentHand.begin() + i);
				numbersToRemove.pop_back();
				break; //if we find a number, stop iterating through the hand
			}
			else if (i == currentHand.size() - 1) //if we are at the end of the hand and it doesn't match then...
			{
				numbersToRemove.pop_back(); //value wasn't found, so remove it
			}
		}

	}

	return;
}


//--------------------------------------------------------------------------------------//

int  Player::setUpperSection(int sectionToSet)
{
	//only allow to add things if the scoreDataVector slot is empty
	if (scoreDataVector[sectionToSet - 1] != Null)
	{
		//there was already something there
		cout << "There is already something in this score space\n";
		return 2;
	}

	//if score slot is empty, do the math
	//tally all #s of the section selected
	int runningTotal = 0;
	for (int i = 0; i < MAX_HAND_SIZE; i++)
	{
		if (currentHand[i] == sectionToSet)
		{
			runningTotal += sectionToSet;
		}
	}

	//if the user tries to 0 something, check
	if (runningTotal == 0)
	{
		cout << "Are you sure you want to zero the " << sectionToSet << "s? (Y / N)\n";

		while (true) //broken by if/else
		{
			string userInput = "";
			getline(cin, userInput);
			StoUpper(userInput);
			if (userInput == "Y") //if user confirms and we haven't already put something here
			{
				scoreDataVector[sectionToSet - 1] = 0;
				return 0;
			}
			else if (userInput == "N")
			{
				return 1; //error code 
			}
		}
	}
	
	//total != 0
	else
	{
		scoreDataVector[sectionToSet - 1] = runningTotal;
		return 0;
	}
		

	return -1; //unreachable fallthrough return
}

//--------------------------------------------------------------------------------------//
	
int Player::set3oaK()
{
	int count = 0;
	int runningTotal = 0;

	//only allow to add things if the scoreDataVector slot is empty
	if (scoreDataVector[ThreeOaK] != Null)
	{
		cout << "There is already something in this score space\n";
		return 2;
	}

	//if score slot is empty, do the math
	//for each value a die could take
	for (int j = 0; j < 6; j++)
	{
		//if we didn't count to 3oaK for the last value, reset the coutner
		if (count < 3) { count = 0; }

		for (int i = 0; i < MAX_HAND_SIZE; i++)
		{
			runningTotal += currentHand[i];
			if (currentHand[i] == j)
			{
				count++;
			}
			//@DEBUG this logic might not be sound?

		}
	}

	//user must confrim they want to zero a space
	if (count < 3)
	{
		cout << "This is not a 3 of a kind. Are you sure you want to zero this? (Y/N)\n";

		while (true) //broken by if/else
		{
			string userInput = "";
			getline(cin, userInput);
			StoUpper(userInput);
			if (userInput == "Y")
			{
				scoreDataVector[ThreeOaK] = 0;
				return 0;
			}
			else if (userInput == "N")
			{
				return 1;
			}
		}
	}
	//valid 3oaK
	else
	{
		scoreDataVector[ThreeOaK] = runningTotal;
		return 0;
	}

	return -1; //unreachable fallthrough return

}

//--------------------------------------------------------------------------------------//

//same as 3oaK but count must hit 4
int Player::set4oaK()
{
	int count = 0;
	int runningTotal = 0;

	//only allow to add things if the scoreDataVector slot is empty
	if (scoreDataVector[FourOaK] != Null)
	{
		cout << "There is already something in this score space\n";
		return 2;
	}

	//if score slot is empty, do the math
	//for each value a die could take
	for (int j = 0; j < 6; j++)
	{
		//if we didn't count to 4oaK for the last value, reset the coutner
		if (count < 4) { count = 0; }

		for (int i = 0; i < MAX_HAND_SIZE; i++)
		{
			runningTotal += currentHand[i];
			if (currentHand[i] == j)
			{
				count++;
			}
			//@DEBUG this logic might not be sound?

		}
	}
		
	//if we didn't count 4 dice of the same kind, it's not valid
	if (count < 4)
	{
		cout << "This is not a 4 of a kind. Are you sure you want to zero this? (Y/N)\n";

		while (true) //broken by if/else
		{
			string userInput = "";
			getline(cin, userInput);
			StoUpper(userInput);
			if (userInput == "Y")
			{
				scoreDataVector[FourOaK] = 0;
				return 0;
			}
			else if (userInput == "N")
			{
				return 1;
			}
		}
	}
	//valid 4oaK
	else
	{
		scoreDataVector[FourOaK] = runningTotal;
		return 0;
	}

	return -1; //unreachable fallthrough return
}

//--------------------------------------------------------------------------------------//

int Player::setFullHouse()
{
	int count = 0;

	//only allow to add things if the scoreDataVector slot is empty
	if (scoreDataVector[FullHouse] != Null)
	{
		cout << "There is already something in this score space\n";
		return 2;
	}

	//if score slot is empty, do the math
	//for each value a die could take
	for (int j = 0; j < 6; j++)
	{
		//count how many times a given value appears
		for (int i = 0; i < MAX_HAND_SIZE; i++)
		{
			if (currentHand[i] == j)
			{
				count++;
			}
		}

		// if there's 1,4, or 5 of any given number it cannot be a full house
		//Note that this will break if we ever change the hand size
		if (count == 1 || count == 4 || count == 5)
		{
			cout << "This is not a full house. Are you sure you want to zero this? (Y/N)\n";

			while (true) //broken by if/else
			{
				string userInput = "";
				getline(cin, userInput);
				StoUpper(userInput);
				if (userInput == "Y")
				{
					scoreDataVector[FullHouse] = 0;
					return 0;
				}
				else if (userInput == "N")
				{
					return 1;
				}
			}
		}
		count = 0;
	}

	//if above didn't fail it must be a full house
	scoreDataVector[8] = 25; //Full House is worth 25 points
	return 0;
		
}

//--------------------------------------------------------------------------------------//

int Player::setSmallStraight()
{
	//only allow to add things if the scoreDataVector slot is empty
	if (scoreDataVector[SmStraight] != Null)
	{
		cout << "There is already something in this score space\n";
		return 2;
	}

	//if score slot is empty, do the math
	//sort from <algorithm> does smallest to largest
	sort(currentHand.begin(), currentHand.end());

	int count = 0;

	for (int i = 0; i < MAX_HAND_SIZE-1; i++)
	{
		if (currentHand[i] == currentHand[i + 1] - 1)
		{
			count++;
		}
		else if (currentHand[i] == currentHand[i + 1])
		{
			//do nothing if we get duplicates in the middle of the straight
			//@TODO redo this?
		}
		else
		{
			count = 0;
		} //@DEBUG this logic might not be sound
	}

	//confrim a zero
	if (count < 4)
	{
		cout << "This is not a small straight. Are you sure you want to zero this? (Y/N)\n";

		while (true) //broken by if/else
		{
			string userInput = "";
			std::getline(cin, userInput);
			StoUpper(userInput);
			if (userInput == "Y")
			{
				scoreDataVector[SmStraight] = 0;
				return 0;
			}
			else if (userInput == "N")
			{
				return 1;
			}
		}
	}
	//valid small straight
	else
	{
		scoreDataVector[SmStraight] = 30; //A small straight is worth 30 points
		return 0;
	}

	return -1; //unreachable fallthrough return
}
	
//--------------------------------------------------------------------------------------//

int Player::setLargeStraight()
{
	int count = 0;

	//only allow to add things if the scoreDataVector slot is empty
	if (scoreDataVector[LgStraight] != Null)
	{
		cout << "There is already something in this score space\n";
		return 2;
	}

	//if score slot is empty, do the math
	//sort from <algorithm> does smallest to largest
	std::sort(currentHand.begin(), currentHand.end());

	for (int i = 0; i < MAX_HAND_SIZE - 1; i++)
	{
		if (currentHand[i] != currentHand[i + 1] - 1)
		{
			cout << "This is not a large straight. Are you sure you want to zero this? (Y/N)\n";

			while (true) //broken by if/else
			{
				string userInput = "";
				std::getline(cin, userInput);
				StoUpper(userInput);
				if (userInput == "Y")
				{
					scoreDataVector[LgStraight] = 0;
					return 0;
				}
				else if (userInput == "N")
				{
					return 1;
				}
			}
		}
	}
		
	//if above didn't fail it's a valid large straight
	scoreDataVector[10] = 40; //Large Straight is worth 40 points
	return 0;

	return -1; //unreachable fallthrough return
}

//--------------------------------------------------------------------------------------//

int Player::setYahtzee()
{
	int numberOnTheDie = 0;
	numberOnTheDie = currentHand[0];

	//only allow to add things if the scoreDataVector slot is empty
	if (scoreDataVector[YahtzeeIndex] != Null)
	{
			cout << "There is already something in this score space\n";
			return 2;
	}
	
	//@TODO investigate this logic
	//if score slot is empty, do the math
	for (int i = 0; i < MAX_HAND_SIZE; i++)
	{
		if (currentHand[i] != numberOnTheDie)
		{
			cout << "This is not a Yahtzee. Are you sure you want to zero this? (Y/N)\n";

			while (true) //broken by if/else
			{
				string userInput = "";
				std::getline(cin, userInput);
				StoUpper(userInput);
				if (userInput == "Y")
				{
					scoreDataVector[YahtzeeIndex] = 0;
					return 0;
				}
				else if (userInput == "N")
				{
					return 1;
				}
			}
		}
		//@TODO: Add bonus yahtzee here

	}

	//if loop never returned, it must be a valid Yahtzee
	scoreDataVector[YahtzeeIndex] = 50; //Yahtzee is worth 50 points
	return 0;
		
	return -1; //unreachable fallthrough return
}

//--------------------------------------------------------------------------------------//

int Player::setChance()
{
	//do math first since this one is really small
	int runningTotal = 0;
	for (int i = 0; i < MAX_HAND_SIZE; i++)
	{
			runningTotal += currentHand[i];
	}

	if (scoreDataVector[Chance] != Null)
	{
		cout << "There is already something in this score space\n";
		return 2;
	}
	else
	{
		scoreDataVector[Chance] = runningTotal;
		return 0;
	}

	return -1; //unreachable fallthrough return
}
