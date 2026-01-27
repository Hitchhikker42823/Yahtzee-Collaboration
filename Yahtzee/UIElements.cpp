#pragma once
#include <string>
#include <iostream>
using namespace std;


//Dice
const char UIDieImage1[] = R"(
===========
||       ||
||   O   ||
||       ||
===========)";

const char UIDieImage2[] = R"(
===========
|| O     ||
||       ||
||     O ||
===========)";

const char UIDieImage3[] = R"(
===========
|| O     ||
||   O   ||
||     O ||
===========)";

const char UIDieImage4[] = R"(
===========
|| O   O ||
||       ||
|| O   O ||
===========)";

const char UIDieImage5[] = R"(
===========
|| O   O ||
||   O   ||
|| O   O ||
===========)";

const char UIDieImage6[] = R"(
===========
|| O   O ||
|| O   O ||
|| O   O ||
===========)";

const char UITitleCard[] = R"(
/-------------------------------------------------------\

 __    __        __      __                            
/\ \  /\ \      /\ \    /\ \__                         
\ `\`\\/'/  __  \ \ \___\ \ ,_\  ____      __     __   
 `\ `\ /' /'__`\ \ \  _ `\ \ \/ /\_ ,`\  /'__`\ /'__`\ 
   `\ \ \/\ \L\.\_\ \ \ \ \ \ \_\/_/  /_/\  __//\  __/ 
     \ \_\ \__/.\_\\ \_\ \_\ \__\ /\____\ \____\ \____\
      \/_/\/__/\/_/ \/_/\/_/\/__/ \/____/\/____/\/____/
                                                       
\-------------------------------------------------------/
)";

const char promptToKeep[] =
R"(
Do you want to keep this hand and add it to the score card?
[1] - Keep hand
[2] - Roll again
)";

const char scoreCardSelectionUI[] =
R"(
Where do you want to put this hand?
[1] - 1s
[2] - 2s
[3] - 3s
[4] - 4s
[5] - 5s
[6] - 6s

[Q] - 3 of a Kind
[W] - 4 of a Kind
[E] - Full House
[R] - Small Straight
[T] - Large Straight
[Y] - Yahtzee
[U] - Chance

)";

//A function to convert a string to all uppercase
//note that unlike stoi() and similar, this is pass by reference and modifies the original string
inline void StoUpper(string& inputString)
{
	for (char& c : inputString) {
		c = std::toupper(c);
	}

	return;
}


inline void clearScreen() {
	cout << "\033[2J\033[H";
}


//@TODO do a buttload of work to make them print on one line


//