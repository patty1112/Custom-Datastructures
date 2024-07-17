/* CSCI 261: LXC Binary Search Trees
 *
 * Author: Patrick Maes
 * Resources used: NONE
 *
 * Create the binary search tree class and insert nodes
 */
#include <iostream>
using namespace std;
#include "BinarySearchTree.hpp"



int main() {
    BinarySearchTree<int> newTree;
    newTree.insert(6);
    newTree.insert(5);
    newTree.insert(7);
    newTree.insert(1);
    newTree.insert(2);
    newTree.insert(9);
    newTree.insert(3);

    cout << "The size of the tree is" << endl;
    cout << newTree.size() << endl;

    cout << "Deallocating the tree:" << endl;
    return 0;
}