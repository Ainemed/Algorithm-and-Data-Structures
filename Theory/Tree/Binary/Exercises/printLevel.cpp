#include "../BinaryTree.hpp"

template<typename T>
/**
 * @brief Print all the Nodes at Level k, Complexity: T(n) = Θ(n)
 * 
 * @param u 
 * @param k 
 */
void printLevel(Node<T>* u, int k){
    if(u){
        if(k==0){
            cout<<u->key<<endl;
        }else{
            printLevel(u->left, k-1);
            printLevel(u->right, k-1);
        }
    }
}



int main(){

    Node<char> elem1('A'), elem2('L'), elem3('B'), elem4('E'), elem5('R'), elem6('O');
    Tree<char> tree(&elem1);

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
    cout<<"----- K Level -----"<<endl;
    int k;
    cout<<"- K : ";

    cin>>k;
    printLevel(tree.root, k);


    return 0;
}