#ifndef BINARYSEARCHTREE
#define BINARYSEARCHTREE
#include "TreeNode.hpp"

template <typename T>
class BinarySearchTree {
    private:
    unsigned int treeSize;      //Tracks the number of nodes in the tree
    TreeNode<T>* root;          //Holds the adress of the root node    

    public:
    
    

    BinarySearchTree();         //Creates tree, assigns root to null and size to 0
    BinarySearchTree<T>& operator=(const BinarySearchTree&);    //Copies the passed binary search tree
    BinarySearchTree(const BinarySearchTree&);              //Makes binary search tree out of another tree
    ~BinarySearchTree();                    //Deallocates all nodes

    TreeNode<T>* copySubTree(TreeNode<T>*);     //Copies a sub tree and returns a pointer to the new subtree
    void insert(T);         //Inserts a node with value into the tree, inserted nodes are leaf nodes
    void remove(T);         //Removes a node of specific value from the tree
    void printInOrder();        //Prints the tree in order
    void printPreOrder();       //Prints the root, then left subtree, then right subtree
    void printPostOrder();      //Prints the right subtree, the left subtree, then the root
    void printBreadthOrder();               //Prints the nodes going down the levels
    void printDepthOrder();                 //Prints the root, the left subtree, then the right subtree
    void printByLevels();                   //Prints the level numbers, then the nodes in the level
    void printHeight();                     //Prints the height of the tree
    unsigned int size() const;              //returns the number of nodes in the tree
    void setUnvisited(TreeNode<T>*);        //Sets all nodes as unvisited
};

template <typename T>
TreeNode<T>* recursiveInsert(TreeNode<T>*, T);           //Inserts to the tree and rearranges children
template <typename T>
TreeNode<T>* recursiveDelete(TreeNode<T>*, T);      //Deletes a value from the tree, rearranges children
template <typename T>
TreeNode<T>* makeTreeNode(T);                       //Creates tree node and returns the adress, node has no children.
template <typename T>
TreeNode<T>* minimumInTree(TreeNode<T>*);       //Returns a pointer to the minimum element
template <typename T>
void deleteSubTree(TreeNode<T>*);               //Deletes a subtree, takes in the root
template <typename T>       
int getHeight(TreeNode<T>*);                    //Returns the height of the tree
template <typename T>
void printLevel(TreeNode<T>*, int);             //Prints a level of the subtree, second arguement is given level
template <typename T>
void preOrder(TreeNode<T>*);
template <typename T>
void inOrder(TreeNode<T>*);
template <typename T>
void postOrder(TreeNode<T>*);

template <typename T>
BinarySearchTree<T>::~BinarySearchTree() {      //Deallocates the whole binary tree
    if(this->root == nullptr) {                 //If the root is nullptr, there is no node to delete
        return;
    }
    deleteSubTree(root->left);              //Recursively deletes the subtree to the left of the root
    deleteSubTree(root->right);             //Recursively deletes the subtree to the right of the root


    delete root;    //Delete the root
}


template <typename T>
BinarySearchTree<T>::BinarySearchTree() {   //Defult constructor for a binary search tree
    root = nullptr;
    treeSize = 0;
}


template <typename T>
TreeNode<T>* makeTreeNode(T value) {        //Makes a node that holds the value and returns pointer to the node
    TreeNode<T>* newNode = new TreeNode<T>;
    newNode->value = value;             //New treeNode holds the value
    newNode->left = nullptr;            //The left and right pointers are nullptr
    newNode->right = nullptr;
    return newNode;
}

template <typename T> 
void BinarySearchTree<T>::insert(T value) {         //Inserts a node with given value
    if(this->root == nullptr) {                     //If the tree is empty
        this->root = recursiveInsert(this->root, value);    //Make the root of the tree the new node
    } else {
        recursiveInsert(this->root, value);         //Else, the root stays the same and the node is inserted
    }
    treeSize += 1;      //Increase the size of the tree
}

template <typename T>
void BinarySearchTree<T>::remove(T value) {     //Removes a node with the given value
    if(root->value == value) {                  //If the root is the node removed,
        root = recursiveDelete(this->root, value);  //Remove the node and reassign the root of the tree
    } else {
        recursiveDelete(this->root, value);         //Else remove the node and reassign children
    }
    treeSize -= 1;      //Decreases the tree size
}

template <typename T>
TreeNode<T>* recursiveInsert(TreeNode<T>* root, T value) {      //Recursively inserts a node in the correct position
    if(root == nullptr) {                   //If the tree is empty, make the root the new node
        root = makeTreeNode(value); 
    } else if(value <= root->value) {           //Else if the value is less than the root value
        root->left = recursiveInsert(root->left, value);        //Insert the value into the left subtree
    } else if(value >= root->value) {           //Else if the value is more than the root value
        root->right = recursiveInsert(root->right, value);      //Insert the value in the right subtree
    } 
    return root;            //Return the adress of the root
}

template <typename T>
TreeNode<T>* recursiveDelete(TreeNode<T>* root, T value) {      //Recursively deletes the node given
    if(root == nullptr) {           //If the tree is empty, do nothing
        
    } else if(value < root->value) {            //Else if the value is less than the root value,
        root->left = recursiveDelete(root->left, value);    //The node is in the left subtree, delete from the left subtree
    } else if(value > root->value) {            //If the value is more than the root value,
        root->right = recursiveDelete(root->right, value);  //The node is in the right subtree, delete from the right subtree
    } else {        //If the node is the value of the root, delete it.
        //Case 1- root has no children
        if(root->left == nullptr && root->right == nullptr) {  
            delete root;    //Delete the node, no children need to be reassigned
            root = nullptr;
            
        } else if (root->left == nullptr) {     //Else if the node has a right child only
            TreeNode<T>* temp = root;       //Make a temporary pointer to the root
            root = root->right;             //The pointer now points to the right child instead of the deleted node
            delete temp;            //Delete the node
            
        } else if(root->right == nullptr) {     //If the node has a left child only
            TreeNode<T>* temp = root;           //Make temporary pointer to the root
            root = root->left;              //The pointer now points to the left child instead of the deleted node
            delete temp;            //Delete the node

        } else {            //Else if the node has two children
            TreeNode<T>* min = minimumInTree(root->right);  //Find the minimum value in the right subtree
            root->value = min->value;           //Make the node hold that value. There are now two nodes that hold the minimum value
            root->right = recursiveDelete(root->right, min->value); //Delete the duplicate value from the right subtree
        }
    }
    return root;        //Return the adress of the current root
}

template <typename T>
TreeNode<T>* minimumInTree(TreeNode<T>* root) {     //Finds the minimum in the subtree
    T minimum = root->value;            //Make a variable to hold the roots value
    while(root->left != nullptr) {          //While the root to the left exists,
        minimum = root->left->value;        //The node to the left is less, so make it the new minimum
        root = root->left;          //Make the root the left node and search again
    }
    return root;            //Return the adress of the minimum node
}

template <typename T>           //Prints the subtree in order, left side, then root, then rightside
void BinarySearchTree<T>::printInOrder() {
    if(root == nullptr) {       //If the list is empty
        return;             //Return
    }
    inOrder(root->left);       //If not empty, print the left subtree
    if(root->visited == false) {    //Print the value of the root if not visited
        cout << root->value << " ";
    }
    root->visited = true;           //Make the node visited
    inOrder(root->right);      //Print the right subtree
    setUnvisited(root);
}

template <typename T>
void BinarySearchTree<T>::printPreOrder() {    //Print the root, then the left subtree, then the right subtree
    if(root == nullptr) {       //If the tree is empty
        return;
    } 
    if(root->visited == false) {            //If the root is not visited
        cout << root->value << " ";        //Print the value of the node
    }
    root->visited = true;               //Make the node visited
    preOrder(root->left);          //Print the left subtree in preorder
    preOrder(root->right);         //Print the right subtree in preorder
    setUnvisited(root);
}


template <typename T>
void BinarySearchTree<T>::printPostOrder() {   //Prints the tree, left subtree, then right subtree, then root
    if(root == nullptr) {           //If the tree is empty
        return;                 //Return
    } 
    
    postOrder(root->left);         //Print the left subtree in postorder
    postOrder(root->right);        //Print the right subtree in post order
    if(root->visited == false) {
        cout << root->value << " ";     //Print the node
    }
    root->visited = true;           //Make the node visited
    setUnvisited(root);
}

template <typename T>
void deleteSubTree(TreeNode<T>* root) {         //Deletes a subtree given its root
    if(root == nullptr) {           //If the root is nullptr
        return;                 //Do nothing
    }
    deleteSubTree(root->left);      //Deletes the left subtree of the subtree
    deleteSubTree(root->right);     //Deletes the right subtree of the subtree

    delete root;            
    

}

template<typename T>        //Copies a subtree from its root
TreeNode<T>* BinarySearchTree<T>::copySubTree(TreeNode<T>* root) {
    if(root == nullptr) {       //If the tree is empty, do nothing
        return nullptr;
    }
    TreeNode<T>* newRoot = makeTreeNode(root->value);       //Make a new node for the given root
    newRoot->left = copySubTree(root->left);            //Copy the left subtree of this root
    newRoot->right = copySubTree(root->right);          //Copy the right subtree of this root
    return newRoot;             //Return the new root
}

template <typename T>           //Makes a binary search tree from another binary search tree
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree& OTHER) {      
    this->root = makeTreeNode(OTHER.root->value);       //Makes a node that holds the root value
    this->root->left = copySubTree(OTHER.root->left);       //Copy the left subtree
    this->root->right = copySubTree(OTHER.root->right);     //Copy the right subtree
    this->treeSize = OTHER.treeSize;                    //Copy the tree size

}

template <typename T>
BinarySearchTree<T>& BinarySearchTree<T>::operator=(const BinarySearchTree& OTHER) {    //Deep copies a binary tree
    if(OTHER.root == nullptr) {     //If the root is nullptr then do nothing
        
    } else {        
        deleteSubTree(root->left);  //Else delete the left subtree of the original
        deleteSubTree(root->right);     //Delete the right subtree of the original

        cout << "Deleting the node " << root->value << endl;      //Delete the root value
        delete root;
    }
    
    this->root = makeTreeNode(OTHER.root->value);       //Copy the root node value
    this->root->left = copySubTree(OTHER.root->left);       //Copy the left subtree of the copied list
    this->root->right = copySubTree(OTHER.root->right);     //Copy the right subtree of the copied list
    this->treeSize = OTHER.treeSize;            //Copy the size of the list
}

template <typename T>
unsigned int BinarySearchTree<T>::size() const {    //Returns the size
    return treeSize;
}

template <typename T>
int getHeight(TreeNode<T>* root) {      //Returns the height of the list
    if(root == nullptr) {           //If the list is empty, return 0
        return 0;
    } else {
        int leftCount = getHeight(root->left);      //Else find the height of the left side
        int rightCount = getHeight(root->right);        //Find the height of the right side

        if(leftCount > rightCount) {        //If the left count is higher
            return leftCount + 1;           //Add 1 for the root and return
        } else {
            return rightCount + 1;          //Else return the right side plus the root node
        }
    }
}

template <typename T>
void BinarySearchTree<T>::printHeight() {       //Prints the height of the tree
    int height = getHeight(this->root);         //Makes variable that holds the height
    cout << "Height: " << height << endl;       //Print the height
}

template <typename T>
void BinarySearchTree<T>::printBreadthOrder() {     //Print the list in breadth order, simmilar to print by levels
    int height = getHeight(this->root);     //Find the height of the list
    for(int i = 0; i <= height; i++) {      //For each level in the list
        printLevel(this->root, i);          //Print the level
    }
    cout << endl;           //Print an empty line
}

template <typename T>
void printLevel(TreeNode<T>* root, int level) {     //Print the level given in the tree
    if(root == nullptr) {       //If the root is nullptr
        return;
    }   
    if(level == 1) {            //If the level is 1
        cout << root->value << " ";     //Print the root
    } else if(level > 1) {          //Else if the level is more than 1
        printLevel(root->left, level - 1);     //Print the level of the left subtree, subtract since we move down the tree     
        printLevel(root->right, level - 1);     //Print the level of the right subtree, subtract since we move down the tree
    }
}


template <typename T>
void BinarySearchTree<T>::printDepthOrder() {       //Prints the tree depth first
    this->printPreOrder();        //Pre order is a type of depth transversal, print preorder
}

template <typename T>   
void BinarySearchTree<T>::printByLevels() {     //Prints the tree by levels
    int height = getHeight(this->root);         //Make variable for the height
    for(int i = 0; i <= height; i++) {      //For each level
        if(i == 0) {    
            continue;;
        }
        cout << "Level " << i << ": ";      //Print the level number
        printLevel(this->root, i);          //Print the current level
        cout << endl;
    }
    cout << endl;           //Print an endl
}   

template <typename T>
void BinarySearchTree<T>::setUnvisited(TreeNode<T>* root) {     //Sets the list as unvisited
    if(root == nullptr) {       //If list is empty, do nothings
        return;
    } 
    
    root->visited = false;      //Make the root unvisited
    setUnvisited(root->left);       //Set the left subtree as unvisited
    setUnvisited(root->right);      //Set the right subtree as unvisited
    
}

template <typename T>           //Prints the subtree in order, left side, then root, then rightside
void inOrder(TreeNode<T>* root) {
    if(root == nullptr) {       //If the list is empty
        return;             //Return
    }
    inOrder(root->left);       //If not empty, print the left subtree
    if(root->visited == false) {    //Print the value of the root if not visited
        cout << root->value << " ";
    }
    root->visited = true;           //Make the node visited
    inOrder(root->right);      //Print the right subtree
}

template <typename T>
void preOrder(TreeNode<T>* root) {    //Print the root, then the left subtree, then the right subtree
    if(root == nullptr) {       //If the tree is empty
        return;
    } 
    if(root->visited == false) {            //If the root is not visited
        cout << root->value << " ";        //Print the value of the node
    }
    root->visited = true;               //Make the node visited
    preOrder(root->left);          //Print the left subtree in preorder
    preOrder(root->right);         //Print the right subtree in preorder
    
}

template <typename T>
void postOrder(TreeNode<T>* root) {   //Prints the tree, left subtree, then right subtree, then root
    if(root == nullptr) {           //If the tree is empty
        return;                 //Return
    } 
    
    postOrder(root->left);         //Print the left subtree in postorder
    postOrder(root->right);        //Print the right subtree in post order
    if(root->visited == false) {
        cout << root->value << " ";     //Print the node
    }
    root->visited = true;           //Make the node visited
    
}

#endif