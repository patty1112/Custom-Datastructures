/* CSCI 261: Lab 4E A Linked List Class
 *
 * Author: Patrick Maes
 * No Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     Video on linked list definition - https://www.youtube.com/watch?v=3gZ7F31Mwi0
 *
 * Create a program to prompt up to 15 numbers from the user and return the max and min.
 */
// The include section adds extra definitions from the C++ standard library.
#include <iostream>
#include "LinkedList.h"
#include "Node.h"


using namespace std;

int main() {
    
    LinkedList newList;             //Makes new LinkedList
    cout <<  "The size of the first list: " << endl << newList.size() << endl;          //Prints size
    newList.pushFront(1);           //Adds 1 to front
    newList.pushBack(2);            //Adds 2 to back
    newList.pushFront(3);           //Adds 3 to front...
    newList.pushBack(4);
    newList.pushFront(5);
    newList.pushBack(6);
    cout <<  "The size of the first list after elements added : " << endl << newList.size() << endl;    //Prints the size
    cout << "Contents of the first list: " << endl;
    newList.printList();
    LinkedList secondList;          //Make a second linked list noting in it
    cout << "The size of the second list: " << endl << secondList.size() << endl;       //Print the size
    secondList = newList;           //Set the second equal to the first (overload of =)
    cout <<  "The size of the second list after copying the first : " << endl << secondList.size() << endl; //Print the size of the second list
    newList.pushFront(7);       //Add two values to the first list
    newList.pushBack(8);        //They should not be added to second list
    cout << "For the FIRST LIST: " << endl;         
    cout <<  "The size of the first list after two more elements added : " << endl << newList.size() << endl;       //Print the size
    cout << "Contents of the first list: " << endl;     //Print all the elements in order
    newList.printList();                //Print the first list
    cout << "For the SECOND LIST: " << endl;        
    cout << "The size of the SECOND list: " << endl;
    cout << secondList.size() << endl;              //Print second list's size
    cout << "Contents of the second list: " << endl;
    secondList.printList();                         //Print contents of the second list
    LinkedList thirdList(newList);                  //Make a third list that copies the first
    cout << "Sizes of the lists in order: " << endl;    //Print the sizes in order
    cout << newList.size() << endl << secondList.size() << endl << thirdList.size() << endl;
    newList.pushFront(9);
    newList.pushBack(10);       //Add two elements to the first list
    cout << "Sizes of the lists in order: (After adding to the first list)" << endl;        //Print the sizes again
    cout << newList.size() << endl << secondList.size() << endl << thirdList.size() << endl;
    cout << "First List: " << endl; 
    newList.printList();                //Print all three lists
    cout << "Second List: " << endl;
    secondList.printList();
    cout << "Third List: " << endl;
    thirdList.printList();
    cout << endl;
        //Memory is deleted using written destructor in LinkedList.cpp 

}