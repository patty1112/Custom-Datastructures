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
    void mergeSort(DoublyNode<T>*&, bool (*compare)(T, T));
    void splitLinkedList(DoublyNode<T>*&, DoublyNode<T>*&, DoublyNode<T>*&);
    DoublyNode<T>* merge(DoublyNode<T>*&, DoublyNode<T>*&, bool (*compare)(T, T));
    bool acending(T, T);
    bool decending(T, T);
};

template <typename T>
DoublyNode<T>* merge(DoublyNode<T>*& LHS, DoublyNode<T>*& RHS, bool (*compare)(T, T)) {    //Merges two lists and returns a pointer to the head
    DoublyNode<T>* mergedHead = nullptr;                //pointer that tracks the head of the list
    
    if(LHS == nullptr) {            //Base case, if the list is already in its sorted postion
        return RHS;
    } else if(RHS == nullptr) {
        return LHS;
    }

    if(!compare(LHS->value, RHS->value)) {                  //If the value of the left is smaller than the right,
        mergedHead = LHS;                           //Make the head the left pointer
        mergedHead->pNext = merge(LHS->pNext, RHS, compare);     //Then merge the next node and RHS
    } else {
        mergedHead  = RHS;                              //Else make the Head the right hand side
        mergedHead->pNext = merge(LHS, RHS->pNext, compare);     //Merge the left hand side and the next node of the right
    }
    return mergedHead;              //Return the head of the list.
}

template <typename T>
void splitLinkedList(DoublyNode<T>*& originalHead, DoublyNode<T>*& LHS, DoublyNode<T>*& RHS) {
    DoublyNode<T>* middlePointer = originalHead;         //Pointer will mark middle of list, or start of the second half
    DoublyNode<T>* endPointer = originalHead;            //Pointer will iterate until the end
    while(endPointer != nullptr) {                      //While endpointer is not null
        endPointer = endPointer->pNext;                 //Advance the endpointer
        if(endPointer != nullptr) {                     //If endpointer is not null
            endPointer = endPointer->pNext;             //Advance both pointers
            middlePointer = middlePointer->pNext;       //NOTE: endPointer is iterated twice for each time middle pointer is iterated
        }
    }
        middlePointer->pPrev->pNext = nullptr;          //The node before now points to nullptr
        middlePointer->pPrev = nullptr;                 //The previous node of middlepointer is nullpointer
        LHS = originalHead;                         //LHS is the original head
        RHS = middlePointer;                        //RHS is the middle pointer
}

template <typename T>
void mergeSort(DoublyNode<T>*& listHead, bool (*compare)(T, T)) {                  //MergeSort, but takes just the pointer as arguement. 
    if(listHead == nullptr || listHead->pNext == nullptr) {     //If the node is the last one, do nothing.

    } else {
        DoublyNode<T>* RHS = nullptr;       //Make the RHS and LHS nullptr
        DoublyNode<T>* LHS = nullptr;
        splitLinkedList(listHead, LHS, RHS);        //Split the list only based off the head pointer
        mergeSort(LHS, compare);                             //Sort the two sides
        mergeSort(RHS, compare);
        listHead = merge(LHS, RHS, compare);             //Make the head of the list the merged list head

    }
}

template <typename T>
bool acending(T x, T y) {
    return x > y; 
}

template <typename T>
bool decending(T x, T y) {
    return x < y;
}

#endif