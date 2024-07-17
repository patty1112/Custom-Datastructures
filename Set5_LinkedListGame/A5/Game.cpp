#include "Game.h"


Game::Game() {                  //Defult constructor
    forwardDirection = true;    //Makes the direction clockwise
    currentPlayer = nullptr;    //Current player is nobody
}


void Game::setStart(CircularlyDoublyLinkedList<Player>& playerList) {   //Sets the start if the players are in a linked list
    forwardDirection = true;                    //Direction is clockwise
    currentPlayer = playerList.getHead();       //Current player is the head
}

int Game::playersIn() {             //Calculates the players with chips
    int playersWChips = 0;                       //Stores number of players in the game
    DoublyNode<Player>* curr = currentPlayer;    //Makes node pointer that points to current player
    int playerChips = 0;                         //Number of chips for a player
    playerChips = curr->value.getChips();        //Number of chips is the current players chips
    if(playerChips > 0) {                       //If they have more than 0,
        playersWChips += 1;                     //They are in the game
    }
    curr = curr->pNext;                         //Move to the next node
    while(curr != currentPlayer) {              //While the node has not been checked
        playerChips = curr->value.getChips();       //Get the value of the player's chips
        if(playerChips > 0) {                       //If they have more than 0,
            playersWChips += 1;                     //They are in the game
        }
        curr = curr->pNext;                         //Advance the player
    }
    cout << playersWChips << " players have chips" << endl;     //Extra cout line to see how long game should last
    return playersWChips;                                   //Return the number of players with chips
}

bool Game::playGame() {                 //Checks if the game should continue
    if(this->playersIn() == 1) {        //If there is 1 player with chips,
        return false;                   //Stop the game, return false
    } else {
        return true;                    //Else keep going
    }
}

DoublyNode<Player>* Game::getCurrentPlayer() const{     //Gets the current player
    return currentPlayer;                               //Return the current player
}

void Game::flipDirections() {                   //Flips direction of play
    forwardDirection = !forwardDirection;       //Flips the value of forwardDirection
}   

void Game::moveNext() {                 //Moves to the next player
    if(forwardDirection) {  
        currentPlayer = currentPlayer->pNext;   //If clockwise, then move forward through list
    } else {
        currentPlayer = currentPlayer->pPrev;    //If counterclockwise, move backwards
    }
}

DoublyNode<Player>* Game::checkNext(const bool& LEFT) const {       //Checks the player to a certain direction, no modified values
    DoublyNode<Player>* curr = currentPlayer;       //Makes a pointer to current player
    if(LEFT) {                                      //If clockwise move forwards
        curr = curr->pNext;
    } else {
        curr = curr->pPrev;                         //Else move backwards
    }
    return curr;                        //Return the next player
}

bool Game::getDirection() const {
    return forwardDirection;            //Returns the direction of play
}

                                                //Function called once, use linear search
int Game::getWinner() const {                         //Linear Search, Finds the number of the winning player
    DoublyNode<Player>* curr = currentPlayer;   //Pointer to the current player
    int currChips = 0;
    currChips = curr->value.getChips();         //Get the chips of the current player
    if(currChips != 0) {                        //If they won,
        return curr->value.getPlayerNumber();           //Return their number
    }
    curr = curr->pNext;                         //Else move to the next player
    while(curr != currentPlayer) {              //While there are more players to check
        currChips = curr->value.getChips();     //get the player's chips
        if(currChips != 0) {                    //If they won,
            return curr->value.getPlayerNumber();       //Return their number
        }
        curr = curr->pNext;                     //Move to the next node
    }
    return -1;                  //If not found, return -1
}

int Game::getWinnerChips() const {                    //Get the chips of the winner
    DoublyNode<Player>* curr = currentPlayer;    //Same function to find winner,
    int currChips = 0;
    currChips = curr->value.getChips();
    if(currChips != 0) {
        return curr->value.getChips();              //Instead return the chips they have
    }
    curr = curr->pNext;
    while(curr != currentPlayer) {
        currChips = curr->value.getChips();
        if(currChips != 0) {
            return curr->value.getChips();          //Instead return the chips they have
        }
        curr = curr->pNext;
    }
    return -1;
}

void Game::play(const int numberOfPlayers, CircularlyDoublyLinkedList<Player> playerList, Game LCR, CircularlyDoublyLinkedList<int>& turnsList) {
    for(int i = 0; i < numberOfPlayers; i++) {          //Iterates for the number of players
        playerList.insert(0, Player());                    //Insert a player
    }
    playerList.assignPlayerNumbers();                      //Assign the numbers of players, CircularlyDoublyLinkedList member

    LCR.setStart(playerList);                              //Set the starting player from the list head
    bool LEFT = true;                                   //Variable left stores which way to pass chips

    int middleChips = 0;                    //Number of chips in the middle
    int turns = 0;                          //Number of turns
    while(LCR.playGame()) {                 //While there is more than one player with chips
        turns += 1;                         //Take a turn
        int moveNext = 1;                   //Number of players to move on next turn is 1.
        int numberOfDice = LCR.getCurrentPlayer()->value.getChips();            //Number of dice is the number of chips the player has
        cout << "Player " << LCR.getCurrentPlayer()->value.getPlayerNumber() << " has " << LCR.getCurrentPlayer()->value.getChips() << " chips left." << endl;      //Print the number of chips they have
        if(numberOfDice > 3) {      //If the number of chips is more than 3,
            numberOfDice = 3;       //The number of dice is 3
        }
        cout << setw(16) << "Rolling " << numberOfDice << " Dice " << endl;     //Print the number of dice rolled
        for(int i = 0; i < numberOfDice; i++) {         //For each dice roll
            Dice newRoll;                               //Make a dice
            newRoll.rollDice();                         //Roll the dice
            int rollValue = newRoll.getRoll();          //Get the roll value
            if(rollValue >= 0 && rollValue <= 2) {          //If they roll a 0, 1, or 2
                cout << setw(17) << "Rolled a " << rollValue << " - keep!" << endl;     //Do nothing, keep chips
            } else if(rollValue == 3) {         //If roll is 3,
                LEFT = true;                    //Pass chip to the left
                LCR.getCurrentPlayer()->value.giveChip(LCR.getCurrentPlayer(), LEFT);       //Call function to pass chip
                int othersChips = LCR.checkNext(LEFT)->value.getChips();        //Get the chips of the reciever
                int othersNumber = LCR.checkNext(LEFT)->value.getPlayerNumber();    //Get the number of the reciever
                //Print the roll number and chip numbers with updated values:
                cout << setw(41) << "Rolled a 3 - give left - player #" << othersNumber << " has " << othersChips << " chips - player #" << LCR.getCurrentPlayer()->value.getPlayerNumber() << " has " << LCR.getCurrentPlayer()->value.getChips() << " chips" << endl;
            } else if(rollValue == 4) {         //If they roll a 4
                LEFT = false;                   //Pass chip right
                LCR.getCurrentPlayer()->value.giveChip(LCR.getCurrentPlayer(), LEFT);   //Call function to pass a chip
                int othersChips = LCR.checkNext(LEFT)->value.getChips();                //Get the chips of the reciever
                int othersNumber = LCR.checkNext(LEFT)->value.getPlayerNumber();        //Get the number of the reciever
                //Print the roll number and chip numbers with updated values
                cout << setw(42) << "Rolled a 4 - give right - player #" << othersNumber << " has " << othersChips << " chips - player #" << LCR.getCurrentPlayer()->value.getPlayerNumber() << " has " << LCR.getCurrentPlayer()->value.getChips() << " chips" << endl;
            } else if(rollValue == 5) {                 //If the roll is a 5,
                LCR.getCurrentPlayer()->value.chipToMiddle();       //Give a chip to the middle
                middleChips += 1;                                   //Add a chip to the middle
                //Print the roll number and updated chips
                cout << setw(46) << "Rolled a 5 - give center - Center has " << middleChips << " chips - Player #" << LCR.getCurrentPlayer()->value.getPlayerNumber() << " has " << LCR.getCurrentPlayer()->value.getChips() << " chips" << endl;                
            } else if(rollValue == 6) {     //If they roll a 6
                LCR.flipDirections();           //Flip direction of play
                //Print the operation
                cout << setw(29) << "Rolled a 6 - reverse!" << endl;
            } else if(rollValue == 7) {     //If they roll a 7
                moveNext += 1;              //Skip an extra player
                cout << setw(38) << "Rolled a 7 - skip! - skipping " << moveNext - 1 << " players" << endl;
            } else {            //Notify if the number generator gives wrong value
                cout << "The roll was not a value 0-7" << endl;
            }

        }
        for(int i = 0; i < moveNext; i++) {         //For the number of players to move next
            int hasChips = 0;                       //Checks the number of chips 
            hasChips = LCR.checkNext(LCR.getDirection())->value.getChips(); //Gets chips of next player in direction of play
            if(hasChips == 0) {     //If they have no chips, they dont roll anyways
                LCR.moveNext();     //Skip them but dont count it towards the number of skips
                i--;
            } else {                //If they have chips
                LCR.moveNext();     //Skip them and count it towards number of skips
            }
        }
    }

    int winner = LCR.getWinner();               //Get the player number of winner
    int winnerChips = LCR.getWinnerChips();     //Get the chips of the winner
    //Print the player who won and the number of chips they had after the number of turns
    cout << "Player #" << winner << " wins with " << winnerChips << " chips after " << turns << " turns." << endl;
    turnsList.insert(0, turns);

} 