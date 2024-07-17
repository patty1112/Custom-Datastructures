/* CSCI 261: Final Project
 *
 * Author: Patrick Maes
 * Resources used: NONE
 *
 * Sorts teams of random players into positions and simulates an entire baseball game.
 */
#include "Dice.h"
#include <random>

void Dice::rollDice() {
    int randomNumber = 0;       //makes a variable to store roll value
    randomNumber = rand() % 101;  //Mod a random number by 8 to get number 0-7.
   currRoll = randomNumber;     //Return the result
}

int Dice::getRoll() const {
    return currRoll;            //Return the roll value
}
