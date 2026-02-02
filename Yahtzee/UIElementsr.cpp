#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;


//Dice
extern const char UIDieImage1[] = R"(
===========
||       ||
||   O   ||
||       ||
===========)";

extern const char UIDieImage2[] = R"(
===========
|| O     ||
||       ||
||     O ||
===========)";

extern const char UIDieImage3[] = R"(
===========
|| O     ||
||   O   ||
||     O ||
===========)";

extern const char UIDieImage4[] = R"(
===========
|| O   O ||
||       ||
|| O   O ||
===========)";

extern const char UIDieImage5[] = R"(
===========
|| O   O ||
||   O   ||
|| O   O ||
===========)";

extern const char UIDieImage6[] = R"(
===========
|| O   O ||
|| O   O ||
|| O   O ||
===========)";

extern const char UITitleCard[] = R"(
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

extern const char promptToKeep[] =
R"(
Do you want to keep this hand and add it to the score card?
[1] - Keep hand
[2] - Roll again
)";

extern const char scoreCardSelectionUI[] =
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


vector<string> UIScoreCardArt = {
"==========================",
"|| Ones           | "," ||",
"|| Twos           | "," ||",
"|| Threes         | "," ||",
"|| Fours          | "," ||",
"|| Fives          | "," ||",
"|| Sixes          | "," ||",
"|| Bonus          | "," ||",
"==================|=======",
"|| 3 of a Kind    | "," ||",
"|| 4 of a Kind    | "," ||",
"|| Full House     | "," ||",
"|| Small Straight | "," ||",
"|| Large Straight | "," ||",
"|| Yahtzee        | "," ||",
"|| Chance         | "," ||",
"|| Bonus Yahtzee  | "," ||",
"==================|=======",
"|| Upper Total    | "," ||",
"|| Lower Total    | "," ||",
"|| GRAND TOTAL    | "," ||",
"=========================="
};



//@TODO do a buttload of work to make them print on one line