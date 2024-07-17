#include <iostream>
#include <fstream>
#include "fileFunctions.hpp"
#include "DoublyLinkedList.hpp"
#include "Position.hpp"



using namespace std;

int main(int argc, char* argv[]) {      //Main takes 2 arguements 
    string fileName = "";               //File name is empty
    if(argc == 1) {                     //If there was only one arguement
        fileName = promptUserForFileName();     //Prompt the file name
    } else if (argc == 2) {         //If the user entered the file name
        fileName = argv[1];         //The file name is the second arguement
    } else {            //Else tell the user how to enter a file
        cerr << "Usage: " << argv[0] << " [filename]" << endl;
        cerr << "filename is an optional parameter, can be entered later." << endl;
    }
    
    ifstream fileContents;      //Make input file stream
    if(!open_file(fileContents, fileName)) {        //Open the file and test if it fails
        cerr << "Could not open file, shutting down..." << endl;    //If fail end the program
        return -1;
    }
    cout << "File successfully opened!" << endl << endl;

    int arrayLength = 0;        //Create variables for the maze dimensions
    int arrayWidth  = 0;    
    DoublyLinkedList<DoublyLinkedList<char> > mazeArray;    //Create a linked list for the maze
    Position searchStart;                                   //Make a position for the S character
    mazeArray = readDimensions(fileContents, arrayLength, arrayWidth, searchStart);     //Build the maze
    
    cout << "Enter 1 to search via BFS" << endl;        //Prompt for the option
    cout << "Enter 2 to search via DFS" << endl;

    string userInput = "";                          //Variable to hold input
    bool repromptNumber = true;                     //While the input is not an integer
    while(repromptNumber) {                         //Prompt again
        cout << "Choice: ";     
        cin >> userInput;                   
        if(userInput.length() == 1) {           //If the input is one digit
            if(isdigit(userInput[0]) && (stoi(userInput) == 1 || stoi(userInput) == 2)) {       //Makes sure its a digit
                repromptNumber = false;         //Stop prompting
            } else {                
                cout << "Please enter an integer (1 or 2)." << endl;    //Else reprompt
            }
        } else {
            cout << "Please enter a one digit number (1 or 2)" << endl;
        }
    }

    Position targetPos;             //Make the variable to hold the target
    if(stoi(userInput) == 1) {      //If they choose BFS
        targetPos = mazeArray.breadthFirstSearch(searchStart);  //Search using BFS
        
    } else if(stoi(userInput) == 2) {       //If they choose DFS
        targetPos = mazeArray.depthFirstSearch(searchStart);    //Search using DFS
    }
    cout << "Printing the position of the end, indexed from 0. Will return -1 if not found: " << endl;
    targetPos.print();          //Print the target position

    fileContents.close();       //Close the file
}