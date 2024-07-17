#ifndef QUEUE
#define QUEUE
#include "DoublyNode.hpp"


template <typename T>
class Queue {
    private:
    DoublyNode<T>* pHead;       //Data members like a linked list
    DoublyNode<T>* pTail;
    unsigned int queueSize;

    public:
    Queue();
    Queue(const Queue&);            //Copy Constructor
    ~Queue();
    void push(T);                   //Add to the BACK
    unsigned int size();            //returns size
    T pop();                        //Pop from the FRONT
    T peak() const;                 //returns the front node value
    bool isEmpty() const;           //returns if empty
};

template <typename T> 
Queue<T>::Queue() {     //Makes empty queue
    pHead = nullptr;
    pTail = nullptr;
    queueSize = 0;
}

template <typename T> 
Queue<T>::~Queue() {        //Destroys queue and its nodes
    if(queueSize == 0) {
        return;
    }
    DoublyNode<T>* curr = pHead;
    while(curr) {
        curr = curr->pNext;
        delete pHead;
        pHead = curr;
        queueSize -= 1;
    }
}

template <typename T>
void Queue<T>::push(T value) {                  //Adds to the back
    if(queueSize == 0) {                            //If size is 0
        DoublyNode<T>* newNode = new DoublyNode<T>;     //Make a new node
        newNode->value = value;                         //Insert a value
        pHead = newNode;                    //This node is the head and tail
        pTail = newNode;
        queueSize += 1;                     //Increase size
        newNode->pNext = nullptr;           //The next and prev are nullptr
        newNode->pPrev = nullptr;
    } else {        
        DoublyNode<T>* newNode = new DoublyNode<T>;     //If the queue has nodes
        newNode->value = value;             //Make node and insert value
        newNode->pPrev = pTail;         //This node is the new tail
        newNode->pPrev->pNext = newNode;            //Connect to the old tail
        pTail = newNode;
        queueSize += 1;             //Increase the size
        newNode->pNext = nullptr;           //Make it point to nullptr
    }
}

template <typename T> 
T Queue<T>::pop() {                     //Remove from front, return value
    if(queueSize == 0) {            //If size is 0
        return T();         //Return default constructor
    } else if(queueSize == 1) {         //If the size is 1
        T oldValue = pHead->value;
        delete pHead;                   //Take head value and delete
        queueSize -= 1;
        pHead = nullptr;
        return oldValue;
    } else {                        //Else,
        T oldValue = pHead->value;
        DoublyNode<T>* curr = pHead;        //Take the head nodes value
        pHead = pHead->pNext;               //Advance the head
        delete curr;                    //Delete the old head
        queueSize -= 1;
        curr = nullptr;                 //Decrease size and return
        return oldValue;
    }
}

template <typename T> 
T Queue<T>::peak() const {          //Returns the next nodes value
    if(queueSize == 0) {            //If size is 0 
        return T();                     //Return default
    }
    T value = pHead->value;     //Return the value of the head if there are nodes
    return value;
}

template <typename T> 
bool Queue<T>::isEmpty() const {        //Returns if empty
    if(queueSize == 0) {
        return true;        //If empty, return true
    } else {
        return false;
    }
}

template <typename T> 
unsigned int Queue<T>::size() {
    return queueSize;               //Return size
}
#endif