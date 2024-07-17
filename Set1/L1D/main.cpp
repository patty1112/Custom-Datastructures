/* CSCI 261: Lab 1D
 *
 * Author: Patrick maes
 * Resources used: None
 *
 * Print na 10 times before batman using all three data structures
 *
 */
// The include section adds extra definitions from the C++ standard library.
#include <iostream> // For cin, cout, etc.

// We will (most of the time) use the standard library namespace in our programs.
using namespace std;

// Define any constants below this comment.

// Must have a function named "main", which is the starting point of a C++ program.
int main() {

int i = 0;
while (i < 11) {
    cout << "NA..." << endl;
    i += 1;
} cout << "Batman!!!" << endl << endl;

i = 0;
do {
    cout << "NA..." << endl;
    i += 1;
} while (i < 11);
cout << "Batman!!!" << endl << endl;

int j;
for(j = 0; j < 11; ++j ) {
    cout << "NA..." << endl;
}
    cout << "Batman!!!" << endl;

  return 0; // signals the operating system that our program ended OK.
}