/* CSCI 261: L5E Bubble Sort Rectangle Objectes
 *
 * Author: Patrick  Maes
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // list here any outside assistance you used/received while following the
 *     // CS@Mines Collaboration Policy and the Mines Academic Code of Honor
 *
 * XXXXXXXX (MORE_COMPLETE_DESCRIPTION_HERE)
 */
#include <iostream>
#include "DoublyLinkedList.hpp"
#include "Rectangle.hpp"
#include <random>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));                 //Seed the random number generator with time, a number will be discarded before used
    cout << "How many rectangles do you want in the list?" << endl;     //Ask for the number of rectangles
    DoublyLinkedList<Rectangle> rectangleList;          //Make a list of rectangles
    int userInput = 0;              //variable for user input
    cin >> userInput;               //Take user input
    for(int i = 0; i < userInput; i++) {        //For as many rectangles as the user wants
        Rectangle newRectangle;             //Create a rectangle
        newRectangle.randomSides();             //randomize the sides
        rectangleList.insert(0, newRectangle);      //Put it into the list
    }
    cout << "Printing the unsorted list:" << endl;          //Print the list unsorted
    for(int i = 0; i < rectangleList.size(); i++) {         
        cout << rectangleList.get(i).getLength() << "X" << rectangleList.get(i).getHeight() << endl;
    }
    rectangleList.bubbleSort(acending);                     //Bubble sort the list, acending order
    cout << "Printing the sorted list (acending):" << endl;     //Print the list
    for(int i = 0; i < rectangleList.size(); i++) {
        cout << rectangleList.get(i).getLength() << "X" << rectangleList.get(i).getHeight() << endl;
    }
    rectangleList.bubbleSort(decending);                    //Bubble sort the list, decending order
    cout << "Printing the sorted list (decending):" << endl;        //Print the list
    for(int i = 0; i < rectangleList.size(); i++) {
        cout << rectangleList.get(i).getLength() << "X" << rectangleList.get(i).getHeight() << endl;
    }

    return 0;
}