#ifndef TREENODE
#define TREENODE



template <typename T>
struct TreeNode {
    //Stores the value of datatype T
   T value;
   bool visited;
   TreeNode* left;
   TreeNode* right;

    TreeNode();
    TreeNode(T);
   
};

template <typename T>
TreeNode<T>::TreeNode() {
    left = nullptr;
    right = nullptr;
    value = T();
    visited = false;
}





#endif