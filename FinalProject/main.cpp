/* CSCI 261: Final Project
 *
 * Author: Patrick Maes
 * Resources used: NONE
 *
 * Sorts teams of random players into positions and simulates an entire baseball game.
 */

#include <iostream>
#include <fstream>
#include <random>
#include <ctime>
#include <string>

#include "Team.h"
#include "fileFunctions.h"
#include "DoublyLinkedList.hpp"
#include "Game.h"
#include "Field.h"

using namespace std;

int main() {
    srand(time(0));
    rand();
    cout << endl;
    cout << "Welcome to the player position sorting program! " << endl;
    cout << "Enter 1 to simulate 2 fully random rosters to play eachother, enter 2 to assign a player's stats yourself first." << endl;
    string userInput = " ";         //Make a string for the user input
    bool reprompt = true;           //Set reprompt as true
    while(reprompt) {                         //Prompt again
        cout << "Choice: ";                 //take user input
        cin >> userInput;                   
        if(userInput.length() == 1) {           //If the input is one digit
            if(isdigit(userInput[0]) && (stoi(userInput) == 1 || stoi(userInput) == 2)) {       //Makes sure its a digit
                reprompt = false;         //Stop prompting
            } else {                
                cout << "Please enter an integer (1 or 2)." << endl;    //Else reprompt
            }
        } else {
            cout << "Please enter a one digit number (1 or 2)" << endl;
        }
    }

    DoublyLinkedList<Player> playerList;    //Create two lists of players
    DoublyLinkedList<Player> playerList2;
    DoublyLinkedList<Player> assignedPlayers;       //Create two lists to track assignedPlayers
    DoublyLinkedList<Player> assignedPlayers2;
    Field playerListPositions;                  //Make a field for each player list
    Field playerListPositions2;
    if(stoi(userInput) == 1) {      //If the user wants two random teams
        for(int i = 1; i < 10; i++) {       //Iterate through 9 times
            Player newPlayer;               //Create a new player
            newPlayer.randomizeStats();     //Randomize their stats
            newPlayer.setName(to_string(i));    //Make their name "Player " i
            playerList.insert(9, newPlayer);    //Insert them into the list
        }

       
        Team firstTeam(playerList);     //Make a team out of the player list
        firstTeam.assignPositions(assignedPlayers, playerListPositions);    //Assign the teams positions
        cout << endl;           
        
        for(int i = 1; i < 10; i++) {   //Iterate through 9 times
            Player newPlayer;           //Create a new player
            newPlayer.randomizeStats();     //Randomize their stats
            newPlayer.setName(to_string(i));        //Make thier name "Player " i  
            playerList2.insert(10, newPlayer);      //Insert them into the list
        }   

        Team secondTeam(playerList2);       //Make a team out of the second list
        secondTeam.assignPositions(assignedPlayers2, playerListPositions2);     //Assign their positions 

        

    } else if(stoi(userInput) == 2) {       //If the user wants to enter their player
        Player userPlayer;          //Make a new player
        string playerName;      //Make a string variable for the name
        string stat;            //Make a string variable for the stat values
        cout << "Enter a player manually before the game is played, stats should be 10-99 inclusive:" << endl;
        cout << "PlayerName- ";
        cin >> playerName;          //User enters the player name, no checks for validity
        userPlayer.setWholeName(playerName);        //Sets the name of the player
        cout << "Armstrength-";         
        cin >> stat;                    //Cin the armstrength stat
        while(!checkInput(stat)) {      //Check validity and reprompt if needed
            cout << "Please enter an integer in the range 10 - 99 inclusive:" << endl;
            cout << "Armstrength-";
            cin >> stat;
        }
        userPlayer.setArmStrength(stoi(stat));      //Set the armStrength

        cout << "Speed-";
        cin >> stat;                //cin the speed stat
        while(!checkInput(stat)) {      //While the input is not valid, reprompt
            cout << "Please enter an integer in the range 10 - 99 inclusive:" << endl;
            cout << "Speed-";
            cin >> stat;
        }
        userPlayer.setSpeed(stoi(stat));        //Set the speed

        cout << "Agility-";             //Enter the agility stat
        cin >> stat;
        while(!checkInput(stat)) {      //While the stat is not valid, reprompt
            cout << "Please enter an integer in the range 10 - 99 inclusive:" << endl;
            cout << "Agility-";
            cin >> stat;
        }
        userPlayer.setAgility(stoi(stat));      //Set the agility

        cout << "GroundRating-";
        cin >> stat;                        //enter the groundRating stat
        while(!checkInput(stat)) {          //While stat is not valid, reprompt
            cout << "Please enter an integer in the range 10 - 99 inclusive:" << endl;
            cout << "GroundRating-";
            cin >> stat;
        }
        userPlayer.setGroundRating(stoi(stat));     //Set the players groundRatings

        cout << "FlyRating-";
        cin >> stat;                    //Enter the stat for flyRating
        while(!checkInput(stat)) {      //While the stat is not valid, reprompt
            cout << "Please enter an integer in the range 10 - 99 inclusive:" << endl;
            cout << "FlyRating-";
            cin >> stat;
        }
        userPlayer.setFlyRating(stoi(stat));        //Set the flyRating
        
        cout << "Stamina-";
        cin >> stat;            //User enters the stamina stat
        while(!checkInput(stat)) {      //While the stat is not valid, reprompt
            cout << "Please enter an integer in the range 10 - 99 inclusive:" << endl;
            cout << "Stamina-";
            cin >> stat;
        }
        userPlayer.setStamina(stoi(stat));      //Set the stamina as the stamina stat

        cout << "Hitting-";     
        cin >> stat;            //Enter the hitting stat
        while(!checkInput(stat)) {      //While the stat is not valid, reprompt
            cout << "Please enter an integer in the range 10 - 99 inclusive:" << endl;
            cout << "Hittings-";
            cin >> stat;
        }
        userPlayer.setHitting(stoi(stat));      //Set the hitting
        playerList.insert(0, userPlayer);       //Enter the player into the list

        for(int i = 2; i < 10; i++) {           //Insert 8 more randomized players to the list
            Player newPlayer;
            newPlayer.randomizeStats();
            newPlayer.setName(to_string(i));
            playerList.insert(10, newPlayer);
        }
        Team firstTeam(playerList);     //Make a team out of the list
        firstTeam.assignPositions(assignedPlayers, playerListPositions);    //Assign the teams positions
        cout << endl;

        for(int i = 1; i < 10; i++) {       //Make another team with 9 players
            Player newPlayer;
            newPlayer.randomizeStats();
            newPlayer.setName(to_string(i));
            playerList2.insert(10, newPlayer);
        }

        Team secondTeam(playerList2);           //Make a second team out of the list
        secondTeam.assignPositions(assignedPlayers2, playerListPositions2); //Assign the teams positions
        
    }

    ofstream fileOutput("Team_Statistics.txt");     //Make ofstream with the file name
    if(fileOutput.fail()) {     
      cerr << "Error opening output file.";    //If it fails, notify and end program
      return 1;
    } else {
      cout << "Writing Team_Statistics.txt" << endl;   //notify of new file being written
    }
    fileOutput << "Printing the away team in position order." << endl;
    writeField(playerListPositions, fileOutput);        //Print the away team first
    fileOutput << endl;
    fileOutput << "Printing the home team in position order." << endl;
    writeField(playerListPositions2, fileOutput);           //Then print the home team
    playGame(playerListPositions2, playerListPositions);    //Play the game with the two teams
    fileOutput.close();         //Close the file output

    
    return 0;
}