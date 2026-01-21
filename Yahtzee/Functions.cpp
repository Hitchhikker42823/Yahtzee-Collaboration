
#include <cstdlib>
#include <iostream>
#include <vector>
#include <sstream>
#include <random>
using namespace std;

//rolls a die
int rollOne()
{
	//random number generation but *fancy* 
	//(will only call this block the first time)
	static random_device rd; //gets a seed from entropy
	static mt19937 engine(rd()); //puts it in a fancy engine
	static uniform_int_distribution<int> dist(1, 6); //defines the range of values
	
	return dist(engine); //actually roll and return the value
}

//takes the current hand and iterates through it to print it
void printCurrentHand(vector<int> currentHand)
{
	for (int i = 0; i < currentHand.size(); i++)
	{
		cout << currentHand[i] << " \n";
	}
}

//rolls 5 dice and returns a full hand. 

vector<int> roll5Dice()
{
	//hands are only 5 big; rolling 5 dice means we can just throw away the old hand
	vector<int> currentHand = {};


	for (int i = 0; i < 5; i++)
	{

		currentHand.push_back(rollOne());
	}

	return currentHand;
}

vector<int> removeFromHand(vector<int> inputHand, vector<int> numbersToRemove)
{
	while (numbersToRemove.size() > 0)
	{

		for (int i = 0; i < inputHand.size(); i++)
		{
			//check against the last element of vector to remove
			if (inputHand[i] == numbersToRemove[numbersToRemove.size() -1]) 
			{
				inputHand.erase(inputHand.begin() + i);
				numbersToRemove.pop_back();
				break; //if we find a number, stop iterating through the hand
			}
			else if (i == inputHand.size() - 1) //if we are at the end of the hand and it doesn't match then...
			{
				numbersToRemove.pop_back(); //value wasn't found, so remove it
			}
		}

	}


	//inputHand should now have numbers removed
	return inputHand;
}

vector<int> askForNumbersToRemove()
{
	vector<int> numbersToRemove = {};
	string input = "";
	int singularValue;
	
	cout << "Please enter numbers to remove:\n";
	getline(cin, input);

	stringstream ss(input); //turns the input into a stream like cin
	while (ss >> singularValue) //keep going until we fail to store a valid value
	{
		numbersToRemove.push_back(singularValue);
	}


	return numbersToRemove;
}