#include "BinaryTree.hpp"

//---------------------------------------------------------- STRUCT CREATION ------------------------------------------------------

//---------------------------------------------------------- Struct Node ------------------------------------------------------

template <typename T>
Node<T>::Node(T key) : p(nullptr), left(nullptr), right(nullptr), key(key) {}

template <typename T>
Node<T>::Node() : p(nullptr), left(nullptr), right(nullptr), key(' ') {}

template <typename T>
Node<T>::Node(Node* p, Node* left, Node* right, T key) : p(p), left(left), right(right), key(key) {}

//---------------------------------------------------------- Struct Tree ------------------------------------------------------
template <typename T>
Tree<T>::Tree() : root(nullptr) {}

template <typename T>
Tree<T>::Tree(Node<T>* root) : root(root) {}

//---------------------------------------------------------- FUNCTIONS ------------------------------------------------------------

//---------------------------------------------------------- Father Node --------------------------------------------------------

template <typename T>
/**
 * @brief Retrun the father of the node v, Complexity : Θ(1)
 * 
 * @param v 
 * @return Node<T>* 
 */
Node<T>* fatherTree(Node<T>* v) {
    return v->p;
}

//---------------------------------------------------------- Empty Tree --------------------------------------------------------


template <typename T>
/**
 * @brief Check if the tree is empty, Complexity : Θ(1)
 * 
 * @param tree 
 * @return true if it is empty
 * @return false if it isn't empty
 */
bool emptyTree(Tree<T> tree) {
    return tree.root == nullptr;
}

//---------------------------------------------------------- Sons Node --------------------------------------------------------

template <typename T>
/**
 * @brief Return a list of all the sons of the Node v , Complexity : Θ(1)
 * 
 * @param tree 
 * @param v 
 * @return list<Node> 
 */
list<Node<T>*> sonsTree(Tree<T> tree, Node<T>* v) {
    list<Node<T>*> nodeList;
    if (v->left) nodeList.push_back(v->left);
    if (v->right) nodeList.push_back(v->right);
    return nodeList;
}

//---------------------------------------------------------- Show Tree --------------------------------------------------------


template <typename T>
/**
 * @brief Print all the node of the tree  , Complexity : Θ(n)
 * 
 * @param v 
 */
void seeDFS_Iter(Node<T>* v) {
    stack<Node<T>*> stack;
    stack.push(v);
    while (!stack.empty()) {
        Node<T>* tmp = stack.top();
        stack.pop();
        if (tmp) {
            cout << tmp->key << endl;
            stack.push(tmp->left);
            stack.push(tmp->right);        
        }
    }
}

template <typename T>
/**
 * @brief Show all the nodes of the tree in Preorder way (A,L,E,R,B,O) , Complexity : Θ(n)
 * 
 * @param tree 
 */
void preorder_seeDFS_Ric(Node<T>* v) {
    if (v) {
        cout << v->key << endl;
        preorder_seeDFS_Ric(v->left); // T(n-1)
        preorder_seeDFS_Ric(v->right); // T(n-1)
    }
}

template <typename T>
/**
 * @brief Show all the nodes of the tree in Symmetric way (E,L,R,A,B,O), Complexity : Θ(n)
 * 
 * @param v 
 */
void symmetric_seeDFS_Ric(Node<T>* v) {
    if (v) {
        symmetric_seeDFS_Ric(v->left); // T(n-1)
        cout<<v->key<<endl;
        symmetric_seeDFS_Ric(v->right); // T(n-1)
    }
}

template <typename T>
/**
 * @brief Show all the nodes of the tree in Postorder way (E,R,L,O,B,A), Complexity : Θ(n)
 * 
 * @param v 
 */
void postorder_seeDFS_Ric(Node<T>* v) {
    if (v) {
        postorder_seeDFS_Ric(v->left); // T(n-1)        
        postorder_seeDFS_Ric(v->right); // T(n-1)
        cout << v->key << endl;
    }
}

template <typename T>
void seeBFS_Iter(Node<T>* v) {
    list<Node<T>*> queue;
    queue.push_back(v);
    while (!queue.empty()) {
        Node<T>* tmp = queue.front();
        queue.pop_front();
        if (tmp) {
            cout << tmp->key << endl;
            queue.push_back(tmp->left);
            queue.push_back(tmp->right);
        }
    }
}

