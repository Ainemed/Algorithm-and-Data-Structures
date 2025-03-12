#include <iostream>

using namespace std;

struct Node{
    
    Node* p;
    Node* left;
    Node* right;
    char key;

    Node(char key){
        this->p=nullptr;
        this->left=nullptr;
        this->right=nullptr;
        this->key=key;
    }
    Node(){
        this->p=nullptr;
        this->left=nullptr;
        this->right=nullptr;
        this->key=0;
    }
    Node(Node p, Node left, Node right, char key){
        this->p=&p;
        this->left=&left;
        this->right=&right;
        this->key=key;
    }

};

struct Tree{
    public:
        Node* root;

        Tree(){
            this->root=nullptr;
        }

        Tree(Node* root){
            this->root=root;
        }

        
};

int main(){
    


    return 0;
}