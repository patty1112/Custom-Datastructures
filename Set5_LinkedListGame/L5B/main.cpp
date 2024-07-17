/* CSCI 261: Lab 5B Linked ListBubble Sort
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

using namespace std;

int main() {
    DoublyLinkedList<int> newList;
    newList.insert(10, 4);              //Insert the given values in the list
    newList.insert(11, 3);
    newList.insert(12, 8);
    newList.insert(13, 1);
    newList.insert(14, 5);
    newList.insert(15, 9);
    newList.insert(16, 7);
    newList.insert(17, 2);
    newList.insert(18, 6);
    cout << "Printing the unsorted list:" << endl;
    newList.print();                    //Print the unsorted list
    newList.bubbleSort();           
    cout << "Printing sorted list: " << endl;       //Sort and print the sorted list
    newList.print();


    return 0;
}