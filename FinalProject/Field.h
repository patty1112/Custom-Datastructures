#ifndef FIELD
#define FIELD
#include "Field.h"
#include "Player.h"
#include "DoublyLinkedList.hpp"
#include "hitOutcomes.h"
#include "pitcherOutcomes.h"
using namespace std;

class Field {
    private:                //Each field contains a player at each position
    Player pitcher;         //corresponds to 1
    Player catcher;         //corresponds to 2
    Player firstBase;       //corresponds to 3
    Player secondBase;      //corresponds to 4
    Player thirdBase;       //corresponds to 5
    Player shortStop;       //corresponds to 6
    Player leftField;       //corresponds to 7
    Player centerField;     //corresponds to 8
    Player rightField;      //corresponds to 9
    int batterUp;

    public:
    Field();            //Defult constructor
    void assignPositions(const DoublyLinkedList<Player>&);      //Assigns the positions of players in a linked list
    Field& operator=(const Field&);         //Sets two fields equal to eachother
    Player getPlayer(const int&) const;       //returns the player in the position, int arguement corresponds to the std field positions
    string getPosition(const string&);  //returns the poition of the arguement player name
    void setPitcher(const Player&);
    void setLeftField(const Player&);
    void setShortStop(const Player&);
    void setCenterField(const Player&);         //Setter function for each position
    void setThirdBase(const Player&);
    void setSecondBase(const Player&);
    void setRightField(const Player&);
    void setFirstBase(const Player&);
    void setCatcher(const Player&);
    void printField();                      //Prints the players in position order
    void setCurrentBatter(const int&);      //Sets the current batter of the lineup
    int getBatterUp() const;                //Gets the position of the current batter, corresponds to position number
    int hitBall(const hitOutcomes&) const;      //If they hit the ball, sets the outcome chances based dice roll
    int lastPitch(const pitcherOutcomes&) const;        //If they dont hit, sets the outcome chances based on stats
    void nextBatter();          //Moves to the next batter
  

};


#endif