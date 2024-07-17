#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"

class LinkedList {
    private:
        Node* pHead;                //Pointers to head and tail, variable for size
        Node* pTail;
        unsigned int listSize;      
        Node* makeNodeForValue(const int&);     //Function that retuns node pointer to a new node
    public:
        void pushFront(const int&);     //Adds node to front
        void pushBack(const int&);      //Adds node to back
        int popFront();                 //Removes from the front
        int front();                //Gets value at front
        int back();                 //Gets value at back
        unsigned int size();        //Returns size
        void printList();           //Prints the list forwards
        int at(const int&);         //Gets the value at a certain position
        LinkedList();                   //Constructor
        ~LinkedList();                  //Destructor
        LinkedList(LinkedList&);        //Copy Constructor
        LinkedList& operator=(const LinkedList&);   //Overload the = operator for deep copy

};
#endif