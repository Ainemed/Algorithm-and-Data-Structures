#ifndef LEFT_CHILD_RIGHT_BROTHER_HPP
#define LEFT_CHILD_RIGHT_BROTHER_HPP

#include <iostream>
#include <list>
#include <stack>
#include <queue>

using namespace std;

template <typename T>
struct Node {
    Node* p;
    Node* left_child;
    Node* right_sib;
    T key;

    Node(T key);
    Node();
    Node(Node* p, Node* left_child, Node* right_sib, T key);
};

template <typename T>
struct Tree {
    Node<T>* root;

    Tree();
    Tree(Node<T>* root);
};

template <typename T> Node<T>* fatherTree(Node<T>* v);
template <typename T> list<Node<T>*> sonsTree(Tree<T> tree, Node<T>* v);


#include "LCBR.tpp"

#endif // LEFT_CHILD_RIGHT_BROTHER_HPP