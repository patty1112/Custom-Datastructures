#include "Player.h"

Player::Player() {
    playerNumber = 1;       //Players start with 3 chips and number 1
    chips = 3;
}

Player::~Player() {
    
}

int Player::getPlayerNumber() const {       //Returns the playerNumber
    return playerNumber;
}

int Player::getChips() const {          //Returns the number of chips
    return chips;
}

void Player::giveChip(DoublyNode<Player>* currentPlayer, bool& direction) {     //Gives a chip to left or right
    DoublyNode<Player>* curr = currentPlayer;       //Gets the current player
    curr->value.subChip();                          //Subtracts a chip
    if(direction) {                     //If the direction is left,
        curr = curr->pNext;             //Move forwards
    } else {                    //Else
        curr = curr->pPrev;     //Move backwards
    }
    curr->value.addChip();      //Add a chip to the next player
    

}

void Player::chipToMiddle() {       //Gives a chip to the middle
    chips -= 1;                     //Subtracts a chip from the player
    return;
}

void Player::setPlayerNumber(int position) {        //Sets the numbers of player in a position
    playerNumber = position;            //Player number is the position
    return;                         
}

void Player::subChip() {
    chips -= 1;                 //Decrement a chip
}

void Player::addChip() {
    chips += 1;                 //Increment a chip
}