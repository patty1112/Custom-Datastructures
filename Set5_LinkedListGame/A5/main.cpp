/* CSCI 261: Assignment A5 Wild Left-Center-Right Simulation
 *
 * Author: Patrick Maes
 * No Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     Video on linked list definition - https://www.youtube.com/watch?v=3gZ7F31Mwi0
 *
 * Create a program to prompt up to 15 numbers from the user and return the max and min.
 */
// The include section adds extra definitions from the C++ standard library.
#include <iostream>
#include "CircularlyDoublyLinkedList.hpp"

#include "Game.h"
#include "Dice.h"
#include <ctime>
#include <random>
#include <string>
#include <iomanip>

using namespace std;
    
int main () {
    srand(time(0));             //Seed the number generator with time
    rand();                     //Discard first value
    CircularlyDoublyLinkedList<Player> newList;     //Make a list of players, circularly doubly linked
    string userInput = "";                          //Variable to hold input
    bool repromptNumber = true;                     //While the input is not an integer
    while(repromptNumber) {                         //Prompt again
        cout << "Enter the number of players to insert into the game: (Integer)" << endl;
        cin >> userInput;                               //Take user input
        int placeValues = userInput.length();           //Find the length of the input
        for(int i = 0; i < placeValues; i++) {          //For each character entered
            repromptNumber = !isdigit(userInput[i]);    //If the character is not a digit, reprompt the number
            if(repromptNumber == true) {                //If all are integers,
                break;                                  //Break
            }
        }
    }

    repromptNumber = true;
    string numberOfSimulations = "";
    while(repromptNumber) {                         //Prompt again
        cout << "Enter the number of simulations: (Integer)" << endl;
        cin >> numberOfSimulations;                               //Take user input
        int placeValues = numberOfSimulations.length();           //Find the length of the input
        for(int i = 0; i < placeValues; i++) {          //For each character entered
            repromptNumber = !isdigit(numberOfSimulations[i]);    //If the character is not a digit, reprompt the number
            if(repromptNumber == true) {                //If one is not an integer,
                break;                                  //Break and reprompt
            }
        }
    }

    Game LCR;
    CircularlyDoublyLinkedList<int> turnsList;
    for(int i = 0; i < stoi(numberOfSimulations); i++) {
        LCR.play(stoi(userInput), newList, LCR, turnsList);
    }
    cout << "Printing the number of turns for each simulation, REVERSE ORDER: " << endl;
    turnsList.print();
    cout << "Printing the average number of turns for all the simulations: " << endl;
    cout << turnsList.average() << endl;

    return 0;
}