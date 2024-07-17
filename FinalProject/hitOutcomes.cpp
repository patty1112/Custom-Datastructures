/* CSCI 261: Final Project
 *
 * Author: Patrick Maes
 * Resources used: NONE
 *
 * Sorts teams of random players into positions and simulates an entire baseball game.
 */
#include "hitOutcomes.h"


hitOutcomes::hitOutcomes() {
    out = 0; 
    single = 0;     //All data initialized to 0
    _double = 0;
    triple = 0;
    HR = 0;
    IPHR = 0;
}

hitOutcomes::hitOutcomes(const int& outcome) {
    if(outcome == 0) {          //If outcome is 0
        out = 65;               //Higher chance of out, 0-65
        single = 85;            //single: 65-85 
        _double = 95;           //Double: 85-95
        triple = 97;            //Triple: 95-97
        HR = 99;                //HR: 97-99
        IPHR = 100;             //IPHR: 99-100
    } else if(outcome == 1) {       //If outcome is 1
        out = 50;                   
        single = 75;                //Lower chance of out
        _double = 90;               //Higher chance of single
        triple = 95;
        HR = 98;
        IPHR = 100;
    } else if(outcome == 2) {
        out = 45;
        single = 70;
        _double = 88;       //Lower chance of out, higher for multi base hits
        triple = 94;
        HR = 98;
        IPHR = 100;
    } else if(outcome == 3) {
        out = 30;
        single = 65;
        _double = 85;           //Highest chances for hits
        triple = 92;
        HR = 97;
        IPHR = 100;
    }
}

int hitOutcomes::getOut() const{
    return out;
}

int hitOutcomes::getSingle() const{
    return single;
}

int hitOutcomes::getDouble() const{
    return _double;
}

int hitOutcomes::getTriple() const{
    return triple;
}

int hitOutcomes::getHR() const{
    return HR;
}

int hitOutcomes::getIPHR() const{
    return IPHR;
}