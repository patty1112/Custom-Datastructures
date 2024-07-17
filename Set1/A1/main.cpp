/* CSCI 261: Assignment 1: A1 - Rock Paper Scissor Throw Down!
 *
 * Author: Patrick Maes
 * Resources used: No resorces Used
 *
 * Random generator that takes user input for "Rock Paper Scissors" and returns the winner.
 */
// The include section adds extra definitions from the C++ standard library.
#include <iostream> // For cin, cout, etc.
#include <cstdlib>
#include <ctime>
// We will (most of the time) use the standard library namespace in our programs.
using namespace std;

// Define any constants below this comment.

// Must have a function named "main", which is the starting point of a C++ program.
int main() {
int playerWins = 0;       //Declaration of most variables. First ones track wins
int computerWins = 0;
int ties = 0;
startOfCode:              //Start here when user wants to play again
//THIS IS A GO-TO STATEMENT, BETTER DONE WITH BIG WHILE LOOP. AVOID THESE WHEN POSSIBLE
int randomChoice;         //Computer generated integer
string playerMove;        //String that player enters to console for rock paper or scissors
int playerMoveNumber;     //Number corresponding to playerMove


cout << "Welcome one and all to a round of Rock, Paper, Scissors! (Enter P, R, or S): " << endl;
cout << "Player: ";
cin >> playerMove;            //Player enters their move to the console


if (playerMove == "P" || playerMove == "p") {
    cout << endl << "Player choose Paper" << endl;        //These statements give user information and assign the chosen string to a number
    playerMoveNumber = 1;                                 //These numbers correspond to the random number the computer generates
} else if (playerMove == "R" || playerMove == "r") {
  cout << endl << "Player choose Rock" << endl;
  playerMoveNumber = 2;
} else if (playerMove == "S" || playerMove == "s") {
  cout << endl << "Player choose Scissors" << endl;
  playerMoveNumber = 3;
}
srand(time(0));         //Seeds based on time


rand();                                       //Disregard first for more randomness
randomChoice = rand() % (3 - 1 + 1) + 1;      //Computer choice must be between 1 and 3 inclusive.

if (randomChoice == 1) {
  cout << "Computer choose Paper" << endl;    //Console statements to log computer choice
} else if (randomChoice == 2) {
  cout << "Computer choose Rock" << endl;
} else {
  cout << "Computer choose Scissors" << endl;
}


if (playerMoveNumber == 1 && randomChoice == 2) {           //Decisions for who wins based on number of choice
  cout << "Paper beats Rock. Player wins!" << endl;
  playerWins += 1;                                          //Update counters for the correct winner

} else if (playerMoveNumber == 1 && randomChoice == 3) {    //Each is the same outside of the moves being compared.
  cout << "Scissors beat Paper. Computer wins!" << endl;
  computerWins += 1;

} else if (playerMoveNumber == 1 && randomChoice == 1) {
  cout << "The computer chose the same as you, nobody wins!" << endl;
  ties += 1;

}  else if (playerMoveNumber == 2 && randomChoice == 1) {
  cout << "Paper beats Rock. Computer wins!" << endl;
  computerWins += 1;

} else if (playerMoveNumber == 2 && randomChoice == 3) {
  cout << "Rock beats Scissors. Player wins!" << endl;
  playerWins += 1;

} else if (playerMoveNumber == 2 && randomChoice == 2) {
  cout << "The computer chose the same as you, nobody wins!" << endl;
  ties += 1;

} else if (playerMoveNumber == 3 && randomChoice == 1) {
  cout << "Scissors beat Paper. Player wins!" << endl;
  playerWins += 1;

} else if (playerMoveNumber == 3 && randomChoice == 2) {
  cout << "Rock beats Scissors. Computer wins!" << endl;
  computerWins += 1;

} else if (playerMoveNumber == 3 && randomChoice == 3) {
  cout << "The computer chose the same as you, nobody wins!" << endl;
  ties += 1;
}



string input;
cout << "Do you want to play again? (Enter y/n)" << endl;         //Ask user to play again
cin >> input;
if (input == "y" || input == "Y") {               
  goto startOfCode;                                               //If yes, go to the startOfCode line (BAD PRACTICE)
}
else if (input == "n" || input == "N") {                        //If no log the winners and end the program
  cout << "Thanks for playing!" << endl;
  cout << "You won " << playerWins << " game(s), and lost " << computerWins << " game(s), and tied " << ties << " game(s)." << endl; //Prints winners
}

  return 0; // signals the operating system that our program ended OK.
}