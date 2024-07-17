#ifndef DOUBLYNODE
#define DOUBLYNODE

template <typename T>
struct DoublyNode {
    //Stores the value of datatype T
    T value;
    //Pointer to the next node
    DoublyNode* pNext;
    //Pointer to the previous node
    DoublyNode* pPrev;
    
};



#endif