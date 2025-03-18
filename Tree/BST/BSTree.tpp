#include "BSTree.hpp"


// Struct BSTNode
template <typename T>
BSTNode<T>::BSTNode(T key) : p(nullptr), left(nullptr), right(nullptr), key(key) {}

template <typename T>
BSTNode<T>::BSTNode() : p(nullptr), left(nullptr), right(nullptr), key(0) {}

template <typename T>
BSTNode<T>::BSTNode(BSTNode* p, BSTNode* left, BSTNode* right, T key) : p(p), left(left), right(right), key(key) {}

// Struct BSTree
template <typename T>
BSTree<T>::BSTree() : root(nullptr) {}

template <typename T>
BSTree<T>::BSTree(BSTNode<T>* root) : root(root) {}

// Functions Implementation

template <typename T>
/**
 * @brief Return the BSTNode with the same key if it exists, NIL otherwise: Complexity: 
 * 
 * @param x 
 * @param k 
 * @return BSTNode<T>* 
 */
BSTNode<T>* BSTree_search_Ric(BSTNode<T>* x, T k){
    if(!x || x->key==k){
        return x;
    }else{
        if(x->key > k){
            return BSTree_search_Ric(x->left,k);
        }else{
            return BSTree_search_Ric(x->right,k);
        }
    }
}

template<typename T> 
void preorder_seeBST_Ric(BSTNode<T>* x){
    if(x){
        cout<<x->key<<endl;
        preorder_seeBST_Ric(x->left);
        preorder_seeBST_Ric(x->right);
    }
}


template <typename T>
void BSTree_insert(BSTree<T>& tree, BSTNode<T>* z){
    BSTNode<T>* y, *x;
    x=tree.root;
    y=nullptr;
    while(x){
        y=x;
        if(z->key < x->key){
            x=x->left;
        }else{
            x=x->right;
        }
    }
    z->p=y;
    if(!y){
        tree.root=z;
    }else{
        if(z->key < y->key){
            y->left=z;
        }else{
            y->right=z;
        }
    }
}

template <typename T>
void createBSTree(BSTree<T>& tree,vector<T> arr){
    for (size_t i = 0; i < arr.size(); i++)
    {
        BSTNode<int> *elem= new BSTNode<int>(arr.at(i));
        BSTree_insert(tree,&*elem);
    }
    
}


