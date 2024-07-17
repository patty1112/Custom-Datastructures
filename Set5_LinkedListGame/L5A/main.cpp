/* CSCI 261: Lab 5A - DoublyLinkedList Templated CLass
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
using namespace std;

int main() {
    cout << "Hi" << endl;
    DoublyLinkedList<int> newList;
    newList.insert(0, 6);
    newList.insert(0, 5);           //insert the given values in the new list
    newList.insert(5, 7);
    newList.insert(-3, 1);
    newList.insert(1, 2);
    newList.insert(2, 9);
    newList.insert(2, 3);
    cout << "Printing the list forwards:" << endl;      //Print the list forwards
    newList.print();
    cout << "Printing the list backwards:" << endl;     //Print the list backwards
    newList.printReverse();     
    newList.set(3, 4);                                  //Set the 3rd position to 4
    cout << "Printing the list forwards (After setting POS 3 to VAL 4.):" << endl;
    newList.print();                                    //Print the list forwards
    newList.remove(-2);                                 //Remove the three values
    newList.remove(6);
    newList.remove(2);
    cout << "Printing the element at POS 2 (After removing POS -2, 6, and 2): " << endl;
    cout << newList.get(2) << endl;                     //Print the element at position 2
    cout << "Printing the size of the list: " << endl;
    cout << newList.size() << endl;                     //Print the size
    cout << "Printing the list forwards: " << endl;
    newList.print();                                    //Print the list

    return 0;


    
}