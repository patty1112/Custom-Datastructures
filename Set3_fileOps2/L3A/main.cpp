/* CSCI 261: Lab 3A Array Min-Max
 *
 * Author: Patrick Maes
 * No Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     
 *
 * Create a program to prompt up to 15 numbers from the user and return the max and min.
 */
// The include section adds extra definitions from the C++ standard library.
#include <iostream> // For cin, cout, etc.

// We will (most of the time) use the standard library namespace in our programs.
using namespace std;

// Define any constants below this comment.

// Must have a function named "main", which is the starting point of a C++ program.
int main() {
int length = 15;    //Declare variable for array length.
int numbers[length];  //Make a new array called numbers
cout << "Enter up to 15 non-zero numbers.  Enter zero to signal the end of data or enter all 15 items:" << endl;

for(int i = 1; i <= length; i++) {    //For each element in numbers
    int userNumber = 1;               //variable for user input
    cout << "Number " << i << ": ";   
    cin >> userNumber;                //cin to the userInput variable
    numbers[i - 1] = userNumber;      //make the index of numbers userInput
    if(userNumber == 0){      //If they enter 0 then break
      break;
    }
}

cout << "The numbers are: ";
for(int i = 0; i < length; i++) {   //For each element in numbers
  if(numbers[i] == 0){    //If number is 0 then stop
    break;
  } else {              
      cout << numbers[i] << " ";    //Else write the number
  }
}
cout << endl;

int maximum = numbers[0];     //Initial values for min and max
int minimum = numbers[0];
for(int i = 0; i < length; i++) {   //For each number in numbers
  if(numbers[i] == 0){  
    break;
  }
  if(numbers[i] > maximum) {    //If the number is greater than the maximum
    maximum = numbers[i];       //Update the maximum
  }
  if(numbers[i] < minimum) {    //If the number is less than the minimum
    minimum = numbers[i];       //update the minimum
  }
}


cout << "The maximum value is: " << maximum << endl;    //Output the max, min and closing statement.
cout << "The minimum value is: " << minimum << endl;
cout << "Have a nice day!" << endl;


  return 0; // signals the operating system that our program ended OK.
}