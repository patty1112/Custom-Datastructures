#ifndef STACK
#define STACK
#include "DoublyNode.hpp"


template <typename T>
class Stack {
    private:
    DoublyNode<T>* pTail;
    unsigned int stackSize;
    
    public:
    Stack();
    Stack(const Stack&);
    ~Stack();
    void push(T);               //Adds to the BACK
    T pop();                    //Takes off from the BACK
    T peak() const;
    bool isEmpty() const;

};

template <typename T> 
Stack<T>::Stack() {
    pTail = nullptr;
    stackSize = 0;
}

template <typename T> 
Stack<T>::~Stack() {
    if(stackSize == 0) {
        return;
    }
    DoublyNode<T>* curr = pTail;
    while(curr) {                       //While there are nodes
        curr = curr->pPrev;
        delete pTail;                   //Advance curr and delete the tail
        pTail = curr;
        stackSize -= 1;
    }
}

template <typename T>
void Stack<T>::push(T value) {          //Adds a node to the back of the stack
    if(stackSize == 0) {                //If size is 0
        DoublyNode<T>* newNode = new DoublyNode<T>;     //Make a node
        newNode->value = value;         //Insert a value
        pTail = newNode;                //Make this node the tail
        stackSize += 1;                 //Increase the size
        newNode->pNext = nullptr;
        newNode->pPrev = nullptr;       //Make the next nodes nullptrs
    } else {
        DoublyNode<T>* newNode = new DoublyNode<T>;     //Else make a node to be inserted
        newNode->value = value;         //Insert a value
        newNode->pPrev = pTail;         //Connect to the old tail
        pTail = newNode;                //Make it the new tail
        stackSize += 1;                //Increase size
        newNode->pNext = nullptr;           //Make the next node nullptr
    }
}

template <typename T>
T Stack<T>::pop() {             //Take node off the back
    if(stackSize == 0) {
        return T();
    } else if (stackSize == 1) {        //If there is only one node
        T oldValue = pTail->value;          //Take the value
        delete pTail;                   //Delete it
        stackSize -= 1; 
        return oldValue;    
    } else {
        DoublyNode<T>* curr = pTail;        //Else make a pointer to the tail
        pTail = pTail->pPrev;               //Move the tail towards the front
        T oldValue = curr->value;               //Take the value of the old tail
        delete curr;                    //Delete it
        stackSize -= 1;
        return oldValue;            //return
    }
}

template <typename T>
T Stack<T>::peak() const {      //returns value of the tail
    if(stackSize == 0) {
        return T();         
    }   
    T value = pTail->value;     //Takes the value of the tail
    return value;               //return
}

template <typename T>
bool Stack<T>::isEmpty() const {        //returns if empty
    if(stackSize == 0) {            //If empty
        return true;                //return true
    } else {
        return false;
    }
}

#endif