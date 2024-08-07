/* CSCI 261: A7 Triangle Land
 *
 * Author: Patrick Maes
 * Resources used: NONE
 *
 * Validates and draws the triangles from triangles.dat
 */
#include "IsoscelesTriangle.h"
#include <cmath>

bool IsoscelesTriangle::setCoordinates(Vector2f& firstVertex, Vector2f& secVertex, Vector2f& thirdVertex) {
    vertex1 = firstVertex;       //Sets the verticies as the arguements
    vertex2 = secVertex;
    vertex3 = thirdVertex;
    float distance1 = 0;        //Make variables for distance
    float distance2 = 0;
    float distance3 = 0;
        //Compute distance for all sides
    distance1 = sqrt(pow((vertex2.x - vertex1.x), 2) + pow((vertex2.y - vertex1.y), 2)); 
    distance2 = sqrt(pow((vertex3.x - vertex2.x), 2) + pow((vertex3.y - vertex2.y), 2)); 
    distance3 = sqrt(pow((vertex1.x - vertex3.x), 2) + pow((vertex1.y - vertex3.y), 2)); 
    if(distance1 == 0 || distance2 == 0 || distance3 == 0) {        //If the sides are 0 in length
        return false;       //Return false
    }
    if(distance1 + distance2 <= distance3) {    //If the distances are not greater than the third
        return false;                           //Return false
    } else if (distance1 + distance3 <= distance2) {
        return false;
    } else if(distance3 + distance2 <= distance1) {
        return false;
    }
    if(distance1 != distance2 && distance2 != distance3 && distance1 != distance3) {    //If the triangle is not isosceles
        return false;       //Return false
    }
    return true;
}
