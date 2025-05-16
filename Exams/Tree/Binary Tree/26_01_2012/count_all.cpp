#include <iostream>
#include <vector>

using namespace std;

struct Node{
    Node* left;
    Node* right;
    int key;

    Node():key(-1), left(nullptr), right(nullptr) {}
    Node(int key):key(key), left(nullptr), right(nullptr) {}
    Node(int key, Node* left, Node* right):key(key), left(left), right(right) {}

};

struct Tree{
    Node* root;
    
    Tree(): root(nullptr){}
    Tree(Node* root): root(root){}
};

void sumKey(Node* r, int& count){
    if(r){
        count += r->key;
        sumKey(r->left, count);
        sumKey(r->right, count);
    }
}

void postorder_see(Node* v){
    if(v){
        cout<<v->key<<endl;
        postorder_see(v->left);
        postorder_see(v->right);
    }
}

int maxSubtreeSum(Node* r, int& maxSum) {
    if (!r) return 0;

    // Somma dei sottoalberi sinistro e destro
    int leftSum = maxSubtreeSum(r->left, maxSum);
    int rightSum = maxSubtreeSum(r->right, maxSum);

    // Somma totale del sottoalbero corrente
    int currentSum = r->key + leftSum + rightSum;

    // Aggiorna il massimo globale se necessario
    if (currentSum > maxSum) {
        maxSum = currentSum;
    }

    return currentSum;
}

int main(){
    Node elem1(1), elem2(2), elem3(3), elem4(4), elem5(5), elem6(6), elem7(7);
    Tree tree(&elem1);

    elem1.left=&elem2;
    elem1.right=&elem3;

    
    elem2.left=&elem4;

    
    elem3.left=&elem5;

    
    elem4.right=&elem6;

    
    elem6.right=&elem7;

    postorder_see(tree.root);

    int count=0;
    sumKey(tree.root, count);

    cout<<"--- Sum key ---"<<endl;
    cout<<count<<endl;

    int maxSum = INT_MIN;
    maxSubtreeSum(tree.root, maxSum);

    cout << "--- Max subtree sum ---" << endl;
    cout << maxSum << endl;

    return 0;
}