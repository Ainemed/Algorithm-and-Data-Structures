#include "BinaryTree.hpp"

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

    
    cout<<"-----"<<endl;
    bool m = emptyTree(tree);   
    if(m){
        cout<<"Is Empty: "<<"Yes"<<endl;
    }else{
        cout<<"Is Empty: "<<"No"<<endl;
    }
    list<Node<char>*> l= sonsTree(tree, &elem1);

    for( Node<char>* elem : l){
        cout<<elem->key<<endl;
    }
    cout<<"---------"<<endl;
    //seeBFS_Iter(tree.root);

    return 0;
}
