#include "BSTree.hpp"



int main(){
    vector<int> arr;
    int dim, search=0;
    cout<<"----------BST----------"<<endl;
    cout<<"Set the number of nodes: ";
    cin>>dim;
    cout<<"--Decide "<<dim<<" numbers---"<<endl;

    for(int i=0;i<dim;i++){
        int elem;
        cout<<"Num "<<i+1<<" : ";
        cin>>elem;
        arr.push_back(elem);
    }

    BSTree<int> tree = createBSTree_tot(arr);


    cout<<"---Show the Tree---"<<endl;
    preorder_seeBST_Ric(tree.root);

    cout<<"---Show the Predecessor---"<<endl;
    BSTNode<int> *elemPred= BST_Predecessor(tree.root);
    cout<<elemPred->key<<endl;

    cout<<"---Show the Successor---"<<endl;
    BSTNode<int> *elemSucc= BST_Successor(tree.root);
    cout<<elemSucc->key<<endl;

    cout<<"---Search The Maximum Node---"<<endl;
    BSTNode<int> *elemMax = BSTree_max(tree.root);
    cout<<"The biggest is: "<<elemMax->key<<endl;


    cout<<"---Search The Minimum Node---"<<endl;
    BSTNode<int> *elemMin = BSTree_min(tree.root);
    cout<<"The biggest is: "<<elemMin->key<<endl;


    cout<<"---Insert a Node---"<<endl;
    BSTNode<int> elemInsert(9);
    BSTree_insert(tree,&elemInsert);
    preorder_seeBST_Ric(tree.root);

    cout<<"---Delete Node---"<<endl;
    int keyDel = 0;
    cout<<"Key of the Node to delete: ";
    cin>>keyDel;
    BSTNode<int> *elemDel= BSTree_search_Iter(tree.root, keyDel);
    BSTree_Delete(tree,elemDel);
    preorder_seeBST_Ric(tree.root);

    cout<<"---Search a Node---"<<endl;
    cout<<"Node number: ";
    cin>>search;
    BSTNode<int> *elemSearch = BSTree_search_Iter(tree.root, search);
    if(elemSearch){
        cout<<"The key: "<<elemSearch->key<<endl;
    }else{
        cout<<"Node doesn't found"<<endl;
    }
    
    
    return 0;
}