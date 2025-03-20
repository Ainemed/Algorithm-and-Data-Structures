#include "../BinaryTree.hpp"

template<typename T>
/**
 * @brief Double the Nodes's key in the Even Level, Complexity: T(n) = Θ(n). But this function doesn't work with this structure.
 *        Because it needs a Node with a pointer for the right sibling and another one for the left child
 * 
 * @param u 
 */
void doubleValue(Node<T>* u){
    Node<T> *iter;

    if(u){
        u->key = u->key*2;
        doubleValue(u->right);

        iter = u->left;
        while(iter){
            doubleValue(iter->left);
            iter = iter->right;
        }
    }
}

template<typename T>
void doubleValueEx(Node<T>* u, int level){
    Node<T> *iter;

    if(u){
        if(level % 2 == 0){
            u->key = u->key *2;            
        }
        doubleValueEx(u->left, level+1);
        doubleValueEx(u->right, level+1);
    }
}



int main(){

    Node<int> elem1(1), elem2(2), elem3(3), elem4(4), elem5(5), elem6(6);
    Tree<int> tree(&elem1);

    elem1.left=&elem2;
    elem1.right=&elem3;

    elem2.p=&elem1;
    elem2.left=&elem4;
    elem4.p=&elem2;
    elem2.right=&elem5;
    elem5.p=&elem2;

    elem3.p=&elem1;
    elem3.right=&elem6;
    elem6.p=&elem3;


    preorder_seeDFS_Ric(tree.root);
    doubleValueEx(tree.root,0);
    //doubleValue(tree.root);
    cout<<"---- Double Value ----"<<endl;
    preorder_seeDFS_Ric(tree.root);


    return 0;
}