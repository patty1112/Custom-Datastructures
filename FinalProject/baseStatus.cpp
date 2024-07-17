/* CSCI 261: Final Project
 *
 * Author: Patrick Maes
 * Resources used: NONE
 *
 * Sorts teams of random players into positions and simulates an entire baseball game.
 */
#include "baseStatus.h"


int baseStatus::runnersOn() const {      //returns the number of runners on
    DoublyNode<int>* curr = pHead;      //pointer to the head of the list
    int runnersOn = 0;                  //variable to track runners on base
    while(curr) {                        //While curr is not nullptr
        runnersOn += curr->value;       //Add the value of the node to runnersOn
        curr = curr->pNext;             //Move the node pointer to the next base
    }
    return runnersOn;                   //Return the number of runners on
}

baseStatus::baseStatus() {
    this->insert(0,0);          //Defult constructor
    this->insert(0,0);          //Inserts 4 nodes with no players
    this->insert(0,0);
    this->insert(0,0);
    this->assignTail();
}

int baseStatus::movePlayers(const int& outcome, const bool& hit, int numberScored) {
    numberScored = 0;               //Initializes the copy (passed by value)
    if(hit) {                       //If the player hit the ball
        if(outcome == 1) {          //If the outcome was a field out
            numberScored = 0;       //Nobody scores
        } else if(outcome == 2) {           //If the outcome was a single
            DoublyNode<int>* temp = pTail;      //Make a pointer to the tail of the list
            while(temp != nullptr) {            //While temp is not nullptr
                if(temp->value == 1) {          //If the base is occupied (holds value 1)
                    temp->pNext->value += 1;    //Make the next base occupied
                    temp->value -= 1;           //Make the current base unoccupied
                }
                temp = temp->pPrev;             //Move the pointer backwards from home to first base
            }   
            pHead->value += 1;              //Move the batter to first base
            numberScored = pTail->value;        //Find how many people made it to home plate
            pTail->value = 0;                   //Make the value of homePlate unoccupied (always ends unoccupied)
        } else if(outcome == 3) {               //If the outcome was a double
            bool firstValue = false;        //tracks if someone was on first
            if(pHead->value == 1) {         //If someone was on first
                firstValue = true;          //Make variable true
            }
            numberScored += this->scoreAll(numberScored);       //Score everyone on base
            if(firstValue) {            //If first was occupied
                numberScored -= 1;      //They dont score
                pTail->pPrev->value = 1;        //Move them to third base
            }
            numberScored -= 1;              //The hitter doesnt score
            pHead->pNext->value = 1;        //Second base is occupied
        } else if(outcome == 4) {                   //If the outcome was a triple
            numberScored += this->scoreAll(numberScored);       //Score everyone on base
            numberScored -= 1;                                  //Subtract a run for the batter (He doesn't score)
            pTail->pPrev->value = 1;                            //Make the value of third base occupied
        } else if(outcome == 5 || outcome == 6) {               //If the player hit a home run
            numberScored += this->scoreAll(numberScored);       //Score all players including the hitter
        }
    } else if(!hit) {                       //If the ball was not hit
        if(outcome == 1) {                  //If the outcome was a strikeout
            numberScored = 0;               //Nobody scores
        } else if(outcome == 2 || outcome == 3) {       //If the batter was hit by pitch or walked
            pHead->value += 1;                      //Make first base occupied
            if(pHead->value > 1) {                  //If already occupied
                DoublyNode<int>* curr = pHead;          //Make a node pointer
                while(curr->pNext != nullptr) {         //While curr is not at home plate
                    while(curr->value > 1) {            //While 2 players occupy the same base
                        curr->pNext->value += 1;        //Move the players over
                        curr->value -= 1;
                    }
                    curr = curr->pNext;             //Move the pointer to the next node
                    while(pTail->value > 0) {           //While the tail is occupied
                        pTail->value -= 1;              //Add a run to the score
                        numberScored += 1;
                    }
                }
            } 
        }
    }
    this->print();              //After each outcome, print the status of the bases. The head is first base
    cout << numberScored << " players scored." << endl;     //Print the number of people scored
    cout << "There are now " << this->runnersOn() << " runners on base." << endl << endl;       //Print the number of people on base
    return numberScored;                //return the number of players scored
}

int baseStatus::scoreAll(int numberScored) {     //Scores all the players including batter
    int runnersOn = this->runnersOn();          //Variable to track the number of runners on
    numberScored += 1;                          //Increase by 1 for the batter's run
    numberScored += runnersOn;                  //Increase by the number of runners on base
    if(runnersOn > 3) {
        cerr << "There were too many runners on for some reason..." << endl;
    }
    DoublyNode<int>* curr = pHead;      //Makes a pointer to the head of the list
    while(curr) {                       //While curr is not nullptr
        curr->value = 0;                //Make the base empty, (holds value 0)
        curr = curr->pNext;             //Move to the next node
    }
    return numberScored;                //Return the number of players scored
}

