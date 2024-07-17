#ifndef LINKEDLIST
#define LINKEDLIST
#include "Node.h"
#include <iostream>
using namespace std;
template <typename T>
class LinkedList{      
    public:
        Node<T>* pHead;                //Pointers to head and tail
        Node<T>* pTail;
        unsigned int listSize;      
        Node<T>* makeNodeForValue(const T&);     //Function, retuns node pointer to a new node
        void pushFront(const T&);
        void pushBack(const T&);
        T popFront();
        T front();
        T back();
        void printList();           //Prints the list forwards
        unsigned int size();
        T at(const int&);
        LinkedList();                   //Constructor
        ~LinkedList();                  //Destructor
        LinkedList(const LinkedList&);        //Copy Constructor
        LinkedList& operator=(const LinkedList&);

};


template <typename T>
LinkedList<T>::LinkedList() {      //Linked List constructor
    pHead = nullptr;            //Sets the head and tail to null  
    pTail = nullptr;    
    listSize = 0;              //Sets list size to 0
}

template <typename T>
LinkedList<T>::~LinkedList() {         //Linked List destructor
    Node<T>* temp = pHead;
    while(listSize != 0){           //While size is not 0   
        while(pHead){               //While pHead holds a value
            pHead = pHead->pNext;   //Advance pHead
            delete temp;            //Delete the previous node
            temp = pHead;           //Move temp to pHead
            listSize -= 1;          //update the size
        }
    }
    temp = nullptr;
    pHead = nullptr;                //Point the pointers to nullptr
    pTail = nullptr;

}

template <typename T>
Node<T>* LinkedList<T>::makeNodeForValue(const T& VALUE) {   //Makes a new node that holds the VALUE. Next node is set to nullptr
    Node<T>* newNode = new Node<T>;           //Makes a node pointer that points to a new node
    newNode->pNext = nullptr;           //The next node is nullptr
    newNode->value = VALUE;             //The node holds the VALUE
    return newNode;                     //Return the new node

}

template <typename T>
void LinkedList<T>::pushFront(const T& VALUE) {     //Adds a node to the front of the list and updates the tail, head and size
    Node<T>* temp = new Node<T>;              //Makes a temporary node pointer that points to a new node
    temp->pNext = pHead;                //Makes the next node the old head
    temp->value = VALUE;                //Sets the value of temp to VALUE
    if(pHead == nullptr) {
        pHead = temp;
        pTail = pHead;
    }
    pHead = temp;                       //Makes the head the temporary node which is at the front
    listSize += 1;                      //Increases the size
}       

template <typename T>
void LinkedList<T>::pushBack(const T& VALUE) {   //Adds a node to the back of a list
    if(listSize == 0) {
        Node<T>* temp = new Node<T>;              //Makes a temporary node pointer that points to a new node
        temp->pNext = pHead;                //Makes the next node the old head
        temp->value = VALUE;                //Sets the value of temp to VALUE
        if(pHead == nullptr) {
            pHead = temp;
            pTail = pHead;
        }
        pHead = temp;                       //Makes the head the temporary node which is at the front
        listSize += 1;                      //Increases the size
        } else {
            Node<T>* temp = new Node<T>;               //Makes a node pointer that points to a new node   
            temp->value = VALUE;                //Sets the value of temp to VALUE
            temp->pNext = nullptr;              //Makes the next node nullptr
            pTail->pNext = temp;                //Make the last node in the list temp
            pTail = temp;                       //Update the tail to be the added node
            listSize += 1;                      //Increase the list size
        }

}

template <typename T>
T LinkedList<T>::popFront() {                //Remove a node from the front
    Node<T>* temp = pHead;                 //Make node pointer that points to the head
     T deletedValue = T();              //Variable to hold the deleted value
    if(listSize == 0 || pHead == nullptr) { //If the list is empty
        return T();                //Return defult
    }
    deletedValue = temp->value;         //Else assign deletedValue temp's value
    pHead = pHead->pNext;               //Make the head the next node
    listSize -= 1;
    delete temp;                        //delete temp (The old head)
    return deletedValue;                //Return the value of the old head

}

template <typename T>
T LinkedList<T>::front() {               //Returns the value of the first node
    int headValue = -1;                     //Variable headValue is initialized to -1
    if(listSize == 0 || pHead == nullptr) {     //If the list is empty, return -1
        return T();                   
    }
    headValue = pHead->value;           //Else headValue is the value in pHead
    return headValue;                   //Return headValue
}

template <typename T>
T LinkedList<T>::back() {                //Returns the value of the last node
    int tailValue = -1;                 //Initialize tailValue variable as -1
    if(listSize == 0 || pHead == nullptr) { //If the list is empty, return -1
        return T();           
    }
    tailValue = pTail->value;           //Else the tailValue is the value in pTail
    return tailValue;                   //Return the tailValue
}

template <typename T>
unsigned int LinkedList<T>::size() {       //Returns the size of the linked list
    return listSize;                    //Return listSize
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList& originalList) {          //Copy Constructor
    listSize = originalList.listSize;                       //The new list's size is the old list's size
    Node<T>* currNewList = nullptr;                            //Make node pointers for current node in iteration
    Node<T>* currCopied = nullptr;
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

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& copiedList) {
    if(this == &copiedList) {                   //If the LHS = RHS 
        return *this;                           //Return the original (LHS)
    }
    Node<T>* curr = this->pHead;                   //Node pointer to deallocate the current list, set at the head
    while(curr) {                               //While there are elements
        curr = curr->pNext;                     //move the pointer to the next node
        delete pHead;                           //Delete the old head
        pHead = curr;                           //Assign head to the new front
    }


    this->pHead = new Node<T>;                         //Make a new node for the head of the list
    pHead->value = copiedList.pHead->value;         //Set the heads as the same value
    Node<T>* currCopied = copiedList.pHead;            //Make a node pointer that points to the copied lists head
    Node<T>* currNewList = this->pHead;                //Make another node pointer that points the head of the new list
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

template <typename T>
T LinkedList<T>::at(const int& position) {
    Node<T>* curr = pHead;                      //Pointer to track position
    for(int i = 0; i < position; i++) {         //Iterates position times
        if(curr->pNext == nullptr) {            //If position is out of range, 
            return T();                         //return defult type constructor
        }
        curr = curr->pNext;             //Else advance the curr pointer
    }
    return curr->value;             //When it is at position, return the value

}

template <typename T>
void LinkedList<T>::printList() {
    Node<T>* curr = pHead;                //make a node pointer that tracks position
    while(curr) {                   //While there is a value in curr
        cout << curr->value << endl;        //print the value
        curr = curr->pNext;            //Advance the node
    }
}

#endif