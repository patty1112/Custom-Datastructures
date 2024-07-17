/* CSCI 261: L7B Starcraft
 *
 * Author: Patrick Maes
 * Resources used: NONE
 *
 * Draws the stars from stars.txt
 */
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Star.h"
#include "starData.h"
#include <fstream>
using namespace std;
using namespace sf;

int main() {
    // create a window
    RenderWindow window( VideoMode(640, 640), "SFML Test" );
    vector<starData> dataList;      //Creates a list for the data
    vector<Star> starList;          //Creates a list for the stars
    ifstream fileContents;          //Input file stream called fileContents
    fileContents.open("stars.txt");
    if(fileContents.fail()) {       //If the file doesnt open
        cerr << "The file failed to open." << endl;     //Throw an error
        return -1;
    }
    cout << "The file opened successfully" << endl;         //Else notify of file opening

    while(!fileContents.eof()) {        //While there is data in the list
        starData newStar;
        float xValue;           //Make variables for the x, y, and brightness
        float yValue;
        float brightness;
        float trash;
        fileContents >> xValue;     //Input the x and y
        fileContents >> yValue;
        fileContents >> trash;      //Trash the z position
        fileContents >> brightness;
        if(brightness > 0 && brightness <= 8) {     //if the brightness is between the two values
            newStar.xValue = xValue;
            newStar.yValue = yValue;            //Enter the data to the struct
            newStar.maxBrightness = brightness;
            dataList.push_back(newStar);            //Push the struct to the vector
        }
        fileContents >> trash;      //Trash last two columns
        fileContents >> trash;
        
    }
    float brightest = dataList.at(0).maxBrightness;     //Find the brightest star in the list
    for(int i = 0; i < dataList.size(); i++) {
        if(dataList.at(i).maxBrightness > brightest) {
           brightest = dataList.at(i).maxBrightness; 
        }
    }
    cout << brightest << endl;          //Prints 7.96- the brightest value

    for(int i = 0; i < dataList.size(); i++) {      //For each element in the list
        
        Star newStar(640, 640, dataList.at(i).maxBrightness);   //Create a star
        cout << "Original x and y read from file:" << endl;     //Print the original x and y coordinates
        cout << dataList.at(i).xValue << " " << dataList.at(i).yValue << endl;      
        cout << "Resetting the position of the star:" << endl;          //Print the position after moving it
        newStar.setPosition(dataList.at(i).xValue, dataList.at(i).yValue);      //Set the position of the star
        newStar.setBrightness(dataList.at(i).maxBrightness);        //Set the brightness as the data list's brightness at that star
        starList.push_back(newStar);        //Add the star to the list
    }
    cout << "Brightest Star:" << endl;          //Print the brightest star
    cout << brightest << endl;

 
    

    

    /////////////////////////////////////
    // BEGIN ANY FILE LOADING

    // perform any file processing once before draw loop begins

    //  END  ANY FILE LOADING
    /////////////////////////////////////

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
        for(int i = 0; i < starList.size(); i++) {
            window.draw(starList.at(i));
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

    return 0;
}