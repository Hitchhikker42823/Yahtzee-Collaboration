#pragma once
#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;


//Dice
extern const char UIDieImage1[];

extern const char UIDieImage2[];

extern const char UIDieImage3[];

extern const char UIDieImage4[];

extern const char UIDieImage5[];
extern const char UIDieImage6[];

extern const char UITitleCard[];

extern const char promptToKeep[];

extern const char scoreCardSelectionUI[];


vector<string> UIScoreCardArt;

//A function to convert a string to all uppercase
//note that unlike stoi() and similar, this is pass by reference and modifies the original string
inline void StoUpper(string& inputString);



inline void clearScreen();