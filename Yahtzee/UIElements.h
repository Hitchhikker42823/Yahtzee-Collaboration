#pragma once
#include <string>
#include <vector>

//Dice
//Dice
inline const std::vector<std::string> UI_DIE_IMAGE_1 = {
"===========",
"||       ||",
"||   O   ||",
"||       ||",
"==========="
};

inline const std::vector<std::string> UI_DIE_IMAGE_2 = {
"===========",
"|| O     ||",
"||       ||",
"||     O ||",
"==========="
};

inline const std::vector<std::string> UI_DIE_IMAGE_3 = {
"===========",
"|| O     ||",
"||   O   ||",
"||     O ||",
"==========="
};

inline const std::vector<std::string> UI_DIE_IMAGE_4 = {
"===========",
"|| O   O ||",
"||       ||",
"|| O   O ||",
"==========="
};

inline const std::vector<std::string> UI_DIE_IMAGE_5 = {
"===========",
"|| O   O ||",
"||   O   ||",
"|| O   O ||",
"==========="
};

inline const std::vector<std::string> UI_DIE_IMAGE_6 = {
"===========",
"|| O   O ||",
"|| O   O ||",
"|| O   O ||",
"==========="
};


inline const std::vector<std::vector<std::string>> UI_DICE_MATRIX = {
    UI_DIE_IMAGE_1,
    UI_DIE_IMAGE_2,
    UI_DIE_IMAGE_3,
    UI_DIE_IMAGE_4,
    UI_DIE_IMAGE_5,
    UI_DIE_IMAGE_6
};




//extern const char UI_TITLE_CARD[];
//
//
//extern const char UI_PROMPT_TO_KEEP[];

//"Yahtzee"
inline const char* UI_TITLE_CARD = R"(
-------------------------------------------------------\

 __    __        __      __                            
\ \  /\ \      /\ \    /\ \__                         
\ `\`\\/'/  __  \ \ \___\ \ ,_\  ____      __     __   
 `\ `\ /' /'__`\ \ \  _ `\ \ \/ /\_ ,`\  /'__`\ /'__`\ 
   `\ \ \/\ \L\.\_\ \ \ \ \ \ \_\/_/  /_/\  __//\  __/ 
     \ \_\ \__/.\_\\ \_\ \_\ \__\ /\____\ \____\ \____\
      \/_/\/__/\/_/ \/_/\/_/\/__/ \/____/\/____/\/____/
                                                       
\-------------------------------------------------------/
)";


inline const char* UI_PROMPT_TO_KEEP =
R"(
Do you want to keep this hand and add it to the score card?
[1] - Keep hand
[2] - Roll again
)";


//The scoreDataVector

//Note that changing this will destroy the printScoreCard() method
inline const std::vector<std::string> UI_SCORECARD_ART = {
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
