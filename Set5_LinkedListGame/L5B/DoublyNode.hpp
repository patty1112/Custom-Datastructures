#ifndef DOUBLYNODE
#define DOUBLYNODE

template <typename T>
struct DoublyNode {
    //Stores the value of datatype T
    T value;
    //Pointer to the next node
    DoublyNode<T>* pNext;
    //Pointer to the previous node
    DoublyNode<T>* pPrev;
    
};



#endif