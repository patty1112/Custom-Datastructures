/* CSCI 261 Lab 2C (_INSERT_LAB_HERE_): Polar-Cartesian Converter
 *
 * Author: Patrick maes
 *
 * Create functions that convert from polar and back.
 */

// The include section adds extra definitions from the C++ standard library.
#include <iostream> // For cin, cout, etc.
#include <cmath>

// We will (most of the time) use the standard library namespace in our programs.
using namespace std;

void polar_to_cartesian(const double &radius, const double &angle) {    //Define function

double x;                       //Declare temporary variables
double y;
x = radius * (cos(angle));      //Set x = rcos(theta (in radians))
y = radius * (sin(angle));      //Set y = rsin(theta(in radians))

cout << "Cartesian coordinates for the polar point (" << radius << ", " << angle << ") <--(RADIANS) is: " << endl;
cout << "("<< x << ", " << y << ")"<< endl;               //Cout the point with x and y

}

void cartesian_to_polar(const double &xCoord, const double &yCoord) {
    double r;
    double theta;               //Declare temporary variables


r = sqrt((pow(xCoord, 2)) + (pow(yCoord, 2)));      //Set r = distance from the origin.                                
theta = atan((yCoord/xCoord));                      //Set theta = arctan(y/x)                                              
theta = theta * (180/M_PI);                         //Change it to degrees             

cout << "Polar coordinates using degrees for (" << xCoord << ", " << yCoord << ") are: " << endl;
cout << "(" << r << ", " << theta << ")" << endl;       //Cout the point in degrees

}


int main() {
int userChoice;             //Define variables
double chosenRadius;
double chosenRadians;
double chosenDegrees;
double chosenX;
double chosenY;

cout << "Welcome to the polar-cartesian converter!" << endl;
cout << "Enter 1 to convert to cartesian ((r,theta) -> (x,y)):" << endl;
cout << "Enter 2 to convert to polar ((x,y) -> (r, theta)):" << endl;
cin >> userChoice;  //prompt user for which option they want

if (userChoice == 1) {      //if option is the first,
    cout << "Enter the radius from the origin: " << endl;
    cin >> chosenRadius;                //prompt for radius and angle
    cout << "Enter the angle from the positive x-axis in degrees: " << endl;
    cin >> chosenDegrees;
    chosenRadians = chosenDegrees * (M_PI/180); //convert to radians for cos and sin function

    polar_to_cartesian(chosenRadius, chosenRadians);    //convert the numbers
}

if (userChoice == 2) {      //if option is the second,
    cout << "Enter the x coordinate of the point (decimal value): " << endl;
    cin >> chosenX;            //prompt for x and y as decimals
    cout << "Enter the y coordinate of the point (decimal value): " << endl;
    cin >> chosenY;

    cartesian_to_polar(chosenX, chosenY);   //convert to polar
}



  return 0; // signals the operating system that our program ended OK.
}
