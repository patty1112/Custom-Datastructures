#ifndef DICE
#define DICE
#include <random>


class Dice {
    private:            
    int currRoll;               //Value of the roll is private member
    public:
    void rollDice();            //Public member to roll the dice
    int getRoll() const;        //Gets the value of the roll
    
};


#endif