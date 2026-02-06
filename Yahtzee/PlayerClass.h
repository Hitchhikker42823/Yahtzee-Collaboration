#pragma once



//@TODO: What the hell is a bonus yahtzee
//@TODO: reduce magic numbers by defining a bunch of constants

class Player {

public:
	//Constructor
	Player(int playerID = 0, int maxHandSize = 5);

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

	//prompts player to put their hand in the scorecard,
	// validates the potential score, and then enters the
	// value of the hand into  std::vector<int> scoreCard
	void placeHandInScorecard();



private:
	//Constants initialized with the class
	const int playerID;
	const int maxHandSize;


	//Variables
	std::vector<int> currentHand = {};
	std::vector<int> scoreCard = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
	//{1s, 2s, 3s, 4s, 5s, 6s, 3oaK, 4oaK, FllHs, SmSt, LgSt, YAHT, Chnc, BnsYah}


	//Functions
	//defines what a single die roll is
	int rollOne();

	//removes the given nubmbers from the hand
	void removeFromHand(std::vector<int> numbersToRemove);

	//The functions to validate the current hand's value and put it in the scorecard
	int  setUpperSection(int sectionToSet);

	int set3oaK();

	int set4oaK();

	int setFullHouse();

	int setSmallStraight();

	int setLargeStraight();

	int setYahtzee();

	int setChance();

};

