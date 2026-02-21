#include <iostream>

using namespace std;

struct Node{
    char elem;
    Node* left;
    Node* right;

    Node(): elem(' '), left(nullptr), right(nullptr){}
    Node(char elem): elem(elem), left(nullptr), right(nullptr){}
    Node(char elem, Node* left, Node* right): elem(elem), left(left), right(right){}
};
typedef Node* PNode;

struct Tree{
    PNode root;
    Tree(PNode root): root(root){}
};
typedef Tree* PTree;

void preorder(PNode v){
    if(v){
        cout<<v->elem<<endl;
        preorder(v->left);
        preorder(v->right);
    }
}
void symmetric(PNode v){
    if(v){
        symmetric(v->left);
        cout<<v->elem<<endl;
        symmetric(v->right);
    }
}

int heightNode(PNode v){
    if(v){
        int left = heightNode(v->left)+1;
        int right = heightNode(v->right)+1;
        if(left>right){
            return left;
        }else{
            return right;
        }
    }
    return 0;
}


int main(){
    Node elem1('a'),elem2('b'), elem3('c'),elem4('d'), elem5('e'), elem6('f'), elem7('g'), elem8('i'), elem9('f'), elem10('f');

    elem1.left= &elem2;
    elem1.right= &elem3;

    elem2.left= &elem4;
    elem3.right=&elem7;
    elem4.right= &elem5;
    elem5.left=&elem9;
    elem7.right=&elem10;
    elem7.left=&elem8;
    
    Tree tree(&elem1);
    symmetric(tree.root);

    cout<<heightNode(&elem7)<<endl;
    return 0;
}