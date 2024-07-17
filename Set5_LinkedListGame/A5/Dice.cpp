#include "Dice.h"

void Dice::rollDice() {
    int randomNumber = 0;       //makes a variable to store roll value
    randomNumber = rand() % 8;  //Mod a random number by 8 to get number 0-7.
   currRoll = randomNumber;     //Return the result
}

int Dice::getRoll() const {
    return currRoll;            //Return the roll value
}

