/* CSCI 261: Lab 4D A Linked List Class
 *
 * Author: Patrick Maes
 * No Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     Video on linked list definition - https://www.youtube.com/watch?v=3gZ7F31Mwi0
 *
 * Create a program to prompt up to 15 numbers from the user and return the max and min.
 */
// The include section adds extra definitions from the C++ standard library.
#include "LinkedList.h"
#include "Node.h"

LinkedList::LinkedList() {      //Linked List constructor
    pHead = nullptr;            //Sets the head and tail to null  
    pTail = nullptr;    
    listSize = 0;              //Sets list size to 0
}

LinkedList::~LinkedList() {         //Linked List destructor
    while(listSize != 0){               //While the size is not 0
        Node* temp = pTail;         //Make a temporary node and point it to the same place as the tail
        pTail = pHead;              //Make the tail point to the head
        while(pTail->pNext != temp) {   //While the tail's next node is not the temporary one,
            pTail->pNext;               //Advance the tail
        }
        delete temp;                    //Delete the temporary node's contents
        listSize -= 1;                  //decrease the size
    }
    pHead = nullptr;
    pTail = nullptr;

}

Node* LinkedList::makeNodeForValue(const int VALUE) {   //Makes a new node that holds the VALUE. Next node is set to nullptr
    Node* newNode = new Node;           //Makes a node pointer that points to a new node
    newNode->pNext = nullptr;           //The next node is nullptr
    newNode->value = VALUE;             //The node holds the VALUE
    return newNode;                     //Return the new node

}

void LinkedList::pushFront(const int VALUE) {     //Adds a node to the front of the list and updates the tail, head and size
    Node* temp = new Node;              //Makes a temporary node pointer that points to a new node
    temp->pNext = pHead;                //Makes the next node the old head
    temp->value = VALUE;                //Sets the value of temp to VALUE
    pHead = temp;                       //Makes the head the temporary node which is at the front
    listSize += 1;                      //Increases the size
}       

void LinkedList::pushBack(const int VALUE) {   //Adds a node to the back of a list
    Node* temp = new Node;               //Makes a node pointer that points to a new node   
    temp->value = VALUE;                //Sets the value of temp to VALUE
    temp->pNext = nullptr;              //Makes the next node nullptr
    pTail->pNext = temp;                //Make the last node in the list temp
    pTail = temp;                       //Update the tail to be the added node
    listSize += 1;                      //Increase the list size

}

int LinkedList::popFront() {                //Remove a node from the front
    Node* temp = pHead;                 //Make node pointer that points to the head
    int deletedValue = -1;              //Variable to hold the deleted value
    if(size == 0 || pHead == nullptr) { //If the list is empty
        return deletedValue;                //Return -1
    }
    deletedValue = temp->value;         //Else assign deletedValue temp's value
    pHead = pHead->pNext;               //Make the head the next node
    delete temp;                        //delete temp (The old head)
    return deletedValue;                //Return the value of the old head

}

int LinkedList::front() {               //Returns the value of the first node
    int headValue = -1;                     //Variable headValue is initialized to -1
    if(size == 0 || pHead == nullptr) {     //If the list is empty, return -1
        return headValue;                   
    }
    headValue = pHead->value;           //Else headValue is the value in pHead
    return headValue;                   //Return headValue
}

int LinkedList::back() {                //Returns the value of the last node
    int tailValue = -1;                 //Initialize tailValue variable as -1
    if(size == 0 || pHead == nullptr) { //If the list is empty, return -1
        return tailValue;           
    }
    tailValue = pTail->value;           //Else the tailValue is the value in pTail
    return tailValue;                   //Return the tailValue
}

unsigned int LinkedList::size() {       //Returns the size of the linked list
    return listSize;                    //Return listSize
}

