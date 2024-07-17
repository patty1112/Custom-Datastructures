/* CSCI 261: Assignment A4 OBJ File Validator
 *
 * Author: Patrick Maes
 * No Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     Video on linked list definition - https://www.youtube.com/watch?v=3gZ7F31Mwi0
 *
 * Create a program to prompt up to 15 numbers from the user and return the max and min.
 */
// The include section adds extra definitions from the C++ standard library.
#include <iostream>
#include <fstream>
#include "Node.h"
#include "Vertex.h"
#include "Face.h"
#include "vector_functions.h"
#include "LinkedList.hpp"


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
    LinkedList<string> commentList;       //Make pointers to the heads of the lists
    LinkedList<Vertex> vertexList;
    LinkedList<Face> faceList;

    read_file_contents(fileContents, commentList, vertexList, faceList);       //Places all contents of file into different linked lists.
    bool valid = false;         //Make a variable, tells if file is valid
    valid = validate_faces(commentList, vertexList, faceList);    //Validate the file and update valid
    if(valid == false) {        //If the file is invalid
        return -1;          //End the program
    }
    
    bool promptFunctions = true;
    while(promptFunctions){     //While function returns true
        promptFunctions = fileFunctions(commentList, vertexList, faceList);  //Prompt the functions for the OBJ file
    }
    cout << "Goodbye!" << endl;
    fileContents.close();           //Close the file
                                    //Lists deleted off freestore using destructor
    return 0;


    
}