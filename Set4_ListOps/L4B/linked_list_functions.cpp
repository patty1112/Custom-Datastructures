/* CSCI 261: Lab 4B Linked List Operations
 *
 * Author: Patrick Maes
 * No Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     Video on linked list definition - https://www.youtube.com/watch?v=3gZ7F31Mwi0
 *
 * Create a program to prompt up to 15 numbers from the user and return the max and min.
 */
// The include section adds extra definitions from the C++ standard library.
#include "linked_list_functions.h"

Node* linked_list_make_node(const int VALUE) {

    Node* newNode = new Node;   //Make a node pointer that points to a new node
    newNode->pNext = nullptr;   //Make the next node nullptr
    newNode->value = VALUE;     //Make the value of the node VALUE
    return newNode;             //return the node
}

int linked_list_get_size(Node* pHead) {
    
    if(pHead == nullptr){   //If pHead is uninitialized, return 0
        return 0;
    }
    int size = 1;           //Make size variable and set it as 1 
    Node* curr = pHead;     //Make a node pointer called curr that points to the head
    while(curr->pNext != nullptr){  //While there is more nodes in the list
        size += 1;                  //Increase the size
        curr = curr->pNext;         //Move curr to the next node
    }
    return size;                //Return the size
}

Node* linked_list_add_value_to_front(Node* pHead, const int VALUE) {    

    Node* newNode = new Node;       //Make node pointer that points to a new node
    newNode->value = VALUE;         //Make the value of the new node VALUE
    newNode->pNext = pHead;         //Make the next node the old Head
    pHead = newNode;                //Make the Head the new node

    return pHead;                   //return the head of the list
}

int linked_list_get_value_at_position(Node* pHead, const int POS) {
    // TODO #4
    if(pHead == nullptr) {      //If pHead is not initailized
        return -1;              //return -1
    }
    Node* curr = pHead;         //Make a node pointer that points to the head
    int value = -999;           //Initialize a value variable
    if(POS < 0){                //If the position is negative, return -1
        return -1;
    }
    for(int i = 0; i < POS; i++){       //Repeat the loop POS times
        curr = curr->pNext;         //Advance curr to the next node
        if(curr == nullptr){        //If curr is nullptr, then POS is out of range
            return -1;          //Return -1
        }
    }
    value = curr->value;        //value is curr's value
    
    return value;               //return value
}

int linked_list_min(Node* pHead) {
    // TODO #5
    if(pHead == nullptr){       //If pHead is not initailized
        return -1;              //Return -1
    }
    int minimum = pHead->value; //The minimum is the first element in pHead
    Node* curr = pHead;         //Make a node pointer that points to the head
    while(curr != nullptr){     //While curr is not out of range
        if(curr->value < minimum){  //Check if curr's value is less than minimum
            minimum = curr->value;  //If it is, then update minimum
        }
        curr = curr->pNext;         //advance curr
    }
    return minimum;             //When finished, return minimum
}

int linked_list_max(Node* pHead) {
    // TODO #6
    if(pHead == nullptr){       //If pHead is not initialized
        return -1;              //return -1
    }
    int maximum = pHead->value; //maximum is the fist element in the list
    Node* curr = pHead;         //make a node pointer that points to the head
    while(curr != nullptr){         //While curr is not out of range
        if(curr->value > maximum){      //If the value of curr is greater than maximum
            maximum = curr->value;      //update maximum
        }
        curr = curr->pNext;         //advance curr
    }
    return maximum;                 //when finished return maximum
}       

int linked_list_find(Node* pHead, const int TARGET) {
    // TODO #7
    Node* curr = pHead;     //make a node pointer that points to the head
    int postion = 0;        //Make a variable to store current position
    if(pHead == nullptr) {      //If pHead is uninitialize, return -1
        return -1;
    }
    while(curr != nullptr){         //While curr is not out of range
        if(curr->value == TARGET){      //if the value is the TARGET
            return postion;             //Return where it was
        }
        curr = curr->pNext;         //Advance curr
        postion += 1;       //iterate the counter each time
    }
    return -1;      //If not found return -1
}

Node* linked_list_remove_node_from_front(Node* pHead) {
    // TODO #8
    if(pHead == nullptr) {      //If phead is not initialized
        return pHead;           //return pHead
    }
    Node* temp = pHead;         //Make node pointer that points to the head 
    pHead = pHead->pNext;       //Make the head the node after it
    delete temp;                //Delete the old head pointer
    return pHead;               //return the new head
}

Node* linked_list_set_value_at_position(Node* pHead, const int POS, const int VALUE) {
    // TODO #9
    Node* curr = pHead;         //Make a node poiner that points to the head
    if(POS < 0){                //If POS is less than 0, return the original list
        return pHead;
    }
    if(pHead == nullptr){       //If pHead is uninitialized, then return pHead
        return pHead;
    }
    for(int i = 0; i < POS; i++){       //For each element until POS
        curr = curr->pNext;             //Advance curr
        if(curr == nullptr){            //if POS is out of range
            return pHead;               //return the original list
        }
    }
    curr->value = VALUE;            //Make the value of curr VALUE
    return pHead;                   //Return pHead
}