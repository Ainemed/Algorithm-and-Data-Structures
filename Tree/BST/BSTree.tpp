#include "BSTree.hpp"


//---------------------------------------------------------- STRUCT CREATION ------------------------------------------------------

//---------------------------------------------------------- Struct BSTNode -----------------------------------------------------
template <typename T>
BSTNode<T>::BSTNode(T key) : p(nullptr), left(nullptr), right(nullptr), key(key) {}

template <typename T>
BSTNode<T>::BSTNode() : p(nullptr), left(nullptr), right(nullptr), key(0) {}

template <typename T>
BSTNode<T>::BSTNode(BSTNode* p, BSTNode* left, BSTNode* right, T key) : p(p), left(left), right(right), key(key) {}

//---------------------------------------------------------- Struct BSTree -----------------------------------------------------
template <typename T>
BSTree<T>::BSTree() : root(nullptr) {}

template <typename T>
BSTree<T>::BSTree(BSTNode<T>* root) : root(root) {}


//---------------------------------------------------------- FUNCTIONS ------------------------------------------------------------

//---------------------------------------------------------- Show BSTree ---------------------------------------------------------


template<typename T> 
void preorder_seeBST_Ric(BSTNode<T>* x){
    if(x){
        cout<<x->key<<endl;
        preorder_seeBST_Ric(x->left);
        preorder_seeBST_Ric(x->right);
    }
}


//---------------------------------------------------------- Insert BSTNode ------------------------------------------------------


template <typename T>
/**
 * @brief Insert the z node into the BSTree tree while maintaining the search property:
 *          - Complexity: T(n)= O(h), where h is the height of the tree
 * 
 * @param tree 
 * @param z 
 */
void BSTree_insert(BSTree<T>& tree, BSTNode<T>* z){
    BSTNode<T>* y, *x;
    x=tree.root;
    y=nullptr;
    while(x){ // T(n)=O(h)
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

//---------------------------------------------------------- Create BSTree -------------------------------------------------------

template <typename T>
/**
 * @brief Create a Tree using an array with the key, Complexity: T(n)= O(h), where h is the height of the tree
 * 
 * @param tree 
 * @param arr 
 */
BSTree<T> createBSTree(vector<T> arr){
    BSTree<int> tree;
    for (size_t i = 0; i < arr.size(); i++)
    {
        BSTNode<int> *elem= new BSTNode<int>(arr.at(i));
        BSTree_insert(tree,&*elem); // T(n) = O(h)
    }
    return tree;
}

template <typename T>
/**
 * @brief Auxiliary Function of createBSTree_tot , Complexity: T(n)= Θ(log n)
 * 
 * @param arr 
 * @param inf 
 * @param sup 
 * @param father 
 * @return BSTNode<T>* 
 */
BSTNode<T>* createBSTree_tot_aux(const vector<T>& arr, int inf, int sup, BSTNode<T>* father){
    if(inf>sup){
        return nullptr;
    }else{
        int med=(inf+sup)/2;
        BSTNode<T> *r = new BSTNode<T>(arr.at(med));
        r->p=father;
        r->left= createBSTree_tot_aux(arr,inf,med-1,r);
        r->right = createBSTree_tot_aux(arr,med+1,sup,r);
        return r;
    }
}

template <typename T>
/**
 * @brief Create a Tree using an array with the key, Complexity: T(n)= Θ(nlog n), because:
 *          - Ordered Array: T(n) = Θ(n)
 *          - Auxiliary Function = T(n) = Θ(log n) 
 * 
 * @param arr must be ordered, Complexity : T(n) = Θ(n)
 * @return BSTree<T> 
 */
BSTree<T> createBSTree_tot(vector<T> arr){
    BSTree<T> tree;
    BSTNode<T> *elem;
    elem = nullptr;
    tree.root = createBSTree_tot_aux(arr, 0, arr.size()-1, elem); //T(n) = Θ(log n)
    return tree;
}


//---------------------------------------------------------- Search BSTNode ------------------------------------------------------

template <typename T>
/**
 * @brief Return the BSTNode with the same key if it exists, NIL otherwise: Complexity:
 *        - Balanced tree: T(n) = O(log n)
 *        - Unbalanced tree: T(n) = O(n)
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
/**
 * @brief Return the BSTNode with the same key if it exists, NIL otherwise: Complexity:
 *        - Balanced tree: T(n) = O(log n)
 *        - Unbalanced tree: T(n) = O(n)
 * 
 * @param x 
 * @param k 
 * @return BSTNode<T>* 
 */
BSTNode<T>* BSTree_search_Iter(BSTNode<T>* x, T k){
    while(x && x->key != k){
        if(k<x->key){
            x = x->left;
        }else{
            x= x->right;
        }
    }
    return x;
}

//---------------------------------------------------------- Maximum BSTNode -----------------------------------------------------

template<typename T>
/**
 * @brief Return the node with the biggest key in the subtree of x : Complexity: T(n)= O(h), where h is the height of the tree
 * 
 * @param x ∈ BSTree
 * @return BSTNode<T>* 
 */
BSTNode<T>* BSTree_max(BSTNode<T>* x){
    while(x->right){
        x=x->right;
    }
    return x;
}


//---------------------------------------------------------- Minimum BSTNode -----------------------------------------------------
template<typename T>
/**
 * @brief Return the node with the smallest key in the subtree of x : Complexity: T(n)= O(h), where h is the height of the tree
 * 
 * @param x ∈ BSTree
 * @return BSTNode<T>* 
 */
BSTNode<T>* BSTree_min(BSTNode<T>* x){
    while(x->left){
        x=x->left;
    }
    return x;
}

//---------------------------------------------------------- Delete BSTNode -----------------------------------------------------


template<typename T>
/**
 * @brief Modify the BSTree to maintain the BST rules, Complexity: T(n) = O(1), linear
 * 
 * @param tree 
 * @param u 
 * @param v 
 */
void BSTree_Transplant(BSTree<T>& tree, BSTNode<T>* u,BSTNode<T>* v){
    if(!u->p){
        tree.root=v;
    }else{
        if(u == u->p->left){
            u->p->left=v;
        }else{
            u->p->right=v;
        }
    }
    if(v){
        v->p=u->p;
    }
}

template<typename T>
/**
 * @brief Delete a specific BSTNode of the BSTree maintaining BST rules, Complexity: T(n) = O(h), where h is the height of the tree
 * 
 * @param tree 
 * @param z 
 */
void BSTree_Delete(BSTree<T>& tree, BSTNode<T>* z){
    if(!z->left){
        BSTree_Transplant(tree,z,z->right);
    }else{
        if(!z->right){
            BSTree_Transplant(tree,z,z->left);
        }else{
            BSTNode<int> *elemMin = BSTree_min(z->right);
            if(elemMin->p != z){
                BSTree_Transplant(tree,z,z->right);
                elemMin->right = z->right;
                z->right->p = elemMin;
            }
            BSTree_Transplant(tree,z,elemMin);
            elemMin->left = z->left;
            elemMin->left->p = elemMin;
        }
    }
}

//---------------------------------------------------------- Successor BSTNode -----------------------------------------------------


template<typename T>
/**
 * @brief Find the Successor of the given BSTNode, Complexity: T(n)=O(h), where h is the height of the tree
 * 
 * @param x 
 * @return BSTNode<T>* 
 */
BSTNode<T>* BST_Successor(BSTNode<T>* x){
    if(x->right){
        return BSTree_min(x->right);
    }else{
        BSTNode<T>* y = x->p;
        while (y && x == y->right)
        {
            x = y;
            y = y->p;
        }
        return y;
        
    }
}

//---------------------------------------------------------- Predecessor BSTNode -----------------------------------------------------

template<typename T>
/**
 * @brief Find the Predecessor of the given BSTNode, Complexity: T(n)=O(h), where h is the height of the tree
 * 
 * @param x 
 * @return BSTNode<T>* 
 */
BSTNode<T>* BST_Predecessor(BSTNode<T>* x){
    if(x->left){
        return BSTree_max(x->left);
    }else{
        BSTNode<T>* y = x->p;
        while (y && x == y->left)
        {
            x = y;
            y = y->p;
        }
        return y;
        
    }
}