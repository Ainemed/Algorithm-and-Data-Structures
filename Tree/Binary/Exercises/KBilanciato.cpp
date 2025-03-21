#include "../BinaryTree.hpp"

template<typename T>
void K_BalancedAux(Node<T>* u,int& min,int& max){
    int minsx, maxsx, mindx, maxdx;

    if(!u){
        min = -1;
        max = -1;
    }else{ 
        // Post-Order View
        K_BalancedAux(u->left, minsx, maxsx);
        K_BalancedAux(u->right, mindx, maxdx);

        min = (minsx <= mindx ? minsx : mindx)+1;
        max = (maxsx <= maxdx ? maxdx : maxsx)+1;
    }
}

template<typename T>
/**
 * @brief Check if the Tree is K Balanced, Complexity: T(n) = Θ(n)
 * 
 * @param u 
 * @param k 
 * @return true if it is K Balanced
 * @return false if it is not K Balanced
 */
bool K_Balanced(Node<T>* u, int k){
    int min=0, max=0;
    K_BalancedAux(u,min,max);
    return (max - min <= k);
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

    
    cout<<"----- K Balanced -----"<<endl;
    int k;
    cout<<"K : ";
    cin>>k;
    bool m = K_Balanced(tree.root, k);   
    if(m){
        cout<<"Is "<<k<<" Balanced: "<<"Yes"<<endl;
    }else{
        cout<<"Is "<<k<<" Balanced: "<<"No"<<endl;
    }

    return 0;
}