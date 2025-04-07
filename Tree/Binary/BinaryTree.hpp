#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

#include <iostream>
#include <list>
#include <stack>
#include <queue>

using namespace std;

template <typename T>
struct Node {
    Node* p;
    Node* left;
    Node* right;
    T key;

    Node(T key);
    Node();
    Node(Node* p, Node* left, Node* right, T key);
};

template <typename T>
struct Tree {
    Node<T>* root;

    Tree();
    Tree(Node<T>* root);
};

// Functions
template <typename T> Node<T>* fatherTree(Node<T>* v);
template <typename T> bool emptyTree(Tree<T> tree);
template <typename T> list<Node<T>*> sonsTree(Tree<T> tree, Node<T>* v);
template <typename T> void seeDFS_Iter(Node<T>* v);
template <typename T> void seeDFS_Ric(Node<T>* v);
template <typename T> void preorder_seeDFS_Ric(Node<T>* v);
template <typename T> void symmetric_seeDFS_Ric(Node<T>* v);
template <typename T> void postorder_seeDFS_Ric(Node<T>* v);
template <typename T> void seeBFS_Iter(Node<T>* v);
template<typename T> bool K_Balanced(Node<T>* u, int k);

#include "BinaryTree.tpp"

#endif // BINARYTREE_HPP
