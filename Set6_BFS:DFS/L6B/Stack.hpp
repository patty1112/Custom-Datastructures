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
    void push(T);
    T pop();
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
    while(curr) {
        curr = curr->pPrev;
        delete pTail;
        pTail = curr;
        stackSize -= 1;
    }
}

template <typename T>
void Stack<T>::push(T value) {
    if(stackSize == 0) {
        DoublyNode<T>* newNode = new DoublyNode<T>;
        newNode->value = value;
        pTail = newNode;
        stackSize += 1;
        newNode->pNext = nullptr;
        newNode->pPrev = nullptr;
    } else {
        DoublyNode<T>* newNode = new DoublyNode<T>;
        newNode->value = value;
        newNode->pPrev = pTail;
        pTail = newNode;
        stackSize += 1;
        newNode->pNext = nullptr;
    }
}

template <typename T>
T Stack<T>::pop() {
    if(stackSize == 0) {
        return T();
    } else if (stackSize == 1) {
        T oldValue = pTail->value;
        delete pTail;
        stackSize -= 1;
        return oldValue;
    } else {
        DoublyNode<T>* curr = pTail;
        pTail = pTail->pPrev;
        T oldValue = curr->value;
        delete curr;
        stackSize -= 1;
        return oldValue;
    }
}

template <typename T>
T Stack<T>::peak() const {
    if(stackSize == 0) {
        return T();
    }
    T value = pTail->value;
    return value;
}

template <typename T>
bool Stack<T>::isEmpty() const {
    if(stackSize == 0) {
        return true;
    } else {
        return false;
    }
}

#endif