#ifndef CIRCULARLYDOUBLYLINKEDLIST
#define CIRCULARLYDOUBLYLINKEDLIST
#include "DoublyNode.hpp"
#include "Player.h"
using namespace std;
template <typename T>
class CircularlyDoublyLinkedList {
    private:
    DoublyNode<T>* pHead;           //Pointers for Head and Tail
    DoublyNode<T>* pTail;
    unsigned int listSize;          //Number of players

    public:
    DoublyNode<T>* getHead() const;
    void assignPlayerNumbers();                 //Assigns player numbers
    CircularlyDoublyLinkedList();                             //Defult Constructor
    CircularlyDoublyLinkedList(const CircularlyDoublyLinkedList&);      //Copy Constructor
    ~CircularlyDoublyLinkedList();                            //Destructor
    CircularlyDoublyLinkedList<T>& operator=(const CircularlyDoublyLinkedList<T>&);       //Operator Overload =, deep copy
    T get(const int) const;                 //Gets position, 0 indexed
    void set(const int, const T);           //Sets the position 0 indexed
    void insert(const int, const T);        //Inserts node at position, 0 indexedd
    void remove(const int);                 //Removes node at position
    int size() const;                       //Returns size
    void print() const;                     //Prints the list
    void printReverse() const;
    float average();

    
};

template <typename T>
//Function to return the head of the list, Head is private so only used to assign Currnent Player at beginning. 
DoublyNode<T>* CircularlyDoublyLinkedList<T>::getHead() const {       
    return pHead;
}

template <typename T>
CircularlyDoublyLinkedList<T>::CircularlyDoublyLinkedList() {                           //Defult Constructor
    pHead = nullptr;                        //Sets pointers to NULL and size to 0.
    pTail = nullptr;
    listSize = 0;
    
}

template <typename T>                       //Copy Constructor, performs deep copy of given list
CircularlyDoublyLinkedList<T>::CircularlyDoublyLinkedList(const CircularlyDoublyLinkedList& OTHER) {
    if(OTHER.listSize == 0) {
        this->listSize = 0;
        this->pHead = nullptr;
        this->pTail = nullptr;
        return;
    }
    DoublyNode<T>* currNewList = nullptr;   //Makes two node pointers to track position in the linked list
    DoublyNode<T>* currOriginal = nullptr;
    pHead = nullptr;                        //Sets the head to nullptr
    listSize = 0;                           //Sets listSize to 0
    currOriginal = OTHER.pHead;             //Position in original list is the head
    DoublyNode<T>* newNode = new DoublyNode<T>; //Make a new node for the new head
    newNode->value = OTHER.pHead->value;        //Make the value in the node the head's value
    pHead = newNode;                        //This node is now the tail and head
    pTail = newNode;
    newNode->pNext = newNode;               //Since size is 1, the prev and next are the same node
    newNode->pPrev = newNode;
    currNewList = pHead;                    //This is also the current position in the newList
    listSize += 1;                          //Update list size
    while(currOriginal->pNext != pHead) {     //While there are more elements in the old list
        while(currNewList->pNext != pHead) {  //While there are more elements in the new list
            currNewList = currNewList->pNext;   //Pointers are updated together. Tracks last position in the new list
            currOriginal = currOriginal->pNext;
        }
        if(currOriginal->pNext == pHead) {     //If all nodes have been copied, break
            break;
        }
        newNode = new DoublyNode<T>;                    //Else make a new node
        newNode->value = currOriginal->pNext->value;    //Holds the value of the other list's node
        currNewList->pNext = newNode;                   //Make this the next node in the list
        newNode->pPrev = currNewList;                   //Make the previous node the last node in the new list
        newNode->pNext = pHead;                       //Make the next node pHead
        newNode = pTail;                                //The new node is now the last node in the list
        pHead->pPrev = pTail;
        listSize += 1;                                  //Update size
    }
}

template <typename T>
CircularlyDoublyLinkedList<T>& CircularlyDoublyLinkedList<T>::operator=(const CircularlyDoublyLinkedList<T>& OTHER) {
    if(this == OTHER) {             //Guard against self assignment
        return *this;               
    }
    if(OTHER.listSize == 0) {
        this->listSize = 0;
        this->pHead = nullptr;
        this->pTail = nullptr;
        return *this;
    }

    DoublyNode<T>* currPos = this->pHead;   //Make the currPos the head of LHS
    while(currPos) {                        //While there is a node
        currPos = currPos->pNext;           //Advance the currPos
        delete this->pHead;                 //Delete the old head
        this->pHead = currPos;              //Reassign the head
    }
    this->pTail = nullptr;              //Tail is nullptr
    this->listSize = 0;                 //Size is 0

    this->pHead = new DoublyNode<T>;            //The head is a new node
    this->pHead->value = OTHER->pHead->value;   //Set the values of the heads to be the same
    pHead->pNext = pHead;                     //Reassign the tail and pointers, list size is 1
    pHead->pPrev = pHead;                       //pHead is the only node
    pTail = pHead;
    DoublyNode<T>* currOriginal = OTHER.pHead;      //Make the currOriginal the head of OTHER
    DoublyNode<T>* currNewList = this->pHead;       //Make the currNewList the head of LHS
    this->listSize += 1;                        //Update size

    while(currOriginal->pNext != pHead) {         //While there are elements in the original
        while(currNewList->pNext != pHead) {      //While there are elements in the new list
            currNewList = currNewList->pNext;       //Update the pointers together, they will always land on the latest element in newlist
            currOriginal = currOriginal->pNext;
        }
        if(currOriginal->pNext == pHead) {        //If the next node has no value
            break;                                  //Break
        }
        DoublyNode<T> newNode = new DoublyNode<T>;                    //Else make a new node
        newNode->value = currOriginal->pNext->value;    //Holds the value of the other list's node
        currNewList->pNext = newNode;                   //Make this the next node in the list
        newNode->pPrev = currNewList;                   //Make the previous node the last node in the new list
        newNode->pNext = pHead;                       //Make the next node pHead
        newNode = pTail;                                //The new node is now the last node in the list
        pHead->pPrev = pTail;
        listSize += 1;                                  //Update size
    }
    return *this;
}

template <typename T>
CircularlyDoublyLinkedList<T>::~CircularlyDoublyLinkedList() {      //Deconstructor
    DoublyNode<T>* currPos = pHead;             //Node pointer that tracks position that starts at the head
    if(listSize == 0) {                         //If the size is 0
        return;                                 //Do noting.
    }
    currPos = currPos->pNext;
    while(listSize != 0) {      //If size is not 0
        delete pHead;           //Delete the head
        pHead = currPos;            //set pHead to the new head
        currPos = currPos->pNext;       //Advance currPos
        listSize -= 1;
    }
    pHead = nullptr;            //When finished, reassign pointers
    currPos = nullptr;
    pTail = nullptr;
}

template <typename T>
T CircularlyDoublyLinkedList<T>::get(const int POS) const {       //Gets the value at the position POS
    if(listSize == 0) {
        return T();
    }
    if(POS == 0){               //If position is 0, return the head values
        return pHead->value;
    }
    DoublyNode<T>* curr = pHead;            //Node pointer tracks the position in the list
    T nodeValue = T();                      //Make a defult variable to hold the value
    for(int i = 0; i < POS; i++) {          //i represents current node, will land on POS
        curr = curr->pNext;                 //Moves curr to the next node.
        if(curr == pHead) {           //If the POS is out of range,
            return T();                 //Return the defult
        }
    }
    nodeValue = curr->value;        //Else, take the value of the i'th node
    return nodeValue;               //return that value
}


template <typename T>
void CircularlyDoublyLinkedList<T>::set(const int POS, const T VAL) { //Sets the value of POS to VAL
    DoublyNode<T>* curr = pHead;     //Node pointer to track position in list
    if(POS == 0) {
        pHead->value = VAL;
        return;
    }
    if(POS < 0) {
        return;
    }

    for(int i = 0; i < POS; i++) {      //Iterates through until POS
        curr = curr->pNext;             //Advances curr each time
        if(curr == pHead) {           //If the POS is out of range
            return;                 //Do nothing
        }
    }
    curr->value = VAL;          //Else make the value the VAL
    return;                     //return
}

template <typename T>
void CircularlyDoublyLinkedList<T>::insert(const int POS, const T VAL) {
    DoublyNode<T>* newNode = new DoublyNode<T>;     //Makes a new node
    newNode->value = VAL;                           //node holds VAL
    DoublyNode<T>* currPos = pHead;      //Tracks the position in the linked list.
    int position = POS;                 //Make copy of POS
    if(POS < 0) {                       //if POS is negative
        position = 0;                   //position is the first node
    }
    if(listSize == 0) {             //If list size is 0
        pHead = newNode;            //The newNode is the head and tail
        pTail = newNode;    
        pHead->pPrev = pHead;         //Makes the pointers point to NULL (its the only node in the list)
        pTail->pNext = pHead;
        pHead->pNext = pHead;
        pTail->pPrev = pHead;
        listSize += 1;                  //Updates size
        return;
    }
    if(position >= listSize) {      //If position if out of range, insert at the end.
        while(currPos->pNext != pHead) {  //currPos will iterate to end of list
            currPos = currPos->pNext;       //advances currPos
        }
        newNode->pNext = pHead;       //Makes the next node nullptr
        newNode->pPrev = currPos;       //Makes the previous node the last node in the list
        currPos->pNext = newNode;       //Connects last node to the new tail
        pTail = newNode;                //updates the tail
        pHead->pPrev = newNode;
    } else if(position == 0) {          //Else if the position is the first node
        newNode->pPrev = pTail;       //Make the previous node nullptr
        currPos->pPrev = newNode;       //Make the head's previous the new node
        newNode->pNext = currPos;       //Make the new node's next point to the head
        pHead = newNode;                //update the head
        pTail->pNext = pHead;
    } else {                            //If position is in the middle of the list
        for(int i = 0; i < position; i++) {     //iterate and land on the position
            currPos = currPos->pNext;           //advancing currPos each time
        }
        currPos->pPrev->pNext = newNode;        //Inserts before POS, so assigns the previous node's next to newNode
        newNode->pPrev = currPos->pPrev;        //Makes the previous of the new node the one before currPos
        currPos->pPrev = newNode;               //Makes the previous of currPos the newNode
        newNode->pNext = currPos;               //The newNode points to currPos
    }
    listSize += 1;                              //Update listSize

}

template <typename T>
int CircularlyDoublyLinkedList<T>::size() const {     //Returns the size of the list
    return listSize;                        //return size
}

template <typename T>
void CircularlyDoublyLinkedList<T>::print() const {   //Prints the list forwards
    DoublyNode<T>* currPos = pHead;         //New pointer to track position
    currPos = currPos->pNext;
    cout << pHead->value << endl;
    while(currPos != pHead) {                        //While there are more nodes
        cout << currPos->value << endl;     //print the value in the node   
        currPos = currPos->pNext;           //Advance the node
    }
}

template <>
void CircularlyDoublyLinkedList<Player>::assignPlayerNumbers() {    //Assigns the player numbers in a list of players
    if(listSize == 0 ) {
        return;             //If size = 0, there are no players
    }
    pHead->value.setPlayerNumber(1);            //Else make the head player 1
    DoublyNode<Player>* curr = pHead;
    curr = curr->pNext;                     //Make the curr point to the second node
    int currNumber = 2;                     //Counter to track the number of players
    while(curr != pHead) {                  //While the player has no number
        curr->value.setPlayerNumber(currNumber);        //Set the player number
        currNumber += 1;                                //Increase number of players
        curr = curr->pNext;                             //Move to the next node
    }

}

template <typename T> 
float CircularlyDoublyLinkedList<T>::average() {
    DoublyNode<T>* curr = pHead;
    T total = T();
    total += curr->value;
    curr = curr->pNext;
    while(curr != pHead) {
        total += curr->value;
        curr = curr->pNext;
    }
    float average = float(total) / listSize;
    return average;
}
#endif