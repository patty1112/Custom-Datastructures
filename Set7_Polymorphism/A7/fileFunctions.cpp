/* CSCI 261: A7 Triangle Land
 *
 * Author: Patrick Maes
 * Resources used: NONE
 *
 * Validates and draws the triangles from triangles.dat
 */
#include "fileFunctions.h"
#include <iostream>

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