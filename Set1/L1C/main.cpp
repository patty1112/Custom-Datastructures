/* CSCI 261: Lab 1C Generate and classify a random value
 *
 * Author: Patrick Maes
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     NO resorces used
 *
 * Generates a random number between two user chosen values and provides the quartile 
 * of the generated number.
 */
// The include section adds extra definitions from the C++ standard library.
#include <iostream> // For cin, cout, etc.
#include <cstdlib>
#include <ctime>

// We will (most of the time) use the standard library namespace in our programs.
using namespace std;

// Define any constants below this comment.

// Must have a function named "main", which is the starting point of a C++ program.
int main() {

float upperLimit;        //Define variables for user input
float lowerLimit;
float randomFloat;

srand( time(0) );             //Seed is based on amount of time waited
rand();       //First number is generated but not used.
cout << "Enter the upper limit of the random number:" << endl;
cin >> upperLimit;
cout << "Enter the lower limit of the random number:" << endl;
cin >> lowerLimit;
randomFloat = rand() / (double)RAND_MAX * (upperLimit - lowerLimit) + lowerLimit;   //Uses the bounds and ensures number is between them
cout << "The random number is: " << randomFloat << endl;

float middleQuartile = (upperLimit + lowerLimit) / 2;    //Create quartiles using averages
float lowerQuartile = (middleQuartile + lowerLimit) / 2;   //Math statement finds the middle of the limits
float upperQuartile = (middleQuartile + upperLimit) / 2;


if (randomFloat <= lowerQuartile) {    // Decides which quartile the number is in
  cout << "This is in the first quartile";

} else if (randomFloat >= lowerQuartile && randomFloat < middleQuartile) {
  cout << "This is in the second quartile";

} else if (randomFloat > middleQuartile && randomFloat < upperQuartile) {
  cout << "This is in the third quartile";

} else if (randomFloat >= upperQuartile) {
  cout << "This is in the fourth quartile";
}



  return 0; // signals the operating system that our program ended OK.
}