#ifndef PLAYER
#define PLAYER
#include "DoublyNode.hpp"


class Player {
    private:
    int playerNumber;           //Private members playerNumber and chips
    unsigned int chips;
    public:
    Player();                   //Defult constructor and destructor
    ~Player();
    void setPlayerNumber(int);      //Sets the player number based off position
    int getPlayerNumber() const;        //Returns the player number
    int getChips() const;                             //Returns the callees number of chips
    void giveChip(DoublyNode<Player>*, bool&);             //Function to give chip to player, takes the current player and direction left or right.
    void chipToMiddle();                        //Chips are decremented when given away
    void subChip();             //Functions to add or subtract a chip
    void addChip();

};

#endif