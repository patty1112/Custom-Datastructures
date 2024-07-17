/* CSCI 261 Lab L1A: Equation Implementation
 *
 * Author: Patrick Maes
 *
 * Pick two of the equations to implement with helpful console output for the user. Equations should be excecuted in succession.
 * My program will compute distance and then volume of a sphere
 */

#include <iostream>
#include <cmath>

using namespace std;

// Define any constants below this comment.
float pi = 3.1415;


int main() {

   cout << "Hello World!" << endl;

    float x;
    float y;
    float distance;                                   //Variables for input and answer
    cout << "1. Distance Calculation \n";               //Prompt user for coordinates
    cout << "Enter the value of the x component: \n";
    cin >> x;                                           //Store in respective variable
    cout << "Enter the value of the y component: \n";
    cin >> y;
    cout << "The distance from the origin is: \n";
    distance = sqrt(pow(x, 2) + pow(y, 2));             // Compute the distance
    cout << distance << endl;                           //print the distance


    float radius;
    float volume;                                 //Variables for radius and volume
    cout << "2. Volume of a Sphere \n";             //Prompt user for the radius
    cout << "Enter the length of the radius: \n";
    cin >> radius;                                       //Store in radius
    cout << "The volume of the sphere is: \n";
    float r3 = pow(radius, 3);                        //r3 is radius cubed
    volume = (r3*pi*4/3);                             //compute volume and print
    cout << volume;
  
  
  return 0; 
}