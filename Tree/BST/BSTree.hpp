#ifndef BSTREE_HPP
#define BSTREE_HPP

#include <iostream>
#include <list>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

template <typename T>
struct BSTNode {
    BSTNode* p;
    BSTNode* left;
    BSTNode* right;
    T key;

    BSTNode(T key);
    BSTNode();
    BSTNode(BSTNode* p, BSTNode* left, BSTNode* right, T key);
};

template <typename T>
struct BSTree {
    BSTNode<T>* root;

    BSTree();
    BSTree(BSTNode<T>* root);
};

template<typename T> BSTNode<T>* BSTree_search_Ric(BSTNode<T>* x, T k);
template<typename T> void preorder_seeBST_Ric(BSTNode<T>* x);
template<typename T>void BSTree_insert(BSTree<T>& tree, BSTNode<T>* z);
template<typename T> void createBSTree(BSTree<T>& tree,vector<T> arr);

#include "BSTree.tpp"

#endif