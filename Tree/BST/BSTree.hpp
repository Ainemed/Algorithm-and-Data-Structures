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
template<typename T> BSTree<T>* createBSTree(BSTree<T>& tree,vector<T> arr);
template<typename T> BSTNode<T>* BSTree_search_Iter(BSTNode<T>* x, T k);
template<typename T> BSTNode<T>* BSTree_max(BSTNode<T>* x);
template<typename T> BSTNode<T>* BSTree_min(BSTNode<T>* x);
template <typename T> BSTNode<T>* createBSTree_tot_aux(const vector<T>& arr, int inf, int sup, BSTNode<T>* father);
template <typename T> BSTree<T> createBSTree_tot(vector<T> arr);
template<typename T> void BSTree_Transplant(BSTree<T>& tree, BSTNode<T>* u,BSTNode<T>* v);
template<typename T> void BSTree_Delete(BSTree<T>& tree, BSTNode<T>* z);

#include "BSTree.tpp"

#endif