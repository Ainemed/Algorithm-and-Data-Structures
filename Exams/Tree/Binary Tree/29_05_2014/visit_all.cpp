#include <iostream>

using namespace std;

struct Node{
    Node* p;
    Node* left;
    Node* right;
    int key;

    Node(): key(-1), p(nullptr), left(nullptr), right(nullptr){}
    Node(int key): key(key), p(nullptr), left(nullptr), right(nullptr){}
    Node(int key, Node* p, Node* left, Node* right): key(key), p(p), left(left), right(){}
    
};


struct Tree{
    Node* root;

    Tree(): root(nullptr){}
    Tree(Node* root): root(root){}

};

void preorder_see(Node* v){
    if(v){
        cout<<v->key<<endl;
        preorder_see(v->left);
        preorder_see(v->right);
    }
}

void symmetric_see(Node* v){
    if(v){
        symmetric_see(v->left);
        cout<<v->key<<endl;
        symmetric_see(v->right);
    }
}

void postorder_see(Node* v){
    if(v){
        postorder_see(v->left);
        postorder_see(v->right);
        cout<<v->key<<endl;
    }
}


int main(){
    Node elem1(1), elem2(2), elem3(3), elem4(4), elem5(5), elem6(6), elem7(7);
    Tree tree(&elem1);

    elem1.left=&elem2;
    elem1.right=&elem3;

    elem2.p=&elem1;
    elem2.left=&elem4;

    elem3.p=&elem1;
    elem3.left=&elem5;

    elem4.p=&elem2;
    elem4.right=&elem6;

    elem6.p=&elem4;
    elem6.right=&elem7;

    cout<<"--- Preorder See ---"<<endl;
    preorder_see(tree.root);
    cout<<"--- Symmetric See ---"<<endl;
    symmetric_see(tree.root);
    cout<<"--- Posorder See ---"<<endl;
    postorder_see(tree.root);

    
    return 0;
}