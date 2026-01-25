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
