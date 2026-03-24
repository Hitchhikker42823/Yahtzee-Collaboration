/*------------------------------------------------------------------------------------------------------/
/ @Author:          Aidan Bernardo
/
/ @Date Modified:   3/24/26
/
/ @Description:     The overall structure of the class that defines a player. Contains their name, score,
/					and any methods necessary to alter their score. Instantiated in the main gameloop.
/------------------------------------------------------------------------------------------------------*/


#pragma once


class Player {

public:
	//Constants initialized with the class
	static const int MAX_HAND_SIZE = 5;
	const string PLAYER_NAME_STRING;

	//Constructor
	Player(string PLAYER_NAME_STRING = "Default Player Name");

	//takes the current hand and iterates through it to print it
	void printCurrentHand();

	//prints the score card UI graphic with values filled in
	void printScoreCard();

	//discards the current hand and rolls a new one
	void FullNewHand(); //@NOTE: private?

	//prompts players for numbers to remove from the current hand
	std::vector<int> askForNumbersToRemove();

	//rolls new numbers until the player's hand is full
	void fillHand(); //@NOTE: private?

	//prompts player to remove a value from their hand and then refills it
	void removeAndRefill();

	//prompts player to put their hand in the scoreDataVector,
	// validates the potential score, and then enters the
	// value of the hand into  std::vector<int> scoreDataVector
	void placeHandInScorecard(string initialInput);
	
	//checks whether the player's scorecard is completely full
	//once all players' cards are completley full, the game is over
	bool isScoreCardFull();

	//Allows the user to manually set their hand for debugging or cheating purposes
	void debugManualHand();

private:

	//just to make it clearer that -1 is null
	const enum Null { Null = -1 };

	//Variables
	std::vector<int> currentHand = {};
	std::vector<int> scoreDataVector = { Null, Null, Null, Null, Null, Null, Null, Null, Null, Null, Null, Null, Null, Null };
	//{1s, 2s, 3s, 4s, 5s, 6s, 3oaK, 4oaK, FllHs, SmSt, LgSt, YAHT, Chnc, BnsYah}
	
	//An enum to give a name to the indicies within the scoreDataVector. Mostly for the score setting functions.
	const enum ScoreCardIndices
	{
		Ones, Twos, Threes, Fours, Fives, Sixes, ThreeOaK, FourOaK, FullHouse, SmStraight, LgStraight, YahtzeeIndex, Chance, BnsYahtzee
	};


	//Functions
	//defines what a single die roll is
	int rollOne();

	//removes the given nubmbers from the hand
	void removeFromHand(std::vector<int> numbersToRemove);

	//The functions to validate the current hand's value and put it in the scoreDataVector
	int  setUpperSection(int sectionToSet);

	int set3oaK();

	int set4oaK();

	int setFullHouse();

	int setSmallStraight();

	int setLargeStraight();

	int setYahtzee();

	int setChance();

};

