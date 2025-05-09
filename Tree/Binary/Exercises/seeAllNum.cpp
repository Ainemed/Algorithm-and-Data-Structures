#include "../BinaryTree.hpp"

int main(){
    Node<int> elem1(1), elem2(2), elem3(3), elem4(4), elem5(5), elem6(6), elem7(7), elem8(8);
    Tree<int> tree(&elem1);

    elem1.left=&elem2;
    elem1.right=&elem3;

    elem2.right=&elem4;
    elem4.left=&elem7;

    elem3.left=&elem5;
    elem3.right=&elem6;
    
    elem5.right=&elem8;

    cout<<"--- Pre Order ---"<<endl;
    preorder_seeDFS_Ric(tree.root);
    cout<<"--- Symmetric Order ---"<<endl;
    symmetric_seeDFS_Ric(tree.root);
    cout<<"--- Post Order ---"<<endl;
    postorder_seeDFS_Ric(tree.root);

    return 0;
}
