#ifndef PLAYER
#define PLAYER
#include <string>
#include <random>
#include <iostream>
#include <iomanip>


using namespace std;

class Player {
    private:
    string playerName;          //Each player has a string identifier
    int armStrength;            //Armstrength prioritized for pitcher and 3rd baseman
    int rawSpeed;               //Speed prioritized for outfield, center specifically
    int agility;                //Agility prioiritiezed for the shortstop
    int groundRating;           //Ground fielding is prioiritized for 2nd baseman
    int flyRating;              //Fly balls important for left and right field
    int stamina;                //Stamina important for catcher, but he is last assigned
    int hitting;                //Hitting is used for probability calculations

    public:
    Player();                       //Defult constructor
    Player(const Player&);          //Copy constructor
    Player& operator=(const Player&);       //Assignment overload
    void randomizeStats();                  //Randomizes the stats of one player
    void setName(const string&);            //Sets the name of the player
    int getArmStrength();
    int getSpeed();
    int getAgility();
    int getGroundRating();      //Getters for each private data member
    int getFlyRating();
    int getStamina();
    int getHitting();
    string getName();
    void print();           //Prints a player and their stats
    void setWholeName(string&);
    void setArmStrength(int);
    void setSpeed(int);
    void setAgility(int);
    void setGroundRating(int);      //Getters for each private data member
    void setFlyRating(int);
    void setStamina(int);
    void setHitting(int);

    

};


#endif