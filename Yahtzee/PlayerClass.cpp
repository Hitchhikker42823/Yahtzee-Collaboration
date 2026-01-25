#pragma once
#include "UIElements.cpp"
#include <vector>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <random>
using namespace std;

using namespace std;

class Player {
private:

	//Constants
	const int playerID;
	const int maxHandSize;

	//Variables
	vector<int> currentHand = {};

	vector<int> scoreCard = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
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

	//Just rolls and adds numbers until the hand has 5 dice in it
	void fillHandTo5()
	{
		while (currentHand.size() < maxHandSize)
		{
			currentHand.push_back(rollOne());
		}
	
		return;
	}

	//a combination function that prompts for numbers to remove, 
	//removes them, and then returns the refilled hand
	void removeAndRefill()
	{
		vector<int> numbersToRemove = askForNumbersToRemove();
		removeFromHand(numbersToRemove);
		fillHandTo5();

		return;
	}




};