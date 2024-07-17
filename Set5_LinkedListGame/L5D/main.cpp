/* CSCI 261: Lab 5D Merge Sort
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
    DoublyLinkedList<int> newList;
    newList.insert(0, 4);
    newList.insert(1, 3);           //Insert the given values
    newList.insert(2, 8);
    newList.insert(3, 1);
    newList.insert(4, 5);
    newList.insert(5, 9);
    newList.insert(6, 7);
    newList.insert(7, 2);
    newList.insert(8, 6);
    cout << "Printing the unsorted list: " << endl;
    newList.print();
    cout << "Sorting the linked list: " << endl;     //Merge sort the list
    newList.listMergeSort();
    newList.print();                //Print the values
    return 0;
}