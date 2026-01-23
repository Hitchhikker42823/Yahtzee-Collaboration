#pragma once
#include <vector>
using namespace std;

inline int rollOne();
vector<int> roll5Dice();
void printCurrentHand(vector<int> currentHand);
vector<int> removeFromHand(vector<int> inputHand, vector<int> numbersToRemove);
vector<int> askForNumbersToRemove();
vector<int> removeAndRefill(vector<int> inputHand);
vector<int> fillHandTo5(vector<int> inputHand);