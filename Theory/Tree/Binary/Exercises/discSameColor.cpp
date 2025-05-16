#include "../BinaryTree.hpp"


template<typename T>
void discSameColorAux(Node<T>* u, int& count, int& white, int& black){
    if(u){
        int bsx=0,nsx=0, bdx=0, ndx=0;
        discSameColorAux(u->left, count, bsx, nsx);
        discSameColorAux(u->right, count, bdx, ndx);

        white = bsx + bdx + (u->key == 'W');
        black = nsx + ndx + (u->key == 'B');
        if(white == black){
            count++;
        }
    }
}




template<typename T>
/**
 * @brief Count the number of nodes with the same number of descendent color, Complexity: T(n) = Θ(n)
 * 
 * @param tree 
 * @return int 
 */
int discSameColor(Tree<T> tree){
    int count=0,white=0, black=0;
    discSameColorAux(tree.root, count, white, black);
    return count;
}



int main(){
    Node<char> elem1('B'), elem2('W'), elem3('B'), elem4('B'), elem5('W'), elem6('B');
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
    cout<<"Node with the same descendent:  "<<discSameColor(tree)<<endl;
    return 0;
}