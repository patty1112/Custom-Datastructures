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

LinkedList::LinkedList() {      //Linked List constructor
    pHead = nullptr;            //Sets the head and tail to null  
    pTail = nullptr;    
    listSize = 0;              //Sets list size to 0
}

LinkedList::~LinkedList() {         //Linked List destructor
    Node* temp = pHead;
    while(listSize != 0){
        while(pHead){
            pHead = pHead->pNext; 
            delete temp;
            temp = pHead;
            listSize -= 1;
        }
    }
    temp = nullptr;
    pHead = nullptr;
    pTail = nullptr;

}

Node* LinkedList::makeNodeForValue(const int &VALUE) {   //Makes a new node that holds the VALUE. Next node is set to nullptr
    Node* newNode = new Node;           //Makes a node pointer that points to a new node
    newNode->pNext = nullptr;           //The next node is nullptr
    newNode->value = VALUE;             //The node holds the VALUE
    return newNode;                     //Return the new node

}

void LinkedList::pushFront(const int &VALUE) {     //Adds a node to the front of the list and updates the tail, head and size
    Node* temp = new Node;              //Makes a temporary node pointer that points to a new node
    temp->pNext = pHead;                //Makes the next node the old head
    temp->value = VALUE;                //Sets the value of temp to VALUE
    if(pHead == nullptr) {
        pHead = temp;
        pTail = pHead;
    }
    pHead = temp;                       //Makes the head the temporary node which is at the front
    listSize += 1;                      //Increases the size
}       

void LinkedList::pushBack(const int &VALUE) {   //Adds a node to the back of a list
    if(listSize == 0) {
        Node* temp = new Node;              //Makes a temporary node pointer that points to a new node
        temp->pNext = pHead;                //Makes the next node the old head
        temp->value = VALUE;                //Sets the value of temp to VALUE
        if(pHead == nullptr) {
            pHead = temp;
            pTail = pHead;
        }
        pHead = temp;                       //Makes the head the temporary node which is at the front
        listSize += 1;                      //Increases the size
        } else {
            Node* temp = new Node;               //Makes a node pointer that points to a new node   
            temp->value = VALUE;                //Sets the value of temp to VALUE
            temp->pNext = nullptr;              //Makes the next node nullptr
            pTail->pNext = temp;                //Make the last node in the list temp
            pTail = temp;                       //Update the tail to be the added node
            listSize += 1;                      //Increase the list size
        }
}

int LinkedList::popFront() {                //Remove a node from the front
    Node* temp = pHead;                 //Make node pointer that points to the head
    int deletedValue = -1;              //Variable to hold the deleted value
    if(listSize == 0 || pHead == nullptr) { //If the list is empty
        return deletedValue;                //Return -1
    }
    deletedValue = temp->value;         //Else assign deletedValue temp's value
    pHead = pHead->pNext;               //Make the head the next node
    delete temp;                        //delete temp (The old head)
    return deletedValue;                //Return the value of the old head

}

int LinkedList::front() {               //Returns the value of the first node
    int headValue = -1;                     //Variable headValue is initialized to -1
    if(listSize == 0 || pHead == nullptr) {     //If the list is empty, return -1
        return headValue;                   
    }
    headValue = pHead->value;           //Else headValue is the value in pHead
    return headValue;                   //Return headValue
}

int LinkedList::back() {                //Returns the value of the last node
    int tailValue = -1;                 //Initialize tailValue variable as -1
    if(listSize == 0 || pHead == nullptr) { //If the list is empty, return -1
        return tailValue;           
    }
    tailValue = pTail->value;           //Else the tailValue is the value in pTail
    return tailValue;                   //Return the tailValue
}

unsigned int LinkedList::size() {       //Returns the size of the linked list
    return listSize;                    //Return listSize
}

LinkedList::LinkedList(LinkedList& originalList) {          //Copy Constructor
    listSize = originalList.listSize;                       //The new list's size is the old list's size
    Node* currNewList = nullptr;                            //Make node pointers for current node in iteration
    Node* currCopied = nullptr;
    pHead = nullptr;                                        //Make pHead uninitialized
    currCopied = originalList.pHead;                        //The copied pointer goes to the copied list's head
    while(currCopied->pNext != nullptr) {                   //While there are more elements in the copied list
        if(pHead == nullptr) {                              //If pHead is uninitialized
            pHead = makeNodeForValue(originalList.pHead->value);       //Make a node for pHead that holds the original head's value
            currNewList = pHead;                            //Make the current in the new list the new Head
        }
        while(currNewList->pNext != nullptr) {              //Finds the last element in currNewList
            currNewList = currNewList->pNext;               //Advances both pointers to the same position
            currCopied = currCopied->pNext;
        }
        if(currCopied->pNext == nullptr){
            break;
        }
        currNewList->pNext = makeNodeForValue((currCopied->pNext)->value);    //Makes the next node the value of the next copied node
    }
    pTail = currNewList;        //The loop will end on the last node, make this node the tail
}

LinkedList& LinkedList::operator=(const LinkedList& copiedList) {
    if(this == &copiedList) {                   //If the LHS = RHS 
        return *this;                           //Return the original (LHS)
    }
    Node* curr = this->pHead;                   //Node pointer to deallocate the current list, set at the head
    while(curr) {                               //While there are elements
        curr = curr->pNext;                     //move the pointer to the next node
        delete pHead;                           //Delete the old head
        pHead = curr;                           //Assign head to the new front
    }


    this->pHead = new Node;                         //Make a new node for the head of the list
    pHead->value = copiedList.pHead->value;         //Set the heads as the same value
    Node* currCopied = copiedList.pHead;            //Make a node pointer that points to the copied lists head
    Node* currNewList = this->pHead;                //Make another node pointer that points the head of the new list
    while(currCopied->pNext != nullptr) {           //While there are more elements in the original list
        while(currNewList->pNext != nullptr) {      //Makes the newList pointer the last element
            currNewList = currNewList->pNext;       //The old lists pointer will only be as far as the new one
            currCopied = currCopied->pNext;
        }
        if((currCopied->pNext) == nullptr) {        //If the next element has no value
            break;                                  
        }
        currNewList->pNext = makeNodeForValue((currCopied->pNext)->value);  //Make a new node that has the same value as the original
    }
    this->pTail = currNewList;                  //Make the tail the last node
    this->listSize = copiedList.listSize;       //Copy the sizes
    return *this;                               //Return the new list
}   

int LinkedList::at(const int& position) {
    Node* curr = pHead;                         //Pointer to track position
    for(int i = 0; i < position; i++) {     //For position iterations,
        if(curr->pNext == nullptr) {         //If position is out of range
            return -1;                  //return -1
        }
        curr = curr->pNext;         //else advance the node pointer
    }
    return curr->value;             //return the value at the end of the loop

}

void LinkedList::printList() {
    Node* curr = pHead;                //make a node pointer that tracks position
    while(curr) {                   //While there is a value in curr
        cout << curr->value << endl;        //print the value
        curr = curr->pNext;            //Advance the node
    }
}