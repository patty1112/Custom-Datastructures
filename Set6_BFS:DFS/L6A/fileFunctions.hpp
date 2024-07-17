#include <iostream> 
#include "DoublyLinkedList.hpp"

string promptUserForFileName();
bool open_file(ifstream&, const string);



//------------------------- Implementations -----------------------------------

string promptUserForFileName() {
    string fileName = "";               //Make a variable to store user input
    cout << "Enter the path and name of the file to be opened: " << endl;   
    cin >> fileName;                    //Store the input in the variable
    return fileName;   
}

bool open_file(ifstream& fileContents, const string fileName) {     //Opens the file that was entered by the user.
    cout << "Opening the file " << fileName <<  endl;               //Notify the user of the file being opened
    fileContents.open(fileName);                                    //Open the file
    if(fileContents.fail()) {                                       //If it fails
        return false;                                               //Return False
    }


    return true;                                                    //Else return true
}   