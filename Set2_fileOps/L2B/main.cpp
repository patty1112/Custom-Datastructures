/* CSCI 261 Lab 2B: Random Number Functions
 *
 * Author: Patrick Maes
 * RESOURCES: None
 * More complete description here...
 * Create random number funtions that output intgers and floats.
 */ 

// The include section adds extra definitions from the C++ standard library.
#include <iostream> // For cin, cout, etc.
#include <cstdlib>
#include <ctime>
// We will (most of the time) use the standard library namespace in our programs.
using namespace std;

// Define any constants below this comment.

// Must have a function named "main", which is the starting point of a C++ program.

void generate_random_integer(bool upperInclusive, bool lowerInclusive) {       //Use void to for no returns
    int upperLimit;                                                                     
    int lowerLimit;                                                             //Declare variables
    int randomInt;
    cout << "Enter the max limit of the random numbers: " << endl;
    cin >> upperLimit;                                                          //Prompt user for upper and lower limits of the random numbers
    cout << "Enter the minimum limit of the random numbers: " << endl;
    cin >> lowerLimit;



    if (upperInclusive == 0) {                                                 //If arguements are False (not inclusive), limits are shifted by one number
        upperLimit -= 1;                                                        //Ensures that chosen limits can not be generated
    } else if(upperInclusive == 1) {
                                                                                //If inclusive, leave the limits as is
    }
    
    if (lowerInclusive == 0) {
        lowerLimit += 1;                                                        //Same process for lower limit
    } else if (lowerInclusive == 1) {

    }

    srand(time(0));                                                         //Seed based on time and throw away first value
    rand();
    randomInt = rand() % (upperLimit - lowerLimit + 1) + lowerLimit;   //Uses the bounds and ensures number is between them
    
    cout << "Uppper Limit: " << endl;
    cout << upperLimit << endl;
    cout << "Lower Limit: " << endl;
    cout << lowerLimit << endl;
    cout << "Random Integer: " << endl;                        //Outputs the limits and random number. Limits will be shifited together by 1 if non-inclusive
    cout << randomInt << endl;
    
    }


void generate_random_float(bool upperInclusive, bool lowerInclusive) {
    int upperLimit;
    int lowerLimit;
    float randomFloat;                                                                  //Declare variables and prompt user
    cout << "Enter the max limit of the random numbers: " << endl;
    cin >> upperLimit;
    cout << "Enter the mminimum limit of the random numbers: " << endl;
    cin >> lowerLimit;


    srand(time(0));                                                                 //Seed with time and throw away first.
    rand();
    randomFloat = rand() / (double)RAND_MAX * (upperLimit - lowerLimit) + lowerLimit;       //Inclusive random float based on limits
    while(upperInclusive == 0 && randomFloat == upperLimit) {
        randomFloat = rand() / (double)RAND_MAX * (upperLimit - lowerLimit) + lowerLimit;
    }                                                                                        //If the float is the same as the limit, then regenerate.
    while(lowerInclusive == 0 && randomFloat == lowerLimit) {
        randomFloat = rand() / (double)RAND_MAX * (upperLimit - lowerLimit) + lowerLimit;
    }
    cout << randomFloat << endl;                                                                //print the float.
}


int main() {


cout << "RANDOM INTEGER GENERATOR: " << endl;
for(int i = 0; i < 10; i++) {                                        //upper and lower variables control the inclusivity.
    string include;                                                 //include are the answers given by the user.
    string include2;                                                // Loops 10 times
    bool upper = 1;
    bool lower = 1;
    cout << "Should the top limit be included? (Enter Y/N): " << endl;      //Prompt inclusion as a y/n question
    cin >> include;
    cout << "Should the bottom limit be included? (Enter Y/N): " << endl;
    cin >> include2;

    if(include == "N" || include == "n" || include == "no" || include == "NO") {
        upper = 0;
    }                                                                                   // if not. boolean arguements are false

    if(include2 == "N" || include2 == "n" || include2 == "no" || include2 == "NO") {
        lower = 0;
    }


    generate_random_integer(upper,lower);   
}

cout << "RANDOM FLOAT GENERATOR: " << endl;
for(int i = 0; i < 10; i++) {
    string include;
    string include2;                                                          //same declarations
    bool upper = 1;                                                         //Same as above, loops 10 times
    bool lower = 1;
    cout << "Should the top limit be included? (Enter Y/N): " << endl;
    cin >> include;
    cout << "Should the bottom limit be included? (Enter Y/N): " << endl;
    cin >> include2;

    if(include == "N" || include == "n" || include == "no" || include == "NO") {
        upper = false;
    }                                                                                      //not inclusive use false booleans.

    if(include2 == "N" || include2 == "n" || include2 == "no" || include2 == "NO") {
        lower = false;
    }

    generate_random_float(upper,lower);
}

  return 0; // signals the operating system that our program ended OK.
}