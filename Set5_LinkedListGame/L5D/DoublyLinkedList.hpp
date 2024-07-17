#ifndef DOUBLYLINKEDLIST
#define DOUBLYLINKEDLIST
#include "DoublyNode.hpp"

using namespace std;
template <typename T>
class DoublyLinkedList {
    private:
    DoublyNode<T>* pHead;
    DoublyNode<T>* pTail;
    unsigned int listSize;

    public:
    DoublyLinkedList();                             //Constructor
    DoublyLinkedList(const DoublyLinkedList&);      //Copy constructor
    ~DoublyLinkedList();                            //Destructor
    DoublyLinkedList& operator=(const DoublyLinkedList&);       //Operator overload =, deep copy
    T get(const int) const;                                         //Gets value at position, 0 indexed
    void set(const int, const T);           //Sets the position to the value, 0 indexed
    void insert(const int, const T);        //Inserts a node with a certain value at a position
    void remove(const int);                 //removes a node at poition
    int size() const;                       //Returns size
    void print() const;                     //Prints the list
    void printReverse() const;              //Prints the list backwards
    void bubbleSort();                      //Bubble sorts the list
    void listMergeSort();                   //Merge sorts the list
    void assignTail();                      //Assigns the tail if not pointing to the end
};

// ------------------------ IMPLEMENTATIONS ------------------------------------------

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() {           //Defult Constructor
    pHead = nullptr;                                //Sets pointers to NULL and size to 0.
    pTail = nullptr;
    listSize = 0;
}

template <typename T>                       //Copy Constructor, performs deep copy of given list
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList& OTHER) {
    DoublyNode<T>* currNewList = nullptr;   //Makes two node pointers to track position in the linked list
    DoublyNode<T>* currOriginal = nullptr;
    pHead = nullptr;                        //Sets the head to nullptr
    listSize = 0;                           //Sets listSize to 0
    currOriginal = OTHER.pHead;             //Position in original list is the head
    DoublyNode<T>* newNode = new DoublyNode<T>; //Make a new node for the new head
    newNode->value = OTHER.pHead->value;        //Make the value in the node the head's value
    pHead = newNode;                        //This node is now the tail and head
    pTail = newNode;
    newNode->pNext = nullptr;               //The next and previous node are NULL
    newNode->pPrev = nullptr;
    currNewList = pHead;                    //This is also the current position in the newList
    listSize += 1;                          //Update list size
    while(currOriginal->pNext != nullptr) {     //While there are more elements in the old list
        while(currNewList->pNext != nullptr) {  //While there are more elements in the new list
            currNewList = currNewList->pNext;   //Pointers are updated together. Tracks last position in the new list
            currOriginal = currOriginal->pNext;
        }
        if(currOriginal->pNext == nullptr) {     //If all nodes have been copied, break
            break;
        }
        newNode = new DoublyNode<T>;                    //Else make a new node
        newNode->value = currOriginal->pNext->value;    //Holds the value of the other list's node
        currNewList->pNext = newNode;                   //Make this the next node in the list
        newNode->pPrev = currNewList;                   //Make the previous node the last node in the new list
        newNode->pNext = nullptr;                       //Make the next node nullptr
        newNode = pTail;                                //The new node is now the last node in the list
        listSize += 1;                                  //Update size
    }
}

template <typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& OTHER) {
    if(this == OTHER) {             //Guard against self assignment
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
    pHead->pNext = nullptr;                     //Reassign the tail and pointers
    pHead->pPrev = nullptr;
    pTail = pHead;
    DoublyNode<T>* currOriginal = OTHER.pHead;      //Make the currOriginal the head of OTHER
    DoublyNode<T>* currNewList = this->pHead;       //Make the currNewList the head of LHS
    this->listSize += 1;                        //Update size

    while(currOriginal->pNext != nullptr) {         //While there are elements in the original
        while(currNewList->pNext != nullptr) {      //While there are elements in the new list
            currNewList = currNewList->pNext;       //Update the pointers together, they will always land on the latest element in newlist
            currOriginal = currOriginal->pNext;
        }
        if(currOriginal->pNext == nullptr) {        //If the next node has no value
            break;                                  //Break
        }
        DoublyNode<T> newNode = new DoublyNode<T>;                    //Else make a new node
        newNode->value = currOriginal->pNext->value;    //Holds the value of the other list's node
        currNewList->pNext = newNode;                   //Make this the next node in the list
        newNode->pPrev = currNewList;                   //Make the previous node the last node in the new list
        newNode->pNext = nullptr;                       //Make the next node nullptr
        newNode = pTail;                                //The new node is now the last node in the list
        listSize += 1;                                  //Update size
    }
    return *this;
}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {      //Deconstructor
    DoublyNode<T>* currPos = pHead;             //Node pointer that tracks position that starts at the head
    if(listSize == 0) {                         //If the size is 0
        return;                                 //Do noting.
    }
    while(listSize != 0) {                      //While the size is not 0
        while(pHead) {                          //While there are more nodes
            pHead = pHead->pNext;               //Move pHead to the next node
            delete currPos;                     //Delete the node 
            currPos = pHead;                    //Reassign the pointer to pHead
            listSize -= 1;                      //Update size
        }   
    }
    currPos = nullptr;          //Make all pointers nullptr
    pHead = nullptr;
    pTail = nullptr;

}


template <typename T>
T DoublyLinkedList<T>::get(const int POS) const {       //Gets the value at the position POS
    if(listSize == 0) {
        return T();
    }
    DoublyNode<T>* curr = pHead;            //Node pointer tracks the position in the list
    T nodeValue = T();                      //Make a defult variable to hold the value
    for(int i = 0; i < POS; i++) {          //i represents current node, will land on POS
        curr = curr->pNext;                 //Moves curr to the next node.
        if(curr == nullptr) {           //If the POS is out of range,
            return T();                 //Return the defult
        }
    }
    nodeValue = curr->value;        //Else, take the value of the i'th node
    return nodeValue;               //return that value
}

template <typename T>
void DoublyLinkedList<T>::set(const int POS, const T VAL) { //Sets the value of POS to VAL
    DoublyNode<T>* curr = pHead;     //Node pointer to track position in list
    for(int i = 0; i < POS; i++) {      //Iterates through until POS
        curr = curr->pNext;             //Advances curr each time
        if(curr == nullptr) {           //If the POS is out of range
            return;                 //Do nothing
        }
    }
    curr->value = VAL;          //Else make the value the VAL
    return;                     //return
}

template <typename T>
void DoublyLinkedList<T>::insert(const int POS, const T VAL) {
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
        pHead->pPrev = nullptr;         //Makes the pointers point to NULL (its the only node in the list)
        pTail->pNext = nullptr;
        pHead->pNext = nullptr;
        pTail->pPrev = nullptr;
        listSize += 1;                  //Updates size
        return;
    }
    if(position >= listSize) {      //If position if out of range, insert at the end.
        while(currPos->pNext != nullptr) {  //currPos will iterate to end of list
            currPos = currPos->pNext;       //advances currPos
        }
        newNode->pNext = nullptr;       //Makes the next node nullptr
        newNode->pPrev = currPos;       //Makes the previous node the last node in the list
        currPos->pNext = newNode;       //Connects last node to the new tail
        pTail = newNode;                //updates the tail
    } else if(position == 0) {          //Else if the position is the first node
        newNode->pPrev = nullptr;       //Make the previous node nullptr
        currPos->pPrev = newNode;       //Make the head's previous the new node
        newNode->pNext = currPos;       //Make the new node's next point to the head
        pHead = newNode;                //update the head
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
int DoublyLinkedList<T>::size() const {     //Returns the size of the list
    return listSize;                        //return size
}

template <typename T>
void DoublyLinkedList<T>::print() const {   //Prints the list forwards
    DoublyNode<T>* currPos = pHead;         //New pointer to track position
    while(currPos) {                        //While there are more nodes
        cout << currPos->value << endl;     //print the value in the node   
        currPos = currPos->pNext;           //Advance the node
    }
}

template <typename T>
void DoublyLinkedList<T>::printReverse() const {        //Prints the list in reverse
    DoublyNode<T>* currPos = pTail;                     //Makes currPos the tail
    while(currPos) {                                //While there are more nodes
        cout << currPos->value << endl;             //Print the value in the node
        currPos = currPos->pPrev;                   //Move back through the list.
    }
}

template <typename T>
void DoublyLinkedList<T>::remove(const int POS) {
    DoublyNode<T>* currPos = pHead;
    if(listSize == 0) {
        return;
    }
    if(listSize == 1) {         //If list size is 1,
        delete currPos;         //delete node and reassign all pointers
        pHead = nullptr;
        pTail = nullptr;
        currPos = nullptr;
        listSize -= 1;
        return;
    }
    if(POS < 0) {              //If position < 0, remove the head.
        pHead = pHead->pNext;   //Advance the head pointer
        delete currPos;         //Delete the old head
        currPos = nullptr;      //Make the currPos pointer nullptr
        pHead->pPrev = nullptr;     //Make the previous node of the head nullptr
        listSize -= 1;              //update listsize
        return;
    }
    if(POS > listSize - 1) {       //If position > listSize - 1, remove the tail.
        currPos = pTail;            //Make currPos the tail
        pTail = pTail->pPrev;       //move tail back through list
        delete currPos;             //Delete old tail
        currPos = nullptr;          //Make the currPos nullptr
        pTail->pNext = nullptr;     //Make the node after the tail nullptr
        listSize -= 1;              //Update the size
        return;
    }
    for(int i = 0; i < POS; i++) {     //Else, remove the position
        currPos = currPos->pNext;       //Advance until the position
    }
    currPos->pPrev->pNext = currPos->pNext;     //Make the node before's next the next node
    currPos->pNext->pPrev = currPos->pPrev;     //Make the next node's prev the prev node
    delete currPos;                             //delete the current node
    currPos = nullptr;                          //Set it to nullptr
    listSize -= 1;                              //Update size
}
template <typename T>
void DoublyLinkedList<T>::bubbleSort() {        
    DoublyNode<T>* currPos;                     //Makes node pointer curr
    for(int i = 0; i < listSize; i++) {         //For each element in the list
        currPos = pHead;                        //Make the curr pointer point to the head
        bool swap = false;                      //Tracks if elements have been switched
        for(int j =  1; j < listSize - i; j++) {        //For each element, last i elements are sorted already
            if(currPos->value > currPos->pNext->value) {        //If the current element is greater than the next,
                int currMax = currPos->value;                //Store the value of the 
                currPos->value = currPos->pNext->value;     //Make the curr value the next nodes value
                currPos->pNext->value = currMax;            //Make the next node hold the current maximum
                swap = true;                                //Note a node has been swaped
            }
            currPos = currPos->pNext;               //Advance curr
        }
        if(swap == false) {         //If no nodes were swaped
            this->assignTail();     //make the last node the tail
            return;                 //return
        }
    }
}

template <typename T>
void DoublyLinkedList<T>::assignTail() {        //Makes the last node in the list the tail
    if(listSize == 0 || pHead == nullptr) {     //If size is 0 or the head is uninitialized,
        return;                                 //return
    }
    DoublyNode<T>* curr = pHead;                //Make a node pointer curr that points to the head
    while(curr->pNext != nullptr) {             //While the next node exists
        curr = curr->pNext;             //Move to the next node 
    }
    pTail = curr;                       //Make this the tail when finished
}


template <typename T>                           //NOTE: Most of the merge sort is with DoublyNode merge sort, this way I dont need to create new linked lists.
void DoublyLinkedList<T>::listMergeSort() {         //Merge sort a linked list, only called once per sort
    if(this->listSize <= 1) {                   //If the size is 1 or less, do nothing

    } else {
        DoublyNode<T>* RHS = nullptr;           //Make node pointers for the head of the left and right lists
        DoublyNode<T>* LHS = nullptr;
        splitLinkedList(this->pHead, LHS, RHS);     //Splits the linked list, takes 3 node pointer arguements
        mergeSort(LHS);                             //Merge sort the lists, takes node pointer arguements, returns the head of the sorted list. (defined in DoublyNode.hpp)
        mergeSort(RHS);                             

        this->pHead = merge(LHS, RHS);              //The head of the list is the head of the merged lists
        this->assignTail();                         //Assign the tail
    }
}

#endif