/* CSCI 261: Lab 4C A Linked List class
 *
 * Author: Patrick Maes
 * No Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     Video on linked list definition - https://www.youtube.com/watch?v=3gZ7F31Mwi0
 *
 * Create a program to prompt up to 15 numbers from the user and return the max and min.
 */
// The include section adds extra definitions from the C++ standard library.
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"

class LinkedList {
    Node* pHead;        //Node pointer to the head
    Node* pTail;        //Node pointer to the tail
    unsigned int size;
    Node* makeNodeForValue(int);    //Makes node that holds integer value
    void pushFront(int);            //Adds integer value to the front of the list
    void pushBack(int);             //Adds integer value to the back of the list
    int popFront();                 //Removes integer value from the front of the list
};
#endif