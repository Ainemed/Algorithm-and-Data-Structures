#include <iostream>
#include <vector>

using namespace std;

struct Node{
    Node* p;
    Node* left;
    Node* right;
    int key;

    Node(int key): key(key), p(nullptr), left(nullptr), right(nullptr){}
    Node(int key, Node* p, Node* left, Node* right): key(key), p(p), left(left), right(right){}
    Node(): key(-1), p(nullptr), left(nullptr), right(nullptr){}
};
typedef Node* PNode;

struct Tree
{   
    Node* root;

    Tree(): root(nullptr){}
    Tree(Node* root): root(root){}
};

int count_nodes(PNode v){
    if(v){
        int left = count_nodes(v->left)+1;
        int right = count_nodes(v->right)+1;
        return left+right;
    }else{
        return 1;
    }
}
void print_Nodes(PNode v){
    if(v){
        int left=count_nodes(v->left);
        int right=count_nodes(v->right);
        if(left>right){
            cout<<v->key<<endl;
        }
        
    }
}


int main(){
    return 0;
}