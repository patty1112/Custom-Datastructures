/* CSCI 261: Final Project
 *
 * Author: Patrick Maes
 * Resources used: NONE
 *
 * Sorts teams of random players into positions and simulates an entire baseball game.
 */
#include "Field.h"
#include "Dice.h"
#include <iostream>


Field::Field() {
    batterUp = 1;       //Initializes the batter as the first player
}

Field& Field::operator=(const Field& OTHER) {
    pitcher = OTHER.pitcher;            //Copies all the data members from OTHER
    catcher = OTHER.catcher;
    firstBase = OTHER.firstBase;
    secondBase = OTHER.secondBase;
    thirdBase = OTHER.thirdBase;
    shortStop = OTHER.shortStop;
    leftField = OTHER.leftField;
    centerField = OTHER.centerField;
    rightField = OTHER.rightField;
    batterUp = OTHER.batterUp;
    return *this;
}

Player Field::getPlayer(const int& position) const {        //Returns player from position number
    if(position == 1) {     //Standard baseball position labling
        return pitcher;         //Pitcher = 1
    } else if(position == 2) {
        return catcher;         //Catcher = 2
    } else if(position == 3) {
        return firstBase;       //First base = 3...
    } else if(position == 4) {
        return secondBase;
    } else if(position == 5) {
        return thirdBase;
    } else if(position == 6) {
        return shortStop;
    } else if(position == 7) {
        return leftField;
    } else if(position == 8) {
        return centerField;
    } else if(position == 9) {
        return rightField;
    } else {
        return Player();
    }
}

//NOTE functions are implemented in order of importance. EX. Pitcher- most important. Left field is second

void Field::setPitcher(const Player& newPitcher) {  
    pitcher = newPitcher;       
}

void Field::setLeftField(const Player& outfielder) {       
    leftField = outfielder;
}

void Field::setShortStop(const Player& infielder) {     
    shortStop = infielder;
}

void Field::setCenterField(const Player& outfielder) {
    centerField = outfielder;
}

void Field::setThirdBase(const Player& infielder) {
    thirdBase = infielder;
}

void Field::setSecondBase(const Player& infielder) {
    secondBase = infielder;
}

void Field::setRightField(const Player& outfielder) {
    rightField = outfielder;
}

void Field::setFirstBase(const Player& infielder) {
    firstBase = infielder;
}

void Field::setCatcher(const Player& infielder) {
    catcher = infielder;
}

void Field::printField() {              //Prints the positions in order, including player stats
    cout << setw(15) << "(Pitcher) ";           //print() is implemented in Player.hpp
    this->getPlayer(1).print();
    cout << setw(15) << "(Catcher) ";
    this->getPlayer(2).print();
    cout << setw(15) << "(1st Base) ";
    this->getPlayer(3).print();
    cout << setw(15) << "(2nd Base) ";
    this->getPlayer(4).print();
    cout << setw(15) << "(3rd Base) ";
    this->getPlayer(5).print();
    cout << setw(15) << "(Short Stop) ";
    this->getPlayer(6).print();
    cout << setw(15) << "(Left Field) ";
    this->getPlayer(7).print();
    cout << setw(15) << "(Center Field) ";
    this->getPlayer(8).print();
    cout << setw(15) << "(Right Field) ";
    this->getPlayer(9).print();
}

void Field::setCurrentBatter(const int& POS) {
    batterUp = POS;         //Sets the batter as a position number
}

int Field::getBatterUp() const {            //Gets the position of the current batter
    return batterUp;
}

int Field::hitBall(const hitOutcomes& outcome) const {      //Decides the outcome based on a dice roll
    Dice newDice;                       //Create dice and roll it.
    newDice.rollDice();                 //Random is initialized in beginning of main

    if(newDice.getRoll() >= outcome.getHR()) {      //If the roll is >= home run range
        return 6;                                   //Return 6, corresponds to inside the park home run
    } else if(newDice.getRoll() >= outcome.getTriple()) {        //If the roll is >= triple range
        return 5;                                       //Return 5, corresponds to Homerun
    } else if(newDice.getRoll() >= outcome.getDouble()) {       //If the roll is >= double range
        return 4;                                       //Return 4, corresponds to triple
    } else if(newDice.getRoll() >= outcome.getSingle()) {   //If the roll is >= single range
        return 3;                                           //Return 3, corresponds to double
    } else if(newDice.getRoll() >= outcome.getOut()) {      //If the roll is >= out range   
        return 2;                                           //Return 2, corresponds to single
    } else if(newDice.getRoll() <= outcome.getOut()) {      //If the roll is <= out range
        return 1;                                               //Return 1, batter is out
    }

    return -1;
}

int Field::lastPitch(const pitcherOutcomes& outcome) const {        //Decides the outcome of the pitch if not hit, simmilar to hitBall()
    Dice newDice;               //Create dice and roll it
    newDice.rollDice();         //Initialized random in main

    if(newDice.getRoll() >= outcome.getWalk()) {        //If the roll was greater than the walk range
        return 3;                                           //Return 3, hit by pitch
    } else if(newDice.getRoll() >= outcome.getStrikeOut()) {        //If the roll was greater than the out range
        return 2;                                           //Return 2, Batter walked
    } else if(newDice.getRoll() <= outcome.getStrikeOut()) {        //If the roll was less than or equal to strike out range
        return 1;                                           //Return 1, strike out
    }
    
    return -1;
}

void Field::nextBatter() {
    batterUp += 1;          //Moves to the next batter
    if(batterUp == 10) {        //If the batter up is 10
        batterUp = 1;           //Move to the beginning of the lineup
    }
    return;
}

