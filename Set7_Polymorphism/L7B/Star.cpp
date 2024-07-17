/* CSCI 261: L7B Starcraft
 *
 * Author: Patrick Maes
 * Resources used: NONE
 *
 * Draws the stars from stars.txt
 */
#include "Star.h"

Star::Star() {
    windowHeight = 0;
    windowWidth = 0;        //Initial height, width and brightness are -1
    starBrightness = 0;
    this->setRadius(2.0);           //Set the radius as 2
    this->setPosition(0.0f, 0.0f);      //Sets the position at 0,0
}

Star::Star(int newWindowWidth, int newWindowHeight, float newMaxBrightness) {
    windowHeight = newWindowHeight;     //Sets the window hight and width
    windowWidth = newWindowWidth;
    this->setBrightness(newMaxBrightness/2);        //uses half max brightness as initial brightness
    this->setRadius(2.0);                   //Sets radisus as 2
    cout << "Constructing the star: initial position -" << endl;
    this->setPosition(0.0f, 0.0f);      //sets the position at 0,0
}

Star::~Star() {
}   

void Star::setPosition(float xPosition, float yPosition) {
    float x = (xPosition + 1) * windowWidth /2;     //computes x into window width
    float y = (-yPosition + 1) * windowHeight /2;   //computes y into window height
    cout << x << " " << y << endl;          //Prints the position after moving
    CircleShape::setPosition(Vector2f(x, y));       //Sets the position

}

void Star::setBrightness(float brightness) {
    float maxBrightness = 7.96;     //max brightness was found to be 7.96
    float invertedBrightness = maxBrightness - brightness;      //Inverts the brightness
    int shadeOfGray = (int)((255.0 * invertedBrightness ) / maxBrightness); //Makes it a shade of grey
    setFillColor(Color(shadeOfGray, shadeOfGray, shadeOfGray));     //Sets the color as the grey color
}   

