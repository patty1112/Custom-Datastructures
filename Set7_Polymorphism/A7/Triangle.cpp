/* CSCI 261: A7 Triangle Land
 *
 * Author: Patrick Maes
 * Resources used: NONE
 *
 * Validates and draws the triangles from triangles.dat
 */
#include "Triangle.h"

Triangle::Triangle() {
    vertex1 = Vector2f(-1, -1);     //Vertexes start as -1
    vertex2 = Vector2f(-1, -1);
    vertex3 = Vector2f(-1, -1);
    this->setColor(Color::White);   //Sets the color to white
    vertexCount = 3;                //3 verticies
}

void Triangle::setColor(const Color newColor) {
    triangleColor = newColor;           //Sets the color as the newColor arguement
}

void Triangle::draw(RenderTarget& window) {     //Draws the triangle to a given window
    ConvexShape triangle;
    triangle.setPointCount(vertexCount);        //Sets 3 points
    triangle.setPoint(0, vertex1);      //Sets the points as the 3 verticies.
    triangle.setPoint(1, vertex2);
    triangle.setPoint(2, vertex3);
    triangle.setFillColor(triangleColor);       //Sets the color
    window.draw(triangle);          //Draws the triangle
}

void Triangle::print() {
        cout << this->vertex1.x << " " << this->vertex1.y << endl;  //Prints a triangles coordinates
        cout << this->vertex2.x << " " << this->vertex2.y << endl;
        cout << this->vertex3.x << " " << this->vertex3.y << endl;
        cout << endl;
}