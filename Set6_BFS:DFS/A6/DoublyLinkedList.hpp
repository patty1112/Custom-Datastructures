#ifndef DOUBLYLINKEDLIST
#define DOUBLYLINKEDLIST
#include "DoublyNode.hpp"
#include "Position.hpp"
#include "Queue.hpp"
#include "Stack.hpp"

using namespace std;
template <typename T>
class DoublyLinkedList {
    private:
    DoublyNode<T>* pHead;
    DoublyNode<T>* pTail;
    unsigned int listSize;
    

    public:
    DoublyLinkedList();                             //Defult Constructor
    DoublyLinkedList(const DoublyLinkedList&);      //Copy Constructor
    ~DoublyLinkedList();                            //Destructor
    DoublyLinkedList& operator=(const DoublyLinkedList&);       //Operator Overload =, deep copy
    T get(const int) const;                 //Gets position, 0 indexed
    void set(const int, const T);           //Sets the position 0 indexed
    void insert(const int, const T&);        //Inserts node at position, 0 indexed
    void remove(const int);                 //Removes node at position
    int size() const;                       //Returns size
    void print() const;                     //Prints the list
    
    void printDimensionalArray();
    Position breadthFirstSearch(Position&);
    Position depthFirstSearch(Position&);
    bool getVisited(const int) const ;
    void visit(Position&);
    void setPosition(Position&);
    void setVisited(const int&);
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
    if(OTHER.listSize == 0) {
        this->pHead = nullptr;
        this->pTail = nullptr;
        this->listSize = 0;
        return;
    }
    DoublyNode<T>* currNewList = nullptr;   //Makes two node pointers to track position in the linked list
    DoublyNode<T>* currOriginal = nullptr;
    pHead = nullptr;                        //Sets the head to nullptr
    listSize = 0;                           //Sets listSize to 0
    currOriginal = OTHER.pHead;             //Position in original list is the head
    DoublyNode<T>* newNode = new DoublyNode<T>; //Make a new node for the new head
    newNode->visited = OTHER.pHead->visited;
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
        newNode->visited = currOriginal->pNext->visited;
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
    if(this == &OTHER) {             //Guard against self assignment
        return *this;               
    }
    if(OTHER.listSize == 0) {
        this->pHead = nullptr;
        this->pTail = nullptr;
        this->listSize = 0;
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
    this->pHead->visited = OTHER.pHead->visited;
    this->pHead->value = OTHER.pHead->value;   //Set the values of the heads to be the same
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
        DoublyNode<T>* newNode = new DoublyNode<T>;                    //Else make a new node
        newNode->visited = currOriginal->pNext->visited;
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
    return curr->value;               //return that value
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
void DoublyLinkedList<T>::insert(const int POS, const T &VAL) {
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
        cout << currPos->value;     //print the value in the node   
        currPos = currPos->pNext;           //Advance the node
    }
    cout << endl;
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
void DoublyLinkedList<T>::printDimensionalArray() {     //Prints a 2d array
    DoublyNode<T>* curr = pHead;
    while(curr) {       //While there are more lists,
        curr->value.print();        //Print the list
        cout << endl;               //End the line
        curr = curr->pNext;         //Move to the next node
    }
}

template <typename T>
Position DoublyLinkedList<T>::breadthFirstSearch(Position& searchStart) {
    Queue<Position> queuer;                     //Make a queue
    queuer.push(searchStart);                   //Add the start of the search
    while(!queuer.isEmpty()) {                  //While the queue is not empty
        Position currPos = queuer.pop();        //Take out the next node
        this->visit(currPos);                       //Visit that node in the list

        if(this->get(currPos.row).get(currPos.column) == 'E') {     //If the node contained an E
            cout << "End was reached! " << endl;                    //The end is reached
            this->printDimensionalArray();                          //Print the array
            return currPos;                                         //Return the position
        } else if(this->get(currPos.row).get(currPos.column) == '.' || this->get(currPos.row).get(currPos.column) == 'S') {     //If it is not the end or a wall
            if(this->get(currPos.row + 1).getVisited(currPos.column) == false) {        //Check below if it has not been checked already
                queuer.push(Position(currPos.row + 1, currPos.column));                 //Add to the queue
            }
            if(this->get(currPos.row).getVisited(currPos.column + 1) == false) {        //If not checked
                queuer.push(Position(currPos.row, currPos.column + 1));                 //Add to the right
            }
            if(this->get(currPos.row - 1).getVisited(currPos.column) == false) {        //If not checked
                queuer.push(Position(currPos.row - 1, currPos.column));                 //Add above
            }
            if(this->get(currPos.row).getVisited(currPos.column - 1) == false) {        //If not checked
                queuer.push(Position(currPos.row, currPos.column - 1));                 //Add to the left
            }
            if(this->get(currPos.row).get(currPos.column) == '.') {             //If the node is a .
                this->setPosition(currPos);         //Make the node @
            }
        } 

    }
    cout << "End cannot be reached." << endl;       //If the queue is empty the end is not availible
    this->printDimensionalArray();                  //Print the array
    return Position(-1, -1);                            //Return -1s
}

template <typename T> 
Position DoublyLinkedList<T>::depthFirstSearch(Position& searchStart) {
    Stack<Position> stacker;                     //Make a queue
    stacker.push(searchStart);                   //Add the start of the search
    while(!stacker.isEmpty()) {                  //While the queue is not empty
        Position currPos = stacker.pop();        //Take out the next node
        this->visit(currPos);                       //Visit that node in the list

        if(this->get(currPos.row).get(currPos.column) == 'E') {     //If the node contained an E
            cout << "End was reached! " << endl;                    //The end is reached
            this->printDimensionalArray();                          //Print the array
            return currPos;                                         //Return the position
        } else if(this->get(currPos.row).get(currPos.column) == '.' || this->get(currPos.row).get(currPos.column) == 'S') {     //If it is not the end or a wall
            if(this->get(currPos.row + 1).getVisited(currPos.column) == false) {        //Check below if it has not been checked already
                stacker.push(Position(currPos.row + 1, currPos.column));                 //Add to the queue
            }
            if(this->get(currPos.row).getVisited(currPos.column + 1) == false) {        //If not checked
                stacker.push(Position(currPos.row, currPos.column + 1));                 //Add to the right
            }
            if(this->get(currPos.row - 1).getVisited(currPos.column) == false) {        //If not checked
                stacker.push(Position(currPos.row - 1, currPos.column));                 //Add above
            }
            if(this->get(currPos.row).getVisited(currPos.column - 1) == false) {        //If not checked
                stacker.push(Position(currPos.row, currPos.column - 1));                 //Add to the left
            }
            if(this->get(currPos.row).get(currPos.column) == '.') {             //If the node is a .
                this->setPosition(currPos);         //Make the node @
            }
        } 

    }
    cout << "End cannot be reached." << endl;       //If the queue is empty the end is not availible
    this->printDimensionalArray();                  //Print the array
    return Position(-1, -1);                            //Return -1s
}


template <typename T>
bool DoublyLinkedList<T>::getVisited(const int POS) const {
    if(listSize == 0) {
        return true;
    } else if(POS < 0) {
        return true;
    }
    DoublyNode<T>* curr = pHead;            //Node pointer tracks the position in the list
    bool nodeVisited = true;                      //Make a defult variable to hold the value
    for(int i = 0; i < POS; i++) {          //i represents current node, will land on POS
        curr = curr->pNext;                 //Moves curr to the next node.
        if(curr == nullptr) {           //If the POS is out of range,
            return true;                 //Return the defult
        }
    }
    nodeVisited = curr->visited;        //Else, take the value of the i'th node
    return nodeVisited;               //return that value
}

template <typename T>
void DoublyLinkedList<T>::visit(Position& POS) {    //Marks node as visited
    DoublyNode<T>* curr = pHead;        //Make a node that points to the head of the list
    for(int i = 0; i < POS.row; i++) {      //Find the node for the desired row
        curr = curr->pNext;
        if(curr == nullptr) {
            return;
        }
    }
    
    curr->value.setVisited(POS.column);
    return;
}



template <typename T>
void DoublyLinkedList<T>::setPosition(Position& POS) {      //Sets the position as an @
    DoublyNode<T>* curr = pHead;                         //Node pointer to the head
    for(int i = 0; i < POS.row; i++) {              //Find the node for row
        curr = curr->pNext;
        if(curr == nullptr) {
            return;
        }
    }
    curr->value.set(POS.column, '@');
    return;
}

template <typename T>
void DoublyLinkedList<T>::setVisited(const int& POS) {
    DoublyNode<T>* curr = pHead;
    for(int j = 0; j < POS; j++) {                   //For find the node in the list
        curr = curr->pNext;
        if(curr == nullptr) {
            return;
        }
    }
    curr->visited = true;          //Change the value to true
    return;
}
#endif