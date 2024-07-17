/* CSCI 261: AXC Forest Walk
 *
 * Author: Patrick Maes
 * Resources used: NONE
 *
 * Creates 3 binary trees and transverses them
 */
#include <iostream>
using namespace std;
#include "BinarySearchTree.hpp"



int main() {
    BinarySearchTree<int> newTree;      //Creates a tree
    newTree.insert(6);          //inserts the values
    newTree.insert(5);
    newTree.insert(7);
    newTree.insert(1);
    newTree.insert(2);
    newTree.insert(9);
    newTree.insert(3);


    cout << "In Order: ";
    newTree.printInOrder();     //Prints in order
    
    cout << endl;
    cout << "PreOrder: ";       
    newTree.printPreOrder();        //Prints preOrder
    
    cout << endl;
    cout << "PostOrder: ";
    newTree.printPostOrder();       //prints postOrder

    cout << endl;
    cout << "BreadthOrder: ";
    newTree.printBreadthOrder();            //Prints breadth order
    
    cout << "DepthOrder: ";
    newTree.printDepthOrder();              //Prints depth order
    
    cout << endl;
    cout << "By Levels: " << endl;          
    newTree.printByLevels();                //prints by levels
    
    newTree.printHeight();
    cout << endl;


    BinarySearchTree<int> newTree2;     //Create new tree
    newTree2.insert(5);
    newTree2.insert(1);             //Insert values
    newTree2.insert(9);
    newTree2.insert(7);
    newTree2.insert(6);
    newTree2.insert(3);
    newTree2.insert(2);

    cout << "In Order: ";
    newTree2.printInOrder();       //Prints in order
    
    cout << endl;
    cout << "PreOrder: ";
    newTree2.printPreOrder();      //prints preOrder
    
    cout << endl;
    cout << "PostOrder: ";
    newTree2.printPostOrder();     //Prints post order
    
    cout << endl;
    cout << "BreadthOrder: ";
    newTree2.printBreadthOrder();               //Prints breadth order
    
    cout << "DepthOrder: ";
    newTree2.printDepthOrder();             //Prints depth order
    
    cout << endl;
    cout << "By Levels: " << endl;
    newTree2.printByLevels();           //Prints by levels
    
    newTree2.printHeight();             //Print the height
    cout << endl;
    
    BinarySearchTree<int> newTree3;     //Create new tree
    newTree3.insert(5);
    newTree3.insert(2);
    newTree3.insert(1);
    newTree3.insert(7);
    newTree3.insert(9);
    newTree3.insert(6);         //Insert nodes to the tree
    newTree3.insert(3);

    cout << "In Order: ";
    newTree3.printInOrder();       //Prints in order
    
    cout << endl;
    cout << "PreOrder: ";
    newTree3.printPreOrder();      //prints pre order
    
    cout << endl;
    cout << "PostOrder: ";  
    newTree3.printPostOrder();     //Prints the post order
    
    cout << endl;
    cout << "BreadthOrder: ";
    newTree3.printBreadthOrder();               //Prints the breadth order
    
    cout << "DepthOrder: ";
    newTree3.printDepthOrder();                 //Prints the depth order
    
    cout << endl;
    cout << "By Levels: " << endl;
    newTree3.printByLevels();                   //Prints by level
    
    newTree3.printHeight();                     //Prints the height
    cout << endl;
    
    return 0;
}