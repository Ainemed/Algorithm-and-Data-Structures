#include "../BinaryTree.hpp"

int main(){
    Node<char> elem1('a'), elem2('b'), elem3('d'), elem4('e'), elem5('f'), elem6('c'), elem7('g'), elem8('i'), elem9('f');
    Tree<char> tree(&elem1);

    elem1.left=&elem2;
    elem1.right=&elem6;

    elem2.left=&elem3;
    elem3.right=&elem4;
    elem4.left=&elem5;

    elem6.right=&elem7;
    elem7.left=&elem8;
    elem7.right=&elem9;


    postorder_seeDFS_Ric(tree.root);

    
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
