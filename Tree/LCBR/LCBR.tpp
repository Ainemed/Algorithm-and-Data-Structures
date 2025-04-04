#include "LCBR.hpp"

//---------------------------------------------------------- STRUCT CREATION ------------------------------------------------------

//---------------------------------------------------------- Struct Node ------------------------------------------------------

template <typename T>
Node<T>::Node(T key) : p(nullptr), left_child(nullptr), right_sib(nullptr), key(key) {}

template <typename T>
Node<T>::Node() : p(nullptr), left_child(nullptr), right_sib(nullptr), key(' ') {}

template <typename T>
Node<T>::Node(Node* p, Node* left_child, Node* right_sib, T key) : p(p), left_child(left_child), right_sib(right_sib), key(key) {}

//---------------------------------------------------------- Struct Tree ------------------------------------------------------
template <typename T>
Tree<T>::Tree() : root(nullptr) {}

template <typename T>
Tree<T>::Tree(Node<T>* root) : root(root) {}

//---------------------------------------------------------- FUNCTIONS ------------------------------------------------------------

template <typename T> 
Node<T>* fatherTree(Node<T>* v){
    return v->p;
}

template <typename T>
/**
 * @brief Return a list of all the sons of the Node v , Complexity : Θ(k)
 * 
 * @param tree 
 * @param v 
 * @return list<Node> 
 */
list<Node<T>*> sonsTree(Tree<T> tree, Node<T>* v){
    list<Node<T>*> listChild;
    Node<T>* iter=v->left_child;

    while (iter != nullptr)
    {
        listChild.push_back(iter);
        iter = iter->right_sib;
    }
    return listChild;
}