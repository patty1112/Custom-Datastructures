/* CSCI 261: A7 Triangle Land
 *
 * Author: Patrick Maes
 * Resources used: NONE
 *
 * Validates and draws the triangles from triangles.dat
 */
#include <iostream>
#include <fstream>
#include "fileFunctions.h"
#include "EquilateralTriangle.h"
#include "IsoscelesTriangle.h"
#include "ScaleneTriangle.h"
#include <vector>
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

    vector<Triangle*> triangleList;     //Make a list of triangle pointers

    while(!fileContents.eof()) {        //While the file has more text
        char type = ' ';                //Create variable for the type
        fileContents >> type;           //Input type
        float xCord1 = 0;               //Make variables for the coordinates
        float yCord1 = 0;
        float xCord2 = 0;
        float yCord2 = 0;
        float xCord3 = 0;
        float yCord3 = 0;
        int red = 0;            //Make variables for the color
        int blue = 0;
        int green = 0;  
        if(type == 'E') {       //If the type is equilateral
            EquilateralTriangle* newTriangle = new EquilateralTriangle; //make equilateral triangle pointer
            fileContents >> xCord1;         //Enter the coordinates and color
            fileContents >> yCord1;
            fileContents >> xCord2;
            fileContents >> yCord2;
            fileContents >> xCord3;
            fileContents >> yCord3;
            fileContents >> red;
            fileContents >> green;
            fileContents >> blue;
            Vector2f first = Vector2f(xCord1, yCord1);     //Make float vectors out of the variables
            Vector2f sec = Vector2f(xCord2, yCord2);
            Vector2f third = Vector2f(xCord3, yCord3);

            if(newTriangle->setCoordinates(first, sec, third)) {        //If the triangle is valid
                newTriangle->setColor(Color(red, green, blue));         //Set the coordinates, color, and add it to the list
                triangleList.push_back(newTriangle);
            } else {        //Else, throw an error and delete it
                cout << "Triangle is invalid. - " << type << " " << xCord1 << " " << yCord1 << " " << xCord2 << " " << yCord2 << " " << xCord3 << " " << yCord3 << " " << red << " " << green << " " << blue << endl;
                delete newTriangle;
            }

        } else if(type == 'I') {        //If isosceles
            IsoscelesTriangle* newTriangle = new IsoscelesTriangle;     //Make isosceles pointer
            fileContents >> xCord1;
            fileContents >> yCord1;
            fileContents >> xCord2;     //Read in the attributes
            fileContents >> yCord2;
            fileContents >> xCord3;
            fileContents >> yCord3;
            fileContents >> red;
            fileContents >> green;
            fileContents >> blue;
            Vector2f first = Vector2f(xCord1, yCord1);      //Make vectors out of the variables
            Vector2f sec = Vector2f(xCord2, yCord2);
            Vector2f third = Vector2f(xCord3, yCord3);

            if(newTriangle->setCoordinates(first, sec, third)) {    //If the triangle is valid
                newTriangle->setColor(Color(red, green, blue)); //Set the color, position, and push it to the list
                triangleList.push_back(newTriangle);
            } else {        //Else throw an error
                cout << "Triangle is invalid. - " << type << " " << xCord1 << " " << yCord1 << " " << xCord2 << " " << yCord2 << " " << xCord3 << " " << yCord3 << " " << red << " " << green << " " << blue << endl;
                delete newTriangle;
            }
            
        } else if(type == 'S') {        //If the type is scalene
            ScaleneTriangle* newTriangle = new ScaleneTriangle; //Create scalene pointer
            fileContents >> xCord1; 
            fileContents >> yCord1;         //Read in variables 
            fileContents >> xCord2;
            fileContents >> yCord2;
            fileContents >> xCord3;
            fileContents >> yCord3;
            fileContents >> red;
            fileContents >> green;
            fileContents >> blue;
            Vector2f first = Vector2f(xCord1, yCord1);      //Make vectors out of the coordinates
            Vector2f sec = Vector2f(xCord2, yCord2);
            Vector2f third = Vector2f(xCord3, yCord3);

            if(newTriangle->setCoordinates(first, sec, third)) {        //If the triangle is valid
                newTriangle->setColor(Color(red, green, blue));     //Set the color, position, and push it to the list
                triangleList.push_back(newTriangle);   
                
            } else {        //Else throw an error
                cout << "Triangle is invalid. - " << type << " " << xCord1 << " " << yCord1 << " " << xCord2 << " " << yCord2 << " " << xCord3 << " " << yCord3 << " " << red << " " << green << " " << blue << endl;
                delete newTriangle;
            }
        }
    }
    cout << triangleList.size() << endl;        //Print the size of the list
    RenderWindow window( VideoMode(640, 640), "SFML Test" );    //Create a window
    
    /////////////////////////////////////
    // BEGIN ANY FILE LOADING

    // perform any file processing once before draw loop begins

    //  END  ANY FILE LOADING
    /////////////////////////////////////
    for(int i = 0; i < triangleList.size(); i++) {
        triangleList.at(i)->print();
    }
    // create an event object once to store future events
    Event event;

    // while the window is open
    while( window.isOpen() ) {
        // clear any existing contents
        window.clear();

        /////////////////////////////////////
        // BEGIN DRAWING HERE

        // place any draw commands here to display in the window

        //  END  DRAWING HERE
        /////////////////////////////////////
        for(int i = 0; i < triangleList.size(); i++) {
            triangleList.at(i)->draw(window);
        }

        // display the current contents of the window
        window.display();

        /////////////////////////////////////
        // BEGIN EVENT HANDLING HERE
        // check if any events happened since the last time checked
        while( window.pollEvent(event) ) {
            // if event type corresponds to pressing window X
            if(event.type == Event::Closed) {
                // tell the window to close
                window.close();
            }
            // check addition event types to handle additional events
        }
        //  END  EVENT HANDLING HERE
        /////////////////////////////////////
    }
    for(int i = 0; i < triangleList.size(); i++) {
        delete triangleList.at(i);
    }
    fileContents.close();
    return 0;
}