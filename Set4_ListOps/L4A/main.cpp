/* CSCI 261: Lab 4A Array vs Linked List
 *
 * Author: Patrick Maes
 * No Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     Video on linked list definition - https://www.youtube.com/watch?v=3gZ7F31Mwi0
 *
 * Create a program to prompt up to 15 numbers from the user and return the max and min.
 */
// The include section adds extra definitions from the C++ standard library.
#include <iostream>
using namespace std;

struct node {
    int integerData;
    node* next;
};


int main() {
    cout << "Using dynamically allocated array: " << endl;
    int* arrayPointer;                  //Make a new pointer 
    arrayPointer = new int[3];          //Make it point to a new list of size 3
    cout << "Enter 3 integer values to be placed in the array." << endl;
    int userNumber = 0;                 //variable for user input
    for(int i = 0; i < 3; i++) {        //For each element in the list
        cin >> userNumber;              //Store user input
        arrayPointer[i] = userNumber;   //Set index as userInput
    }

    cout << "Printing the array contents in order." << endl;
    for(int j = 0; j < 3; j++) {    //For each element in the array
        cout << arrayPointer[j] << endl;    //Print the elements
    }

    cout << "Printing the array contents backwards." << endl;
    for(int k = 2; k >= 0; k--) {           //For each element in the list backwards
        cout << arrayPointer[k] << endl;    //Print the elements
    }
    delete[] arrayPointer;                  //delete the array


    cout << "Using a linked list: " << endl;

    node* head = NULL;          //Create 3 pointers to nodes
    node* curr = NULL;
    node* temp = NULL;
    
    cout << "Enter 3 numbers to be placed in a linked list." << endl;
    for(int l = 0; l < 3; l++) {        //Iterate loop 3 times
        int userInput = 0;              //variable for userInput
        cin >> userInput;               //Store userInput in the variable
        node* newNode = new node;       //Make a new node to be added
        newNode->next = NULL;           //Make the node the end of the linked list
        newNode->integerData = userInput;   //Make the data of the node the input

        if(head != NULL) {          //If the head already exists
            curr = head;            //point the curr pointer to the head
            while(curr->next != NULL) {  //While the next node exists
                curr = curr->next;       //Move curr along the linked list
            }
            curr->next = newNode;        //Then make the new node after the last element
        } else {                        //Else if head doesnt exist
            head = newNode;             //The new node is the new head
        }
    }

    cout << "Printing the contents in the linked list." << endl;
    curr = head;            //curr pointer is at the head
    while(curr) {           //While curr is not NULL
        cout << curr->integerData << endl;      //Cout the data in curr 
        curr = curr->next;                      //move curr to the next node
    }

    cout << "Printing the contents in the linked list backwards." << endl;
    curr = head;                    //curr pointer is at the head
    while(curr->next != NULL){      //While the next node is not the end
        curr = curr->next;          //Move to the next node
    }
    temp = curr;                    //Since curr is the last node, temp is now a tail pointer but will be changed to the last printed item
    cout << temp->integerData << endl;  //Cout the data in the last node
    curr = head;                        //Set the current back to the head
    while(temp != head){                //Temp will iterate towards front of list. While temp is not head,
            curr = head;                    //Reset the curr pointer to the head
        while(curr->next != temp) {         //While the next value is not the tail pointer
            curr = curr->next;              //Move curr to the next node, it will finish on the one before the most recently printed
        }
        cout << curr->integerData << endl;  //print the data in the curr pointer
        temp = curr;                        //Make the temp pointer point to the node that has been printed already
    }
    
    return 0;
}