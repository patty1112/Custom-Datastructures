/* CSCI 261: Final Project
 *
 * Author: Patrick Maes
 * Resources used: NONE
 *
 * Sorts teams of random players into positions and simulates an entire baseball game.
 */
#include "Player.h"
Player::Player() {
    playerName = "Player ";         //Each player will be assigned a number
    armStrength = 0;
    rawSpeed = 0;               //Initializes all data to 0
    agility = 0;
    groundRating = 0;
    flyRating = 0;
    stamina = 0;
    hitting = 0;
}

Player::Player(const Player& OTHER) { 
    playerName = OTHER.playerName;
    armStrength = OTHER.armStrength;
    rawSpeed = OTHER.rawSpeed;
    agility = OTHER.agility;
    groundRating = OTHER.groundRating;      //Copy the data members of OTHER
    flyRating = OTHER.flyRating;
    stamina = OTHER.stamina;
    hitting = OTHER.hitting;
}

Player& Player::operator=(const Player& OTHER) { 
    playerName = OTHER.playerName;
    armStrength = OTHER.armStrength;
    rawSpeed = OTHER.rawSpeed;
    agility = OTHER.agility;    
    groundRating = OTHER.groundRating;      //Copy the data members of OTHER
    flyRating = OTHER.flyRating;
    stamina = OTHER.stamina;
    hitting = OTHER.hitting;
    return *this;
}

void Player::randomizeStats() {         //Values are randomized from 10 to 100
    int max = 90;                       //Make a variable to hold max value - 10
    armStrength = (rand() % max) + 10;      //randomize max number and mod by 90 to get number 1 - 89
    rawSpeed = (rand() % max) + 10;         //Add 10 to get number between 10-99
    agility = (rand() % max) + 10;
    groundRating = (rand() % max) + 10;
    flyRating = (rand() % max) + 10;
    stamina = (rand() % max) + 10;
    hitting = (rand() % max) + 10;
}

int Player::getArmStrength() {
    return armStrength;
}

int Player::getSpeed() {
    return rawSpeed;
}

int Player::getAgility() {
    return agility;
}

int Player::getGroundRating() {
    return groundRating;
}

int Player::getHitting() {
    return hitting;
}

int Player::getFlyRating() {
    return flyRating;
}

int Player::getStamina() {
    return stamina;
}

void Player::setName(const string& newName) {   //Function is passed the number of the player
    string name = "Player ";                    //creates a new name variable as "Player "
    name += newName;                            //Adds the given number
    playerName = name;                          //Set this string as the playerName

}

string Player::getName() {
    return playerName;
}

void Player::print() {          //Prints all data members
    cout << playerName << ": ";             //Prints player name
    cout << setw(13) <<  "ArmStrength-" << armStrength << " ";
    cout << setw(8) << "Speed-" << rawSpeed << " ";             //Prints all stats separated by a space
    cout << setw(10) << "Agiliy-" << agility << " ";
    cout << setw(17) << "GroundFielding-" << groundRating << " ";
    cout << setw(19) << "FlyBallFielding-" << flyRating << " ";
    cout << setw(11) << "Stamina-" << stamina << " ";
    cout << setw(11) << "Hitting-" << hitting << " ";
    cout << endl;
}

void Player::setWholeName(string& playerName) {
    this->playerName = playerName;
}

void Player::setArmStrength(int strength) {
    armStrength = strength;
}

void Player::setSpeed(int playerSpeed) {
    rawSpeed = playerSpeed;
}

void Player::setAgility(int playerAgility) {
    agility = playerAgility;
}

void Player::setGroundRating(int ground) {
    groundRating = ground;
}

void Player::setFlyRating(int fly) {
    flyRating = fly;
}

void Player::setStamina(int stam) {
    stamina = stam;
}

void Player::setHitting(int hit) {
    hitting = hit;
}


