#include <iostream>
#include <vector>
#include <list>

using namespace std;

struct Node{
    char key;
    Node* p;
    Node* left;
    Node* right;

    Node(): key(-1), p(nullptr), left(nullptr), right(nullptr){}
    Node(char key): key(key), p(nullptr), left(nullptr), right(nullptr){}
    Node(char key, Node* p, Node* left, Node* right): key(key), p(p), left(left), right(right){}
};
typedef Node* PNode;

struct Tree{
    PNode root;

    Tree(): root(nullptr){}
    Tree(PNode root): root(root){}
};
typedef Tree* PTree;
void seeBFS(PTree v){
    list<PNode> queue;
    queue.push_back(v->root);
    while(!queue.empty()){
        PNode tmp=queue.front();
        queue.pop_front();
        if(tmp){
            cout<<tmp->key<<endl;
            queue.push_back(tmp->left);
            queue.push_back(tmp->right);
        }
    }
}

void seeLevel(PNode v, int h) {
    if (!v || h < 0) return;

    list<pair<PNode, int>> queue;
    queue.push_back({v, 0});
    bool m = true;
    while (!queue.empty() && m) {
        pair<PNode, int> tmp = queue.front();;
        queue.pop_front();
        if (tmp.second > h){
            m = false;
        }else{
            cout << tmp.first->key << endl;
            if (tmp.first->left)
                queue.push_back({tmp.first->left, tmp.second + 1});
            if (tmp.first->right)
                queue.push_back({tmp.first->right, tmp.second + 1});
        }
    }
}

void seeEvenLevel(PNode v){
    if (!v) return;

    list<pair<PNode, int>> queue;
    queue.push_back({v, 0});
    bool m = true;
    while (!queue.empty() && m) {
        pair<PNode, int> tmp = queue.front();
        queue.pop_front();
        if (tmp.second%2==0){    
            cout << tmp.first->key << endl;
        }
        if (tmp.first->left)
            queue.push_back({tmp.first->left, tmp.second + 1});
        if (tmp.first->right)
            queue.push_back({tmp.first->right, tmp.second + 1});
        
        
    }
    
}


int main(){
    PNode elemA= new Node('A'),elemL = new Node('L'), elemB = new Node('B'),elemE = new Node('E'),elemR = new Node('R'),elemO = new Node('O');
    PTree tree = new Tree(elemA);

    elemA->left=elemL;
    elemA->right=elemB;

    elemL->left=elemE;
    elemL->right=elemR;

    elemB->left=elemO;

    seeEvenLevel(tree->root);
    

    return 0;
}