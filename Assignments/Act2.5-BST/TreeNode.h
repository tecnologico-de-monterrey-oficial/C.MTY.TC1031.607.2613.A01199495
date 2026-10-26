#ifndef TREENODE_H
#define TREENODE_H

template<typename T>
struct TreeNode {
    T data;
    TreeNode<T>* left;
    TreeNode<T>* right;

    TreeNode(const T& value) : data(value), left(nullptr), right(nullptr) {}
};

#endif
