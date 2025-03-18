#include "BSTree.hpp"


int main(){
    BSTree<int> tree;
    vector<int> arr;
    int dim;
    cout<<"Set the number of nodes: ";
    cin>>dim;

    cout<<"--Decide "<<dim<<" numbers---"<<endl;
    for(int i=0;i<4;i++){
        int elem;
        cout<<"Num "<<i+1<<" : ";
        cin>>elem;
        arr.push_back(elem);
        
    }
    createBSTree(tree,arr);
    
    cout<<"---Show the Tree---"<<endl;

    preorder_seeBST_Ric(tree.root);
    
    return 0;
}