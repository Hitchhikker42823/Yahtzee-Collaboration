#pragma once
#include "UIElements.cpp"
#include <vector>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <random>
#include <string>
#include <algorithm>
using namespace std;

using namespace std;

class Player {
private:

	//Constants
	const int playerID;
	const int maxHandSize;

	//Variables
	vector<int> currentHand = {};

	vector<int> scoreCard = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
	//{1s, 2s, 3s, 4s, 5s, 6s, 3oaK, 4oaK, FllHs, SmSt, LgSt, YAHT, Chnc, BnsYah}

	//rolls a die
	//all other rolling functions reference this, so use this to alter the dice fundamentally
	int rollOne()
	{
		//random number generation but *fancy* 
		//(will only call this block the first time)
		static random_device rd; //gets a seed from entropy
		static mt19937 engine(rd()); //puts it in a fancy engine
		static uniform_int_distribution<int> dist(1, 6); //defines the range of values

		return dist(engine); //actually roll and return the value
	}


public:
	//Constructor
	Player(int playerID= 0, int maxHandSize= 5)
		: playerID(playerID), maxHandSize(maxHandSize) //initializes constants
	{
	 //blank constructor body for now
	}


	//--------------------------------------------------------------------------------------//

	//takes the current hand and iterates through it to print it
	void printCurrentHand()
	{
		for (int i = 0; i < currentHand.size(); i++)
		{
			switch (currentHand[i])
			{
			case 1:
				cout << UIDieImage1;
				break;
			case 2:
				cout << UIDieImage2;
				break;
			case 3:
				cout << UIDieImage3;
				break;
			case 4:
				cout << UIDieImage4;
				break;
			case 5:
				cout << UIDieImage5;
				break;
			case 6:
				cout << UIDieImage6;
				break;
			default:
				cout << "\nInvalid die value in this hand location\n";
			}
		}

		return;
	}
 
	//--------------------------------------------------------------------------------------//

	void FullNewHand()
	{
		//throw away the old hand
		currentHand = {};

		//roll until hand is full
		for (int i = 0; i < maxHandSize; i++)
		{

			currentHand.push_back(rollOne());
		}

		return;
	}

	//--------------------------------------------------------------------------------------//

	void removeFromHand(vector<int> numbersToRemove)
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

	//@TODO replace with a GUI eventually
	vector<int> askForNumbersToRemove()
	{
		vector<int> numbersToRemove = {};
		string input = "";
		int singularValue;

		cout << "\nPlease enter numbers to remove:\n";
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
	void fillHandTo5()
	{
		while (currentHand.size() < maxHandSize)
		{
			currentHand.push_back(rollOne());
		}
	
		return;
	}

	//--------------------------------------------------------------------------------------//

	//a combination function that prompts for numbers to remove, 
	//removes them, and then returns the refilled hand
	void removeAndRefill()
	{
		vector<int> numbersToRemove = askForNumbersToRemove();
		removeFromHand(numbersToRemove);
		fillHandTo5();

		return;
	}

	//--------------------------------------------------------------------------------------//

	int  setUpperSection(int sectionToSet)
	{
		//tally all #s of the section selected
		int runningTotal = 0;
		for (int i = 0; i < maxHandSize; i++)
		{
			if (currentHand[i] == sectionToSet)
			{
				runningTotal += sectionToSet;
			}
		}

		//if the user tries to 0 something, check
		if (runningTotal == 0)
		{
			cout << "Are you sure you want to zero this ? (Y / N)\n";

			while (true) //broken by if/else
			{
				string userInput = "";
				getline(cin, userInput);
				StoUpper(userInput);
				if (userInput == "Y" && scoreCard[sectionToSet - 1] == -1) //if user confirms and we haven't already put something here
				{
					scoreCard[sectionToSet - 1] = 0;
					return 0;
				}
				else if (userInput == "N")
				{
					return 1; //error code 
				}
			}

			scoreCard[sectionToSet - 1] = runningTotal;

			return 0;
		}
	}

	//--------------------------------------------------------------------------------------//
	
	int set3oaK()
	{
		int count = 0;
		int runningTotal = 0;

		//loop through and count how many 1s,2s,3s,4s,5s,6s.
		//sum all no matter if it's 3oaK or not
		for (int j = 0; j < 6; j++)
		{
			//if last number wasn't 3oaK, re-count. Otherwise, remember the fact it's 3oaK
			if (count < 3) { count = 0; }

			for (int i = 0; i < maxHandSize; i++)
			{
				runningTotal += currentHand[i];
				if (currentHand[i] == j)
				{
					count++;
				}
				//@DEBUG this logic might not be sound?

			}
		}
		
		
		//if it's 3oaK and scorecard place hasn't been written to yet, add it
		if (count == 3 && scoreCard[6] == -1)
		{
			scoreCard[6] = runningTotal;
			return 0;
		}
		//user must confrim they want to zero a space
		else if (count < 3)
		{
			cout << "This is not a 3 of a kind. Are you sure you want to zero this? (Y/N)\n";

			while (true) //broken by if/else
			{
				string userInput = "";
				getline(cin, userInput);
				StoUpper(userInput);
				if (userInput == "Y" && scoreCard[6] == -1)
				{
					scoreCard[6] = 0;
					return 0;
				}
				else if (userInput == "N")
				{
					return 1;
				}
			}
			
		}
		return 2; //this should not be reached
	}

	//--------------------------------------------------------------------------------------//

	//same as 3oaK but count must hit 4
	int set4oaK()
	{
		int count = 0;
		int runningTotal = 0;

		//loop through and count how many 1s,2s,3s,4s,5s,6s.
		//sum all no matter if it's 4oaK or not
		for (int j = 0; j < 6; j++)
		{
			//if last number wasn't 3oaK, re-count. Otherwise, remember the fact it's 4oaK
			if (count < 4) { count = 0; }

			for (int i = 0; i < maxHandSize; i++)
			{
				runningTotal += currentHand[i];
				if (currentHand[i] == j)
				{
					count++;
				}
				//@DEBUG this logic might not be sound?

			}
		}

		//if it's 4oaK and scorecard place hasn't been written to yet, add it
		if (count == 4 && scoreCard[7] == -1)
		{
			scoreCard[7] = runningTotal;
			return 0;
		}
		//user must confrim they want to zero a space
		else if (count < 4)
		{
			cout << "This is not a 4 of a kind. Are you sure you want to zero this? (Y/N)\n";

			while (true) //broken by if/else
			{
				string userInput = "";
				getline(cin, userInput);
				StoUpper(userInput);
				if (userInput == "Y" && scoreCard[7] == -1)
				{
					scoreCard[7] = 0;
					return 0;
				}
				else if (userInput == "N")
				{
					return 1;
				}
			}

		}
		return 2; //this should not be reached
	}

	//--------------------------------------------------------------------------------------//

	int setFullHouse()
	{
		int count = 0;

		for (int j = 0; j < 6; j++)
		{

			for (int i = 0; i < maxHandSize; i++)
			{
				if (currentHand[i] == j)
				{
					count++;
				}
			}

			// if there's 1,4, or 5 of any given number it cannot be a full house
			if (count == 1 || count == 4 || count == 5)
			{
				cout << "This is not a full house. Are you sure you want to zero this? (Y/N)\n";

				while (true) //broken by if/else
				{
					string userInput = "";
					getline(cin, userInput);
					StoUpper(userInput);
					if (userInput == "Y" && scoreCard[8] == -1)
					{
						scoreCard[8] = 0;
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

		//if it got through everything above it must be a full house
		if (scoreCard[8] == -1)
		{
			scoreCard[8] = 25;
			return 0;
		}
		
		return 2; //should not be reached
	}

	//--------------------------------------------------------------------------------------//

	int setSmallStraight()
	{
		//sort from <algorithm> does smallest to largest
		sort(currentHand.begin(), currentHand.end());

		int count = 0;

		for (int i = 0; i < maxHandSize-1; i++)
		{
			if (currentHand[i] == currentHand[i + 1] - 1)
			{
				count++;
			}
			else
			{
				count = 0;
			} //@DEBUG this logic might not be sound
		}

		if (count >= 4 && scoreCard[9] == -1)
		{
			scoreCard[9] = 30;
			return 0;
		}
		else
		{
			cout << "This is not a small straight. Are you sure you want to zero this? (Y/N)\n";

			while (true) //broken by if/else
			{
				string userInput = "";
				getline(cin, userInput);
				StoUpper(userInput);
				if (userInput == "Y" && scoreCard[9] == -1)
				{
					scoreCard[9] = 0;
					return 0;
				}
				else if (userInput == "N")
				{
					return 1;
				}
			}
		}
	}
	
	//--------------------------------------------------------------------------------------//

	int setLargeStraight()
	{
		//sort from <algorithm> does smallest to largest
		sort(currentHand.begin(), currentHand.end());

		int count = 0;

		for (int i = 0; i < maxHandSize - 1; i++)
		{
			if (currentHand[i] != currentHand[i + 1] - 1)
			{
				cout << "This is not a large straight. Are you sure you want to zero this? (Y/N)\n";

				while (true) //broken by if/else
				{
					string userInput = "";
					getline(cin, userInput);
					StoUpper(userInput);
					if (userInput == "Y" && scoreCard[10] == -1)
					{
						scoreCard[10] = 0;
						return 0;
					}
					else if (userInput == "N")
					{
						return 1;
					}
				}
			}
		}

		if (scoreCard[10] == -1)
		{
			scoreCard[10] = 40;
			return 0;
		}

		return 2; //should not be reached
	}

	//--------------------------------------------------------------------------------------//

	int setYahtzee()
	{
		int numberOnTheDie = 0;
		numberOnTheDie = currentHand[0];

		for (int i = 0; i < maxHandSize; i++)
		{
			if (currentHand[i] != numberOnTheDie)
			{
				cout << "This is not a Yahtzee. Are you sure you want to zero this? (Y/N)\n";

				while (true) //broken by if/else
				{
					string userInput = "";
					getline(cin, userInput);
					StoUpper(userInput);
					if (userInput == "Y" && scoreCard[11] == -1)
					{
						scoreCard[11] = 0;
						return 0;
					}
					else if (userInput == "N")
					{
						return 1;
					}
				}
			}
			else if (scoreCard[11] == -1)
			{
				scoreCard[11] = 50;
				return 0;
			}
			//@TODO: Add bonus yahtzee here
		}

		return 2; //should not be reached
	}
};

//@TODO reduce magic numbers by defining a bunch of constants