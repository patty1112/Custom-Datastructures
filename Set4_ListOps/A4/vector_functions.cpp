#include "vector_functions.h"
#include <iostream>
#include <fstream>
#include "Node.h"
#include "Vertex.h"
#include "Face.h"
#include "LinkedList.hpp"
using namespace std;

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


//Reads the contents of the file into three linked lists, all three lists use different classes
void read_file_contents(ifstream& fileContents, LinkedList<string>& commentList, LinkedList<Vertex>& vertexList, LinkedList<Face>& faceList) {
    string currentString;               //Make strings for the first character and the comments 
    string commentString;
    while(!fileContents.eof()) {        //While the file is open
        currentString = "";
        fileContents >> currentString;  //input the character into the currentString
        if(currentString == "#") {              //If the line is a comment,
            getline(fileContents, commentString);       //Get the line
            commentList.pushBack(commentString);            //Store it in the comment list
        } else if(currentString == "v") {           //If the line is a vertex
            float x = 0;                        //Initialize the x, y and z values
            float y = 0;
            float z = 0;
            fileContents >> x;              //Input the x, y and z values from the file
            fileContents >> y;
            fileContents >> z;
            Vertex newVertex(x, y, z);      //Make a new vertex with the given values
            vertexList.pushBack(newVertex);     //Add it to the vertex list
        } else if(currentString == "f") {       //If the line is a face
                int first = 0;                                  //Initialize the face indecies
                int second = 0;
                int third = 0;
                fileContents >> first;              //Input the vertices in the variables
                fileContents >> second;                                 
                fileContents >> third;
                Face newFace(first, second, third);     //Make a new face with the given vertices
                faceList.pushBack(newFace);             //Add it to the face list
        }
    }
    cout << "Read in" << endl;                                  //Print how many of each occured
    cout << '\t' << commentList.size() << " comments" << endl;
    cout << '\t' << vertexList.size() << " vertices" << endl;
    cout << '\t' << faceList.size() << " faces" << endl << endl;
}

bool validate_faces(LinkedList<string>& commentList, LinkedList<Vertex>& vertexList, LinkedList<Face>& faceList) {  //Function to validate the faces read
    cout << "Validating faces..." << endl;  
    bool valid = true;                  //Tracks if the file is valid
    Node<Face>* curr = faceList.pHead;
    int i = 1;                          //Tracks the current node
    while(curr) {
        bool duplicates = false;    //Tracks if it failed the out of range test
        if(curr->value.Vertex1 == curr->value.Vertex2 || curr->value.Vertex2 == curr->value.Vertex3 || curr->value.Vertex1 == curr->value.Vertex3) {        //If any are the same
            cout << setw(8) << "Face " << i <<  " has duplicate indices." << endl;     //If there are duplicates, print the face
            valid = false;                                            //File is invalid
        }
        if(curr->value.Vertex1 > vertexList.size() || curr->value.Vertex2 > vertexList.size() || curr->value.Vertex3 > vertexList.size()) {    //If the vertex is out of range
            cout << setw(8) << "Face " << i <<  " contains vertices out of range" << endl;     //Print the face of the error
            valid = false;              //File is invalid
            duplicates = true;          //There are verticies out of range
        }
        if(!duplicates && (curr->value.Vertex1 < 0 || curr->value.Vertex2 < 0 || curr->value.Vertex3 < 0)) {       //First checks if the face already has verticies out of range, if it is then checks that verticies are above 0
            cout << setw(8) << "Face " << i <<  " contains vertices out of range" << endl;
            valid = false;              //Face is invalid, prints face number
        }
        i++;
        curr = curr->pNext;     //Advances the current face and the counter i
    }
    if(valid) {         //If the file is valid
            cout << "...The file is valid!" << endl << endl;        //Print the file is valid
        } else {
            cout << "...The file is invalid." << endl;
        }
        return valid;               //Return valid to continue the program
}

bool fileFunctions(LinkedList<string>& commentList, LinkedList<Vertex>& vertexList, LinkedList<Face>& faceList) {       //Operates on the file
    bool keepPrompting = true;      //Keeps prompting the user
    while(keepPrompting) {          //While the user wants to perform an operation
        string userInput = "";
        cout << "What do you wish to do? (Enter an Integer)" << endl;
        cout << '\t' << "1) Print comments" << endl;
        cout << '\t' << "2) Print vertices" << endl;
        cout << '\t' << "3) Print faces" << endl;
        cout << '\t' << "4) Quit" << endl; 
        bool repromptOptions = true;        //Ensures that the user enters an integer
        while(repromptOptions) {            //While the input is not an integer
            cout << "Choice: ";             //Take user input
            cin >> userInput;
            if(userInput.length() == 1) {       //If the length is more than 1
                if(isdigit(userInput[0])) {     //If the input is a digit
                    if(stoi(userInput) >= 1 && stoi(userInput) <= 4) {      //If the digit is between 1 and 4
                        repromptOptions = false;                //Stop prompting, good input
                    } else {                    //Else print error message
                        cout << "Enter a number between 1 and 4. (inclusive)" << endl;
                    }} else {
                        cout << "Enter a one digit integer between 1 and 4 (inclusive)." << endl;
                    }} else {
                        cout << "Enter a one digit number between 1 and 4. (inclusive)" << endl;
                    }}
                    cout << endl;
                    if(stoi(userInput) == 1) {
                        Node<string>* curr = commentList.pHead;
                        for(int i = 1; i <= commentList.size(); i++) {
                            if(i <= 9) {                        //Adds extra space for allignment
                                cout << setw(10) << "Comment #" << i << ":" << setw(8) << curr->value << endl;       //Prints the contents of the comment
                            } else if (i > 9) {     //Adds one less space for allignment
                                cout << "Comment #" << i << ":" << setw(8) << curr->value << endl;           //Prints the comment
                            }
                            curr = curr->pNext;     //Advance the pointer
                        }
                        cout << endl;
                        return true;
                    } else if(stoi(userInput) == 2) {
                        Node<Vertex>* curr = vertexList.pHead;
                        for(int i = 1; i <= vertexList.size(); i++) {
                            if(i <= 9) {        //Adds extra space for allignment
                                cout << setw(9) << "Vertex #" << i << ":" << setw(8) << "(" << curr->value.xValue << "," << curr->value.yValue << "," << curr->value.zValue << ")" << endl;     //Print the vertex
                            } else if (i > 9) {     //Adds one less space
                                cout << "Vertex #" << i << ":" << setw(8) << "(" << curr->value.xValue << "," << curr->value.yValue << "," << curr->value.zValue << ")" << endl;        //Print the vertex
                            }
                            curr = curr->pNext;     //Advance the pointer
                        }
                        cout << endl;
                        return true;
                    } else if(stoi(userInput) == 3) {
                        Node<Face>* curr = faceList.pHead;          //Pointer to iterate face list
                        for(int i = 1; i <= faceList.size(); i++) {     //For each face
                            int Vertex1 = curr->value.Vertex1;       //Makes variables to hold the vertex in the face
                            int Vertex2 = curr->value.Vertex2;
                            int Vertex3 = curr->value.Vertex3;
                            Node<Vertex>* currVertex = vertexList.pHead;    //Also make pointer for vertex list
                            for(int i = 1; i < Vertex1; i++) {
                                currVertex = currVertex->pNext;         //Find position of vertex1
                            }
                            Node<Vertex>* firstVertex = currVertex;     //Store the postion
                            currVertex = vertexList.pHead;
                            for(int i = 1; i < Vertex2; i++) {          //Finds where vertex2 is
                                currVertex = currVertex->pNext;
                            }
                            Node<Vertex>* secondVertex = currVertex;      //Stores vertex2 in a new pointer
                            currVertex = vertexList.pHead;
                            for(int i = 1; i < Vertex3; i++) {      //Finds where vertex3 is
                                currVertex = currVertex->pNext;
                            }
                            Node<Vertex>* thirdVertex = currVertex;       //Stores it in a new pointer
                            //Alligns and prints the vertices in order
                            if(i <= 9) {
                                cout << setw(7) << "Face #" << i << ": " << setw(8)<< "(" << firstVertex->value.xValue << "," << firstVertex->value.yValue << "," << firstVertex->value.zValue << ")" << setw(8) << "(" << secondVertex->value.xValue << "," << secondVertex->value.yValue << "," << secondVertex->value.zValue << ")" << setw(8) << "(" << thirdVertex->value.xValue << "," << thirdVertex->value.yValue << "," << thirdVertex->value.zValue << ")" << endl;
                            } else if (i > 9) {
                                cout << "Face #" << i << ": " << setw(8)<< "(" << firstVertex->value.xValue << "," << firstVertex->value.yValue << "," << firstVertex->value.zValue << ")" << setw(8) << "(" << secondVertex->value.xValue << "," << secondVertex->value.yValue << "," << secondVertex->value.zValue << ")" << setw(8) << "(" << thirdVertex->value.xValue << "," << thirdVertex->value.yValue << "," << thirdVertex->value.zValue << ")" << endl;
                            }
                        }
                        cout << endl;
                        return true;
                        } else if(stoi(userInput) == 4) {       //If enters 4,
                            return false;                       //Quit
                        }
    }
    return true;            //Else keep prompting
}