#ifndef TEAM
#define TEAM
#include "Player.h"
#include "DoublyLinkedList.hpp"

#include "Field.h"

class Team {
    private:
    DoublyLinkedList<Player> teamList;      //Has a list of players
    int score;                              //Tracks its own score

    public:
    Team();                                 //Defult constructor
    Team(const DoublyLinkedList<Player>&);      //Copy constructor
    void assignPlayers();                       //Assigns player names from list postion
    DoublyLinkedList<Player> getTeamList() const;       //Gets the linked list of players
    void setTeamList(const DoublyLinkedList<Player>&);      //Sets the team list as a given list
    void printTeam();                                           //Prints the whole team
    void assignPositions(DoublyLinkedList<Player>&, Field&);        //Assigns the positions to field

};

#endif