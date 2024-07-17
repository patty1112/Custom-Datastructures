/* CSCI 261: Lab 4F A Linked List Class
 *
 * Author: Patrick Maes
 * No Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     Video on linked list definition - https://www.youtube.com/watch?v=3gZ7F31Mwi0
 *
 * Create a program to prompt up to 15 numbers from the user and return the max and min.
 */
// The include section adds extra definitions from the C++ standard library.
#include <iostream>
#include "LinkedList.hpp"
#include "Node.hpp"


using namespace std;

int main() {
    
    LinkedList<int> newList;            //Make new list
    cout <<  "The size of the first list: " << endl << newList.size() << endl;  //Print the list's size
    newList.pushFront(1);           //Add values to list
    newList.pushBack(2);
    newList.pushFront(3);
    newList.pushBack(4);
    newList.pushFront(5);
    newList.pushBack(6);
    cout <<  "The size of the first list after elements added : " << endl << newList.size() << endl;        //Print size
    LinkedList<int> secondList;     //Make second list
    cout << "The size of the second list: " << endl << secondList.size() << endl;       //Print size
    secondList = newList;       //operator overload, deep copy first list
    cout <<  "The size of the second list after copying the first : " << endl << secondList.size() << endl;     //print size
    newList.pushFront(7);       //Add two elements to first list
    newList.pushBack(8);
    cout << "For the FIRST LIST: " << endl;         //Print size and contents of first list
    cout <<  "The size of the first list after two more elements added : " << endl << newList.size() << endl;
    cout << "Contents of the first list: " << endl;
    newList.printList();    
    cout << "For the SECOND LIST: " << endl;            //Print size and contents of the second list
    cout << "The size of the SECOND list: " << endl;
    cout << secondList.size() << endl;
    cout << "Contents of the second list: " << endl;
    secondList.printList();
    LinkedList<int> thirdList(newList);         //Make third list, copys the first list
    cout << "Sizes of the lists in order: " << endl;        //Print the list sizes
    cout << newList.size() << endl << secondList.size() << endl << thirdList.size() << endl;        
    newList.pushFront(9);       //Add two values to first list
    newList.pushBack(10);
    cout << "Sizes of the lists in order: (After adding to the first list)" << endl;        //Print list sizes
    cout << newList.size() << endl << secondList.size() << endl << thirdList.size() << endl;
    cout << "First List: " << endl;         //Print contents of all lists
    newList.printList();
    cout << "Second List: " << endl;
    secondList.printList();
    cout << "Third List: " << endl;
    thirdList.printList();
    LinkedList<string> stringList;      //Make a list of strings
    stringList.pushFront("is");     //Add some strings
    stringList.pushBack("working");
    stringList.pushFront("This");
    stringList.pushBack("now");

    stringList.printList();         //Print using templated function, or method that adds spaces. Could also build a function for stiring linked lists.
    cout << stringList.at(0) << " " << stringList.at(1) << " " << stringList.at(2) << " " << stringList.at(3) << endl;

    return 0;

        //Memory is deleted using defult destructors written in LinkedList.hpp


}