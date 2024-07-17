/* CSCI 261: Lab 5F Needle in a Haystack
 *
 * Author: Patrick Maes
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // list here any outside assistance you used/received while following the
 *     // CS@Mines Collaboration Policy and the Mines Academic Code of Honor
 *
 * XXXXXXXX (MORE_COMPLETE_DESCRIPTION_HERE)
 */
#include <iostream>
#include "DoublyLinkedList.hpp"
#include "DoublyNode.hpp"
#include <random>
#include <ctime>
using namespace std;

int main() {
    DoublyLinkedList<int> newList;      //Make a new list of integers
    srand(time(0));                     //Seed the random number generator
    rand();                             //Discard a value 
    cout << "Enter the number of integers to be placed in the list:" << endl;
    int userInput = 0;      //Make variable for user input
    cin >> userInput;       //Take user input
    int maximum = 100;      //Max and min limits for the random number generator
    int minimum = 1;
    for(int i = 0; i < userInput; i++) {        //For as many numbers as the user wants
        newList.insert(0, rand() % (maximum - minimum + 1) + minimum);      //Insert that many random integers
    }
    cout << "Printing the unsorted list." << endl;          //Print the list as it is
    newList.print();
    newList.listMergeSort(acending);                        //Merge sort the list acending
    cout << "Printing the sorted list in acending order:" << endl;  
    newList.print();                                        //Print the list
    cout << "Enter the number of values you would like to search the list for:" << endl;
    cin >> userInput;                                       //User enters number of values
    int desiredValue = 0;                                   //Make variable for the value they want
    for(int i = 0; i < userInput; i++) {                    //For as many iterations as the user wants
        cout << "Enter the integer value you would like to search for." << endl;            
        cout << "The position of the value will be returned, or -1 if not found." << endl;
        cin >> desiredValue;                            //User enters the desired value
        int start_pos = 0;
        int end_pos = newList.size() - 1;           //Variables for the start and end positions
        int middleVal = 0;              //Variable stores the middle value
        
        bool keepSearching = true;      //stores whether the value is found
        while(keepSearching) {          //While not found
            int mid_pos = end_pos - start_pos / 2 + start_pos;  //stores the middle position
            if(end_pos < start_pos) {       //If the end is less than the start
                keepSearching = false;      //Stop searching    
                cout << -1 << endl;             //Print a -1
            }
            middleVal = newList.get(mid_pos);       //Middle value is value of middle node
            if(middleVal == desiredValue) {         //If the value is the desired one,
                keepSearching = false;              //Stop searching
                cout << "Position: " << mid_pos << endl << endl;        //Print the position of the found value
            }
            if(middleVal > desiredValue) {      //If the desired value is less than the found one
                end_pos = mid_pos - 1;          //Search the left side of the list, move the right pointer
            }
            if(middleVal < desiredValue) {      //If the desired value is more than the found one
                start_pos = mid_pos + 1;        //Search the right side of the list, move the left pointer
            }
        }

    }
}