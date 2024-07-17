#ifndef BASESTATUS
#define BASESTATUS
#include "DoublyLinkedList.hpp"

struct baseStatus : public DoublyLinkedList<int> {       //Inherits DoublyLinkedList's data members
    
    int runnersOn() const;          //Returns the number of runners on base
    //Moves the players on base, takes the outcome of the hit, if they hit the ball, and a copy of the numberScored
    int movePlayers(const int&, const bool&, int);     
    int scoreAll(int);              //Scores all the players currently on base and the hitter
    baseStatus();                   //Constructs the bases, inserts 4 nodes
};



#endif