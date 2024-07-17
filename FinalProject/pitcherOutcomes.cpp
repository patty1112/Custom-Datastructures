/* CSCI 261: Final Project
 *
 * Author: Patrick Maes
 * Resources used: NONE
 *
 * Sorts teams of random players into positions and simulates an entire baseball game.
 */
#include "pitcherOutcomes.h"


pitcherOutcomes::pitcherOutcomes() {
    strikeOut = 0;                  //Constructor initializes all values to 0.
    walk = 0;
    hitBatter = 0;
}

pitcherOutcomes::pitcherOutcomes(const int& outcome) {
    if(outcome == 0) {              //If bad predicted outcome,
        strikeOut = 70;             //High chance of strikeout
        walk = 99;                  //Lower chance of walk or hitting the batter
        hitBatter = 100;
    } else if(outcome == 1) {       //If outcome was okay
        strikeOut = 65;
        walk = 99;                  //Strikeout chance lowered, walk chance raised
        hitBatter = 100;
    } else if(outcome == 2) {       //If outcome is good,
        strikeOut = 60;             //Lower chance for strikeout
        walk = 99;
        hitBatter = 100;
    } else if(outcome == 3) {
        strikeOut = 50;             //Else if the outcome was great,
        walk = 90;
        hitBatter = 100;            // 50/50 chance to get on base
    }
}

int pitcherOutcomes::getStrikeOut() const {
    return strikeOut;
}

int pitcherOutcomes::getWalk() const {
    return walk;
}

int pitcherOutcomes::getHitBatter() const {
    return hitBatter;
}