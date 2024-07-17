#ifndef QUEUE
#define QUEUE
#include "DoublyNode.hpp"


template <typename T>
class Queue {
    private:
    DoublyNode<T>* pHead;
    DoublyNode<T>* pTail;
    unsigned int queueSize;

    public:
    Queue();
    Queue(const Queue&);
    ~Queue();
    void push(T);
    T pop();
    T peak() const;
    bool isEmpty() const;
};

template <typename T> 
Queue<T>::Queue() {
    pHead = nullptr;
    pTail = nullptr;
    queueSize = 0;
}

template <typename T> 
Queue<T>::~Queue() {
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
void Queue<T>::push(T value) {
    if(queueSize == 0) {
        DoublyNode<T>* newNode = new DoublyNode<T>;
        newNode->value = value;
        pHead = newNode;
        pTail = newNode;
        queueSize += 1;
        newNode->pNext = nullptr;
        newNode->pPrev = nullptr;
    } else {
        DoublyNode<T>* newNode = new DoublyNode<T>;
        newNode->value = value;
        newNode->pPrev = pTail;
        newNode->pPrev->pNext = newNode;
        pTail = newNode;
        queueSize += 1;
        newNode->pNext = nullptr;
    }
}

template <typename T> 
T Queue<T>::pop() {
    if(queueSize == 0) {
        return T();
    } else if(queueSize == 1) {
        int oldValue = pHead->value;
        delete pHead;
        queueSize -= 1;
        pHead = nullptr;
        return oldValue;
    } else {
        int oldValue = pHead->value;
        DoublyNode<T>* curr = pHead;
        pHead = pHead->pNext;
        delete curr;
        queueSize -= 1;
        curr = nullptr;
        return oldValue;
    }
}

template <typename T> 
T Queue<T>::peak() const { 
    if(queueSize == 0) {
        return T();
    }
    T value = pHead->value;
    return value;
}

template <typename T> 
bool Queue<T>::isEmpty() const {
    if(queueSize == 0) {
        return true;
    } else {
        return false;
    }
}

#endif