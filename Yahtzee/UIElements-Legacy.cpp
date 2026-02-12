#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>



//Dice
extern const char UI_DIE_IMAGE_1[] = R"(
===========
||       ||
||   O   ||
||       ||
===========)";

extern const char UI_DIE_IMAGE_2[] = R"(
===========
|| O     ||
||       ||
||     O ||
===========)";

extern const char UI_DIE_IMAGE_3[] = R"(
===========
|| O     ||
||   O   ||
||     O ||
===========)";

extern const char UI_DIE_IMAGE_4[] = R"(
===========
|| O   O ||
||       ||
|| O   O ||
===========)";

extern const char UI_DIE_IMAGE_5[] = R"(
===========
|| O   O ||
||   O   ||
|| O   O ||
===========)";

extern const char UI_DIE_IMAGE_6[] = R"(
===========
|| O   O ||
|| O   O ||
|| O   O ||
===========)";

extern const char UI_TITLE_CARD[] = R"(
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

extern const char UI_PROMPT_TO_KEEP[] =
R"(
Do you want to keep this hand and add it to the score card?
[1] - Keep hand
[2] - Roll again
)";



//Note that changing this will destroy the printScoreCard() method
std::vector<std::string> UI_SCORECARD_ART = {
"==========================",
"|| Ones           | "," ||   [1]",
"|| Twos           | "," ||   [2]",
"|| Threes         | "," ||   [3]",
"|| Fours          | "," ||   [4]",
"|| Fives          | "," ||   [5]",
"|| Sixes          | "," ||   [6]",
"|| Bonus          | "," ||",
"==================|=======",
"|| 3 of a Kind    | "," ||   [Q]",
"|| 4 of a Kind    | "," ||   [W]",
"|| Full House     | "," ||   [E]",
"|| Small Straight | "," ||   [R]",
"|| Large Straight | "," ||   [T]",
"|| Yahtzee        | "," ||   [Y]",
"|| Chance         | "," ||   [U]",
"|| Bonus Yahtzee  | "," ||",
"==================|=======",
"|| Upper Total    | "," ||",
"|| Lower Total    | "," ||",
"|| GRAND TOTAL    | "," ||",
"=========================="
};



////Legacy code not used anymore
//extern const char scoreCardSelectionUI[] =
//R"(
//Where do you want to put this hand?
//[1] - 1s
//[2] - 2s
//[3] - 3s
//[4] - 4s
//[5] - 5s
//[6] - 6s
//
//[Q] - 3 of a Kind
//[W] - 4 of a Kind
//[E] - Full House
//[R] - Small Straight
//[T] - Large Straight
//[Y] - Yahtzee
//[U] - Chance
//
//)";
