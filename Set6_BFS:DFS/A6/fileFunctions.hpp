#ifndef FILEFUNCTIONS
#define FILEFUNCTIONS


#include <iostream>
#include "Position.hpp"
#include "DoublyLinkedList.hpp"
#include <fstream>
using namespace std;

string promptUserForFileName();
bool open_file(ifstream&, const string);
DoublyLinkedList<DoublyLinkedList<char> > readDimensions(ifstream&, int&, int&, Position&);



//---------------------------- Implementations ---------------------------

string promptUserForFileName() {        //Prompts the user for the filename if not entered
    string fileName = "";               //Make a variable to store user input
    cout << "Enter the path and name of the file to be opened: " << endl;   
    cin >> fileName;                    //Store the input in the variable
    return fileName;                    //Return the fileName
}

bool open_file(ifstream& fileContents, const string fileName) {     //Opens the file that was entered by the user.
    cout << "Opening the file " << fileName <<  endl;               //Notify the user of the file being opened
    fileContents.open(fileName);                                    //Open the file
    if(fileContents.fail()) {                                       //If it fails
        return false;                                               //Return False
    }


    return true;                                                    //Else return true
}   

DoublyLinkedList<DoublyLinkedList<char> > readDimensions(ifstream& fileContents, int& length, int& width, Position& searchStart) {
    fileContents >> length;         //Reads in the length and width
    fileContents >> width;
    
    DoublyLinkedList<DoublyLinkedList<char> > parentList;       //Makes a list to hold lists
    for(int i = 0; i < length; i++) {               //Make as many lists as rows
        DoublyLinkedList<char> listToInsert;                    //Makes a list of chars
        for(int j = 0; j < width; j++) {            //Make as many inner lists as columns
            char currentValue = ' ';        //Make the current value variable
            fileContents >> currentValue;       //Take input from the file
            if(currentValue == 'S') {       //If the variable reads S
                searchStart.column = j;
                searchStart.row = i;    //Make that position the start of the search
            }
            listToInsert.insert(width, currentValue);   //Insert a node with the file value
        }
        parentList.insert(length, listToInsert);        //Insert that whole list into the parent list
    }
    return parentList;          //Return the outside list
}



#endif