#include <iostream>
using namespace std;

struct Node {
    Node* left;
    Node* right;
    int key;

    Node(): key(-1), left(nullptr), right(nullptr) {}
    Node(int key): key(key), left(nullptr), right(nullptr) {}
    Node(int key, Node* left, Node* right): key(key), left(left), right(right) {}
};

// Definizione di tipo
typedef Node* PNode;

struct Tree {
    PNode root;

    Tree(): root(nullptr) {}
    Tree(PNode root): root(root) {}
};

void preorder_see(PNode v) {
    if (v) {
        cout << v->key << endl;
        preorder_see(v->left);
        preorder_see(v->right);
    }
}

void countLeaf(PNode v, int& count) {
    if (v) {
        if (!v->left && !v->right) {
            count++;
        }
        countLeaf(v->left, count);
        countLeaf(v->right, count);
    }
}

int countEvenNodes(PNode r, int& countEven) {
    if (!r) return 0;

    if (!r->left && !r->right) return 1;

    int leftLeaves = countEvenNodes(r->left, countEven);
    int rightLeaves = countEvenNodes(r->right, countEven);
    int totalLeaves = leftLeaves + rightLeaves;

    if (totalLeaves % 2 == 0) countEven++;

    return totalLeaves;
}

int main() {
    Node elem1(1), elem2(2), elem3(3), elem4(4), elem5(5), elem6(6), elem7(7);
    Tree tree(&elem1);

    elem1.left = &elem2;
    elem1.right = &elem3;
    elem2.left = &elem4;
    elem3.left = &elem5;
    elem4.right = &elem6;
    elem6.right = &elem7;

    preorder_see(tree.root);

    cout << "--- Count Leaf ---" << endl;
    int count = 0;
    countEvenNodes(tree.root, count);
    cout << count << endl;

    return 0;
}