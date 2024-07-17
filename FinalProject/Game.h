#ifndef GAME
#define GAME
#include <iostream>
#include <cmath>
#include "Player.h"
#include "Field.h"
#include "hitOutcomes.h"
#include "pitcherOutcomes.h"
#include "Dice.h"
#include "DoublyLinkedList.hpp"



void playGame(const Field&, const Field&);          //Plays the game
int playHalf(const Field&, Field&);                 //Plays half an inning
int decideOutcome(const float&);                    //Decides the hit outcome based on the hit probability
bool decideHit(float);                      //Decides the hit based on the hit probability


#endif