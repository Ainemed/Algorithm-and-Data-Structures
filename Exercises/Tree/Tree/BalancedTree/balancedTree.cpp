#include <iostream>
#include "math.h"
#include <vector>

using namespace std;
struct Node{
    int val;
    Node* left;
    Node* right;
    
    Node():val(0),left(nullptr),right(nullptr){}
    Node(int val):val(val),left(nullptr),right(nullptr){}
    Node(int val, Node* left, Node* right):val(val),left(left),right(right){}
    
};
typedef Node* PNode;

struct Tree{
    PNode root;
    Tree(PNode root):root(root){}
};
typedef Tree* PTree;

int heightTree(PNode root, bool& m){
    if(root){
        int left = heightTree(root->left,m);
        int right= heightTree(root->right,m);
        if(abs(left-right)>1){
            m = false;
        }
        return 1+ max(right,left);
    }
    return 0;
}
bool isBalanced(PNode root) {
    bool m = true;
    heightTree(root,m);
    return m;
}
int main(){
    
    return 0;
}