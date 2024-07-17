/* CSCI 261: Lab 4D A Linked List Class
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
    private:
        Node* pHead;                //Variables to track head, tail and size
        Node* pTail;
        unsigned int listSize;              
        Node* makeNodeForValue(const int);      //Makes node of certain value
    public:
        void pushFront(const int);      //Adds node to front
        void pushBack(const int);       //Adds node to the back
        int popFront();                 //Removes from the front
        int front();            //Returns value at front
        int back();             //Returns value at back
        unsigned int size();    //Returns size (pvt member)
        LinkedList();           //Constructor
        ~LinkedList();          //Destructor
};
#endif