#ifndef GAME
#define GAME
#include "DoublyNode.hpp"
#include "CircularlyDoublyLinkedList.hpp"
#include "Player.h"
#include "Dice.h"
#include <iomanip>
using namespace std;


class Game {
    private:
    bool forwardDirection;          //Tracks if the game moves clockwise (true)
    DoublyNode<Player>* currentPlayer;

    public:
    Game();                             //Defult Constructor
    void setStart(CircularlyDoublyLinkedList<Player>&);
    bool playGame();
    int playersIn();
    DoublyNode<Player>* getCurrentPlayer() const;
    void flipDirections();
    void moveNext();
    DoublyNode<Player>* checkNext(const bool&) const;
    bool getDirection() const;
    int getWinner() const;
    int getWinnerChips() const;
    void play(const int, CircularlyDoublyLinkedList<Player>, Game, CircularlyDoublyLinkedList<int>&);
    
};


#endif