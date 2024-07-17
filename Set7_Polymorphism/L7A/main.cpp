/* CSCI 261: L7A SFML Drawing
 *
 * Author: Patrick Maes
 * Resources used: NONE
 *
 * Creates a picture of concentric circles and squares
 */
#include <SFML/Graphics.hpp>
#include <cmath>
using namespace sf;

int main() {
    // create a window
    RenderWindow window( VideoMode(640, 640), "SFML Test" );    //Create window with 640x640 pixels
    CircleShape outerCircle(100);                       //Create circle shape with radius 100
    outerCircle.setOrigin(outerCircle.getRadius(), outerCircle.getRadius());    //set the origin as the middle
    outerCircle.setPosition(640/2, 640/2);  //Set position in center of window

    RectangleShape outerRectangle;              //Create rectangle shape
    outerRectangle.setSize(Vector2f(200, 200)); //Sets the size of the rectangle as the circles diameter
    outerRectangle.setFillColor(Color::Blue);   //Sets color as blue
    Vector2f outerPosition(220, 220);           //Sets position to be middle of window
    outerRectangle.setPosition(outerPosition);  


    RectangleShape innerRectangle;                //Make second rectangle
    innerRectangle.setSize(Vector2f(200/sqrt(2), 200/sqrt(2))); //Make corners touch outside of circle
    innerRectangle.setFillColor(Color::Blue);       //Set color as blue
    Vector2f innerPosition(320 - (200/sqrt(2))/2, 320 - (200/sqrt(2))/2);   //Set the position as middle of window
    innerRectangle.setPosition(innerPosition);      //

    CircleShape innerCircle(200/(2*sqrt(2)));           //Make a circle that is radius of the previous rectangle
    innerCircle.setOrigin(innerCircle.getRadius(), innerCircle.getRadius());    //Make the origin the center
    innerCircle.setPosition(640/2, 640/2);      //Set position as the center of the window

    RectangleShape middle;      //Create very middle rectangle
    middle.setSize(Vector2f(100, 100));     //Set dimensions as first circle radius
    middle.setFillColor(Color::Blue);       //Set color as blue
    Vector2f middlePos(320 - (50), 320 - (50));     //Set the rectangle to the middle of the window
    middle.setPosition(middlePos);

    
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
        window.draw(outerRectangle);
        window.draw(outerCircle);
        window.draw(innerRectangle);
        window.draw(innerCircle);
        window.draw(middle);
      
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