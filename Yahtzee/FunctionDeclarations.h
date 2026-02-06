#pragma once

#include <string>
#include <iostream>

//A function to convert a string to all uppercase
//note that unlike stoi() and similar, this is pass by reference and modifies the original string
inline void StoUpper(std::string& inputString)
{
	for (char& c : inputString) {
		c = std::toupper(c);
	}

	return;
}

//Asks the system to execute "cls"
inline void clearScreen() {
	std::cout << system("cls");
}


//---------NOTE: thus far only inline functions are used, so we can just define them in the header.
//-------------- Uncomment if these become not inline or otherwise