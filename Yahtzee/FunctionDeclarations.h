/*------------------------------------------------------------------------------------------------------/
/ @Author:          Aidan Bernardo
/
/ @Date Modified:   3/24/26
/
/ @Description:     The declarations for the general functins not part of the player class.
/------------------------------------------------------------------------------------------------------*/


#pragma once

#include <string>
#include <iostream>

#include "PlayerClass.h"


//Asks the system to execute "cls"
//so small that it can be inline and defined here
inline void clearScreen() {
	system("cls");
}

//A function to convert a string to all uppercase
//note that unlike stoi() and similar, this is pass by reference and modifies the original string
void StoUpper(std::string& inputString);

//iterates to check if all score cards are full
bool areAllScoreCardsFull(int playerCount, vector<Player>& listOfPlayers);

//prompts for and returns number of players to add to the game
int getPlayerCount();

//instantiates the player class a specified number of times
void createPlayers(int playerCount, vector<Player>& listOfPlayers);